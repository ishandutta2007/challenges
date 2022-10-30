/*

Write a function that returns the total number of integers covered from an array of intervals (inclusive). In other words, return the number of different integers in the arrays.

Examples

coveredIntegers([[80, 81], [1, 2], [9, 11]]) ➞ 7
// Seven integers are covered: 1, 2, 9, 10, 11, 80, 81

coveredIntegers([[3, 6], [4, 6], [5, 6]]) ➞ 4

coveredIntegers([[1, 2], [1, 2]]) ➞ 2

Notes

    Intervals may overlap, be subintervals of each other, or be identical.
    For each interval [l, u], l and u will be integers, and l <= u will always be true.

*/

package main

import (
	"sort"
)

func main() {
	assert(covered([][2]int{{80, 81}, {1, 2}, {9, 11}}) == 7)
	assert(covered([][2]int{{3, 6}, {4, 6}, {5, 6}}) == 4)
	assert(covered([][2]int{{1, 2}, {1, 2}}) == 2)
	assert(covered([][2]int{{1, 11}}) == 11)
	assert(covered([][2]int{{8, 9}, {102, 104}}) == 5)
	assert(covered([][2]int{{1, 1}, {5, 5}, {8, 8}}) == 3)
	assert(covered([][2]int{{0, 5}, {5, 5}, {8, 8}}) == 7)
	assert(covered([][2]int{{1, 5}, {3, 5}, {4, 6}, {5, 7}}) == 7)
	assert(covered([][2]int{{-3, 10}, {-2, 9}, {-1, 8}, {0, 7}, {1, 6}, {2, 5}, {3, 4}}) == 14)
}

func assert(x bool) {
	if !x {
		panic("assertion failed")
	}
}

func covered(a [][2]int) int {
	p := merge(a)
	r := 0
	for _, i := range p {
		r += i[1] - i[0] + 1
	}
	return r
}

// https://www.geeksforgeeks.org/merging-intervals/
func merge(a [][2]int) [][2]int {
	if len(a) == 0 {
		return nil
	}

	sort.Slice(a, func(i, j int) bool {
		return a[i][0] < a[j][0]
	})

	p := [][2]int{a[0]}
	for _, i := range a[1:] {
		n := len(p) - 1
		t := p[n]
		if t[1] < i[0] {
			p = append(p, i)
		} else if t[1] < i[1] {
			t[1] = i[1]
			p[n] = t
		}
	}
	return p
}
