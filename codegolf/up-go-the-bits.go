/*

Given an integer N perform the following steps: (using 9 as an example).

    Receive input N. (9)
    Convert N from base10 to base2. (1001)
    Increase every bit by 1. (2112)
    Treat the result as base3 and convert it back to base10. (68)
    Return/Output the result.

Input

May be received in any reasonable number format.
You only need to handle cases where N > 0.
Output

Either return as a number or string, or print to stdout.
Rules

    This is code-golf, the shortest code in bytes wins.
    Default loopholes are forbidden.

Test Cases

1 -> 2
2 -> 7
5 -> 23
9 -> 68
10 -> 70
20 -> 211
1235 -> 150623
93825 -> 114252161

*/

package main

import (
	"fmt"
	"strconv"
)

func main() {
	assert(conv(1) == 2)
	assert(conv(2) == 7)
	assert(conv(5) == 23)
	assert(conv(9) == 68)
	assert(conv(10) == 70)
	assert(conv(20) == 211)
	assert(conv(1235) == 150623)
	assert(conv(93825) == 114252161)
}

func assert(x bool) {
	if !x {
		panic("assertion failed")
	}
}

func conv(n int64) int64 {
	s := []byte(fmt.Sprintf("%b", n))
	for i := range s {
		s[i]++
	}

	v, _ := strconv.ParseInt(string(s), 3, 64)
	return v
}
