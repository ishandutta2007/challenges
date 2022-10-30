/*

An identity matrix is defined as a square matrix with 1s running from the top left of the square to the bottom right. The rest are 0s.
The identity matrix has applications ranging from machine learning to the general theory of relativity.

Create a function that takes an integer n and returns the identity matrix of n x n dimensions.
For this challenge, if the integer is negative, return the mirror image of the identity matrix of n x n dimensions.
It does not matter if the mirror image is left-right or top-bottom.

Examples

id_mtrx(2) ➞ [
  [1, 0],
  [0, 1]
]

id_mtrx(-2) ➞ [
  [0, 1],
  [1, 0]
]

id_mtrx(0) ➞ []

Notes

Incompatible types passed as n should return the string "Error".

*/

package main

import (
	"reflect"
)

func main() {
	m1 := [][]int{
		{1},
	}
	m2 := [][]int{
		{1, 0},
		{0, 1},
	}
	m3 := [][]int{
		{1, 0, 0},
		{0, 1, 0},
		{0, 0, 1},
	}
	m4 := [][]int{
		{1, 0, 0, 0},
		{0, 1, 0, 0},
		{0, 0, 1, 0},
		{0, 0, 0, 1},
	}
	m5 := [][]int{
		{0, 0, 0, 0, 0, 1},
		{0, 0, 0, 0, 1, 0},
		{0, 0, 0, 1, 0, 0},
		{0, 0, 1, 0, 0, 0},
		{0, 1, 0, 0, 0, 0},
		{1, 0, 0, 0, 0, 0},
	}

	test(m1, 1)
	test(m2, 2)
	test(m3, 3)
	test(m4, 4)
	test(m5, -6)
}

func test(r [][]int, n int) {
	m := make([][]int, len(r))
	for i := range m {
		m[i] = make([]int, len(r))
	}
	identity(m, n)
	assert(reflect.DeepEqual(m, r))
}

func assert(x bool) {
	if !x {
		panic("assertion failed")
	}
}

func identity(m [][]int, n int) {
	f := false
	if n < 0 {
		n = -n
		f = true
	}

	for i := 0; i < n; i++ {
		for j := 0; j < n; j++ {
			m[i][j] = 0
		}

		if !f {
			m[i][i] = 1
		} else {
			m[i][n-i-1] = 1
		}
	}
}
