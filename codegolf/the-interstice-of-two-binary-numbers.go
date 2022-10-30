/*

Given two integers, compute the two numbers that come from the blending the bits of the binary numbers of equal length(same number of digits, a number with less digits has zeros added), one after the other, like such:

2 1
10 01
1 0
1001
0 1
0110
some examples:

Input	Binary	Conversion	Output
1,0	1,0	10,01	2,1
1,2	01,10	0110,1001	6,9
2,3	10,11	1101,1110	13,14
4,9	0100,1001	01100001,10010010	97,146
12,12	1100,1100	11110000,11110000	240,240
1,3	01,11	0111,1011	7,11
7,11	0111,1011	01101111,10011111	111,159
7,3	111,011	101111,011111	47,31
The program must take integers as inputs and give integers as outputs

*/

package main

import (
	"fmt"
	"math/bits"
)

func main() {
	test(1, 0, 2, 1)
	test(1, 2, 6, 9)
	test(2, 3, 13, 14)
	test(4, 9, 97, 146)
	test(12, 12, 240, 240)
	test(1, 3, 7, 11)
	test(7, 11, 111, 159)
	test(7, 3, 47, 31)
}

func assert(x bool) {
	if !x {
		panic("assertion failed")
	}
}

func test(x, y, rxy, ryx uint64) {
	xy, yx := blend(x, y)
	fmt.Println(xy, yx)
	assert(xy == rxy)
	assert(yx == ryx)
}

func blend(x, y uint64) (uint64, uint64) {
	n := max(bitlen(x), bitlen(y))
	return interleave(x, y, n), interleave(y, x, n)
}

func interleave(x, y uint64, n int) uint64 {
	r := uint64(0)
	for i := n - 1; i >= 0; i-- {
		r = r<<2 | ((x>>i)&1)<<1 | ((y >> i) & 1)
	}
	return r
}

func bitlen(x uint64) int {
	return 64 - bits.LeadingZeros64(x)
}

func max(a, b int) int {
	if a > b {
		return a
	}
	return b
}
