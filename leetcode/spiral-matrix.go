/*

Given an m x n matrix, return all elements of the matrix in spiral order.

Example 1:
Input: matrix = [[1,2,3],[4,5,6],[7,8,9]]
Output: [1,2,3,6,9,8,7,4,5]

Input: matrix = [[1,2,3,4],[5,6,7,8],[9,10,11,12]]
Output: [1,2,3,4,8,12,11,10,9,5,6,7]

Constraints:

m == matrix.length
n == matrix[i].length
1 <= m, n <= 10
-100 <= matrix[i][j] <= 100

*/

package main

import (
	"fmt"
	"reflect"
)

func main() {
	test([][]int{{1, 2, 3}, {4, 5, 6}, {7, 8, 9}}, []int{1, 2, 3, 6, 9, 8, 7, 4, 5})
	test([][]int{{1, 2, 3, 4}, {5, 6, 7, 8}, {9, 10, 11, 12}}, []int{1, 2, 3, 4, 8, 12, 11, 10, 9, 5, 6, 7})
	test([][]int{{1, 2, 3, 4}}, []int{1, 2, 3, 4})
	test([][]int{{1, 2}, {3, 4}}, []int{1, 2, 4, 3})
	test([][]int{{10}, {11}, {12}, {13}}, []int{10, 11, 12, 13})
	test([][]int{{1, 2, 3, 4}, {5, 6, 7, 8}}, []int{1, 2, 3, 4, 8, 7, 6, 5})
	test([][]int{{}}, []int{})
}

func assert(x bool) {
	if !x {
		panic("assertion failed")
	}
}

func test(m [][]int, r []int) {
	p := spiral(m)
	fmt.Println(p)
	assert(reflect.DeepEqual(p, r))
}

func spiral(m [][]int) []int {
	if len(m) == 0 || len(m[0]) == 0 {
		return []int{}
	}

	h := len(m)
	w := len(m[0])
	p := []int{}

	x0, x1 := 0, w-1
	y0, y1 := 0, h-1
	for x0 <= x1 && y0 <= y1 {
		for x, y := x0, y0; x <= x1; x++ {
			p = append(p, m[y][x])
		}

		for x, y := x1, y0+1; y <= y1; y++ {
			p = append(p, m[y][x])
		}

		for x, y := x1-1, y1; x >= x0 && y0 != y1; x-- {
			p = append(p, m[y][x])
		}

		for x, y := x0, y1-1; y > y0 && x0 != x1; y-- {
			p = append(p, m[y][x])
		}

		x0, y0 = x0+1, y0+1
		x1, y1 = x1-1, y1-1
	}
	return p
}
