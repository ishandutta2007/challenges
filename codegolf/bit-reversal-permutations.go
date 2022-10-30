/*

Your goal is to create a function or a program to reverse the bits in a range of integers given an integer n. In other words, you want to find the bit-reversal permutation of a range of 2n items, zero-indexed.
This is also the OEIS sequence A030109. This process is often used in computing Fast Fourier Transforms, such as the in-place Cooley-Tukey algorithm for FFT.
There is also a challenge for computing the FFT for sequences where the length is a power of 2.

This process requires you to iterate over the range [0,2n−1], convert each value to binary and reverse the bits in that value.
You will be treating each value as a n-digit number in base 2 which means reversal will only occur among the last n bits.

For example, if n=3, the range of integers is [0, 1, 2, 3, 4, 5, 6, 7]. These are

i  Regular  Bit-Reversed  j
0    000        000       0
1    001        100       4
2    010        010       2
3    011        110       6
4    100        001       1
5    101        101       5
6    110        011       3
7    111        111       7

where each index i is converted to an index j using bit-reversal. This means that the output is [0, 4, 2, 6, 1, 5, 3, 7].

The output for n from 0 thru 4 are

n    Bit-Reversed Permutation
0    [0]
1    [0, 1]
2    [0, 2, 1, 3]
3    [0, 4, 2, 6, 1, 5, 3, 7]

You may have noticed a pattern forming. Given n, you can take the previous sequence for n−1

and double it. Then concatenate that doubled list to the same double list but incremented by one. To show,

[0, 2, 1, 3] * 2 = [0, 4, 2, 6]
[0, 4, 2, 6] + 1 = [1, 5, 3, 7]
[0, 4, 2, 6] ⊕ [1, 5, 3, 7] = [0, 4, 2, 6, 1, 5, 3, 7]

where ⊕ represents concatenation.

You can use either of the two methods above in order to form your solution. If you know a better way, you are free to use that too. Any method is fine as long as it outputs the correct results.
Rules

    This is code-golf so the shortest solution wins.
    Builtins that solve this challenge as a whole and builtins that compute the bit-reversal of a value are not allowed. This does not include builtins which perform binary conversion or other bitwise operations.
    Your solution must be, at the least, valid for n from 0 to 31.

*/

package main

import (
	"fmt"
	"math/bits"
)

func main() {
	for i := uint(0); i < 8; i++ {
		fmt.Println(gen(i))
	}
}

func gen(n uint) []uint {
	m := uint(1 << n)
	r := make([]uint, m)
	for i := uint(0); i < m; i++ {
		r[i] = bits.Reverse(i) >> (bits.UintSize - n)
	}
	return r
}
