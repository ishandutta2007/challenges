/*

An integer is binary-heavy if its binary representation contains more 1s than 0s while ignoring leading zeroes.
For example 1 is binary-heavy, as its binary representation is simply 1, however 4 is not binary heavy, as its binary representation is 100.
In the event of a tie (for example 2, with a binary representation of 10), the number is not considered binary-heavy.

Given a positive integer as input, output a truthy value if it is binary-heavy, and a falsey value if it is not.

Testcases
Format: input -> binary -> output

1          ->                                1 -> True
2          ->                               10 -> False
4          ->                              100 -> False
5          ->                              101 -> True
60         ->                           111100 -> True
316        ->                        100111100 -> True
632        ->                       1001111000 -> False
2147483647 ->  1111111111111111111111111111111 -> True
2147483648 -> 10000000000000000000000000000000 -> False

*/

package main

import "math/bits"

func main() {
	assert(heavy(0) == false)
	assert(heavy(1) == true)
	assert(heavy(2) == false)
	assert(heavy(4) == false)
	assert(heavy(5) == true)
	assert(heavy(60) == true)
	assert(heavy(316) == true)
	assert(heavy(632) == false)
	assert(heavy(2147483647) == true)
	assert(heavy(2147483648) == false)
	assert(heavy(^uint(0)) == true)
}

func assert(x bool) {
	if !x {
		panic("assertion failed")
	}
}

func heavy(x uint) bool {
	o := bits.OnesCount(x)
	z := bits.UintSize - o - bits.LeadingZeros(x)
	return o > z
}
