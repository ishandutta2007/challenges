/*

Create a function that gets every pair of numbers from an array that sums up to eight and returns it as an array of pairs (sorted ascendingly).
See the following examples for more details.

Examples

sumsUp([1, 2, 3, 4, 5]) ➞ [[3, 5]]

sumsUp([1, 2, 3, 7, 9]) ➞ [[1, 7]]

sumsUp([10, 9, 7, 2, 8]) ➞ []

sumsUp([1, 6, 5, 4, 8, 2, 3, 7]) ➞ [[2, 6], [3, 5], [1, 7]]
// [6, 2] first to complete the cycle (to sum up to 8)
// [5, 3] follows
// [1, 7] lastly
// the pair that completes the cycle is always found on the left
// [2, 6], [3, 5], [1, 7] sorted according to cycle completeness, then pair-wise.

Notes

    Remember the idea of "completes the cycle first" when getting the sort order of the pairs.
    Only unique numbers are present in the array.
    Return an empty array if nothing sums up to eight.

*/

package main

import (
	"fmt"
	"reflect"
)

func main() {
	test([]int{1, 2, 3, 4, 5}, [][2]int{{3, 5}})
	test([]int{10, 9, 7, 2, 8}, [][2]int{})
	test([]int{1, 6, 5, 4, 8, 2, 3, 7}, [][2]int{{2, 6}, {3, 5}, {1, 7}})
	test([]int{5, 7, 2, 3, 0, 1, 6, 4, 8}, [][2]int{{3, 5}, {1, 7}, {2, 6}, {0, 8}})
	test([]int{10, 9, 7, 1, 8, -2, -1, 2, 6}, [][2]int{{1, 7}, {-2, 10}, {-1, 9}, {2, 6}})
	test([]int{0, 1, -2, 7, 9, 5, 4, 10, 8, -1, 6}, [][2]int{{1, 7}, {-2, 10}, {0, 8}, {-1, 9}})
}

func test(a []int, r [][2]int) {
	p := sumsup(a)
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

func sumsup(a []int) (p [][2]int) {
	m := make(map[int]int)
	for _, x := range a {
		y := 8 - x
		if m[y] > 0 {
			p = append(p, [2]int{min(x, y), max(x, y)})
			m[y]--
		} else {
			m[x]++
		}
	}
	return
}

func min(x, y int) int {
	if x < y {
		return x
	}
	return y
}

func max(x, y int) int {
	if x > y {
		return x
	}
	return y
}
