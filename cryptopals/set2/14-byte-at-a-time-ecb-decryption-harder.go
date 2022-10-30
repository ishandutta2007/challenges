/*

Byte-at-a-time ECB decryption (Harder)

Take your oracle function from #12. Now generate a random count of random bytes and prepend this string to every plaintext. You are now doing:

AES-128-ECB(random-prefix || attacker-controlled || target-bytes, random-key)

Same goal: decrypt the target-bytes.
Stop and think for a second.

What's harder than challenge #12 about doing this? How would you overcome that obstacle? The hint is: you're using all the tools you already have; no crazy math is required.

Think "STIMULUS" and "RESPONSE".

*/

package main

import (
	"bytes"
	"crypto/aes"
	crand "crypto/rand"
	"encoding/base64"
	"flag"
	"fmt"
	"log"
	"math/rand"
	"time"
)

var (
	rndrange = flag.Int("c", 1000, "random count range")
)

func main() {
	log.SetFlags(0)
	log.SetPrefix("ecb-decryption-harder: ")

	rand.Seed(time.Now().UnixNano())
	src, err := base64.StdEncoding.DecodeString("Um9sbGluJyBpbiBteSA1LjAKV2l0aCBteSByYWctdG9wIGRvd24gc28gbXkgaGFpciBjYW4gYmxvdwpUaGUgZ2lybGllcyBvbiBzdGFuZGJ5IHdhdmluZyBqdXN0IHRvIHNheSBoaQpEaWQgeW91IHN0b3A/IE5vLCBJIGp1c3QgZHJvdmUgYnkK")
	ck(err)

	crack([]byte(src))
}

func ck(err error) {
	if err != nil {
		log.Fatal(err)
	}
}

// idea is to find the block size and detect ECB mode, which
// it is but we do it anyways.
// we then fill a input with a constant byte up until the blocksize-1
// then we fill the last remaining blocksize-1 slot with 256 possible
// combinations, building a dictionary of them. We then go through the
// unknown string text and then put each character in the blocksize-1 slot,
// let the ECB function encrypt and then match against the dictionary we
// built, and which ever dictionary slot it matches gives us our decrypted
// byte back
func crack(src []byte) {
	key := randn(16)
	blocksz := findblocksz(key)
	if blocksz != aes.BlockSize {
		log.Fatalf("failed to find correct blocksize, got %d", blocksz)
	}
	if !isecb(key, blocksz) {
		log.Fatal("detected non ECB mode, only ECB mode is supported!")
	}

	// there is a random prefix in the beginning here, but we don't care
	// because we already prepend that random string in our encryption, so our
	// prebuilt table already contains that random prefix during build time.
	// so the match will be the same and the logic doesn't change here
	// the challenge was unclear on whether or not our table needed to be
	// non-random prefixed or not so we assumed it was since that is what we did
	// in challenge #12

	var e [256][]byte
	p := bytes.Repeat([]byte("A"), blocksz)
	for i := 0; i < 256; i++ {
		p[blocksz-1] = byte(i)
		e[i] = encrypt(key, p)
	}

	var dst []byte
	for i := 0; i < len(src); i++ {
		p[blocksz-1] = src[i]

		c := encrypt(key, p)
		for i := range e {
			if bytes.Compare(c, e[i]) == 0 {
				dst = append(dst, byte(i))
			}
		}
	}
	fmt.Printf("original string: %q\n", src)
	fmt.Printf("decrypted string: %q\n", dst)
}

// since there is a random but fixed string appended to our plaintext
// every time we need to run 2 iterations, 1 iteration to find a reference
// point where it changes sizes, that will be our zero point, and then
// we just apply the same trick as before and start counting
func findblocksz(key []byte) int {
	n := 1
	m := 0
	s := 0
	for i := 0; i < 2; i++ {
		s = 0
		for ; ; n++ {
			p := bytes.Repeat([]byte("A"), n)
			e := encrypt(key, p)
			if s == 0 {
				s = len(e)
			} else if s != len(e) {
				break
			}
			if i == 1 {
				m++
			}
		}
	}
	return m
}

// the way we detect ecb is just to fill the data with a constant
// and see if the blocks return the same output at block boundary
// if it does, it is ECB mode, CBC mode or something else will
// make all blocks look random even with the same input for every block
func isecb(key []byte, blocksz int) bool {
	p := bytes.Repeat([]byte("A"), blocksz*32)
	e := encrypt(key, p)
	for i := 0; i < len(e); i += blocksz {
		for j := 0; j < i; j += blocksz {
			if bytes.Compare(e[j:j+blocksz], e[i:i+blocksz]) == 0 {
				return true
			}
		}
	}
	return false
}

func encrypt(key, src []byte) []byte {
	src = randc(src)
	src = pkcs7(src)
	dst := make([]byte, len(src))

	cipher, err := aes.NewCipher(key)
	ck(err)

	for i := 0; i < len(src); i += aes.BlockSize {
		cipher.Encrypt(dst[i:], src[i:])
	}

	return dst
}

func pkcs7(src []byte) []byte {
	n := len(src) % aes.BlockSize
	if n == 0 {
		n = aes.BlockSize
	} else {
		n = aes.BlockSize - n
	}
	for i := 0; i < n; i++ {
		src = append(src, byte(n))
	}
	return src
}

var (
	rndsz int
	rnd   []byte
)

func randc(src []byte) []byte {
	if rndsz == 0 {
		rndsz = rand.Intn(*rndrange) + 1
		rnd = make([]byte, rndsz)
		for i := range rnd {
			rnd[i] = byte(rand.Intn(256))
		}
	}

	for _, v := range rnd {
		src = append([]byte{v}, src...)
	}
	return src
}

func randn(n int) []byte {
	p := make([]byte, n)
	_, err := crand.Read(p)
	ck(err)
	return p
}
