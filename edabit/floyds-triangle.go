/*

Floyd's triangle is a right-angled triangular array of natural numbers. It's defined by filling the rows of the triangle with consecutive numbers, starting with a 1 in the top left corner:

Floyd's triangle

Write a function that takes an integer n and returns Floyd's triangle's rows as a list of lists. Your function should return one of two possibilities:

    If a value is passed to n_row, return the first n rows.
    If a value is passed to up_to, return all rows up to, and including, the row that contains n.

Expect an argument to be passed to one parameter or the other, but not both.

Examples

floyd(up_to = 5) ➞ [[1], [2, 3], [4, 5, 6]]
# The third row contains a 5.

floyd(n_row = 5) ➞[[1], [2, 3], [4, 5, 6], [7, 8, 9, 10], [11, 12, 13, 14, 15]]
# Returns the first five rows.

floyd(up_to = 10) ➞ [[1], [2, 3], [4, 5, 6], [7, 8, 9, 10]]

floyd(n_row = 1) ➞[[1]]

Notes

Hint: You can define n_row from up_to using the triangular number sequence. That is, n_row should be x in the equation (x*(x+1))/2 = up_to rounded up. Then, you only need to write a function for n_row.

*/

package main

import (
	"math"
	"reflect"
)

func main() {
	test(floydu(1), [][]int{{1}})
	test(floydu(2), [][]int{{1}, {2, 3}})
	test(floydu(7), [][]int{{1}, {2, 3}, {4, 5, 6}, {7, 8, 9, 10}})
	test(floydu(9), [][]int{{1}, {2, 3}, {4, 5, 6}, {7, 8, 9, 10}})
	test(floydu(15), [][]int{{1}, {2, 3}, {4, 5, 6}, {7, 8, 9, 10}, {11, 12, 13, 14, 15}})
	test(floydu(50), [][]int{{1}, {2, 3}, {4, 5, 6}, {7, 8, 9, 10}, {11, 12, 13, 14, 15}, {16, 17, 18, 19, 20, 21}, {22, 23, 24, 25, 26, 27, 28}, {29, 30, 31, 32, 33, 34, 35, 36}, {37, 38, 39, 40, 41, 42, 43, 44, 45}, {46, 47, 48, 49, 50, 51, 52, 53, 54, 55}})

	test(floydr(1), [][]int{{1}})
	test(floydr(2), [][]int{{1}, {2, 3}})
	test(floydr(5), [][]int{{1}, {2, 3}, {4, 5, 6}, {7, 8, 9, 10}, {11, 12, 13, 14, 15}})
	test(floydr(6), [][]int{{1}, {2, 3}, {4, 5, 6}, {7, 8, 9, 10}, {11, 12, 13, 14, 15}, {16, 17, 18, 19, 20, 21}})
	test(floydr(11), [][]int{{1}, {2, 3}, {4, 5, 6}, {7, 8, 9, 10}, {11, 12, 13, 14, 15}, {16, 17, 18, 19, 20, 21}, {22, 23, 24, 25, 26, 27, 28}, {29, 30, 31, 32, 33, 34, 35, 36}, {37, 38, 39, 40, 41, 42, 43, 44, 45}, {46, 47, 48, 49, 50, 51, 52, 53, 54, 55}, {56, 57, 58, 59, 60, 61, 62, 63, 64, 65, 66}})
}

func test(x, y [][]int) {
	assert(reflect.DeepEqual(x, y))
}

func assert(x bool) {
	if !x {
		panic("assertion failed")
	}
}

func floydr(r int) [][]int {
	var p [][]int
	for i, k := 1, 1; i <= r; i++ {
		q := make([]int, i)
		for j := range q {
			q[j], k = k, k+1
		}
		p = append(p, q)
	}
	return p
}

func floydu(u int) [][]int {
	r, ok := quadratic(1, 1, -2*float64(u))
	if !ok {
		return nil
	}
	n := int(math.Ceil(r[0]))
	return floydr(n)
}

func quadratic(a, b, c float64) ([2]float64, bool) {
	var r [2]float64
	d := b*b - 4*a*c
	if d < 0 {
		return r, false
	}

	s := math.Sqrt(d)
	r[0] = (-b + s) / (2 * a)
	r[1] = (-b - s) / (2 * a)
	return r, true
}
