/*

Every number of the form 2i (where i is a non-negative integer) has a single 1 in its binary representation.
Given such a number, output the 1-based position of the 1.

Examples:

DECIMAL   BINARY    POSITION
--------------------------
1            0001      1
2            0010      2
4            0100      3
8            1000      4

N         0...1...0     ?

*/

package main

import (
	"math/bits"
)

func main() {
	for i := uint(0); i < bits.UintSize; i++ {
		assert(one(1<<i) == int(i+1))
	}
}

func assert(x bool) {
	if !x {
		panic("assertion failed")
	}
}

func one(x uint) int {
	return bits.TrailingZeros(x) + 1
}
