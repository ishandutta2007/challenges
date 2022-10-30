/*

Create a function that divides an array into chunks of size n, where n is the length of each chunk.
Examples

chunkify([2, 3, 4, 5], 2) ➞ [[2, 3], [4, 5]]

chunkify([2, 3, 4, 5, 6], 2) ➞ [[2, 3], [4, 5], [6]]

chunkify([2, 3, 4, 5, 6, 7], 3) ➞ [[2, 3, 4], [5, 6, 7]]

chunkify([2, 3, 4, 5, 6, 7], 1) ➞ [[2], [3], [4], [5], [6], [7]]

chunkify([2, 3, 4, 5, 6, 7], 7) ➞ [[2, 3, 4, 5, 6, 7]]

Notes

	It's O.K. if the last chunk is not completely filled (see example #2).
	Integers will always be single-digit.

*/

package main

import (
	"reflect"
)

func main() {
	test([]int{2, 3, 4, 5}, 2, [][]int{{2, 3}, {4, 5}})
	test([]int{2, 3, 4, 5, 6}, 2, [][]int{{2, 3}, {4, 5}, {6}})
	test([]int{2, 3, 4, 5, 6, 7}, 3, [][]int{{2, 3, 4}, {5, 6, 7}})
	test([]int{2, 3, 4, 5, 6, 7}, 1, [][]int{{2}, {3}, {4}, {5}, {6}, {7}})
	test([]int{2, 3, 4, 5, 6, 7}, 7, [][]int{{2, 3, 4, 5, 6, 7}})
	test([]int{2, 3, 4, 5}, 3, [][]int{{2, 3, 4}, {5}})
	test([]int{2, 3, 4, 5, 6, 7, 8}, 3, [][]int{{2, 3, 4}, {5, 6, 7}, {8}})
	test([]int{2, 3, 4, 5, 6}, 2, [][]int{{2, 3}, {4, 5}, {6}})
}

func test(a []int, n int, r [][]int) {
	p := chunkify(a, n)
	assert(reflect.DeepEqual(p, r))
}

func assert(x bool) {
	if !x {
		panic("assertion failed")
	}
}

func chunkify(a []int, n int) [][]int {
	if n <= 0 {
		return nil
	}

	var r [][]int
	for i := 0; i < len(a); i += n {
		r = append(r, a[i:min(i+n, len(a))])
	}
	return r
}

func min(a, b int) int {
	if a < b {
		return a
	}
	return b
}
