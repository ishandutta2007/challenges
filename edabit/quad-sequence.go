/*

Write a function that receives an array of x integers and returns an array of x integers in the Nth term of a quadratic number sequence (where x is the length of the incoming array).
Your function should return the continuation of the quadratic sequence of the length equal to the length of the given array.

Examples

quadSequence([48, 65, 84]) ➞ [105, 128, 153]

quadSequence([0, 1, 6, 15, 28]) ➞ [45, 66, 91, 120, 153]

quadSequence([9, 20, 33, 48]) ➞ [65, 84, 105, 128]

Notes

Both positive and negative numbers are included in the test cases.

*/

package main

import (
	"fmt"
	"reflect"
)

func main() {
	test([]int{48, 65, 84}, []int{105, 128, 153})
	test([]int{9, 20, 33, 48}, []int{65, 84, 105, 128})
	test([]int{0, 1, 6, 15, 28}, []int{45, 66, 91, 120, 153})
	test([]int{6, 10, 16, 24}, []int{34, 46, 60, 76})
	test([]int{3, 12, 27, 48, 75, 108, 147, 192, 243, 300}, []int{363, 432, 507, 588, 675, 768, 867, 972, 1083, 1200})
	test([]int{-3, 8, 23, 42, 65}, []int{92, 123, 158, 197, 240})
	test([]int{0, 12, 10}, []int{-6, -36, -80})
}

func test(a, r []int) {
	p := quad(a)
	fmt.Println(p)
	assert(reflect.DeepEqual(p, r))
}

func assert(x bool) {
	if !x {
		panic("assertion failed")
	}
}

func quad(a []int) []int {
	x, y, n := 0, 0, len(a)
	if n >= 2 {
		x = a[n-1] - a[n-2]
	}
	if n >= 3 {
		y = x - (a[n-2] - a[n-3])
	}

	p := make([]int, len(a))
	for i := range p {
		x += y
		if i == 0 {
			p[0] = a[n-1] + x
		} else {
			p[i] = p[i-1] + x
		}
	}
	return p
}
