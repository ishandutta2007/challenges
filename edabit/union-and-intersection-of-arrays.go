/*

Create a function takes in two arrays and returns an intersection array and a union array.

    Intersection Array: Elements shared by both.
    Union Array: Elements that exist in first or second array, or both (not exclusive OR).

While the input arrays may have duplicate numbers, the returned intersection and union arrays should be set-ified -
that is, contain no duplicates. Returned arrays should be sorted in ascending order.

Array 1: [5, 6, 6, 6, 8, 9]
Array 2: [3, 3, 4, 4, 5, 5, 8]

Intersection: [5, 8]
// 5 and 8 are the only 2 numbers that exist in both arrays.

Union: [3, 4, 5, 6, 8, 9]
// Each number exists in at least one array.

Examples

intersectionUnion([1, 2, 3, 4, 4], [4, 5, 9]) ➞ [[4], [1, 2, 3, 4, 5, 9]]

intersectionUnion([1, 2, 3], [4, 5, 6]) ➞ [[], [1, 2, 3, 4, 5, 6]]

intersectionUnion([1, 1], [1, 1, 1, 1]) ➞ [[1], [1]]

Notes

    Order of output should be: [Intersection], [Union].
    Remember both output arrays should be in ascending order.
    Each input array will have at least one element.
    If both arrays are disjoint (share nothing in common), return an empty array [] for the intersection.

*/

package main

import (
	"fmt"
	"reflect"
	"sort"
)

func main() {
	test([]int{1, 2, 3, 4, 4}, []int{4, 5, 9}, [2][]int{{4}, {1, 2, 3, 4, 5, 9}})
	test([]int{1, 2, 3}, []int{4, 5, 6}, [2][]int{{}, {1, 2, 3, 4, 5, 6}})
	test([]int{1, 1}, []int{1, 1, 1, 1}, [2][]int{{1}, {1}})
	test([]int{5}, []int{5, 6}, [2][]int{{5}, {5, 6}})
	test([]int{7, 8, 9, 6}, []int{9, 7, 6, 8}, [2][]int{{6, 7, 8, 9}, {6, 7, 8, 9}})
	test([]int{4, 1, 1, 2}, []int{1, 4, 4, 4, 4, 4, 4}, [2][]int{{1, 4}, {1, 2, 4}})
}

func test(a, b []int, r [2][]int) {
	p := iun(a, b)
	fmt.Println(p)
	for i := range p {
		if len(p[i]) == 0 {
			assert(len(p[i]) == len(r[i]))
		} else {
			assert(reflect.DeepEqual(p[i], r[i]))
		}
	}
}

func assert(x bool) {
	if !x {
		panic("assertion failed")
	}
}

func iun(a, b []int) [2][]int {
	m := make(map[int]int)
	for _, v := range a {
		m[v] = 1
	}
	for _, v := range b {
		m[v] |= 2
	}

	var p, q []int
	for k, v := range m {
		if v == 3 {
			p = append(p, k)
		}
		if v != 0 {
			q = append(q, k)
		}
	}

	sort.Ints(p)
	sort.Ints(q)

	return [2][]int{p, q}
}
