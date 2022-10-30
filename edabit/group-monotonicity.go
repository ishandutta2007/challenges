/*

Create a function which returns the indices where the monotonicity of a 1-D array changes. If there are none, return an empty array. A monotonic array is one that is either non-increasing or non-decreasing.
Examples

groupMonotonic([0, 1]) ➞ []

groupMonotonic([0, 2, 1]) ➞ [1]

groupMonotonic([0, 1, 1, 0]) ➞ [2]

Notes

Trivially, all points and line-segments are monotonic (see example #1).
Return the indices where each monotonic section stops, not where each new one begins: i.e. return the "peaks" of the triangles (see example #2).
Monotonic arrays are allowed to be constant (see example #3).
You can expect positive and negative values in the array.

*/

package main

import "fmt"

func main() {
	fmt.Println(monotone([]int{}))
	fmt.Println(monotone([]int{0}))
	fmt.Println(monotone([]int{1}))
	fmt.Println(monotone([]int{0, 1}))
	fmt.Println(monotone([]int{1, 0}))
	fmt.Println(monotone([]int{1, 1}))
	fmt.Println(monotone([]int{1, 1}))
	fmt.Println(monotone([]int{0, 1, 2}))
	fmt.Println(monotone([]int{2, 1, 0}))
	fmt.Println(monotone([]int{0, 2, 1}))
	fmt.Println(monotone([]int{1, 0, 2}))
	fmt.Println(monotone([]int{0, 1, 1, 0}))
	fmt.Println(monotone([]int{1, 2, 3, 4, 4, 4, 3, 2, 1}))
	fmt.Println(monotone([]int{0, 6, 10, 9, 3, -3, -9, -10, -6, 0}))
}

func monotone(a []int) (p []int) {
	for i := 1; i < len(a)-1; i++ {
		if cmp(a[i-1], a[i]) != cmp(a[i], a[i+1]) {
			p = append(p, i)
		}
	}
	return
}

func cmp(a, b int) int {
	if a <= b {
		return 1
	}
	return -1
}
