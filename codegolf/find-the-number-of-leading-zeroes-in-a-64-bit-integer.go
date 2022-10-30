/*

Problem:

Find the number of leading zeroes in a 64-bit signed integer

Rules:

The input cannot be treated as string; it can be anything where math and bitwise operations drive the algorithm
The output should be validated against the 64-bit signed integer representation of the number, regardless of language
Default code golf rules apply
Shortest code in bytes wins
Test cases:

These tests assume two's complement signed integers. If your language/solution lacks or uses a different representation of signed integers, please call that out and provide additional test cases that may be relevant.
I've included some test cases that address double precision, but please feel free to suggest any others that should be listed.

input                output   64-bit binary representation of input (2's complement)
-1                   0        1111111111111111111111111111111111111111111111111111111111111111
-9223372036854775808 0        1000000000000000000000000000000000000000000000000000000000000000
9223372036854775807  1        0111111111111111111111111111111111111111111111111111111111111111
4611686018427387903  2        0011111111111111111111111111111111111111111111111111111111111111
1224979098644774911  3        0001000011111111111111111111111111111111111111111111111111111111
9007199254740992     10       0000000000100000000000000000000000000000000000000000000000000000
4503599627370496     11       0000000000010000000000000000000000000000000000000000000000000000
4503599627370495     12       0000000000001111111111111111111111111111111111111111111111111111
2147483648           32       0000000000000000000000000000000010000000000000000000000000000000
2147483647           33       0000000000000000000000000000000001111111111111111111111111111111
2                    62       0000000000000000000000000000000000000000000000000000000000000010
1                    63       0000000000000000000000000000000000000000000000000000000000000001
0                    64       0000000000000000000000000000000000000000000000000000000000000000

*/

package main

import "math/bits"

func main() {
	assert(leadingzeros(-1) == 0)
	assert(leadingzeros(-9223372036854775808) == 0)
	assert(leadingzeros(9223372036854775807) == 1)
	assert(leadingzeros(4611686018427387903) == 2)
	assert(leadingzeros(1224979098644774911) == 3)
	assert(leadingzeros(9007199254740992) == 10)
	assert(leadingzeros(4503599627370496) == 11)
	assert(leadingzeros(4503599627370495) == 12)
	assert(leadingzeros(2147483648) == 32)
	assert(leadingzeros(2147483647) == 33)
	assert(leadingzeros(2) == 62)
	assert(leadingzeros(1) == 63)
	assert(leadingzeros(0) == 64)
}

func assert(x bool) {
	if !x {
		panic("assertion failed")
	}
}

func leadingzeros(x int64) int {
	return bits.LeadingZeros64(uint64(x))
}
