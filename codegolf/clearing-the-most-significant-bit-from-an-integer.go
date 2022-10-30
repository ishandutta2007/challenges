/*

Input
The input is a single positive integer n

Output
The output is n with its most significant bit set to 0.

Test Cases
1 -> 0
2 -> 0
10 -> 2
16 -> 0
100 -> 36
267 -> 11
350 -> 94
500 -> 244

For example: 350 in binary is 101011110. Setting its most significant bit (i.e. the leftmost 1 bit) to 0 turns it into 001011110 which is equivalent to the decimal integer 94, the output. This is OEIS A053645.

*/

package main

import (
	"math/bits"
)

func main() {
	assert(clear(1) == 0)
	assert(clear(2) == 0)
	assert(clear(10) == 2)
	assert(clear(16) == 0)
	assert(clear(100) == 36)
	assert(clear(267) == 11)
	assert(clear(350) == 94)
	assert(clear(500) == 244)
}

func assert(x bool) {
	if !x {
		panic("assertion failed")
	}
}

func clear(n uint) uint {
	s := bits.UintSize - bits.LeadingZeros(n) - 1
	return n &^ (1 << s)
}
