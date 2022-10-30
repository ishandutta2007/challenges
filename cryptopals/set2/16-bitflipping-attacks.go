/*


CBC bitflipping attacks

Generate a random AES key.

Combine your padding code and CBC code to write two functions.

The first function should take an arbitrary input string, prepend the string:

"comment1=cooking%20MCs;userdata="

.. and append the string:

";comment2=%20like%20a%20pound%20of%20bacon"

The function should quote out the ";" and "=" characters.

The function should then pad out the input to the 16-byte AES block length and encrypt it under the random AES key.

The second function should decrypt the string and look for the characters ";admin=true;" (or, equivalently, decrypt, split the string on ";", convert each resulting string into 2-tuples, and look for the "admin" tuple).

Return true or false based on whether the string exists.

If you've written the first function properly, it should not be possible to provide user input to it that will generate the string the second function is looking for. We'll have to break the crypto to do that.

Instead, modify the ciphertext (without knowledge of the AES key) to accomplish this.

You're relying on the fact that in CBC mode, a 1-bit error in a ciphertext block:

    Completely scrambles the block the error occurs in
    Produces the identical 1-bit error(/edit) in the next ciphertext block.

Stop and think for a second.

Before you implement this attack, answer this question: why does CBC mode have this property?

*/
package main

import (
	"crypto/aes"
	"crypto/cipher"
	"crypto/rand"
	"flag"
	"fmt"
	"strings"
)

var (
	key []byte
	iv  []byte
)

// the idea is that CBC XOR the plain text with the cipher text, so if the cipher
// text gets corrupted in a byte position, it scrambles the current block but
// the plain text in the next block will get xor with that value since (C ^ V) ^ P = C ^ (V ^ P)
// where C is the cipher text and V is the value and P is the plaintext
// so we know the character we want and what exist where in the encryption, what we do is
// make the position we want to be NUL character and then xor the cipher with ';' and '='
// messing up the previous block but will give us what we want in the next plain text
func main() {
	flag.Parse()
	x := gen("AAAAAAAAAAAAAAAA\x00admin\x00true")
	x[32] ^= ';'
	x[38] ^= '='
	fmt.Println(exist(x))
}

func init() {
	key = randn(16)
	iv = randn(aes.BlockSize)
}

func gen(str string) []byte {
	str = strings.Replace(str, ";", "%3b", -1)
	str = strings.Replace(str, "=", "%3d", -1)
	str = "comment1=cooking%20MCs;userdata=" + str + ";comment2=%20like%20a%20pound%20of%20bacon"
	plain := pkcs7([]byte(str))
	return encrypt(plain)
}

func exist(enc []byte) bool {
	dec := decrypt(enc)
	toks := strings.Split(string(dec), ";")
	for _, tok := range toks {
		tuple := strings.Split(tok, "=")
		if len(tuple) != 2 {
			continue
		}
		if tuple[0] == "admin" && tuple[1] == "true" {
			return true
		}
	}
	return false
}

func decrypt(src []byte) []byte {
	dst := make([]byte, len(src))

	ebc, err := aes.NewCipher(key)
	pk(err)

	cbc := cipher.NewCBCDecrypter(ebc, iv)
	cbc.CryptBlocks(dst, src)

	pad := int(dst[len(dst)-1])
	dst = dst[:len(dst)-pad]
	fmt.Printf("%q %d\n", dst, pad)

	return dst
}

func encrypt(src []byte) []byte {
	dst := make([]byte, len(src))

	ebc, err := aes.NewCipher(key)
	pk(err)

	cbc := cipher.NewCBCEncrypter(ebc, iv)
	cbc.CryptBlocks(dst, src)

	return dst
}

func pk(err error) {
	if err != nil {
		panic(err)
	}
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
	_, err := rand.Read(p)
	pk(err)
	return p
}