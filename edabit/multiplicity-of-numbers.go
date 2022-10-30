/*

Write a function that returns an array of elements [number, multiplicity].
The multiplicity of a number refers to the number of times it occurs in the array.

To illustrate:

[5, 5, 1, 1, 5, 5, 3]
[[5, 4], [1, 2], [3, 1]]

// Since 5 appears 4 times, 1 appears twice, and 3 appears once.

The final array should only include unique elements, and the elements should be ordered by when they first appeared in the original array.

Examples

multiplicity([1, 1, 1, 2, 2, 3]) ➞ [[1, 3], [2, 2], [3, 1]]

multiplicity([1, 1, 1, 1, 1]) ➞ [[1, 5]]

multiplicity([1, 5, 4, 3, 2]) ➞ [[1, 1], [5, 1], [4, 1], [3, 1], [2, 1]]

Notes

N/A

*/

package main

import (
	"fmt"
	"reflect"
)

func main() {
	test([]int{1, 1, 1, 2, 2, 3}, [][2]int{{1, 3}, {2, 2}, {3, 1}})
	test([]int{1, 1, 1, 1, 1}, [][2]int{{1, 5}})
	test([]int{1, 5, 4, 3, 2}, [][2]int{{1, 1}, {5, 1}, {4, 1}, {3, 1}, {2, 1}})
	test([]int{5, 5, 5, 5, 8}, [][2]int{{5, 4}, {8, 1}})
	test([]int{3, 3, 3, 0}, [][2]int{{3, 3}, {0, 1}})
	test([]int{1, 1, 2, 2, 3, 3, 4, 4}, [][2]int{{1, 2}, {2, 2}, {3, 2}, {4, 2}})
	test([]int{4, 4, 3, 3, 2, 2, 1, 1}, [][2]int{{4, 2}, {3, 2}, {2, 2}, {1, 2}})
}

func test(a []int, r [][2]int) {
	p := multiplicity(a)
	fmt.Println(p)
	if len(p) == 0 {
		assert(len(p) == len(r))
	} else {
		assert(reflect.DeepEqual(p, r))
	}
}

func assert(x bool) {
	if !x {
		panic("assertion failed")
	}
}

func multiplicity(a []int) (p [][2]int) {
	m := make(map[int]int)
	for _, v := range a {
		if i, f := m[v]; f {
			p[i][1]++
		} else {
			p = append(p, [2]int{v, 1})
			m[v] = len(p) - 1
		}
	}
	return
}
