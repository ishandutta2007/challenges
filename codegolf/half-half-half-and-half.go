/*

Consider the following number sequence:

0,12,14,34,18,38,58,78,116,316,516,716,916,1116,1316,1516,132,332,532,…
It enumerates all binary fractions in the unit interval [0,1).

(To make this challenge easier, the first element is optional: You may skip it and consider the sequence starts with 1/2.)

Task
Write a program (complete program or a function) which...

Choose one of these behaviors:

Input n, output nth element of the sequence (0-indexed or 1-indexed);
Input n, output first n elements of the sequence;
Input nothing, output the infinite number sequence which you can take from one by one;
Rule
Your program should at least support first 1000 items;
You may choose to output decimals, or fractions (built-in, integer pair, strings) as you like;
Input / Output as binary digits is not allowed in this question;
This is code-golf, shortest codes win;
Standard loopholes disallowed.
Testcases
input output
1     1/2     0.5
2     1/4     0.25
3     3/4     0.75
4     1/8     0.125
10    5/16    0.3125
100   73/128  0.5703125
511   511/512 0.998046875
512   1/1024  0.0009765625
These examples are based on 0-indexed sequence with the leading 0 included. You would need to adjust the input for fitting your solution.

Read More
OEIS A006257
Josephus problem: a2n=2an−1,a2n+1=2an+1. (Formerly M2216)
0, 1, 1, 3, 1, 3, 5, 7, 1, 3, 5, 7, 9, 11, 13, 15, 1, 3, 5, ...
OEIS A062383
a0=1: for n>0, an=2⌊log2n+1⌋ or an=2a⌊n2⌋.
1, 2, 4, 4, 8, 8, 8, 8, 16, 16, 16, 16, 16, 16, 16, 16, 32, 32, 32, ...
A006257(n)/A062383(n) = (0, 0.1, 0.01, 0.11, 0.001, ...) enumerates all binary fractions in the unit interval [0, 1). - Fredrik Johansson, Aug 14 2006

*/

package main

import (
	"math/big"
)

func main() {
	test(1, "1/2")
	test(2, "1/4")
	test(3, "3/4")
	test(4, "1/8")
	test(10, "5/16")
	test(100, "73/128")
	test(511, "511/512")
	test(512, "1/1024")
}

func test(n int, r string) {
	x := seq(n)
	assert(x.String() == r)
}

func assert(x bool) {
	if !x {
		panic("assertion failed")
	}
}

// https://oeis.org/A006257
// https://oeis.org/A062383
// A006257(n)/A062383(n)
func seq(n int) *big.Rat {
	if n <= 0 {
		return big.NewRat(0, 1)
	}

	a, b := int64(1), int64(2)
	for i := 2; i <= n; i++ {
		if a += 2; a >= b {
			a, b = 1, b*2
		}
	}
	return big.NewRat(a, b)
}
