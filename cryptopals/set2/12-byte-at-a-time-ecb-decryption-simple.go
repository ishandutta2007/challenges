/*

Byte-at-a-time ECB decryption (Simple)

Copy your oracle function to a new function that encrypts buffers under ECB mode using a consistent but unknown key (for instance, assign a single random key, once, to a global variable).

Now take that same function and have it append to the plaintext, BEFORE ENCRYPTING, the following string:

Um9sbGluJyBpbiBteSA1LjAKV2l0aCBteSByYWctdG9wIGRvd24gc28gbXkg
aGFpciBjYW4gYmxvdwpUaGUgZ2lybGllcyBvbiBzdGFuZGJ5IHdhdmluZyBq
dXN0IHRvIHNheSBoaQpEaWQgeW91IHN0b3A/IE5vLCBJIGp1c3QgZHJvdmUg
YnkK

Spoiler alert.

Do not decode this string now. Don't do it.

Base64 decode the string before appending it. Do not base64 decode the string by hand; make your code do it. The point is that you don't know its contents.

What you have now is a function that produces:

AES-128-ECB(your-string || unknown-string, random-key)

It turns out: you can decrypt "unknown-string" with repeated calls to the oracle function!

Here's roughly how:

    Feed identical bytes of your-string to the function 1 at a time --- start with 1 byte ("A"), then "AA", then "AAA" and so on. Discover the block size of the cipher. You know it, but do this step anyway.
    Detect that the function is using ECB. You already know, but do this step anyways.
    Knowing the block size, craft an input block that is exactly 1 byte short (for instance, if the block size is 8 bytes, make "AAAAAAA"). Think about what the oracle function is going to put in that last byte position.
    Make a dictionary of every possible last byte by feeding different strings to the oracle; for instance, "AAAAAAAA", "AAAAAAAB", "AAAAAAAC", remembering the first block of each invocation.
    Match the output of the one-byte-short input to one of the entries in your dictionary. You've now discovered the first byte of unknown-string.
    Repeat for the next byte.

Congratulations.

This is the first challenge we've given you whose solution will break real crypto. Lots of people know that when you encrypt something in ECB mode, you can see penguins through it. Not so many of them can decrypt the contents of those ciphertexts, and now you can. If our experience is any guideline, this attack will get you code execution in security tests about once a year.

*/

package main

import (
	"bytes"
	"crypto/aes"
	"crypto/rand"
	"encoding/base64"
	"fmt"
	"log"
)

func main() {
	log.SetFlags(0)
	log.SetPrefix("ecb-decryption: ")

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
	if !isecb(key, blocksz) {
		log.Fatal("detected non ECB mode, only ECB mode is supported!")
	}

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

// we are assuming that this is a block cipher
// because if it is a another type like a stream cipher, since
// those can handle messages of any size
// since we are passing in data that is not of block size,
// we assume that the block cipher algorithm will pad it for us
// so we just repeat the bytes until the length of the returned
// ciphertext is different and that will be the block size
func findblocksz(key []byte) int {
	n := 1
	s := 0
	for ; ; n++ {
		p := bytes.Repeat([]byte("A"), n)
		e := encrypt(key, p)
		if s == 0 {
			s = len(e)
		} else if s != len(e) {
			break
		}
	}
	return n
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

func randn(n int) []byte {
	p := make([]byte, n)
	_, err := rand.Read(p)
	ck(err)
	return p
}