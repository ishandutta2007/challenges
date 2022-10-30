/*

In this challenge you will compute numbers from a curious sequence.

Your input is a single decimal nonnegative integer. Reverse the bits in this integer and then square the number to get the required output.

When reversing the bits you must not use any leading zeroes in the input. For example:

26 (base 10) = 11010 (base 2) -> 01011 (base 2) = 11 -> 11*11 = 121

The first 25 inputs/outputs of this sequence:

0: 0
1: 1
2: 1
3: 9
4: 1
5: 25
6: 9
7: 49
8: 1
9: 81
10: 25
11: 169
12: 9
13: 121
14: 49
15: 225
16: 1
17: 289
18: 81
19: 625
20: 25
21: 441
22: 169
23: 841
24: 9

Your solution should work for arbitrarily sized integers. If your language does not have a convenient built-in method of using those, implement your answer as if it does. You are then excused if your answer breaks for large numbers. However, do not use tricks/bounds that only work for a limited domain (such as a lookup table).

Your score is the number of bytes of source code.

-50% bonus if you never convert the number to/from binary. This is not limited to builtins, if you loop over the number bit by bit (either by shifting or masking or any other method), it will also count as conversion. I don't know whether this is actually possible, but it gives an incentive to spot a pattern in the sequence.

Smallest score wins.

*/

package main

import (
	"math/bits"
)

func main() {
	tab := []uint{
		0, 1, 1, 9, 1, 25, 9, 49, 1, 81, 25, 169, 9, 121,
		49, 225, 1, 289, 81, 625, 25, 441, 169, 841, 9,
	}
	for i := range tab {
		assert(revsq(uint(i)) == tab[i])
	}
}

func assert(x bool) {
	if !x {
		panic("assertion failed")
	}
}

func revsq(x uint) uint {
	s := bits.UintSize - bits.Len(x)
	y := bits.Reverse(x) >> s
	return y * y
}
