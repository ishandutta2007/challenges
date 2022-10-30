/*

Originally from a CMC I proposed for the last BMG event

Challenge

Given a non-negative integer n, create a 2D array of size 2n×2n

which is generated in the following manner:

    Divide the matrix into four quadrants of size 2n−1×2n−1.
    Visiting order of the four quadrants is defined to be the Z-shape (top-left, top-right, bottom-left, then bottom-right).
    Recursively apply the ordering (steps 1-2) to each quadrant, until the ordering is defined for each cell in the matrix.
    Visit each cell in the defined order, sequentially writing down 0, 1, 2, 3, ... to each cell.

You can output 1-based instead of 0-based (add 1 to all cells in the examples below).

Standard code-golf rules apply. The shortest code in bytes wins.

Examples

n = 0:
[[0]]

n = 1:
[[0, 1],
 [2, 3]]

n = 2:
[[0,  1,  4,  5],
 [2,  3,  6,  7],
 [8,  9,  12, 13],
 [10, 11, 14, 15]]

n = 3:
[[0,  1,  4,  5,  16, 17, 20, 21],
 [2,  3,  6,  7,  18, 19, 22, 23],
 [8,  9,  12, 13, 24, 25, 28, 29],
 [10, 11, 14, 15, 26, 27, 30, 31],
 [32, 33, 36, 37, 48, 49, 52, 53],
 [34, 35, 38, 39, 50, 51, 54, 55],
 [40, 41, 44, 45, 56, 57, 60, 61],
 [42, 43, 46, 47, 58, 59, 62, 63]]

Brownie points for beating or tying with my 9 6 bytes in Jelly or 19 bytes in J.

*/

package main

import (
	"fmt"
	"math/bits"
)

func main() {
	for i := 0; i <= 3; i++ {
		dump(zmatrix(i))
	}
}

func dump(m [][]int) {
	for i := range m {
		for j := range m[i] {
			fmt.Printf("%2d ", m[i][j])
		}
		fmt.Println()
	}
	fmt.Println()
}

func zmatrix(n int) [][]int {
	if n < 0 {
		return nil
	}
	m := zeros(1 << n)
	fill(m)
	return m
}

func fill(m [][]int) {
	for y := range m {
		for x := range m[y] {
			m[y][x] = morton(x, y)
		}
	}
}

func zeros(n int) [][]int {
	m := make([][]int, n)
	p := make([]int, n*n)
	for i := 0; i < n; i++ {
		m[i] = p[i*n : (i+1)*n]
	}
	return m
}

// https://en.wikipedia.org/wiki/Z-order_curve
func morton(x, y int) int {
	z := 0
	for i := 0; i < bits.UintSize; i++ {
		z |= (x&(1<<i))<<i | (y&(1<<i))<<(i+1)
	}
	return z
}
