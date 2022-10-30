/*

Anyone knows that the best place to learn the art of espionage is at the Manhattan Academy of Private Spies (MAPS).
Scattered across Manhattan are a number of safe houses, which are used by MAPS when conducting drills.
During a drill, each spy-in-training is required to travel from their current location to the nearest safe house.
If there are multiple safe houses that are nearest to their current location, then it does not matter which safe house that spy chooses to travel to. Each safe house is large enough to accommodate any number of spies.

Manhattan is modeled as a grid of city blocks.
Initially (before any drill), each block may contain a single safe house or a single spy, but not both.
The distance between two city blocks is measured using Manhattan distance, also known as taxicab distance.
Formally, the Manhattan distance between two locations is the sum of the absolute value of their vertical difference and the absolute value of their horizontal difference.

What is the maximum Manhattan distance that any spy has to travel to reach the nearest safe house?

Input

The first line of input contains an integer, N, where 2≤N≤100, denoting the width and height of the grid.
Each of the next N lines contain N characters, with each character denoting a city block.
A spy is represented by an ‘S’ character, a safe house is represented by an ‘H’ character, and the remaining city blocks in the grid are represented by ‘.’ (period) characters.
There is at least one spy and at least one safe house.

Output

Output an integer indicating the maximum Manhattan distance that any spy has to travel in order to reach the nearest safe house.

*/

package main

import (
	"image"
	"math"
)

func main() {
	assert(safehouse([][]byte{
		{'.', '.', '.', '.', 'H'},
		{'.', '.', '.', '.', '.', '.'},
		{'S', '.', '.', '.', '.'},
		{'.', '.', '.', '.', 'H'},
		{'.', '.', '.', '.', '.'},
	}) == 5)

	assert(safehouse([][]byte{
		{'S', '.', '.', '.'},
		{'.', '.', 'H', 'S'},
		{'.', '.', '.', '.'},
		{'.', 'H', '.', '.'},
	}) == 3)
}

func assert(x bool) {
	if !x {
		panic("assertion failed")
	}
}

func safehouse(m [][]byte) int {
	var s, h []image.Point
	for i := range m {
		for j := range m[i] {
			if m[i][j] == 'S' {
				s = append(s, image.Point{j, i})
			} else if m[i][j] == 'H' {
				h = append(h, image.Point{j, i})
			}
		}
	}

	r := 0
	for i := range s {
		d := math.MaxInt
		for j := range h {
			d = min(d, manhattan(s[i], h[j]))
		}
		r = max(r, d)
	}
	return r
}

func manhattan(a, b image.Point) int {
	return abs(a.X-b.X) + abs(a.Y-b.Y)
}

func abs(x int) int {
	if x < 0 {
		x = -x
	}
	return x
}

func max(a, b int) int {
	if a > b {
		return a
	}
	return b
}

func min(a, b int) int {
	if a < b {
		return a
	}
	return b
}
