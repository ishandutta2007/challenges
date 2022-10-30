/*

Create a function that takes an unsorted list of numbers and returns the number of unique triplets whose sum is equal to the variable n.

Examples

tripletSum([1, 0, 2, 6, 3, 9, 3], n = 11) ➞ 2
// Since we found two unique triplets that equate to 11: 0+2+9 and 2+6+3

tripletSum([1, 2, 6, 3, 4, 5, 9, 10, 11], n = 20) ➞ 5

tripletSum([5, 2, 8], n = 2) ➞ 0

Notes

You should also expect lists with less than three elements.

*/

package main

import (
	"sort"
)

func main() {
	assert(triplet([]int{1, 2, 6, 3, 4, 5, 9, 10, 11}, 20) == 5)
	assert(triplet([]int{6, 2, 6}, 9) == 0)
	assert(triplet([]int{6, 2, 6, 0, 9, 2, 5, 8}, 15) == 2)
	assert(triplet([]int{1, -2, 0, 6, 11, 15, 6, 2, 6, 0, 9, 2, 5, 8}, 15) == 9)
	assert(triplet([]int{1, 15}, 16) == 0)
	assert(triplet([]int{}, 0) == 0)
}

func assert(x bool) {
	if !x {
		panic("assertion failed")
	}
}

func triplet(a []int, v int) int {
	if len(a) < 3 {
		return 0
	}

	m := make(map[[3]int]bool)
	r := 0
	for i := range a {
		for j := range a {
			for k := range a {
				if i == j || i == k || j == k || a[i]+a[j]+a[k] != v {
					continue
				}

				p := [3]int{a[i], a[j], a[k]}
				sort.Ints(p[:])
				if !m[p] {
					r, m[p] = r+1, true
				}
			}
		}
	}
	return r
}
