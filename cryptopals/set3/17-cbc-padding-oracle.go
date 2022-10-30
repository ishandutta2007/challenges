/*

The CBC padding oracle

This is the best-known attack on modern block-cipher cryptography.

Combine your padding code and your CBC code to write two functions.

The first function should select at random one of the following 10 strings:

MDAwMDAwTm93IHRoYXQgdGhlIHBhcnR5IGlzIGp1bXBpbmc=
MDAwMDAxV2l0aCB0aGUgYmFzcyBraWNrZWQgaW4gYW5kIHRoZSBWZWdhJ3MgYXJlIHB1bXBpbic=
MDAwMDAyUXVpY2sgdG8gdGhlIHBvaW50LCB0byB0aGUgcG9pbnQsIG5vIGZha2luZw==
MDAwMDAzQ29va2luZyBNQydzIGxpa2UgYSBwb3VuZCBvZiBiYWNvbg==
MDAwMDA0QnVybmluZyAnZW0sIGlmIHlvdSBhaW4ndCBxdWljayBhbmQgbmltYmxl
MDAwMDA1SSBnbyBjcmF6eSB3aGVuIEkgaGVhciBhIGN5bWJhbA==
MDAwMDA2QW5kIGEgaGlnaCBoYXQgd2l0aCBhIHNvdXBlZCB1cCB0ZW1wbw==
MDAwMDA3SSdtIG9uIGEgcm9sbCwgaXQncyB0aW1lIHRvIGdvIHNvbG8=
MDAwMDA4b2xsaW4nIGluIG15IGZpdmUgcG9pbnQgb2g=
MDAwMDA5aXRoIG15IHJhZy10b3AgZG93biBzbyBteSBoYWlyIGNhbiBibG93

... generate a random AES key (which it should save for all future encryptions), pad the string out to the 16-byte AES block size and CBC-encrypt it under that key, providing the caller the ciphertext and IV.

The second function should consume the ciphertext produced by the first function, decrypt it, check its padding, and return true or false depending on whether the padding is valid.
What you're doing here.

This pair of functions approximates AES-CBC encryption as its deployed serverside in web applications; the second function models the server's consumption of an encrypted session token, as if it was a cookie.

It turns out that it's possible to decrypt the ciphertexts provided by the first function.

The decryption here depends on a side-channel leak by the decryption function. The leak is the error message that the padding is valid or not.

You can find 100 web pages on how this attack works, so I won't re-explain it. What I'll say is this:

The fundamental insight behind this attack is that the byte 01h is valid padding, and occur in 1/256 trials of "randomized" plaintexts produced by decrypting a tampered ciphertext.

02h in isolation is not valid padding.

02h 02h is valid padding, but is much less likely to occur randomly than 01h.

03h 03h 03h is even less likely.

So you can assume that if you corrupt a decryption AND it had valid padding, you know what that padding byte is.

It is easy to get tripped up on the fact that CBC plaintexts are "padded". Padding oracles have nothing to do with the actual padding on a CBC plaintext. It's an attack that targets a specific bit of code that handles decryption. You can mount a padding oracle on any CBC block, whether it's padded or not.

*/

package main

import (
	"crypto/aes"
	"crypto/cipher"
	crand "crypto/rand"
	"fmt"
	"log"
	"math/rand"
	"time"
)

func main() {
	rand.Seed(time.Now().UnixNano())
	crack()
}

func crack() {
	for i := 0; i < 1; i++ {
		iv, enc := roll()
		decrypt(iv, enc)
	}
}

// the idea is that since CBC has the property such that if you flip one byte
// in the previous CBC block, it affects the next CBC block, so what we do is
// we take advantage of that and start flipping one byte since there is a info leak
// of whether or not we have a valid padding or not. We can brute force our first
// byte out of 255 tries to get one with a valid padding, that value is our last byte
// then we work out the second to last by using that last byte as a starting point
// and increase the padding to 0x2, this allows us to cut down the search space exponentially,
// we keep doing that until we decrypt all of the cipher text
func decrypt(iv, enc []byte) []byte {
	sec, _ := check(iv, enc)
	fmt.Printf("%q\n", sec)

	dec := atkpad(iv, enc[:aes.BlockSize])
	for i := 0; i < len(enc)-aes.BlockSize; i += aes.BlockSize {
		dec = append(dec, atkpad(enc[i:i+aes.BlockSize], enc[i+aes.BlockSize:i+2*aes.BlockSize])...)
	}
	pad := int(dec[len(dec)-1])
	dec = dec[:len(dec)-pad]

	fmt.Printf("%q\n", dec)
	return nil
}

