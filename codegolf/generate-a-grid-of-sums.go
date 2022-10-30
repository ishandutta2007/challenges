/*

Generate a 7 by 7 grid, filled with random numbers. However, in cells with an odd row and column number (starting at 0), you must use the sum of the surrounding cells. Here's a small example with a 3 by 3 grid (sum-square bolded):

2 2  2
2 16 2
2 2  2

And here's an example 7 by 7 grid:

6 5  4 3  7 2  5
6 43 3 50 8 43 8
4 7  8 8  9 3  1
4 36 1 43 6 40 5
3 3  6 1  4 7  5
4 35 3 45 9 42 1
2 6  8 6  8 5  3

Rules

    Numbers that are not sums must always be between 1 and 9 inclusive.

    Grid must be randomly generated. For each non-sum, every digit must have an equal chance of appearing, regardless of which cell it is in.

    Numbers must be aligned. This means that either the first or last digit of each number in a column must line up vertically. (You may assume that the middle numbers will always be two digits.)

    Surrounding cells includes diagonals. Therefore, each sum square will have eight numbers surrounding it, which you must add.

    Shortest code wins, since this is code-golf.

*/

package main

import (
	"fmt"
	"math/rand"
	"time"
)

func main() {
	rand.Seed(time.Now().UnixNano())
	dump(gen(3))
	dump(gen(7))
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

func gen(n int) [][]int {
	m := randm(n)
	m = surround(m)
	return m
}

func randm(n int) [][]int {
	m := make([][]int, n)
	t := make([]int, n*n)
	for i := range m {
		m[i] = t[i*n : (i+1)*n]
	}

	for i := range m {
		for j := range m[i] {
			m[i][j] = 1 + rand.Intn(9)
		}
	}
	return m
}

func surround(m [][]int) [][]int {
	for i := range m {
		for j := range m[i] {
			if i&1 == 0 || j&1 == 0 {
				continue
			}

			m[i][j] = at(m, i-1, j-1)
			m[i][j] += at(m, i-1, j)
			m[i][j] += at(m, i-1, j+1)
			m[i][j] += at(m, i, j-1)
			m[i][j] += at(m, i, j+1)
			m[i][j] += at(m, i+1, j-1)
			m[i][j] += at(m, i+1, j)
			m[i][j] += at(m, i+1, j+1)
		}
	}
	return m
}

func at(m [][]int, i, j int) int {
	n := len(m)
	if i < 0 || i >= n || j < 0 || j >= n {
		return 0
	}
	return m[i][j]
}
