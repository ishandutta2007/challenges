/*

A numbers factor length is simply its total number of factors.

For instance:

3: 1, 3
// 3's factor length = 2

8: 1, 2, 4, 8
// 8's factor length = 4

36 : 1, 2, 3, 4, 6, 9, 12, 18, 36
// 36's factor length = 9

Create a function that sorts an array by factor length in descending order. If multiple numbers have the same factor length, sort these numbers in descending order, with the largest first.

In the example below, since 13 and 7 both have only 2 factors, we put 13 ahead of 7.

factorSort([9, 7, 13, 12]) ➞ [12, 9, 13, 7]
// 12 : 6, 9: 3, 13: 2, 7: 2

Examples

factorSort([1, 2, 31, 4]) ➞ [4, 31, 2, 1]

factorSort([5, 7, 9]) ➞ [9, 7, 5]

factorSort([15, 8, 2, 3]) ➞ [15, 8, 3, 2]

Notes

Descending order: numbers with a higher factor length go before numbers with a lower factor length.

*/

package main

import (
	"fmt"
	"reflect"
	"sort"
)

func main() {
	test([]uint64{1, 2, 31, 4}, []uint64{4, 31, 2, 1})
	test([]uint64{5, 7, 9}, []uint64{9, 7, 5})
	test([]uint64{15, 8, 2, 3}, []uint64{15, 8, 3, 2})
	test([]uint64{1, 2, 3, 7, 11, 13, 16}, []uint64{16, 13, 11, 7, 3, 2, 1})
	test([]uint64{1, 5, 25, 17}, []uint64{25, 17, 5, 1})
	test([]uint64{1, 5, 4, 17}, []uint64{4, 17, 5, 1})
}

func test(p, r []uint64) {
	u := factorsort(p)
	fmt.Println(u)
	assert(reflect.DeepEqual(u, r))
}

func assert(x bool) {
	if !x {
		panic("assertion failed")
	}
}

func factorsort(p []uint64) []uint64 {
	r := make([][2]uint64, len(p))
	for i := range p {
		r[i][0] = p[i]
		r[i][1] = factors(p[i])
	}
	sort.Slice(r, func(i, j int) bool {
		if r[i][1] > r[j][1] {
			return true
		}
		if r[i][1] == r[j][1] {
			return r[i][0] > r[j][0]
		}
		return false
	})

	u := make([]uint64, len(p))
	for i := range u {
		u[i] = r[i][0]
	}
	return u
}

func factors(n uint64) uint64 {
	if n <= 1 {
		return 1
	}
	r := uint64(1)
	for i := uint64(2); i <= n; i++ {
		if n%i == 0 {
			r++
		}
	}
	return r
}
