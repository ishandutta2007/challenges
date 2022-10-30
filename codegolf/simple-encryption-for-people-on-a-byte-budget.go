/*

Overview

Your goal is to implement RC4 encryption. RC4 encryption, invented by Ron Rivest (of RSA fame), was designed to be secure, yet simple enough to be implemented from memory by military soldiers on the battlefield.
Today, there are several attacks on RC4, but it's still used in many places today.

Your program should accept a single string with both a key and some data. It will be presented in this format.

\x0Dthis is a keythis is some data to encrypt
The first byte represents how long the key is. It can be assumed the key will no longer than 255 bytes, and no shorter than 1 byte. The data can be arbitrarily long.

Your program should process the key, then return the encrypted data. RC4 encryption and decryption are identical, so using the same key to "encrypt" the ciphertext should return the original plaintext.

How RC4 Works
Initialization
Initialization of RC4 is quite simple. A state array of 256 bytes is initialized to all bytes from 0 to 255.

S = [0, 1, 2, 3, ..., 253, 254, 255]
Key processing
Values in the state are swapped around based on the key.

j = 0
for i from 0 to 255
    j = (j + S[i] + key[i mod keylength]) mod 256
    swap S[i] and S[j]
Encryption
Encryption is accomplished by using the state to generate pseudo-random bytes, which are then XOR'd to the data. Values in the state are swapped around constantly.

i = j = 0
for each byte B in data
    i = (i + 1) mod 256
    j = (j + S[i]) mod 256
    swap S[i] and S[j]
    K = S[(S[i] + S[j]) mod 256]
    output K XOR B
Expected inputs and outputs
Non-printable characters will be shown in \xAB format.

Input: \x01\x00\x00\x00\x00\x00\x00
Output: \xde\x18\x89A\xa3
Output(hex): de188941a3

Input: \x0Dthis is a keythis is some data to encrypt
Output: \xb5\xdb?i\x1f\x92\x96\x96e!\xf3\xae(!\xf3\xeaC\xd4\x9fS\xbd?d\x82\x84{\xcdN
Output(hex): b5db3f691f9296966521f3ae2821f3ea43d49f53bd3f6482847bcd4e

Input: \x0dthis is a key\xb5\xdb?i\x1f\x92\x96\x96e!\xf3\xae(!\xf3\xeaC\xd4\x9fS\xbd?d\x82\x84{\xcdN
Input(hex): 0d746869732069732061206b6579b5db3f691f9296966521f3ae2821f3ea43d49f53bd3f6482847bcd4e
Output: this is some data to encrypt

Input: Sthis is a rather long key because the value of S is 83 so the key length must matchand this is the data to be encrypted
Output: \x96\x1f,\x8f\xa3%\x9b\xa3f[mk\xdf\xbc\xac\x8b\x8e\xfa\xfe\x96B=!\xfc;\x13`c\x16q\x04\x11\xd8\x86\xee\x07
Output(hex): 961f2c8fa3259ba3665b6d6bdfbcac8b8efafe96423d21fc3b13606316710411d886ee07

*/

package main

import "fmt"

func main() {
	test("\x01\x00\x00\x00\x00\x00\x00", "\xde\x18\x89A\xa3")
	test("\x0Dthis is a keythis is some data to encrypt", "\xb5\xdb?i\x1f\x92\x96\x96e!\xf3\xae(!\xf3\xeaC\xd4\x9fS\xbd?d\x82\x84{\xcdN")
	test("\x0dthis is a key\xb5\xdb?i\x1f\x92\x96\x96e!\xf3\xae(!\xf3\xeaC\xd4\x9fS\xbd?d\x82\x84{\xcdN", "this is some data to encrypt")
	test("Sthis is a rather long key because the value of S is 83 so the key length must matchand this is the data to be encrypted", "\x96\x1f,\x8f\xa3%\x9b\xa3f[mk\xdf\xbc\xac\x8b\x8e\xfa\xfe\x96B=!\xfc;\x13`c\x16q\x04\x11\xd8\x86\xee\x07")
}

func assert(x bool) {
	if !x {
		panic("assertion failed")
	}
}

func test(str, res string) {
	out := process(str)
	fmt.Printf("%q\n", out)
	assert(out == res)
}

func process(str string) string {
	key, in := split(str)
	out := make([]byte, len(in))

	rc4 := new(RC4)
	rc4.Init(key)
	rc4.Crypt(out, in)

	return string(out)
}

func split(str string) (key, data []byte) {
	l := len(str)
	if l == 0 {
		return
	}

	n := int(str[0])
	if l < n+1 {
		return
	}

	key = []byte(str[1 : n+1])
	data = []byte(str[n+1:])
	return
}

type RC4 struct {
	state [256]byte
}

func (r *RC4) Init(key []byte) {
	for i := range r.state {
		r.state[i] = byte(i)
	}

	for i, j := 0, 0; i < 256; i++ {
		a := int(r.state[i])
		b := int(key[i%len(key)])

		j = (j + a + b) & 0xff
		r.state[i], r.state[j] = r.state[j], r.state[i]
	}
}

func (r *RC4) Crypt(dst, src []byte) {
	i, j := 0, 0
	for n, b := range src {
		i = (i + 1) & 0xff
		j = (j + int(r.state[i])) & 0xff
		r.state[i], r.state[j] = r.state[j], r.state[i]

		k := r.state[(r.state[i]+r.state[j])&0xff]
		dst[n] = k ^ b
	}
}
