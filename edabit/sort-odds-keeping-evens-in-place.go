/*

Write a function that sorts only the odd numbers in an array in ascending order, keeping the even numbers in their current place.

For example, if our input array is: [5, 2, 6, 6, 1, 4, 9, 3]:

[_, 2, 6, 6, _, 4, _, _]  // keep evens in place.

// Sort odds: [5, 1, 9, 3] => [1, 3, 5, 9]

[1, 2, 6, 6, 3, 4, 5, 9]  // final array.

Examples

oddSort([7, 5, 2, 3, 1]) ➞ [1, 3, 2, 5, 7]

oddSort([3, 7, 0, 9, 3, 2, 4, 8]) ➞ [3, 3, 0, 7, 9, 2, 4, 8]

oddSort([2, 2, 8, 4]) ➞ [2, 2, 8, 4]

oddSort([7, 9, 7]) ➞ [7, 7, 9]

Notes

Arrays may contain duplicate numbers.

*/

package main

import (
	"fmt"
	"reflect"
	"sort"
)

func main() {
	test([]int{5, 2, 6, 6, 1, 4, 9, 3}, []int{1, 2, 6, 6, 3, 4, 5, 9})
	test([]int{7, 9, 7}, []int{7, 7, 9})
	test([]int{1, 8, 4, 3, 2, 6, 7, 5}, []int{1, 8, 4, 3, 2, 6, 5, 7})
	test([]int{7, 5, 2, 3, 1}, []int{1, 3, 2, 5, 7})
	test([]int{2, 2, 9, 7, 4, 4, 4, 9}, []int{2, 2, 7, 9, 4, 4, 4, 9})
	test([]int{2, 2, 4, 0, 3, 1}, []int{2, 2, 4, 0, 1, 3})
	test([]int{2, 2, 8, 4}, []int{2, 2, 8, 4})
	test([]int{1, 9, 1}, []int{1, 1, 9})
}

func test(a, r []int) {
	p := oddsort(a)
	fmt.Println(p)
	assert(reflect.DeepEqual(p, r))
}

func assert(x bool) {
	if !x {
		panic("assertion failed")
	}
}

func oddsort(a []int) []int {
	t := make([]int, len(a))
	n := 0
	for i := range a {
		if a[i]&1 != 0 {
			t[n], n = a[i], n+1
		}
	}
	sort.Ints(t[:n])

	p := make([]int, len(a))
	for i, j := 0, 0; i < len(a); i++ {
		p[i] = a[i]
		if a[i]&1 != 0 {
			p[i], j = t[j], j+1
		}
	}
	return p
}
