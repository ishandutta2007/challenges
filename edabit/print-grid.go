/*

Write a method that accepts two integer parameters rows and cols.
The output is a 2d array of numbers displayed in column-major order,
meaning the numbers shown increase sequentially down each column and wrap
to the top of the next column to the right once the bottom of the current column is reached.

Examples

printGrid(3, 6) ➞ [
  [1, 4, 7, 10, 13, 16],
  [2, 5, 8, 11, 14, 17],
  [3, 6, 9, 12, 15, 18]
]

printGrid(5, 3) ➞ [
  [1, 6, 11],
  [2, 7, 12],
  [3, 8, 13],
  [4, 9, 14],
  [5, 10, 15]
]

printGrid(4, 1) ➞ [
  [1],
  [2],
  [3],
  [4]
]

Notes

N/A

*/

package main

import (
	"fmt"
	"reflect"
)

func main() {
	test(3, 6, [][]int{{1, 4, 7, 10, 13, 16}, {2, 5, 8, 11, 14, 17}, {3, 6, 9, 12, 15, 18}})
	test(5, 3, [][]int{{1, 6, 11}, {2, 7, 12}, {3, 8, 13}, {4, 9, 14}, {5, 10, 15}})
	test(4, 1, [][]int{{1}, {2}, {3}, {4}})
	test(1, 3, [][]int{{1, 2, 3}})
	test(10, 2, [][]int{{1, 11}, {2, 12}, {3, 13}, {4, 14}, {5, 15}, {6, 16}, {7, 17}, {8, 18}, {9, 19}, {10, 20}})
}

func test(r, c int, q [][]int) {
	p := grid(r, c)
	fmt.Println(p)
	assert(reflect.DeepEqual(p, q))
}

func assert(x bool) {
	if !x {
		panic("assertion failed")
	}
}

func grid(r, c int) [][]int {
	p := make([][]int, r)
	q := make([]int, r*c)
	for i := range p {
		p[i] = q[i*c : (i+1)*c]
	}

	n := 1
	for x := 0; x < c; x++ {
		for y := 0; y < r; y++ {
			p[y][x], n = n, n+1
		}
	}

	return p
}
