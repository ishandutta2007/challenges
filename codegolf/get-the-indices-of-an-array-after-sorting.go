/*

Your challenge today is to write a program or function which takes a list l and gives the positions in l at which each successive element of l sorted appears.

In other words, output the index of the smallest value, followed by the index of the second smallest value, etc.

You can assume that the input array will contain only positive integers, and will contain at least one element.

Test cases:

Input                  | Output (1-indexed)
[7, 4, 5]              | [2, 3, 1]
[1, 2, 3]              | [1, 2, 3]
[2, 6, 1, 9, 1, 2, 3]  | [3, 5, 1, 6, 7, 2, 4]
[4]                    | [1]

When two or more elements with the same value appear, their indices should appear next to each other from smallest to largest.

This is code-golf, fewest bytes wins!

*/

package main

import (
	"fmt"
	"reflect"
	"sort"
)

func main() {
	test([]int{7, 4, 5}, []int{2, 3, 1})
	test([]int{1, 2, 3}, []int{1, 2, 3})
	test([]int{2, 6, 1, 9, 1, 2, 3}, []int{3, 5, 1, 6, 7, 2, 4})
	test([]int{4}, []int{1})
}

func test(a, r []int) {
	p := indexsort(a)
	fmt.Println(p)
	assert(reflect.DeepEqual(p, r))
}

func assert(x bool) {
	if !x {
		panic("assertion failed")
	}
}

func indexsort(a []int) []int {
	p := make([][2]int, len(a))
	for i := range p {
		p[i][0] = i + 1
		p[i][1] = a[i]
	}

	sort.SliceStable(p, func(i, j int) bool {
		return p[i][1] < p[j][1]
	})

	r := make([]int, len(a))
	for i := range r {
		r[i] = p[i][0]
	}
	return r
}
