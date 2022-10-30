/*

Create a function that takes four arrays as arguments and returns a count of the total number of identical arrays.

Examples

countIdenticalArrays([0, 0, 0], [0, 1, 2], [0, 0, 0], [2, 1, 0]) ➞ 2

countIdenticalArrays([0, 1, 0], [0, 1, 2], [0, 2, 0], [2, 1, 0]) ➞ 0

countIdenticalArrays([0, 1, 2], [0, 1, 2], [0, 1, 2], [2, 1, 0]) ➞ 3

Notes

    Don't forget to return the result.
    If you get stuck on a challenge, find help in the Resources tab.
    If you're really stuck, unlock solutions in the Solutions tab.

*/

package main

import (
	"reflect"
	"sort"
)

func main() {
	assert(identical([][]int{{0, 0, 0}, {0, 1, 2}, {0, 0, 0}, {2, 1, 0}}) == 2)
	assert(identical([][]int{{0, 1, 0}, {0, 1, 2}, {0, 2, 0}, {2, 1, 0}}) == 0)
	assert(identical([][]int{{0, 1, 2}, {0, 1, 2}, {0, 1, 2}, {2, 1, 0}}) == 3)
}

func assert(x bool) {
	if !x {
		panic("assertion failed")
	}
}

func identical(a [][]int) int {
	p := make([][]int, len(a))
	for i := range a {
		p[i] = append(p[i], a[i]...)
	}
	sort.Slice(p, func(i, j int) bool {
		n, m := len(p[i]), len(p[j])
		if n < m {
			return true
		}
		if m > n {
			return false
		}

		for k := range p[i] {
			if p[i][k] < p[j][k] {
				return true
			} else if p[j][k] > p[i][k] {
				return false
			}
		}
		return false
	})

	r := 0
	for i, n := 0, len(a); i < n; {
		j := i + 1
		c := 0
		for j < n && reflect.DeepEqual(p[i], p[j]) {
			j++
			c++
		}
		if r += c; c > 0 {
			r++
		}
		i = j
	}
	return r
}
