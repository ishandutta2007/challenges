/*

Given a number n, return an array containing several arrays. Each array increment in size, from range 1 to n inclusive, contaning its length as the elements.

Examples

pyramidArrays(1) ➞ [[1]]

pyramidArrays(3) ➞ [[1], [2, 2], [3, 3, 3]]

pyramidArrays(5) ➞ [[1], [2, 2], [3, 3, 3], [4, 4, 4, 4], [5, 5, 5, 5, 5]]

Notes

n will be a positive integer.

*/

package main

import (
	"fmt"
	"reflect"
)

func main() {
	test(1, [][]uint{{1}})
	test(2, [][]uint{{1}, {2, 2}})
	test(3, [][]uint{{1}, {2, 2}, {3, 3, 3}})
	test(4, [][]uint{{1}, {2, 2}, {3, 3, 3}, {4, 4, 4, 4}})
	test(5, [][]uint{{1}, {2, 2}, {3, 3, 3}, {4, 4, 4, 4}, {5, 5, 5, 5, 5}})
	test(6, [][]uint{{1}, {2, 2}, {3, 3, 3}, {4, 4, 4, 4}, {5, 5, 5, 5, 5}, {6, 6, 6, 6, 6, 6}})
	test(7, [][]uint{{1}, {2, 2}, {3, 3, 3}, {4, 4, 4, 4}, {5, 5, 5, 5, 5}, {6, 6, 6, 6, 6, 6}, {7, 7, 7, 7, 7, 7, 7}})
	test(8, [][]uint{{1}, {2, 2}, {3, 3, 3}, {4, 4, 4, 4}, {5, 5, 5, 5, 5}, {6, 6, 6, 6, 6, 6}, {7, 7, 7, 7, 7, 7, 7}, {8, 8, 8, 8, 8, 8, 8, 8}})
	test(9, [][]uint{{1}, {2, 2}, {3, 3, 3}, {4, 4, 4, 4}, {5, 5, 5, 5, 5}, {6, 6, 6, 6, 6, 6}, {7, 7, 7, 7, 7, 7, 7}, {8, 8, 8, 8, 8, 8, 8, 8}, {9, 9, 9, 9, 9, 9, 9, 9, 9}})
	test(10, [][]uint{{1}, {2, 2}, {3, 3, 3}, {4, 4, 4, 4}, {5, 5, 5, 5, 5}, {6, 6, 6, 6, 6, 6}, {7, 7, 7, 7, 7, 7, 7}, {8, 8, 8, 8, 8, 8, 8, 8}, {9, 9, 9, 9, 9, 9, 9, 9, 9}, {10, 10, 10, 10, 10, 10, 10, 10, 10, 10}})
}

func test(n uint, r [][]uint) {
	p := pyramid(n)
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

func pyramid(n uint) [][]uint {
	p := make([][]uint, n)
	for i := uint(1); i <= n; i++ {
		q := make([]uint, i)
		for j := uint(0); j < i; j++ {
			q[j] = i
		}
		p[i-1] = q
	}
	return p
}
