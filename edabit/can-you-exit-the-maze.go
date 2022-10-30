/*

A maze can be represented by a 2D matrix, where 0s represent walkeable areas, and 1s represent walls.
You start on the upper left corner and the exit is on the most lower right cell.

Create a function that returns true if you can walk from one end of the maze to the other.
You can only move up, down, left and right. You cannot move diagonally.

Notes

In a maze of size m x n, you enter at [0, 0] and exit at [m-1, n-1].
There can be dead ends in a maze - one exit path is sufficient.

*/

package main

import "fmt"

func main() {
	fmt.Println(canexit([][]int{
		{0, 1, 1, 1, 1, 1, 1},
		{0, 0, 1, 1, 0, 1, 1},
		{1, 0, 0, 0, 0, 1, 1},
		{1, 1, 1, 1, 0, 0, 1},
		{1, 1, 1, 1, 1, 0, 0},
	}))

	fmt.Println(canexit([][]int{
		{0, 1, 1, 1, 1, 1, 1},
		{0, 0, 1, 0, 0, 1, 1},
		{1, 0, 0, 0, 0, 1, 1},
		{1, 1, 0, 1, 0, 0, 1},
		{1, 1, 0, 0, 1, 1, 1},
	}))

	fmt.Println(canexit([][]int{
		{0, 1, 1, 1, 1, 0, 0},
		{0, 0, 0, 0, 1, 0, 0},
		{1, 1, 1, 0, 0, 0, 0},
		{1, 1, 1, 1, 1, 1, 0},
		{1, 1, 1, 1, 1, 1, 1},
	}))

	fmt.Println(canexit([][]int{
		{0, 1, 1, 1, 1, 0, 0},
		{0, 0, 0, 0, 1, 0, 0},
		{1, 1, 1, 0, 0, 0, 0},
		{1, 0, 0, 0, 1, 1, 0},
		{1, 1, 1, 1, 1, 1, 0},
	}))

	fmt.Println(canexit([][]int{
		{0, 1, 1, 1, 1, 0, 0},
		{0, 0, 0, 0, 1, 0, 0},
		{1, 1, 1, 0, 0, 0, 0},
		{1, 0, 0, 0, 0, 1, 1},
		{1, 1, 1, 1, 0, 0, 0},
	}))

	fmt.Println(canexit([][]int{
		{0, 1, 1, 1, 1, 0, 1},
		{0, 0, 0, 0, 1, 0, 1},
		{1, 1, 1, 0, 0, 0, 1},
		{1, 0, 0, 0, 0, 1, 1},
		{1, 1, 1, 1, 0, 1, 1},
	}))

	fmt.Println(canexit([][]int{
		{0, 0, 0, 0, 0, 0, 0},
		{0, 0, 0, 0, 1, 0, 0},
		{1, 1, 1, 0, 0, 0, 0},
		{1, 0, 0, 0, 0, 1, 0},
		{1, 1, 1, 1, 0, 1, 0},
	}))

	fmt.Println(canexit([][]int{
		{0, 0, 0, 0, 0, 0, 0},
		{0, 1, 1, 1, 1, 1, 0},
		{0, 1, 1, 1, 1, 1, 0},
		{0, 1, 1, 1, 1, 1, 0},
		{0, 0, 0, 0, 0, 0, 1},
	}))

	fmt.Println(canexit([][]int{
		{0, 0, 1, 1, 1, 1, 1},
		{1, 0, 0, 1, 1, 1, 1},
		{1, 1, 0, 0, 1, 1, 1},
		{1, 1, 1, 0, 0, 0, 0},
		{1, 1, 1, 1, 1, 1, 0},
	}))

	fmt.Println(canexit([][]int{
		{0, 0, 0, 0, 0, 0, 0},
		{0, 1, 1, 1, 1, 1, 0},
		{0, 1, 1, 1, 1, 1, 0},
		{0, 1, 1, 1, 1, 1, 1},
		{0, 0, 0, 0, 0, 1, 0},
	}))

	fmt.Println(canexit([][]int{
		{0, 1, 0, 0, 0, 0, 0},
		{0, 1, 1, 1, 1, 1, 0},
		{0, 1, 1, 1, 1, 1, 0},
		{0, 1, 1, 1, 1, 1, 0},
		{0, 0, 0, 0, 0, 1, 0},
	}))
}

func canexit(M [][]int) bool {
	if len(M) == 0 || len(M[0]) == 0 {
		return false
	}

	N := make([][]int, len(M))
	for i := range N {
		N[i] = append(N[i], M[i]...)
	}
	traverse(0, 0, N)
	return N[0][0] == -1 && N[len(N)-1][len(N[0])-1] == -1
}

func traverse(r, c int, M [][]int) {
	if r < 0 || c < 0 || r >= len(M) || c >= len(M[0]) {
		return
	}
	if M[r][c] != 0 {
		return
	}
	if M[0][0] == -1 && M[len(M)-1][len(M[0])-1] == -1 {
		return
	}
	M[r][c] = -1

	traverse(r+1, c, M)
	traverse(r-1, c, M)
	traverse(r, c-1, M)
	traverse(r, c+1, M)
}
