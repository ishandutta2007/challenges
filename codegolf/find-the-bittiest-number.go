/*

The Challenge

Given a list of integers, the "bittiest" number among them is the one with the most bits on - that is, the largest amount of bits set to 1.

Write a function (or a program) that takes as input a list of 32-bit signed integers and returns as output the "bittiest" number among them.

You may assume the list has at least one item.
Test Cases

Input: 1, 2, 3, 4

Output: 3

Input: 123, 64, 0, -4

Output: -4

Input: 7, 11

Output: Either 7 or 11 (but not both)

Input: 1073741824, 1073741823

Output: 1073741823
Good Luck

This is code golf, so the shortest program in bytes wins.
Clarification

If your language doesn't support 32-bit signed integers, you may use any other numeric (read: not textual) representation as long as it can represent all integers from -2^31 to 2^31 - 1 inclusive, using two's complement for negatives.

*/

package main

import "math/bits"

func main() {
	assert(bittiest([]int{1, 2, 3, 4}) == 3)
	assert(bittiest([]int{123, 64, 0, -4}) == -4)
	assert(bittiest([]int{7, 11}) == 7)
	assert(bittiest([]int{1073741824, 1073741823}) == 1073741823)
}

func assert(x bool) {
	if !x {
		panic("assertion failed")
	}
}

func bittiest(a []int) int {
	r, m := 0, 0
	for _, v := range a {
		n := bits.OnesCount(uint(v))
		if n > m {
			r, m = v, n
		}
	}
	return r
}
