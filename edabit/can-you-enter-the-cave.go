/*

You are playing a video game. Your screen can be represented as a 2D array, where 0s represent walkeable areas and 1s represent unwalkeable areas.
You are currently searching for the entrance to a cave that is located on the right side of the screen. Your character starts anywhere in the leftmost column.

Create a function that determines if you can enter the cave. You can only move left, right, up, or down (not allowed to move diagonally).

To illustrate:

[
  [0, 0, 1, 1, 1, 0, 0, 0],
  [0, 0, 0, 0, 1, 0, 0, 0],
  [0, 0, 1, 0, 0, 0, 0, 0],
  [0, 0, 1, 1, 1, 1, 1, 0]
]

You found the entrance! Function should output true.

[
  [0, 0, 0, 1, 0, 0, 0, 0],
  [0, 0, 0, 1, 1, 0, 0, 0],
  [0, 0, 0, 0, 1, 1, 0, 0],
  [0, 0, 0, 1, 1, 1, 1, 0]
]

Nope, keep looking. Function should output false.
Examples

canEnterCave([
  [0, 1, 1, 1, 0, 1, 1, 0],
  [0, 0, 1, 1, 0, 0, 0, 0],
  [0, 0, 0, 0, 1, 1, 1, 0],
  [0, 1, 1, 1, 1, 1, 1, 0]
]) ➞ false

// You cannot walk diagonally!


canEnterCave([
  [0, 1, 1, 1, 0, 1, 1, 0],
  [0, 0, 1, 1, 0, 0, 0, 0],
  [1, 0, 0, 0, 0, 1, 0, 0],
  [1, 1, 1, 1, 1, 1, 1, 0]
]) ➞ true


canEnterCave([
  [0, 1, 1, 1, 1, 1, 1, 0],
  [0, 0, 0, 0, 1, 0, 0, 0],
  [0, 0, 1, 1, 1, 1, 1, 0],
  [0, 1, 1, 0, 0, 1, 1, 0]
]) ➞ false

Notes

    You are seeing the game screen from a birds-eye view.
    Another way of thinking about it: You can enter the cave if you can move from the left side of the screen to the right side by only walking up, down or right.
    The entrance is not necessarily the first square, you may have to search for it in the left hand column.

*/

package main

func main() {
	assert(walkable([][]int{
		{0, 0, 1, 1, 1, 0, 0, 0},
		{0, 0, 0, 0, 1, 0, 0, 0},
		{0, 0, 1, 0, 0, 0, 0, 0},
		{0, 0, 1, 1, 1, 1, 1, 0},
	}) == true)

	assert(walkable([][]int{
		{0, 0, 0, 1, 0, 0, 0, 0},
		{0, 0, 0, 1, 1, 0, 0, 0},
		{0, 0, 0, 0, 1, 1, 0, 0},
		{0, 0, 0, 1, 1, 1, 1, 0},
	}) == false)

	assert(walkable([][]int{
		{0, 1, 1, 1, 0, 1, 1, 0},
		{0, 0, 1, 1, 0, 0, 0, 0},
		{0, 0, 0, 0, 0, 1, 0, 0},
		{0, 1, 1, 1, 1, 1, 1, 0},
	}) == true)

	assert(walkable([][]int{
		{0, 1, 1, 1, 0, 1, 1, 0},
		{0, 0, 1, 1, 0, 0, 0, 0},
		{0, 0, 0, 1, 0, 1, 0, 0},
		{0, 1, 1, 1, 1, 1, 1, 0},
	}) == false)

	assert(walkable([][]int{
		{0, 1, 1, 1, 0, 1, 1, 0},
		{0, 0, 1, 1, 0, 0, 0, 0},
		{0, 0, 0, 0, 1, 1, 1, 0},
		{0, 1, 1, 1, 1, 1, 1, 0},
	}) == false)

	assert(walkable([][]int{
		{0, 1, 1, 1, 1, 1, 1, 0},
		{0, 0, 0, 0, 1, 0, 0, 0},
		{0, 0, 1, 1, 1, 1, 1, 0},
		{0, 1, 1, 0, 0, 1, 1, 0},
	}) == false)

	assert(walkable([][]int{
		{0, 1, 1, 1, 1, 1, 1, 0},
		{0, 1, 0, 0, 1, 0, 0, 0},
		{0, 0, 1, 0, 1, 1, 1, 0},
		{0, 1, 1, 0, 0, 1, 1, 0},
	}) == false)

	assert(walkable([][]int{
		{0, 1, 1, 1, 1, 1, 1, 1},
		{0, 0, 0, 0, 1, 0, 0, 1},
		{0, 0, 1, 0, 1, 0, 0, 0},
		{0, 1, 1, 0, 0, 0, 1, 0},
	}) == true)

	assert(walkable([][]int{
		{1, 0, 0, 0, 0, 0, 1, 0, 0},
		{1, 0, 1, 1, 1, 0, 1, 0, 1},
		{1, 0, 1, 0, 0, 0, 1, 0, 1},
		{1, 0, 1, 0, 1, 1, 1, 0, 1},
		{0, 0, 1, 0, 0, 0, 0, 0, 1},
	}) == true)
}

func assert(x bool) {
	if !x {
		panic("assertion failed")
	}
}

func walkable(a [][]int) bool {
	if len(a) == 0 || len(a[0]) == 0 {
		return false
	}

	n, m := len(a), len(a[0])
	for i := 0; i < n; i++ {
		floodfill(a, n, m, i, 0)
	}
	f := 0
	for i := 0; i < n && f != 3; i++ {
		if a[i][0] == 2 {
			f |= 1
		}
		if a[i][m-1] == 2 {
			f |= 2
		}
	}
	return f == 3
}

func floodfill(a [][]int, n, m, i, j int) {
	if i < 0 || j < 0 || i >= n || j >= m || a[i][j] != 0 {
		return
	}

	a[i][j] = 2
	floodfill(a, n, m, i+1, j)
	floodfill(a, n, m, i-1, j)
	floodfill(a, n, m, i, j+1)
	floodfill(a, n, m, i, j-1)
}
