/*

Java offers some bit operations but not bit rotation. To complete that, create a function that takes three parameters:

    n: Integer, which in binary representaion should be rotated.
    m: Number of rotation steps that should be performed.
    d: Boolean value; true = rotation right, false = rotation left.

Your function should return an integer as a result of its rotated binary representation.
Examples

bitRotate(8, 1, true) ➞ 4
// 8 in bin: 1000, rotated 1 step to the right: 0100, in dec: 4

bitRotate(16, 1, false) ➞ 1
// 16 in bin: 10000, rotated 1 step to the left: 00001, in dec: 1

bitRotate(17, 2, false) ➞ 6
// 17 in bin: 10001, rotated 2 steps to the left: 00110, in dec: 6

Notes

For parameters use unsigned integers only.

*/

package main

import (
	"math/bits"
)

func main() {
	assert(bitrotate(16, 1, false) == 1)
	assert(bitrotate(17, 2, false) == 6)
	assert(bitrotate(8, 1, true) == 4)
	assert(bitrotate(16, 2, true) == 4)
	assert(bitrotate(283, 7, true) == 110)
	assert(bitrotate(16, 1, false) == 1)
	assert(bitrotate(17, 2, false) == 6)
	assert(bitrotate(122, 7, false) == 122)
	assert(bitrotate(125, 10, true) == 95)
	assert(bitrotate(1022, 8, false) == 767)
	assert(bitrotate(33, 6, true) == 33)
}

func assert(x bool) {
	if !x {
		panic("assertion failed")
	}
}

func bitrotate(n, m uint, d bool) uint {
	if n == 0 || m == 0 {
		return n
	}

	b := uint(bits.UintSize - bits.LeadingZeros(n))
	s := uint(1<<b) - 1
	m %= b

	var r uint
	if d {
		r = ((n >> m) | (n << (b - m))) & s
	} else {
		r = ((n << m) | (n >> (b - m))) & s
	}
	return r
}
