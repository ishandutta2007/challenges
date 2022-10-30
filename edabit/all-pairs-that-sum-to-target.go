/*

Create a function that returns all pairs of numbers in an array that sum to a target.
Sort the pairs in ascending order with respect to the smaller number, then order each pair in this order: [smaller, larger].

Examples

allPairs([2, 4, 5, 3], 7) ➞ [[2, 5], [3, 4]]
// 2 + 5 = 7, 3 + 4 = 7

allPairs([5, 3, 9, 2, 1], 3) ➞ [[1, 2]]

allPairs([4, 5, 1, 3, 6, 8], 9) ➞ [[1, 8], [3, 6], [4, 5]]
// Sorted: 1 < 3 < 4; each pair is ordered [smaller, larger]

Notes

    If no pairs are found, return an empty array [].
    You are only allowed to use each number once in a pair.
    See Comments for a hint.

*/

package main

import (
	"sort"
)

func main() {
	eq(allpairs([]int{2, 4, 5, 3}, 7), [][2]int{{2, 5}, {3, 4}})
	eq(allpairs([]int{5, 3, 9, 2, 1}, 3), [][2]int{{1, 2}})
	eq(allpairs([]int{4, 5, 1, 3, 6, 8}, 9), [][2]int{{1, 8}, {3, 6}, {4, 5}})
	eq(allpairs([]int{5, 2}, 14), [][2]int{})
	eq(allpairs([]int{5, 5, 2}, 14), [][2]int{})
	eq(allpairs([]int{8, 7, 7, 2, 4, 6}, 14), [][2]int{{6, 8}, {7, 7}})
	eq(allpairs([]int{8, 7, 2, 4, 6}, 14), [][2]int{{6, 8}})
	eq(allpairs([]int{1, 3, 5, 4, 0}, 4), [][2]int{{0, 4}, {1, 3}})
	eq(allpairs([]int{1, 3, 5, 4, 0, 2}, 4), [][2]int{{0, 4}, {1, 3}})
	eq(allpairs([]int{1, 3, 5, 4, 0, 2, 2}, 4), [][2]int{{0, 4}, {1, 3}, {2, 2}})
}

func allpairs(a []int, v int) [][2]int {
	m := make(map[int]int)
	for _, n := range a {
		m[n]++
	}

	var p [][2]int
	for _, x := range a {
		y := v - x
		if m[x]--; m[y] > 0 {
			p = append(p, [2]int{min(x, y), max(x, y)})
			m[y]--
		}
	}
	sort.Slice(p, func(i, j int) bool {
		return p[i][0] < p[j][0]
	})
	return p
}

func max(a, b int) int {
	if a > b {
		return a
	}
	return b
}

func min(a, b int) int {
	if a < b {
		return a
	}
	return b
}

func assert(x bool) {
	if !x {
		panic("assertion failed")
	}
}

func eq(a, b [][2]int) {
	assert(len(a) == len(b))
	for i := range a {
		for j := range a[i] {
			assert(a[i][j] == b[i][j])
		}
	}
}