func atkpad(c1, c2 []byte) []byte {
	z := make([]byte, aes.BlockSize)
	for i := aes.BlockSize - 1; i >= 0; i-- {
		z[i] = guessbyte(c1, c2, z, i)
	}
	return z
}

func guessbyte(c1, c2 []byte, xor []byte, pos int) byte {
	m := aes.BlockSize - pos%aes.BlockSize
	for i := 0; i < 256; i++ {
		x := append([]byte{}, c1...)
		for j := range x {
			x[j] ^= xor[j] ^ byte(m)
		}
		x[pos] ^= byte(i)

		_, pass := check(x, c2)
		if pass {
			return byte(i)
		}
	}

	log.Fatalf("no match at %d %#x", pos, m)
	return 0
}

var (
	key = randn(16)
)

func roll() (iv, enc []byte) {
	tab := []string{
		"MDAwMDAwTm93IHRoYXQgdGhlIHBhcnR5IGlzIGp1bXBpbmc=",
		"MDAwMDAxV2l0aCB0aGUgYmFzcyBraWNrZWQgaW4gYW5kIHRoZSBWZWdhJ3MgYXJlIHB1bXBpbic=",
		"MDAwMDAyUXVpY2sgdG8gdGhlIHBvaW50LCB0byB0aGUgcG9pbnQsIG5vIGZha2luZw==",
		"MDAwMDAzQ29va2luZyBNQydzIGxpa2UgYSBwb3VuZCBvZiBiYWNvbg==",
		"MDAwMDA0QnVybmluZyAnZW0sIGlmIHlvdSBhaW4ndCBxdWljayBhbmQgbmltYmxl",
		"MDAwMDA1SSBnbyBjcmF6eSB3aGVuIEkgaGVhciBhIGN5bWJhbA==",
		"MDAwMDA2QW5kIGEgaGlnaCBoYXQgd2l0aCBhIHNvdXBlZCB1cCB0ZW1wbw==",
		"MDAwMDA3SSdtIG9uIGEgcm9sbCwgaXQncyB0aW1lIHRvIGdvIHNvbG8=",
		"MDAwMDA4b2xsaW4nIGluIG15IGZpdmUgcG9pbnQgb2g=",
		"MDAwMDA5aXRoIG15IHJhZy10b3AgZG93biBzbyBteSBoYWlyIGNhbiBibG93",
	}
	choice := tab[rand.Intn(len(tab))]
	plain := pkcs7([]byte(choice))

	ebc, err := aes.NewCipher(key)
	if err != nil {
		panic(err)
	}
	iv = randn(aes.BlockSize)
	cbc := cipher.NewCBCEncrypter(ebc, iv)

	enc = make([]byte, len(plain))
	cbc.CryptBlocks(enc, plain)

	return
}

func check(iv, enc []byte) (dec []byte, pass bool) {
	dec = make([]byte, len(enc))
	ebc, err := aes.NewCipher(key)
	if err != nil {
		panic(err)
	}
	cbc := cipher.NewCBCDecrypter(ebc, iv)
	cbc.CryptBlocks(dec, enc)

	if len(dec) == 0 {
		return
	}

	pad := int(dec[len(dec)-1])
	if pad > len(dec) || pad == 0 {
		return
	}

	for i := 0; i < int(pad); i++ {
		if int(dec[len(dec)-1-i]) != pad {
			return
		}
	}
	dec = dec[:len(dec)-pad]
	pass = true

	return
}

func pkcs7(buf []byte) []byte {
	pad := aes.BlockSize - (len(buf) % aes.BlockSize)
	for i := 0; i < pad; i++ {
		buf = append(buf, byte(pad))
	}
	return buf
}

func randn(n int) []byte {
	p := make([]byte, n)
	_, err := crand.Read(p)
	if err != nil {
		panic(err)
	}
	return p
}
