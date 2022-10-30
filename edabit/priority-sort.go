/*

Given an array and a set, return a sorted array with its items in ascending order but prioritize the elements in the set over the other items in the array.
Examples

prioritySort([5, 4, 3, 2, 1], new Set([2, 3])) ➞ [2, 3, 1, 4, 5]

prioritySort([5, 4, 3, 2, 1], new Set([3, 6])) ➞ [3, 1, 2, 4, 5]

prioritySort([-5, -4, -3, -2, -1, 0], new Set([-4, -3])) ➞ [-4, -3, -5, -2, -1, 0]

Notes

    If the array is empty, return an empty array.
    If the set is empty there is nothing to prioritize, but the array should still be sorted.
    The set may contain values that are not in the array.
    The array may contain duplicates.
    The array and the set will only contain integer values.

*/

package main

import (
	"fmt"
	"reflect"
	"sort"
)

func main() {
	test([]int{5, 4, 3, 2, 1}, []int{2, 3}, []int{2, 3, 1, 4, 5})
	test([]int{}, []int{2, 3}, []int{})
	test([]int{}, []int{}, []int{})
	test([]int{1, 2, 3}, []int{}, []int{1, 2, 3})
	test([]int{5, 4, 3, 2, 1}, []int{3, 6}, []int{3, 1, 2, 4, 5})
	test([]int{-5, -4, -3, -2, -1, 0}, []int{-4, -3}, []int{-4, -3, -5, -2, -1, 0})
	test([]int{-10, 0, 10}, []int{0}, []int{0, -10, 10})
	test([]int{4, 2, 2}, []int{1}, []int{2, 2, 4})
	test([]int{1, 5, 5, 5, 5, 2, 1}, []int{1, 5}, []int{1, 1, 5, 5, 5, 5, 2})
}

func test(a, s, r []int) {
	p := priosort(a, set(s))
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

func priosort(a []int, m map[int]int) []int {
	sort.Slice(a, func(i, j int) bool {
		x, fx := m[a[i]]
		y, fy := m[a[j]]
		switch {
		case fx && fy:
			return x < y
		case fx:
			return true
		case fy:
			return false
		}
		return a[i] < a[j]
	})
	return a
}

func set(a []int) map[int]int {
	m := make(map[int]int)
	for i := range a {
		m[a[i]] = i
	}
	return m
}
