/*

You are given a list of (x,y) grid coordinates. Your function should decide whether the figure obtained by coloring in the squares of the grid with the given coordinates is connected or not.

Squares adjacent diagonally are not considered connected.

Example input:

(0,0),(1,0),(2,0),(3,0),(3,1),(3,2),(2,2),
(1,2),(0,2),(0,3),(0,4),(1,4),(2,4),(3,4)
which looks like:

****
*
****
   *
****
Output:

YES
Example input:

(0,0),(1,0),(2,0),(0,1),(0,2),(2,2),(3,2),(4,2),(0,3),
(4,3),(0,4),(1,4),(2,4),(4,4),(4,5),(2,6),(3,6),(4,6)
which looks like:

  ***
    *
*** *
*   *
* ***
*
***
Output:

NO
Your function must take as input a list of pairs of integers (e.g. in C++, maybe vector<pair<int,int>>) and return a boolean. You may not assume any particular ordering of the input points. The coordinates will be between 0 and 99 inclusive.

Smallest code wins.

*/

package main

import (
	"image"
)

func main() {
	assert(connected([]image.Point{
		{0, 0},
		{1, 0},
		{2, 0},
		{3, 0},
		{3, 1},
		{3, 2},
		{2, 2},
		{1, 2},
		{0, 2},
		{0, 3},
		{0, 4},
		{1, 4},
		{2, 4},
		{3, 4},
	}) == true)

	assert(connected([]image.Point{
		{0, 0},
		{1, 0},
		{2, 0},
		{0, 1},
		{0, 2},
		{2, 2},
		{3, 2},
		{4, 2},
		{0, 3},
		{4, 3},
		{0, 4},
		{1, 4},
		{2, 4},
		{4, 4},
		{4, 5},
		{2, 6},
		{3, 6},
		{4, 6},
	}) == false)
}

func assert(x bool) {
	if !x {
		panic("assertion failed")
	}
}

func connected(p []image.Point) bool {
	dir := []image.Point{
		{-1, 0},
		{1, 0},
		{0, 1},
		{0, -1},
	}

	if len(p) == 0 {
		return true
	}

	s := make(map[image.Point]bool)
	m := make(map[image.Point]bool)
	for _, p := range p {
		m[p] = true
	}

	q := []image.Point{p[0]}
	c := 0
	for len(q) > 0 {
		s[q[0]] = true
		for _, d := range dir {
			v := q[0].Add(d)
			if m[v] && !s[v] {
				q = append(q, v)
			}
		}
		c, q = c+1, q[1:]
	}
	return c == len(p)
}
