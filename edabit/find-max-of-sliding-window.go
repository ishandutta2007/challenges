/*

The sliding window is a technique used to simplify complex data problems. A window that slides over the data to examine different sections of it.

Your challenge is to create a sliding window that traverses the array and returns the maximum value in each window.

Arguments

    Array:The array over which you are traversing.
    windowLength: The length of the window you will be using to do the search.
    Returns Array: A new array containing the maximums for each window.
    You are given this array and a window length of 2.

[4, 5, 6, 7, 8, 9]

Our function would start by examining the first two elements of the array and pushes the max value to a new array.

[**4, 5,** 6, 7, 8, 9]

... then the window slides to examine the next two, in this case 5 and 6, and pushes the max value to the array.

[4, **5, 6**, 7, 8, 9]

The window will examine the entire length of the array until the maximums for each window have been added to the new array.
Examples

windowMaxes([1, 2, 3, 4, 3, 2, 1, 2, 5], 3) ➞ [3, 4, 4, 4, 3, 2, 5]

Notes

    This is part of my Data Structures series. A collection of common coding interview challenges used to test ones understanding of data structures.
    This entire series of challenges can be found here.

*/

package main

import (
	"reflect"
)

func main() {
	test([]int{4, 5, 6, 7, 8, 9}, 2, []int{5, 6, 7, 8, 9})
	test([]int{1, 2, 3, 4, 3, 2, 1, 2, 5}, 4, []int{4, 4, 4, 4, 3, 5})
	test([]int{1, 2, 3, 4, 3, 2, 1, 2, 5}, 3, []int{3, 4, 4, 4, 3, 2, 5})
	test([]int{1, 2, 3, 4, 3, 2, 1, 2, 5}, 5, []int{4, 4, 4, 4, 5})
	test([]int{1, 4, -2, -9, 5, 32, -89, 23, 43, 2, 75, 3, 12, -3}, 6, []int{32, 32, 32, 43, 43, 75, 75, 75, 75})
	test(nil, 0, nil)
}

func test(a []int, w int, r []int) {
	p := wmax(a, w)
	assert(reflect.DeepEqual(p, r))
}

func assert(x bool) {
	if !x {
		panic("assertion failed")
	}
}

func wmax(a []int, w int) []int {
	if len(a) == 0 || w <= 0 {
		return nil
	}

	var p []int
	for i := 0; i+w <= len(a); i++ {
		v := a[i]
		for j := 1; j < w && i+j < len(a); j++ {
			v = max(v, a[i+j])
		}
		p = append(p, v)
	}
	return p
}

func max(a, b int) int {
	if a > b {
		return a
	}
	return b
}
