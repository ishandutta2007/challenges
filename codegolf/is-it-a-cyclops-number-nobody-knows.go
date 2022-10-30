/*

Task:

Given an integer input, figure out whether or not it is a Cyclops Number.

What is a Cyclops number, you may ask? Well, it's a number whose binary representation only has one 0 in the center!

Test Cases:

Input | Output | Binary  | Explanation
--------------------------------------
0     | truthy | 0       | only one zero at "center"
1     | falsy  | 1       | contains no zeroes
5     | truthy | 101     | only one zero at center
9     | falsy  | 1001    | contains two zeroes (even though both are at the center)
10    | falsy  | 1010    | contains two zeroes
27    | truthy | 11011   | only one zero at center
85    | falsy  | 1010101 | contains three zeroes
101   | falsy  | 1100101 | contains three zeroes
111   | falsy  | 1101111 | only one zero, not at center
119   | truthy | 1110111 | only one zero at center
Input:

An integer or equivalent types. (int, long, decimal, etc.)

Assume that if evaluating the input results in an integer overflow or other undesirable problems, then that input doesn't have to be evaluated.

Output:

Truthy or falsy.

Truthy/falsy output must meet the used language's specifications for truthy/falsy. (e.g. C has 0 as false, non-zero as true)

Challenge Rules:

Input that is less than 0 is assumed to be falsy and thus does not have to be evaluated.

If the length of the binary representation of the number is even, then the number cannot be a Cyclops number.

General Rules:

This is code-golf, so the shortest answers in bytes wins!.

Default loopholes are forbidden.

Standard rules apply for your answer with default I/O rules.

This is my first Programming Puzzles & Code Golf challenge, so any feedback on how I should improve would be much appreciated!

*/

package main

import "fmt"

func main() {
	assert(cyclops(0) == true)
	assert(cyclops(1) == false)
	assert(cyclops(5) == true)
	assert(cyclops(9) == false)
	assert(cyclops(10) == false)
	assert(cyclops(27) == true)
	assert(cyclops(85) == false)
	assert(cyclops(101) == false)
	assert(cyclops(111) == false)
	assert(cyclops(119) == true)
}

func assert(x bool) {
	if !x {
		panic("assertion failed")
	}
}

func cyclops(n uint64) bool {
	p := fmt.Sprintf("%b", n)
	c := 0
	for i := range p {
		if p[i] == '0' {
			if c >= 1 || len(p)/2 != i {
				return false
			}
			c++
		}
	}
	return c == 1
}
