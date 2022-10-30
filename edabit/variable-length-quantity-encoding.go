/*

In this challenge you have to create functions to encode and decode variable-length quantities.
A variable-length quantity (VLQ) is a universal code that uses an arbitrary number of binary octets (eight-bit bytes) to represent an arbitrarily large integer.
A VLQ is essentially a base-128 representation of an unsigned integer with the addition of the eighth bit to mark continuation of bytes.

The way it works is fairly simple. As a big-endian series of bytes, the most significant bit (MSB) of each byte is a 1 to indicate that another VLQ byte follows. The remaining 7 bits of each byte make up the decoded value.
Examples

# ENCODE:
intToVlq(127) ➞ [127]
// numbers between 0 and 127 are unchanged
// binary: [01111111]

intToVlq(128) ➞ [129, 0]
// 1st byte = 1 + 128 equivalent to 1 * 128 with MSB set to 1 indicating byte follows
// 2nd byte = 0
// 128 + 0 ➞ 128
// binary: [10000001, 00000000]

intToVlq(106903) ➞ [134, 195, 23]
// 1st byte = 128 + 6 ➞ 6 * 128^2 ➞ 98304
// 2nd byte = 128 + 67 ➞ 67 * 128 ➞ 8576
// 3rd byte = 23 ➞ 23
// 98304 + 8576 + 23 = 106903
// binary: [10000110, 11000011, 00010111]

# DECODE:
vlqToInt([229, 145, 63]) ➞ 1657023
// (229 - 128)*128^2 + (145 - 128)*128 + 63 = 1657023

Notes

Integer values for encoding will be in the range 0 <= n <= 2^63

*/

package main

import (
	"fmt"
	"reflect"
)

func main() {
	test(0, []uint8{0})
	test(12, []uint8{12})
	test(128, []uint8{129, 0})
	test(106903, []uint8{134, 195, 23})
	test(268435455, []uint8{255, 255, 255, 127})
	test(1234567890123, []uint8{163, 247, 143, 236, 137, 75})
	test(562949953421312, []uint8{129, 128, 128, 128, 128, 128, 128, 0})
	test(9223372036854775807, []uint8{255, 255, 255, 255, 255, 255, 255, 255, 127})
}

func assert(x bool) {
	if !x {
		panic("assertion failed")
	}
}

func test(x uint64, r []uint8) {
	p := vlqenc(x)
	q := vlqdec(p)
	fmt.Println(p)
	assert(reflect.DeepEqual(p, r))
	assert(x == q)
}

func vlqenc(x uint64) []uint8 {
	p := make([]uint8, 16)
	n := len(p)

	l := n
	for {
		p[l-1], l = uint8(x&0x7f), l-1
		if x >>= 7; x == 0 {
			break
		}
	}

	for i := l; i < n-1; i++ {
		p[i] |= 0x80
	}

	return p[l:]
}

func vlqdec(x []uint8) uint64 {
	var r uint64
	for _, v := range x {
		r = r<<7 | uint64(v&0x7f)
		if v&0x80 == 0 {
			break
		}
	}
	return r
}
