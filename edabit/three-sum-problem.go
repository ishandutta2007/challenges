/*

Write a function that returns all sets of three elements that sum to 0.

Examples

threeSum([0, 1, -1, -1, 2]) ➞ [[0, 1, -1], [-1, -1, 2]]

threeSum([0, 0, 0, 5, -5]) ➞ [[0, 0, 0], [0, 5, -5]]

threeSum([1, 2, 3]) ➞ []

threeSum([1]) ➞ []

Notes

    The original array may contain duplicate numbers.
    Each three-element subarray in your output should be distinct.
    Subarrays should be ordered by the first element of the subarray.
    Subarrays themselves should be ordered the same as the original array.
    Return an empty array if no three elements sum to zero.
    Return an empty array if there are fewer than three elements.

*/

package main

import (
	"fmt"
	"reflect"
)

func main() {
	test([]int{0, 1, -1, -1, 2}, [][3]int{{0, 1, -1}, {-1, -1, 2}})
	test([]int{0, 0, 0, 5, -5}, [][3]int{{0, 0, 0}, {0, 5, -5}})
	test([]int{0, -1, 1, 0, -1, 1}, [][3]int{{0, -1, 1}, {0, 1, -1}, {-1, 1, 0}, {-1, 0, 1}, {1, 0, -1}})
	test([]int{0, 5, 5, 0, 0}, [][3]int{{0, 0, 0}})
	test([]int{0, 5, -5, 0, 0}, [][3]int{{0, 5, -5}, {0, 0, 0}, {5, -5, 0}})
	test([]int{1, 2, 3, -5, 8, 9, -9, 0}, [][3]int{{1, 8, -9}, {2, 3, -5}, {9, -9, 0}})
	test([]int{0, 0, 0}, [][3]int{{0, 0, 0}})
	test([]int{1, 5, 5, 2}, [][3]int{})
	test([]int{1, 1}, [][3]int{})
	test([]int{}, [][3]int{})
}

func test(a []int, r [][3]int) {
	p := threes(a)
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

func threes(a []int) [][3]int {
	if len(a) < 3 {
		return nil
	}

	m := make(map[[3]int]bool)
	var p [][3]int
	for i := 0; i < len(a); i++ {
		for j := i + 1; j < len(a); j++ {
			for k := j + 1; k < len(a); k++ {
				v := [3]int{a[i], a[j], a[k]}
				if a[i]+a[j]+a[k] == 0 && !m[v] {
					p = append(p, [3]int{a[i], a[j], a[k]})
					m[v] = true
				}
			}
		}
	}
	return p
}
