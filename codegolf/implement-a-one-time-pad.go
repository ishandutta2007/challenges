/*

Background

A one-time pad is a form of encryption that has been proven impossible to crack if used properly.

Encryption is performed by taking a plaintext (comprised of only letters A-Z) and generating a random string on the same length (also only letters). This string acts as the key. Each character in the plaintext is then paired up with the corresponding character in the key. The ciphertext is computed as follows: For each pair, both characters are converted to numbers (A=0, B=1, ... Z=25). The two numbers are added modulo 26. This number is the converted back into a character.

Decryption is exactly the opposite. The characters in the ciphertext and key are paired up and converted to numbers. The key is then subtracted from the ciphertext modulo 26, and the result is converted back into a character A-Z.
The Challenge

Your challenge is to write the shortest program possible that can both encrypt and decrypt a one-time pad.

On the first line of input (to STDIN), there will be either the word "ENCRYPT" or the word "DECRYPT".

If the word is encrypt, then the next line will be the plaintext. Your program should output two lines (to STDOUT), the first being the key, and the second being the ciphertext.

If the word is decrypt, your program will get two more line of input. The first line will be the key, and the second line will be the ciphertext. You program should output one line, which will be the plaintext that has been decrypted.

The plaintext, ciphertext, and key should always consist of uppercase letters A-Z. They will always be a single line and contain no whitespace.

The key should always be random. No large parts of it should repeat between runs, and there should be no patterns that can be found in the text.

Two simple examples:

ENCRYPT
HAPPYBIRTHDAY
>ABKJAQLRJESMG
>HBZYYRTICLVME

DECRYPT
ABKJAQLRJESMG
HBZYYRTICLVME
>HAPPYBIRTHDAY

The > represents which lines are output, so you don't have to print that symbol as output.

*/

package main

import (
	"bytes"
	"crypto/rand"
	"fmt"
)

func main() {
	test("ABKJAQLRJESMG", "HAPPYBIRTHDAY", "HBZYYRTICLVME")
}

func test(key, msg, res string) {
	cph := crypt('e', key, msg)
	pln := crypt('d', key, cph)
	fmt.Println(cph, pln)
	assert(cph == res)
	assert(pln == msg)
}

func assert(x bool) {
	if !x {
		panic("assertion failed")
	}
}

func genkey(s string) string {
	b := make([]byte, len(s))
	rand.Read(b)
	for i := range b {
		b[i] = 'A' + (b[i] % 26)
	}
	return string(b)
}

func crypt(op int, k, s string) string {
	w := new(bytes.Buffer)
	for i := 0; i < len(s); i++ {
		var c byte
		a := int(k[i]) - 'A'
		b := int(s[i]) - 'A'
		switch op {
		case 'e':
			c = byte(mod(b+a, 26))
		case 'd':
			c = byte(mod(b-a, 26))
		default:
			panic("invalid operation")
		}
		w.WriteByte(c + 'A')
	}
	return w.String()
}

func mod(x, m int) int {
	x %= m
	if x < 0 {
		x += m
	}
	return x
}
