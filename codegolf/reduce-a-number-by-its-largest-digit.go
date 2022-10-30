/*

Given an integer number in decimal number system, reduce it to a single decimal digit as follows:

    Convert the number to a list of decimal digits.
    Find the largest digit, D
    Remove D from the list. If there is more than one occurrence of D, choose the first from the left (at the most significant position), all others should remain intact.
    Convert the resulting list to a decimal number and multiply it by D.
    If the number is bigger than 9 (has more than 1 decimal digit), repeat the whole procedure, feeding the result into it. Stop when you get a single-digit result.
    Display the result.

Example:

26364 ->
1. 2 6 3 6 4
2. The largest digit is 6, so D=6
3. There are two occurrences or 6: at positions 1 and 3 (0-based). We remove the left one,
    at position 1 and get the list 2 3 6 4
4. we convert the list 2 3 6 4 to 2364 and multiply it by D:
   2364 * 6 = 14184
5. 14184 is greater than 9 so we repeat the procedure, feeding 14184 into it.

We continue by repeating the procedure for 14184 and so on and we go through the following intermediate results, finally reaching 8:

11312
3336
1998
1782
1376
952
468
368
288
224
88
64
24
8

So the result for 26364 is 8.

Input: An integer / a string representing an integer

Output: A single digit, the result of the reduction applied to the number.

Test cases:

9 -> 9
27 -> 4
757 -> 5
1234 -> 8
26364 -> 8
432969 -> 0
1234584 -> 8
91273716 -> 6

This is code-golf, so the shortest answers in bytes in each language win.

*/

package main

import (
	"fmt"
	"math/bits"
	"strconv"
)

func main() {
	assert(reduce(9) == 9)
	assert(reduce(27) == 4)
	assert(reduce(757) == 5)
	assert(reduce(1234) == 8)
	assert(reduce(26364) == 8)
	assert(reduce(432969) == 0)
	assert(reduce(1234584) == 8)
	assert(reduce(91273716) == 6)
	assert(reduce(10) == 0)
}

func assert(x bool) {
	if !x {
		panic("assertion failed")
	}
}

func reduce(n uint) uint {
	for n > 9 {
		s := fmt.Sprint(n)
		m := uint(0)
		j := -1
		for i := range s {
			v := uint(s[i] - '0')
			if m < v || j < 0 {
				m, j = v, i
			}
		}
		r, _ := strconv.ParseUint(s[:j]+s[j+1:], 10, bits.UintSize)
		n = uint(r) * m
	}
	return n
}
