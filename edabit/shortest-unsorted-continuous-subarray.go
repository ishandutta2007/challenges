/*

Given an integer array, you need to find the shortest continuous subarray that if you only sort this subarray in ascending order, then the whole array will be sorted in ascending order, too.

Create a function that returns the length of that subarray.

Examples

findUnsortedSubarray([1, 3, 2, 5, 8, 7, 13]) ➞ 5
// You need to sort [3, 2, 5, 8, 7] in ascending order to make
// the whole array sorted in ascending order.

findUnsortedSubarray([10, 7, 5, 3]) ➞ 4

findUnsortedSubarray([2, 4, 4, 4, 4, 3]) ➞ 5

Notes

    The given array can contain duplicates, so ascending order here means <= (see example #3).
    If the given array is already sorted or is empty, return 0.

*/

package main

import (
	"sort"
)

func main() {
	assert(unsorted([]int{1, 3, 2, 5, 8, 7, 13}) == 5)
	assert(unsorted([]int{10, 7, 5, 3}) == 4)
	assert(unsorted([]int{2, 4, 4, 4, 4, 3}) == 5)
	assert(unsorted([]int{1, 1, 1}) == 0)
	assert(unsorted([]int{5, 15, 25}) == 0)
	assert(unsorted([]int{4, 8, 6, 10, 9, 11, 13, 15}) == 4)
	assert(unsorted([]int{1, 2, 3, 4, -4, -3, -2, -1}) == 8)
	assert(unsorted([]int{0, 10, 20, 30, 10, 45, 50}) == 3)
	assert(unsorted([]int{-200, -201, -100, -1, 1, 0, 100, 200, 300, 68, 400}) == 10)
	assert(unsorted([]int{1000, 500, 0, 500, 501, 521, 2551, 2656, 3020}) == 6)
	assert(unsorted([]int{15, 5, 15, 5, 15, 5}) == 6)
	assert(unsorted([]int{}) == 0)
}

func assert(x bool) {
	if !x {
		panic("assertion failed")
	}
}

func unsorted(a []int) int {
	n := len(a)
	p := append([]int{}, a...)
	sort.Ints(p)

	i, j := 0, n-1
	for i < n && a[i] == p[i] {
		i++
	}
	for j >= i && a[j] == p[j] {
		j--
	}
	return j - i + 1
}
