/*

Rijndael's S-box is a frequently used operation in AES encryption and decryption.
It is typically implemented as a 256-byte lookup table.
That's fast, but means you need to enumerate a 256-byte lookup table in your code.
I bet someone in this crowd could do it with less code, given the underlying mathematical structure.

Write a function in your favorite language that implements Rijndael's S-box. Shortest code wins.

*/

package main

import "fmt"

func main() {
	b := sbox()
	bi := sboxinv(b)
	dump("S-Box", b)
	dump("Inverse S-Box", bi)
}

func dump(s string, b [256]uint8) {
	fmt.Println(s)
	fmt.Println()
	for i := 0; i < 16; i++ {
		for j := 0; j < 16; j++ {
			fmt.Printf("%02x ", b[i*16+j])
		}
		fmt.Println()
	}
	fmt.Println()
}

func sboxinv(b [256]uint8) (bi [256]uint8) {
	for i := range b {
		bi[b[i]] = uint8(i)
	}
	return
}

// https://en.wikipedia.org/wiki/Rijndael_S-box
func sbox() (b [256]uint8) {
	p, q := uint8(1), uint8(1)
	for {
		t := uint8(0)
		if p&0x80 != 0 {
			t = 0x1b
		}
		p = p ^ (p << 1) ^ t

		q ^= q << 1
		q ^= q << 2
		q ^= q << 4
		t = 0
		if q&0x80 != 0 {
			t = 0x09
		}
		q ^= t

		x := q ^ rotl8(q, 1) ^ rotl8(q, 2) ^ rotl8(q, 3) ^ rotl8(q, 4)
		b[p] = x ^ 0x63

		if p == 1 {
			break
		}
	}
	b[0] = 0x63

	return
}

func rotl8(x, s uint8) uint8 {
	return (x << s) | (x >> (8 - s))
}
