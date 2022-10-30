/*

ECB cut-and-paste

Write a k=v parsing routine, as if for a structured cookie. The routine should take:

foo=bar&baz=qux&zap=zazzle

... and produce:

{
  foo: 'bar',
  baz: 'qux',
  zap: 'zazzle'
}

(you know, the object; I don't care if you convert it to JSON).

Now write a function that encodes a user profile in that format, given an email address. You should have something like:

profile_for("foo@bar.com")

... and it should produce:

{
  email: 'foo@bar.com',
  uid: 10,
  role: 'user'
}

... encoded as:

email=foo@bar.com&uid=10&role=user

Your "profile_for" function should not allow encoding metacharacters (& and =). Eat them, quote them, whatever you want to do, but don't let people set their email address to "foo@bar.com&role=admin".

Now, two more easy functions. Generate a random AES key, then:

    Encrypt the encoded user profile under the key; "provide" that to the "attacker".
    Decrypt the encoded user profile and parse it.

Using only the user input to profile_for() (as an oracle to generate "valid" ciphertexts) and the ciphertexts themselves, make a role=admin profile.

*/

package main

import (
	"bytes"
	"crypto/aes"
	crand "crypto/rand"
	"encoding/json"
	"flag"
	"fmt"
	"log"
	"math/rand"
	"strings"
	"time"
)

func main() {
	rand.Seed(time.Now().UnixNano())
	flag.Parse()
	spoof()
}

// we made some assumptions regarding this challenge
// that wasn't clear from the text, assume that uid is always 10, if it
// was variable then this would break down since the encryption
// buffer will change size that is out of our control since we can't
// just keep add padding to the email address to change the buffer size
// an adverserial uid generator could always foil us
// the second assumption is that the encrypt function always does pkcs7
// for us, there are other solutions online that pkcs7 the plain text
// before passing to encrypt and that leads to a different padding scheme
// here we assume encrypt pads for us, this means that our p3 will have some
// unwanted text at the end after decryption, but since we know exactly what
// is in the buffer, we can just truncate it and get the answer
func spoof() {
	key = randn(16)

	blocksz := findblocksz()
	if blocksz != aes.BlockSize {
		log.Fatalf("failed to find correct blocksize, got %d", blocksz)
	}
	if !isecb(blocksz) {
		log.Fatalf("failed to detect ECB mode")
	}

	p0 := profile("AAA@A.com")
	p1 := profile("AAAAAAA@A.admin")
	p2 := profile("blaz@blue.com")
	p3 := []byte(string(p2[0:32]) + string(p1[16:32]) + string(p0[32:48]))

	d0 := decrypt(p0)
	d1 := decrypt(p1)
	d2 := decrypt(p2)
	fmt.Printf("p0=%s\n", d0)
	fmt.Printf("p1=%s\n", d1[16:32])
	fmt.Printf("p2=%s\n", d2[0:32])

	buf := decrypt(p3)[:37]
	str, _ := parsekv(string(buf))
	fmt.Printf("p3=%s\n", buf)
	fmt.Printf("%s\n", str)
}

var (
	key []byte
)

// since the challenge was unclear on whether or not
// uid is unique for a user or is it 10 for all users
// we assume 10, since if it is unique, it becomes hard
// since the length of the block size will change and there
// is no way to just keep adding padding on a user and expect
// any correlation between uid and user email
func profilefor(email string) string {
	email = strings.Replace(email, "&", "", -1)
	email = strings.Replace(email, "=", "", -1)
	uid := 10
	return fmt.Sprintf("email=%s&uid=%d&role=user", email, uid)
}

func profile(email string) []byte {
	return encrypt([]byte(profilefor(email)))
}

func parsekv(str string) (string, error) {
	m := make(map[string]string)
	t := strings.Split(str, "&")
	for _, t := range t {
		x := strings.Split(t, "=")
		if len(x) != 2 {
			continue
		}
		m[x[0]] = x[1]
	}
	s, err := json.MarshalIndent(m, "", "\t")
	if err != nil {
		return "", err
	}
	return string(s), nil
}

func encrypt(src []byte) []byte {
	src = pkcs7(src)
	dst := make([]byte, len(src))

	cipher, err := aes.NewCipher(key)
	if err != nil {
		panic(err)
	}

	for i := 0; i < len(src); i += aes.BlockSize {
		cipher.Encrypt(dst[i:], src[i:])
	}

	return dst
}

func decrypt(src []byte) []byte {
	dst := make([]byte, len(src))

	cipher, err := aes.NewCipher(key)
	if err != nil {
		panic(err)
	}

	for i := 0; i < len(src); i += aes.BlockSize {
		cipher.Decrypt(dst[i:], src[i:])
	}
	pad := int(dst[len(dst)-1])
	dst = dst[:len(dst)-pad]
	return dst
}

func pkcs7(src []byte) []byte {
	n := aes.BlockSize - (len(src) % aes.BlockSize)
	for i := 0; i < n; i++ {
		src = append(src, byte(n))
	}
	return src
}

func randn(n int) []byte {
	p := make([]byte, n)
	_, err := crand.Read(p)
	if err != nil {
		panic(err)
	}
	return p
}

// we start with a "valid" email address
// and just keep generating cipher text until we find
// a block size that is beyond some threshold matching
// since ECB-AES will give us the same output for a block
// with enough As in it and the byte will differ enough
// up until a block size since a good block cipher will scramble
// the text enough making two closely related plaintext
// not match at all in the ciphertext
func findblocksz() int {
	p := "A@A.com"
	q := "AA@A.com"
	n := 0

	l := len(profile(p))
	for i := 0; i < l; i++ {
		x := profile(p)
		y := profile(q)

		for m := 0; m < len(x) && m < len(y); m++ {
			if x[m] != y[m] {
				if n == 0 && m > 1 {
					n = m
				}
				break
			}
		}

		p = "A" + p
		q = "A" + q
	}
	return n
}

// go through all the blocks, if all of them don't match
// then we are not using ECB
func isecb(blocksz int) bool {
	p := bytes.Repeat([]byte("A@A.com"), blocksz*32)
	e := encrypt(p)
	for i := 0; i < len(e); i += blocksz {
		for j := 0; j < i; j += blocksz {
			if bytes.Compare(e[j:j+blocksz], e[i:i+blocksz]) == 0 {
				return true
			}
		}
	}
	return false
}