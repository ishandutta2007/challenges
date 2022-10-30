/*

This is a 2-dimensional version of this question.

Given a non-empty 2-dimensional array/matrix containing only non-negative integers:

Output the array with surrounding zeroes removed, i.e. the largest contiguous subarray without surrounding zeroes:

Examples:

Input:
[[0, 0, 0, 0, 0], [0, 0, 0, 1, 0], [0, 0, 0, 0, 1], [0, 0, 1, 1, 1], [0, 0, 0, 0, 0]]

Output:
[[0, 1, 0], [0, 0, 1], [1, 1, 1]]

Input:
[[0, 0, 0, 0], [0, 0, 0, 3], [0, 0, 0, 0], [0, 5, 0, 0], [0, 0, 0, 0]]

Output:
[[0, 0, 3], [0, 0, 0], [5, 0, 0]]

Input:
[[1, 2, 3], [4, 5, 6], [7, 8, 9]]

Output:
[[1, 2, 3], [4, 5, 6], [7, 8, 9]]

Input:
[[0, 0, 0, 0], [0, 0, 0, 0], [0, 0, 0, 0]]

Output:
[]

Input:
[[0, 0, 0, 0], [1, 1, 1, 1], [0, 0, 0, 0]]

Output:
[[1, 1, 1, 1]]

Input:
[[0, 1, 0, 0], [0, 1, 0, 0], [0, 1, 0, 0]]

Output:
[[1], [1], [1]]

Input:
[[1, 1, 1, 1], [1, 2, 3, 1], [1, 1, 1, 1]]

Output:
[[1, 1, 1, 1], [1, 2, 3, 1], [1, 1, 1, 1]]

*/

package main

import (
	"fmt"
	"math"
	"reflect"
)

func main() {
	test(
		[][]int{
			{0, 0, 0, 0, 0},
			{0, 0, 0, 1, 0},
			{0, 0, 0, 0, 1},
			{0, 0, 1, 1, 1},
			{0, 0, 0, 0, 0},
		},
		[][]int{{0, 1, 0}, {0, 0, 1}, {1, 1, 1}},
	)

	test(
		[][]int{
			{0, 0, 0, 0},
			{0, 0, 0, 3},
			{0, 0, 0, 0},
			{0, 5, 0, 0},
			{0, 0, 0, 0},
		},
		[][]int{
			{0, 0, 3},
			{0, 0, 0},
			{5, 0, 0},
		},
	)

	test(
		[][]int{{1, 2, 3}, {4, 5, 6}, {7, 8, 9}},
		[][]int{{1, 2, 3}, {4, 5, 6}, {7, 8, 9}},
	)

	test(
		[][]int{{0, 0, 0, 0}, {0, 0, 0, 0}, {0, 0, 0, 0}},
		[][]int{},
	)

	test(
		[][]int{{0, 0, 0, 0}, {1, 1, 1, 1}, {0, 0, 0, 0}},
		[][]int{{1, 1, 1, 1}},
	)

	test(
		[][]int{{0, 1, 0, 0}, {0, 1, 0, 0}, {0, 1, 0, 0}},
		[][]int{{1}, {1}, {1}},
	)

	test(
		[][]int{{1, 1, 1, 1}, {1, 2, 3, 1}, {1, 1, 1, 1}},
		[][]int{{1, 1, 1, 1}, {1, 2, 3, 1}, {1, 1, 1, 1}},
	)
}

func assert(x bool) {
	if !x {
		panic("assertion failed")
	}
}

func test(m, r [][]int) {
	p := rmz(m)
	fmt.Println(p)
	assert(reflect.DeepEqual(p, r))
}

func rmz(m [][]int) [][]int {
	x0 := math.MaxInt
	x1 := 0
	y0 := math.MaxInt
	y1 := 0
	for y := range m {
		for x := range m[y] {
			x0 = zmin(m[y][x], x0, x)
			x1 = zmax(m[y][x], x1, x)
			y0 = zmin(m[y][x], y0, y)
			y1 = zmax(m[y][x], y1, y)
		}
	}

	r := [][]int{}
	for y := y0; y <= y1; y++ {
		var p []int
		for x := x0; x <= x1; x++ {
			p = append(p, m[y][x])
		}
		r = append(r, p)
	}
	return r
}

func zmin(v, x, y int) int {
	if v == 0 || x < y {
		return x
	}
	return y
}

func zmax(v, x, y int) int {
	if v == 0 || x > y {
		return x
	}
	return y
}
