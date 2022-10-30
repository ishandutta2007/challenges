/*

Description

A 3x3 magic square is a 3x3 grid of the numbers 1-9 such that each row, column, and major diagonal adds up to 15. Here's an example:

8 1 6
3 5 7
4 9 2

The major diagonals in this example are 8 + 5 + 2 and 6 + 5 + 4. (Magic squares have appeared here on r/dailyprogrammer before, in #65 [Difficult] in 2012.)

Write a function that, given a grid containing the numbers 1-9, determines whether it's a magic square. Use whatever format you want for the grid, such as a 2-dimensional array, or a 1-dimensional array of length 9, or a function that takes 9 arguments. You do not need to parse the grid from the program's input, but you can if you want to. You don't need to check that each of the 9 numbers appears in the grid: assume this to be true.
Example inputs/outputs

[8, 1, 6, 3, 5, 7, 4, 9, 2] => true
[2, 7, 6, 9, 5, 1, 4, 3, 8] => true
[3, 5, 7, 8, 1, 6, 4, 9, 2] => false
[8, 1, 6, 7, 5, 3, 4, 9, 2] => false

Optional bonus 1

Verify magic squares of any size, not just 3x3.
Optional bonus 2

Write another function that takes a grid whose bottom row is missing, so it only has the first 2 rows (6 values). This function should return true if it's possible to fill in the bottom row to make a magic square. You may assume that the numbers given are all within the range 1-9 and no number is repeated. Examples:

[8, 1, 6, 3, 5, 7] => true
[3, 5, 7, 8, 1, 6] => false

Hint: it's okay for this function to call your function from the main challenge.

This bonus can also be combined with optional bonus 1. (i.e. verify larger magic squares that are missing their bottom row.)

*/

package main

import (
	"fmt"
	"image"
)

func main() {
	check([][]uint{
		{8, 1, 6},
		{3, 5, 7},
		{4, 9, 2},
	})
	check([][]uint{
		{2, 7, 6},
		{9, 5, 1},
		{4, 3, 8},
	})
	check([][]uint{
		{3, 5, 7},
		{8, 1, 6},
		{4, 9, 2},
	})
	check([][]uint{
		{8, 1, 6},
		{7, 5, 3},
		{4, 9, 2},
	})
	checkgen([][]uint{
		{8, 1, 6},
		{3, 5, 7},
		{0, 0, 0},
	})
	checkgen([][]uint{
		{3, 5, 7},
		{8, 1, 6},
		{0, 0, 0},
	})
}

func check(m [][]uint) {
	fmt.Printf("%v %v\n", m, verify(m))
}

func checkgen(m [][]uint) {
	p := dup(m)
	found := gen(m)
	if found {
		fmt.Printf("%v %v\n", m, found)
	} else {
		fmt.Printf("%v %v\n", p, found)
	}
}

func gen(m [][]uint) bool {
	if !issquare(m) {
		return false
	}

	var (
		p []image.Point
		t []uint
	)
	u := make([]bool, len(m)*len(m))
	for i := range m {
		for j, v := range m[i] {
			switch {
			case v > uint(len(m)*len(m)):
				return false
			case v == 0:
				p = append(p, image.Pt(i, j))
			case u[v-1]:
				return false
			default:
				u[v-1] = true
			}
		}
	}
	for i := range u {
		if !u[i] {
			t = append(t, uint(i+1))
		}
	}
	if len(t) != len(p) {
		return false
	}

	d := newperm(len(t))
	for {
		if !nextperm(d) {
			break
		}
		for i := range d {
			l := p[i]
			x := d[i].index
			m[l.X][l.Y] = t[x]
		}
		if verify(m) {
			return true
		}
	}

	return false
}

func dup(m [][]uint) [][]uint {
	p := make([][]uint, len(m))
	for i := range p {
		p[i] = make([]uint, len(m[i]))
		copy(p[i], m[i])
	}
	return p
}

func issquare(m [][]uint) bool {
	// check if it is a square
	if len(m) == 0 {
		return false
	}
	for i := range m {
		if len(m[i]) != len(m) {
			return false
		}
	}
	return true
}

func verify(m [][]uint) bool {
	if !issquare(m) {
		return false
	}

	// check if each entries have a positive number between 1 and n*n
	// where n is the square size and it is unique
	u := make([]bool, len(m)*len(m))
	for i := range m {
		for _, v := range m[i] {
			if !(0 < v && v <= uint(len(m)*len(m))) || u[v-1] {
				return false
			}
			u[v-1] = true
		}
	}

	for i := range u {
		if !u[i] {
			return false
		}
	}

	// check rows
	M := uint(0)
	for i := range m {
		N := uint(0)
		for j := range m[i] {
			N += m[i][j]
		}

		if M == 0 {
			M = N
		}

		if M != N {
			return false
		}
	}

	// check columns
	for i := range m {
		N := uint(0)
		for j := range m {
			N += m[j][i]
		}
		if M != N {
			return false
		}
	}

	// check diagonal/anti-diagonal
	N := uint(0)
	O := uint(0)
	for i := range m {
		N += m[i][i]
		O += m[len(m)-1-i][len(m)-1-i]
	}
	if M != N || M != O {
		return false
	}

	return true
}

// steinhaus-johnson-trotter permutation algorithm
type dint struct {
	index int
	dir   bool
}

func newperm(n int) []dint {
	p := make([]dint, n)
	for i := range p {
		p[i] = dint{i, false}
	}
	return p
}

func nextperm(p []dint) bool {
	x, y, v := largest(p)
	if x == -1 {
		return false
	}
	p[x], p[y] = p[y], p[x]
	reverse(p, v)
	return true
}

func largest(p []dint) (x, y, v int) {
	x, y, v = -1, -1, -1
	for i := range p {
		switch {
		case i > 0 && !p[i].dir && p[i].index > p[i-1].index && p[i].index > v:
			x, y, v = i, i-1, p[i].index
		case i < len(p)-1 && p[i].dir && p[i].index > p[i+1].index && p[i].index > v:
			x, y, v = i, i+1, p[i].index
		}
	}
	return
}

func reverse(p []dint, v int) {
	for i := range p {
		if p[i].index > v {
			p[i].dir = !p[i].dir
		}
	}
}
