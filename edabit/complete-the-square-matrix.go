/*

Sadly, the mathematical world is biased in favor of square matrices. As such, this challenge will help rectangular matrices by making them square.

For example, for the matrix:

[
  [1, 2],
  [3, 4],
  [5, 6]
]

This can be done by padding it with a column of zeroes on the right to get:

[
  [1, 2, 0],
  [3, 4, 0],
  [5, 6, 0]
]

While for the matrix:

[
  [1, 2, 3, 4],
  [5, 6, 7, 8]
]

One can pad it with two rows of zeros at the bottom to get:

[
  [1, 2, 3, 4],
  [5, 6, 7, 8],
  [0, 0, 0, 0],
  [0, 0, 0, 0]
]

Write a function that pads a rectangular matrix with zeros on the right or at the bottom to make it square.
Examples

completeSquare([
  [2, 5]
]) ➞ [
  [2, 5],
  [0, 0]
]

completeSquare([
  [2, 5],
  [1, 7]
]) ➞ [
  [2, 5],
  [1, 7]
]

completeSquare([
  [1, 2],
  [3, 4],
  [5, 6]
 ]) ➞ [
  [1, 2, 0],
  [3, 4, 0],
  [5, 6, 0]
]

Notes

    Matrices should be padded on the right or at the bottom, but not both simultaneously (i.e. the size of the biggest direction shouldn't change).
    If the input is already a square matrix, just return that matrix.

*/

package main

import "reflect"

func main() {
	m1 := [][]int{
		{2, 5},
	}
	r1 := [][]int{
		{2, 5},
		{0, 0},
	}

	m2 := [][]int{
		{2, 5},
		{1, 7},
	}
	r2 := [][]int{
		{2, 5},
		{1, 7},
	}

	m3 := [][]int{
		{1, 2},
		{3, 4},
		{5, 6},
	}
	r3 := [][]int{
		{1, 2, 0},
		{3, 4, 0},
		{5, 6, 0},
	}

	m4 := [][]int{
		{1, 2, 3, 4},
		{5, 6, 7, 8},
	}
	r4 := [][]int{
		{1, 2, 3, 4},
		{5, 6, 7, 8},
		{0, 0, 0, 0},
		{0, 0, 0, 0},
	}

	m5 := [][]int{
		{1, 2, 3, 2, 1},
		{5, 6, 7, 6, 5},
	}
	r5 := [][]int{
		{1, 2, 3, 2, 1},
		{5, 6, 7, 6, 5},
		{0, 0, 0, 0, 0},
		{0, 0, 0, 0, 0},
		{0, 0, 0, 0, 0},
	}

	m6 := [][]int{
		{1, 8, 9},
		{3, 6, 7},
		{5, 4, 5},
		{7, 2, 3},
		{9, 0, 1},
	}
	r6 := [][]int{
		{1, 8, 9, 0, 0},
		{3, 6, 7, 0, 0},
		{5, 4, 5, 0, 0},
		{7, 2, 3, 0, 0},
		{9, 0, 1, 0, 0},
	}

	test(m1, r1)
	test(m2, r2)
	test(m3, r3)
	test(m4, r4)
	test(m5, r5)
	test(m6, r6)
}

func test(m, r [][]int) {
	p := squarize(m)
	assert(reflect.DeepEqual(p, r))
}

func assert(x bool) {
	if !x {
		panic("assertion failed")
	}
}

func squarize(m [][]int) [][]int {
	n := max(len(m), len(m[0]))
	p := make([][]int, n)
	for i := range p {
		p[i] = make([]int, n)
	}
	for i := range m {
		copy(p[i], m[i])
	}
	return p
}

func max(a, b int) int {
	if a > b {
		return a
	}
	return b
}
