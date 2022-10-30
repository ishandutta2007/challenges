/*

Write a function that returns true if two arrays, when combined, form a consecutive sequence.
Examples

consecutiveCombo([7, 4, 5, 1], [2, 3, 6]) ➞ true

consecutiveCombo([1, 4, 6, 5], [2, 7, 8, 9]) ➞ false

consecutiveCombo([1, 4, 5, 6], [2, 3, 7, 8, 10]) ➞ false

consecutiveCombo([44, 46], [45]) ➞ true

Notes

    The input arrays will have unique values.
    The input arrays can be in any order.
    A consecutive sequence is a sequence without any gaps in the integers, e.g. 1, 2, 3, 4, 5 is a consecutive sequence, but 1, 2, 4, 5 is not.

*/

package main

import (
	"sort"
)

func main() {
	assert(consecutive([]int{1, 4, 5, 7}, []int{2, 3, 6}) == true)
	assert(consecutive([]int{1, 4, 5, 6}, []int{2, 7, 8, 9}) == false)
	assert(consecutive([]int{1, 4, 5, 6}, []int{2, 3, 7, 8, 10}) == false)
	assert(consecutive([]int{7, 5, 4, 1}, []int{2, 3, 6, 8}) == true)
	assert(consecutive([]int{33, 34, 40}, []int{39, 38, 37, 36, 35, 32, 31, 30}) == true)
	assert(consecutive([]int{1, 4, 5, 6}, []int{2, 3, 7, 8, 10}) == false)
	assert(consecutive([]int{44, 46}, []int{45}) == true)
	assert(consecutive([]int{4, 3, 1}, []int{2, 5}) == true)
	assert(consecutive([]int{4, 3, 1}, []int{2, 5, 7, 6}) == true)
	assert(consecutive([]int{4, 3, 1}, []int{7, 6, 5}) == false)
	assert(consecutive([]int{4, 3, 1}, []int{0, 7, 6, 5}) == false)
	assert(consecutive([]int{44, 46}, []int{45}) == true)
}

func consecutive(a, b []int) bool {
	var p []int
	p = append(p, a...)
	p = append(p, b...)
	sort.Ints(p)
	for i := 1; i < len(p); i++ {
		if p[i]-1 != p[i-1] {
			return false
		}
	}
	return true
}

func assert(x bool) {
	if !x {
		panic("assertion failed")
	}
}
