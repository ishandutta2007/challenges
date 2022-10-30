/*

A 30x30 grid of squares contains 900 fleas, initially one flea per square. When a bell is rung, each flea jumps to an adjacent square at random (usually 4 possibilities, except for fleas on the edge of the grid or at the corners).

What is the expected number of unoccupied squares after 50 rings of the bell? Give your answer rounded to six decimal places.

source: project euler

*/

package main

import (
	"fmt"
	"math/rand"
	"time"
)

func main() {
	rand.Seed(time.Now().UnixNano())
	fmt.Printf("%.6f\n", sim(30, 50, 5e4))
}

func sim(s, b, t int) float64 {
	p := alloc(s)
	q := alloc(s)
	c := 0
	for i := 0; i < t; i++ {
		reset(p, 1)

		for j := 0; j < b; j++ {
			step(p, q)
			p, q = q, p
		}
		if b&1 != 0 {
			p = q
		}

		c += count(p)
	}

	return float64(c) / float64(t)
}

func alloc(n int) [][]int {
	p := make([][]int, n)
	t := make([]int, n*n)
	for i := range p {
		p[i] = t[i*n : (i+1)*n]
	}
	return p
}

func reset(p [][]int, v int) {
	for i := range p {
		for j := range p[i] {
			p[i][j] = v
		}
	}
}

func step(p, q [][]int) {
	n := len(p)
	reset(q, 0)
	for y := 0; y < n; y++ {
		for x := 0; x < n; x++ {
			for i := 0; i < p[y][x]; i++ {
				move(q, x, y)
			}
		}
	}
}

func move(p [][]int, x, y int) {
	s := len(p)
	m := [4][2]int{
		{x - 1, y},
		{x + 1, y},
		{x, y - 1},
		{x, y + 1},
	}

	var (
		r [4][2]int
		l int
	)
	for _, c := range m {
		px, py := c[0], c[1]
		if px < 0 || px >= s || py < 0 || py >= s {
			continue
		}
		r[l], l = [2]int{px, py}, l+1
	}

	i := rand.Intn(l)
	nx := r[i][0]
	ny := r[i][1]
	p[ny][nx]++
}

func count(p [][]int) int {
	r := 0
	for i := range p {
		for j := range p[i] {
			if p[i][j] == 0 {
				r++
			}
		}
	}
	return r
}
