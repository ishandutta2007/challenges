/*

Create a function that returns an array that expands by 1 from 1 to the value of the input, and then reduces back to 1.
Items in the lists will be the same as the length of the lists.

Examples

diamond_arrays(1) ➞ [[1]]

diamond_arrays(2) ➞ [[1], [2, 2], [1]]

diamond_arrays(5) ➞ [[1], [2, 2], [3, 3, 3], [4, 4, 4, 4], [5, 5, 5, 5, 5], [4, 4, 4, 4], [3, 3, 3], [2, 2], [1]]

Notes

N/A

*/

package main

import (
	"fmt"
	"reflect"
)

func main() {
	test(1, [][]int{{1}})
	test(2, [][]int{{1}, {2, 2}, {1}})
	test(3, [][]int{{1}, {2, 2}, {3, 3, 3}, {2, 2}, {1}})
	test(5, [][]int{{1}, {2, 2}, {3, 3, 3}, {4, 4, 4, 4}, {5, 5, 5, 5, 5}, {4, 4, 4, 4}, {3, 3, 3}, {2, 2}, {1}})
	test(7, [][]int{{1}, {2, 2}, {3, 3, 3}, {4, 4, 4, 4}, {5, 5, 5, 5, 5}, {6, 6, 6, 6, 6, 6}, {7, 7, 7, 7, 7, 7, 7}, {6, 6, 6, 6, 6, 6}, {5, 5, 5, 5, 5}, {4, 4, 4, 4}, {3, 3, 3}, {2, 2}, {1}})
}

func test(n int, r [][]int) {
	p := diamond(n)
	fmt.Println(p)
	assert(reflect.DeepEqual(p, r))
}

func assert(x bool) {
	if !x {
		panic("assertion failed")
	}
}

func diamond(n int) [][]int {
	var r [][]int
	for i := 1; i <= n; i++ {
		r = append(r, fill(i))
	}
	for i := n - 1; i >= 1; i-- {
		r = append(r, fill(i))
	}
	return r
}

func fill(n int) []int {
	p := make([]int, n)
	for i := range p {
		p[i] = n
	}
	return p
}
