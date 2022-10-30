/*

Given the diagonals of a matrix, reconstruct the original matrix.
The diagonals parallel to the major diagonal (the main diagonals) will be given.
matrix image

Diagonals: [[5], [4, 10], [3, 9, 15], [2, 8, 14, 20], [1, 7, 13, 19, 25], [6, 12, 18, 24], [11, 17, 23], [16, 22], [21]]

Rules
The matrix will be non-empty and will consist of positive integers
You get to choose how the input diagonals will be given:
starting with the main diagonal and then alternating between the outer diagonals (moving outwards from the main diagonal)
from the top-right diagonal to the bottom-left diagonal
from the bottom-left diagonal to the top-right diagonal
The end matrix will always be a square
The order of the numbers in the diagonals should be from top-left to bottom-right
Input and output matrix can be flattened
This is code-golf, so the shortest answer wins

Test cases
[In]: [[5]]
[Out]: [[5]]

[In]: [[0], [1, 69], [13]]
[Out]: [[1, 0], [13, 69]]

[In]: [[25], [0, 1], [6, 23, 10], [420, 9], [67]]
[Out]: [[6, 0, 25], [420, 23, 1], [67, 9, 10]]

*/

package main

import (
	"fmt"
	"reflect"
)

func main() {
	test([][]int{
		{5},
		{4, 10},
		{3, 9, 15},
		{2, 8, 14, 20},
		{1, 7, 13, 19, 25},
		{6, 12, 18, 24},
		{11, 17, 23},
		{16, 22},
		{21},
	}, [][]int{
		{1, 2, 3, 4, 5},
		{6, 7, 8, 9, 10},
		{11, 12, 13, 14, 15},
		{16, 17, 18, 19, 20},
		{21, 22, 23, 24, 25},
	})

	test([][]int{
		{5},
	}, [][]int{
		{5},
	})

	test([][]int{
		{0},
		{1, 69},
		{13},
	}, [][]int{
		{1, 0},
		{13, 69},
	})

	test([][]int{
		{25},
		{0, 1},
		{6, 23, 10},
		{420, 9},
		{67},
	}, [][]int{
		{6, 0, 25},
		{420, 23, 1},
		{67, 9, 10},
	})
}

func assert(x bool) {
	if !x {
		panic("assertion failed")
	}
}

func test(a [][]int, r [][]int) {
	m := reconstruct(a)
	dump(m)
	assert(reflect.DeepEqual(m, r))
}

func reconstruct(a [][]int) [][]int {
	l := len(a) / 2
	n := len(a[l])
	m := alloc(n)

	j := 0
	for i := n - 1; i >= 0; i, j = i-1, j+1 {
		diag(m, a[j], 0, i)
	}
	for i := 1; i < n; i, j = i+1, j+1 {
		diag(m, a[j], i, 0)
	}

	return m
}

func alloc(n int) [][]int {
	m := make([][]int, n)
	for i := range m {
		m[i] = make([]int, n)
	}
	return m
}

func diag(m [][]int, a []int, r, c int) {
	for i := range a {
		m[r][c], r, c = a[i], r+1, c+1
	}
}

func dump(m [][]int) {
	for i := range m {
		for j := range m[i] {
			fmt.Printf("% 4d", m[i][j])
		}
		fmt.Println()
	}
	fmt.Println()
}
