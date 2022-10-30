/*

In this challenge you will be given an array similar to the following:

[[3], 4, [2], [5], 1, 6]

In words, elements of the array are either an integer or an array containing a single integer. We humans can clearly see that this array can reasonably be sorted according to "the content of the elements" as:

[1, [2], [3], 4, [5], 6]

Create a function that, given an array similar to the above, sorts the array according to the "content of the elements".
Examples

sortIt([4, 1, 3]) ➞ [1, 3, 4]

sortIt([[4], [1], [3]]) ➞ [[1], [3], [4]]

sortIt([4, [1], 3]) ➞ [[1], 3, 4]

sortIt([[4], 1, [3]]) ➞ [1, [3], [4]]

sortIt([[3], 4, [2], [5], 1, 6]) ➞ [1, [2], [3], 4, [5], 6]

Notes

To reiterate, elements of the array will be either integers or arrays with a single integer.

*/

package main

import (
	"reflect"
	"sort"
)

type any []interface{}

func main() {
	eq(sorti(any{4, 1, 3}), any{1, 3, 4})
	eq(sorti(any{[]int{4}, []int{1}, []int{3}}), any{[]int{1}, []int{3}, []int{4}})
	eq(sorti(any{4, []int{1}, 3}), any{[]int{1}, 3, 4})
	eq(sorti(any{[]int{4}, 1, []int{3}}), any{1, []int{3}, []int{4}})
	eq(sorti(any{[]int{3}, 4, []int{2}, []int{5}, 1, 6}), any{1, []int{2}, []int{3}, 4, []int{5}, 6})
	eq(sorti(any{[]int{3}, 7, []int{9}, []int{5}, 1, 6}), any{1, []int{3}, []int{5}, 6, 7, []int{9}})
	eq(sorti(any{[]int{3}, 7, []int{9}, []int{5}, 1, 6, []int{0}}), any{[]int{0}, 1, []int{3}, []int{5}, 6, 7, []int{9}})
}

func sorti(a any) any {
	sort.Slice(a, func(i, j int) bool {
		x, xi := a[i].(int)
		y, yi := a[j].(int)
		p, pi := a[i].([]int)
		q, qi := a[j].([]int)

		if pi {
			sort.Ints(p)
		}
		if qi {
			sort.Ints(q)
		}

		switch {
		case xi && yi:
			return x < y
		case xi && qi:
			return x < q[0]
		case pi && yi:
			return p[0] < y
		case pi && qi:
			return p[0] < q[0]
		}
		return false
	})
	return a
}

func eq(a, b any) {
	assert(reflect.DeepEqual(a, b))
}

func assert(x bool) {
	if !x {
		panic("assertion failed")
	}
}
