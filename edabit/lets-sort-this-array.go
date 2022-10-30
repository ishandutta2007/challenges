/*

Create a function that takes an array of numbers arr, a string s and return an array of numbers as per the following rules:

    "Asc" returns a sorted array in ascending order.
    "Des" returns sorted array in descending order.
    "None" returns array without any modification.

Examples

AscDesNone([4, 3, 2, 1], "Asc" ) ➞ [1, 2, 3, 4]

AscDesNone([7, 8, 11, 66], "Des") ➞ [66, 11, 8, 7]

AscDesNone([1, 2, 3, 4], "None") ➞ [1, 2, 3, 4]

Notes

*/

package main

import (
	"fmt"
	"sort"
)

func main() {
	test([]int{4, 3, 2, 1}, "Asc", []int{1, 2, 3, 4})
	test([]int{7, 8, 11, 66}, "Des", []int{66, 11, 8, 7})
	test([]int{1, 2, 3, 4}, "None", []int{1, 2, 3, 4})
	test([]int{1, 0, 1, 0}, "Asc", []int{0, 0, 1, 1})
	test([]int{1, 2, 2, 2, 2, 2, 2}, "Des", []int{2, 2, 2, 2, 2, 2, 1})
	test([]int{9, 7, 43, 11, 16, 111, 19}, "Asc", []int{7, 9, 11, 16, 19, 43, 111})
}

func sortarray(v []int, t string) []int {
	switch t {
	case "Asc":
		sort.Ints(v)
	case "Des":
		sort.Slice(v, func(i, j int) bool { return v[i] > v[j] })
	case "None":
	default:
		panic(fmt.Sprintf("invalid sort type %v", t))
	}
	return v
}

func test(a []int, t string, b []int) {
	sortarray(a, t)
	assert(len(a) == len(b))
	for i := range a {
		assert(a[i] == b[i])
	}
}

func assert(x bool) {
	if !x {
		panic("assertion failed")
	}
}
