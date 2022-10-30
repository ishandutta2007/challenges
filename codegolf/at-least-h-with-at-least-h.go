/*

Input

A list of nonnegative integers.
Output

The largest nonnegative integer h such that at least h of the numbers in the list are greater than or equal to h.
Test Cases

[0,0,0,0] -> 0
[12,312,33,12] -> 4
[1,2,3,4,5,6,7] -> 4
[22,33,1,2,4] -> 3
[1000,2,2,2] -> 2
[23,42,12,92,39,46,23,56,31,12,43,23,54,23,56,73,35,73,42,12,10,15,35,23,12,42] -> 20

Rules

You can write either a full program or a function, and anonymous functions are allowed too. This is code-golf, so the fewest byte count wins. Standard loopholes are disallowed.
Background

The h-index is a notion used in academia which aims to capture the impact and productivity of a researcher.
According to Wikipedia, a researcher has index h, if he or she has published h scientific articles, each of which has been cited in other articles at least h times.
Thus, this challenge is about computing the h-index from a list of citation counts.

*/

package main

import (
	"sort"
)

func main() {
	assert(hindex([]int{0, 0, 0, 0}) == 0)
	assert(hindex([]int{12, 312, 33, 12}) == 4)
	assert(hindex([]int{1, 2, 3, 4, 5, 6, 7}) == 4)
	assert(hindex([]int{22, 33, 1, 2, 4}) == 3)
	assert(hindex([]int{1000, 2, 2, 2}) == 2)
	assert(hindex([]int{23, 42, 12, 92, 39, 46, 23, 56, 31, 12, 43, 23, 54, 23, 56, 73, 35, 73, 42, 12, 10, 15, 35, 23, 12, 42}) == 20)
	assert(hindex([]int{3, 0, 6, 1, 5}) == 3)
	assert(hindex([]int{0}) == 0)
	assert(hindex([]int{1}) == 1)
	assert(hindex([]int{1, 2, 2}) == 2)
	assert(hindex([]int{2, 2}) == 2)
}

func assert(x bool) {
	if !x {
		panic("assertion failed")
	}
}

func hindex(a []int) int {
	h := 0
	sort.Slice(a, func(i, j int) bool { return a[i] > a[j] })
	sort.Search(len(a), func(i int) bool {
		b := a[i] >= i+1
		if b {
			h = i + 1
		}
		return !b
	})
	return h
}
