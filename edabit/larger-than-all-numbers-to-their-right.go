/*

Create a function that retrieves every number that is strictly larger than every number that follows it.

Examples

larger_than_right([3, 13, 11, 2, 1, 9, 5]) ➞ [13, 11, 9, 5]
# 13 is larger than all numbers to its right, etc.

larger_than_right([5, 5, 5, 5, 5, 5]) ➞ [5]
# Must be strictly larger.
# Always include the last number.

larger_than_right([5, 9, 8, 7]) ➞ [9, 8, 7]

Notes

The last number in an array is trivially strictly larger than all numbers that follow it (no numbers follow it).

*/

package main

import (
	"fmt"
	"reflect"
)

func main() {
	test([]int{3, 13, 11, 2, 1, 9, 5}, []int{13, 11, 9, 5})
	test([]int{9, 8, 7, 6}, []int{9, 8, 7, 6})
	test([]int{1, 2, 3, 4}, []int{4})
	test([]int{5, 9, 8, 7}, []int{9, 8, 7})
	test([]int{5, 5, 5, 5, 5}, []int{5})
	test([]int{}, []int{})
}

func test(a, r []int) {
	p := largersright(a)
	fmt.Println(p)
	assert(reflect.DeepEqual(p, r))
}

func assert(x bool) {
	if !x {
		panic("assertion failed")
	}
}

func largersright(a []int) []int {
	r := []int{}
	n := len(a)
	if n == 0 {
		return r
	}

	p := make([]int, len(a))
	p[n-1] = a[n-1]
	for i := n - 2; i >= 0; i-- {
		p[i] = max(p[i], p[i+1])
	}

	for i := range a {
		if i+1 >= n || a[i] > p[i+1] {
			r = append(r, a[i])
		}
	}
	return r
}

func max(a, b int) int {
	if a > b {
		return a
	}
	return b
}
