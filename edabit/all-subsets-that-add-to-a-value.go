/*

Create a function that returns all subarrays in an array that sum to a particular value. Return the subarrays in the following order:

    First by ascending length.
    Second by comparing element-by-element, starting from the leftmost one. Put the array with the smaller element first in the pairwise comparison.

The following example will illustrate:

getSubsets([-3, -2, -1, 0, 1, 2, 3], 2)
[ // All the subsets below sum to 2.
  [2],
  [-1, 3],
  [0, 2], // Same length: -1 < 0, so [-1, 3] goes before [0, 2]
  [-3, 2, 3],
  [-2, 1, 3],
  [-1, 0, 3],
  [-1, 1, 2],
  [-3, 0, 2, 3],
  [-2, -1, 2, 3],
  [-2, 0, 1, 3], // Same length + same first element: -1 < 0, so [-2, -1, 2, 3] goes before [-2, 0, 1, 3]
  [-1, 0, 1, 2],
  [-3, -1, 1, 2, 3],
  [-2, -1, 0, 2, 3],
  [-3, -1, 0, 1, 2, 3]
]

Examples

getSubsets([-1, 0, 1, 2], 2) ➞ [[2], [0, 2], [-1, 1, 2], [-1, 0, 1, 2]]

getSubsets([-1, 0, 1, 2], 3) ➞ [[1, 2], [0, 1, 2]]

getSubsets([1, 2, 3, 4], 5) ➞ [[1, 4], [2, 3]]

getSubsets([-1, 0, 1, 2], 4) ➞ []

Notes

    Arrays will have unique numbers.
    Return an empty array if there does not a exist a subset whose numbers sum to that value (see fourth example).

*/

package main

import (
	"fmt"
	"reflect"
	"sort"
)

func main() {
	a1 := []int{-1, 0, 1, 2}
	r1 := [][]int{{2}, {0, 2}, {-1, 1, 2}, {-1, 0, 1, 2}}

	a2 := []int{-1, 0, 1, 2}
	r2 := [][]int{{1, 2}, {0, 1, 2}}

	a3 := []int{-1, 0, 1, 2}
	r3 := [][]int{}

	a4 := []int{1, 2, 3, 4, 5, 6}
	r4 := [][]int{{6}, {1, 5}, {2, 4}, {1, 2, 3}}

	a5 := []int{-3, -2, -1, 0, 1, 2, 3}
	r5 := [][]int{
		{2},
		{-1, 3},
		{0, 2},
		{-3, 2, 3},
		{-2, 1, 3},
		{-1, 0, 3},
		{-1, 1, 2},
		{-3, 0, 2, 3},
		{-2, -1, 2, 3},
		{-2, 0, 1, 3},
		{-1, 0, 1, 2},
		{-3, -1, 1, 2, 3},
		{-2, -1, 0, 2, 3},
		{-3, -1, 0, 1, 2, 3},
	}

	test(a1, 2, r1)
	test(a2, 3, r2)
	test(a3, 4, r3)
	test(a4, 6, r4)
	test(a5, 2, r5)
}

func test(a []int, t int, r [][]int) {
	p := subsets(a, t)
	fmt.Println(p)
	assert(len(p) == len(r))
	for i := range p {
		assert(reflect.DeepEqual(p[i], r[i]))
	}
}

func assert(x bool) {
	if !x {
		panic("assertion failed")
	}
}

func subsets(a []int, t int) [][]int {
	r := recurse(a, t, 0, make([]bool, len(a)), []int{}, [][]int{})

	for i := range r {
		sort.Ints(r[i])
	}
	sort.Slice(r, func(i, j int) bool {
		if len(r[i]) < len(r[j]) {
			return true
		}
		if len(r[i]) > len(r[j]) {
			return false
		}
		for k := range r[i] {
			if r[i][k] < r[j][k] {
				return true
			} else if r[i][k] > r[j][k] {
				break
			}
		}
		return false
	})

	n := 0
	for i := 0; i < len(r); {
		j := i + 1
		for j < len(r) && reflect.DeepEqual(r[j], r[i]) {
			j++
		}
		r[n], n = r[i], n+1
		i = j
	}
	r = r[:n]

	return r
}

func recurse(a []int, t, v int, b []bool, p []int, r [][]int) [][]int {
	if t == v && len(p) > 0 {
		r = append(r, append([]int{}, p...))
	}

	for i := range a {
		if !b[i] {
			b[i] = true
			p = append(p, a[i])
			r = recurse(a, t, v+a[i], b, p, r)
			b[i] = false
			p = p[:len(p)-1]
		}
	}

	return r
}
