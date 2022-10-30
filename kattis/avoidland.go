/*

Avoidland is a puzzle played on an n×n board with n pawns.
The pawns are initially placed on the squares of the board, at most one pawn per square.
The goal is to move the pawns so that they “avoid” each other—there cannot be a row or a column with more than one pawn.
In one move a pawn can move to a neighboring unoccupied square, that is, a square that shares a side with the pawn’s current location and there is no pawn on it.
Given the initial locations of the pawns, what is the minimum number of moves needed to solve the puzzle?

Input

The first line contains an integer n, then n lines follow.
The i-th line contains the initial row and column coordinates of the i-th pawn, separated by space.
Each coordinate is an integer between 1 and n. You may assume that n is at most 1000000.

Output

The line contains the minimum number of moves needed to solve the puzzle.

*/

package main

import (
	"image"
	"sort"
)

func main() {
	assert(moves([]image.Point{
		{1, 3},
		{2, 3},
		{3, 1},
	}) == 1)

	assert(moves([]image.Point{
		{1, 4},
		{4, 1},
		{1, 1},
		{4, 4},
	}) == 4)
}

func assert(x bool) {
	if !x {
		panic("assertion failed")
	}
}

func moves(p []image.Point) int {
	sort.Slice(p, func(i, j int) bool { return p[i].X < p[j].X })
	r := 0
	for i := range p {
		r += abs(i + 1 - p[i].X)
	}

	sort.Slice(p, func(i, j int) bool { return p[i].Y < p[j].Y })
	for i := range p {
		r += abs(i + 1 - p[i].Y)
	}

	return r
}

func abs(x int) int {
	if x < 0 {
		x = -x
	}
	return x
}
