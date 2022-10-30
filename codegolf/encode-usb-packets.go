/*

Inspired by this video by Ben Eater. This challenge forms a pair with Decode USB packets.

The USB 2.0 protocol uses, at a low level, a line code called non-return-to-zero encoding (specifically, a variant called NRZI), in which a stream of bits is encoded into a stream of two electrical level states J and K. Encoding works as follows:

    Start with some initial state, which is either J or K
    For each bit to be encoded:
        If the bit is a 0, switch the state from J to K or from K to J
        If the bit is a 1, maintain the same state as before
        and output that state

For this challenge, we will assume the encoding starts in state J.

However, it's not that simple: an additional process called bit stuffing takes place, which is designed to make it easier to detect if the signal has dropped out.
After 6 consecutive 1s are read, an extra meaningless 0 bit is processed to ensure the signal never stays in the same state (J or K) for too long.

The full USB specification is available here on the USB website, or mirrored (and easier to access) here, but I'd caution you before reading it because it's extremely long and the pertinent information is hard to pin down.
Task

Given a non-empty binary string as input, encode the string using the USB implementation of NRZI described above, and output a string of Js or Ks.
Test-cases

Input              Output
=====================================
1                  J
0                  K
1000101            JKJKKJJ
00000000           KJKJKJKJ
11111111           JJJJJJKKK
001111100          KJJJJJJKJ
0011111100         KJJJJJJJKJK
00111111100        KJJJJJJJKKJK
0011111111111100   KJJJJJJJKKKKKKKJKJ
0011011000111001   KJJJKKKJKJJJJKJJ
01101000011101000111010001110000011100110011101000101111001011110111011101110111011101110010111001111001011011110111010101110100011101010110001001100101001011100110001101101111011011010010111101110111011000010111010001100011011010000011111101110110001111010110010001010001011101110011010001110111001110010101011101100111010110000110001101010001   KKKJJKJKJJJJKKJKJJJJKKJKJJJJKJKJKKKKJKKKJKKKKJJKJKKJJJJJKJJKKKKKJJJJKKKKJJJJKKKKJJJJKKKKJKKJJJJKJJJJJKJJKKKJJJJJKKKKJJKKJJJJKKJKJJJJKKJJKKKJKJJKJJJKJJKKJKKJJJJKJJJKJKKKJJJKKKKKJJJKKKJJKJJKKKKKJJJJKKKKJJJKJKJJKKKKJJKJKKKJKJJJKKKJJKJKJKKKKKKKJKKKKJJJKJKKKKKJJKKKJKKJKJJKKJKJJKKKKJJJJKJJJKKJKJJJJKKKKJKKKKJKKJJKKJJJJKKKJKKKKJJKKKJKJKKKJKJJJKKJJKJKK

Rules

    The input should be a string or array of 1s and 0s or of trues and falses
    The output should be a string or array, with the two states J and K being represented by any two distinct values
    You may use any standard I/O method
    Standard loopholes are forbidden
    This is code-golf, so the shortest code in bytes wins


*/

package main

import (
	"bytes"
)

func main() {
	assert(encode("1") == "J")
	assert(encode("0") == "K")
	assert(encode("1000101") == "JKJKKJJ")
	assert(encode("00000000") == "KJKJKJKJ")
	assert(encode("11111111") == "JJJJJJKKK")
	assert(encode("001111100") == "KJJJJJJKJ")
	assert(encode("0011111100") == "KJJJJJJJKJK")
	assert(encode("00111111100") == "KJJJJJJJKKJK")
	assert(encode("0011111111111100") == "KJJJJJJJKKKKKKKJKJ")
	assert(encode("0011011000111001") == "KJJJKKKJKJJJJKJJ")
	assert(encode("01101000011101000111010001110000011100110011101000101111001011110111011101110111011101110010111001111001011011110111010101110100011101010110001001100101001011100110001101101111011011010010111101110111011000010111010001100011011010000011111101110110001111010110010001010001011101110011010001110111001110010101011101100111010110000110001101010001") == "KKKJJKJKJJJJKKJKJJJJKKJKJJJJKJKJKKKKJKKKJKKKKJJKJKKJJJJJKJJKKKKKJJJJKKKKJJJJKKKKJJJJKKKKJKKJJJJKJJJJJKJJKKKJJJJJKKKKJJKKJJJJKKJKJJJJKKJJKKKJKJJKJJJKJJKKJKKJJJJKJJJKJKKKJJJKKKKKJJJKKKJJKJJKKKKKJJJJKKKKJJJKJKJJKKKKJJKJKKKJKJJJKKKJJKJKJKKKKKKKJKKKKJJJKJKKKKKJJKKKJKKJKJJKKJKJJKKKKJJJJKJJJKKJKJJJJKKKKJKKKKJKKJJKKJJJJKKKJKKKKJJKKKJKJKKKJKJJJKKJJKJKK")
}

func assert(x bool) {
	if !x {
		panic("assertion failed")
	}
}

func encode(s string) string {
	if len(s) == 0 {
		return ""
	}

	w := new(bytes.Buffer)
	t := output(w, s[0])
	c := one(s[0])
	for i := 1; i < len(s); i++ {
		if s[i] == '0' {
			t, c = flip(t), 0
		}
		output(w, t)
		if c += one(s[i]); c >= 6 {
			t, c = flip(t), 0
			output(w, t)
		}
	}
	return w.String()
}

func output(w *bytes.Buffer, c byte) byte {
	v := c
	switch c {
	case '0':
		v = 'K'
	case '1':
		v = 'J'
	}
	w.WriteByte(v)
	return c
}

func flip(c byte) byte {
	switch c {
	case '0':
		c = '1'
	case '1':
		c = '0'
	}
	return c
}

func one(c byte) int {
	if c == '1' {
		return 1
	}
	return 0
}
