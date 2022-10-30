/*

This challenge is to compute the most efficient multiplication order for a product of several matrices.

The size of the matrices is specified on a single line of standard input. You should print to standard output a list of integers indicating the order in which to do the multiplications to minimize the total multiplication cost.
example 1
input

5x6 6x12 12x100 100x7

output

3 2 1

The input line will be a space-separated list of matrix sizes, each of which is the number of rows, followed by an x, followed by the number of columns. For the example, there are 4 matrices to multiply together (so 3 total multiplications), and since matrix multiplication is associative they can be done in any order.

The output should be the order in which to perform the multiplications to minimize total cost. This should be a space-separated list of integers representing the index of the multiplication to perform next. For N matrices, this list should contain the numbers 1 through N-1, inclusive. For example 1, the output 3 2 1 means you should do the 12x100 * 100x7 multiplication first, then the 6x12 * 12x7 multiplication (the second matrix times the result of the previous step), then finally the resulting 5x6 * 6x7 multiplication.

The matrix multiplications will always be compatible, i.e. the number of columns of a matrix will match the number of rows of the subsequent matrix. Assume the cost of multiplying two matrices AxB * BxC is A*B*C.

Your code must handle lists of up to 100 matrices, each of dimension up to 999, and do so in a reasonable time.
example 2
input

5x10 10x5 5x15 15x5

output

1 3 2

or

3 1 2

example 3
input

22x11 11x78 78x123 123x666 666x35 35x97 97x111 111x20 20x50

output

2 3 4 5 6 7 8 1

Note: for verification, the best total cost for the three examples is 9114, 750, and 1466344.

Shortest code wins!

*/

package main

import (
	"fmt"
	"math"
	"reflect"
)

func main() {
	test([]int{1, 2, 3}, []int{1})
	test([]int{10, 30, 5, 60}, []int{1, 2})
	test([]int{40, 20, 30, 10, 30}, []int{2, 3, 1})
	test([]int{10, 20, 30, 40, 30}, []int{1, 2, 3})
	test([]int{10, 20, 30}, []int{1})
	test([]int{5, 6, 12, 100, 7}, []int{3, 2, 1})
	test([]int{5, 10, 5, 15, 5}, []int{1, 2, 3})
	test([]int{22, 11, 78, 123, 666, 35, 97, 111, 20, 50}, []int{2, 3, 4, 5, 6, 7, 8, 1})
}

func test(d, r []int) {
	c, p := matorder(d)
	fmt.Println(c, p)
	assert(reflect.DeepEqual(p, r))
}

func assert(x bool) {
	if !x {
		panic("assertion failed")
	}
}

// https://en.wikipedia.org/wiki/Matrix_chain_multiplication
func matchain(d []int) (m, s [][]int) {
	n := len(d) - 1
	if n <= 0 {
		return
	}

	m = make([][]int, n)
	s = make([][]int, n)
	for i := range m {
		m[i] = make([]int, n)
		s[i] = make([]int, n)
	}

	for l := 1; l < n; l++ {
		for i := 0; i < n-l; i++ {
			j := i + l
			m[i][j] = math.MaxInt
			for k := i; k < j; k++ {
				c := m[i][k] + m[k+1][j] + d[i]*d[k+1]*d[j+1]
				if c < m[i][j] {
					m[i][j] = c
					s[i][j] = k
				}
			}
		}
	}
	return
}

func matorderrec(s [][]int, i, j int, b []bool, r *[]int) {
	if i == j {
		return
	}
	matorderrec(s, i, s[i][j], b, r)
	matorderrec(s, s[i][j]+1, j, b, r)
	if !b[i] && i+1 < len(s) {
		*r = append(*r, i+1)
	}
	if !b[j] && j+1 < len(s) {
		*r = append(*r, j+1)
	}
	b[i], b[j] = true, true
}

func matorder(d []int) (c int, r []int) {
	n := len(d)
	if n < 2 {
		return
	}
	m, s := matchain(d)
	b := make([]bool, n)
	matorderrec(s, 0, n-2, b, &r)
	return m[0][n-2], r
}
