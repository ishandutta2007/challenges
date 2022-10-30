/*

Given a non-empty rectangular array of integers from 0 to 9, output the amount of cells that are 8 and do not have a neighbour that is 8.
Neighbouring is here understood in the Moore sense, that is, including diagonals.
So each cell has 8 neighbours, except for cells at the edges of the array.

For example, given the input

8 4 5 6 5
9 3 8 4 8
0 8 6 1 5
6 7 9 8 2
8 8 7 4 2

the output should be 3. The three qualifying cells would be the following, marked with an asterisk (but only the amount of such entries should be output):

* 4 5 6 5
9 3 8 4 *
0 8 6 1 5
6 7 9 * 2
8 8 7 4 2

Additional rules

    You can optionally take two numbers defining the size of the array as additional inputs.

    Input can be taken by any reasonable means. The format is flexible as usual. For example, it can be a 2D character array, or a list of lists of numbers, or a flat list.

    Programs or functions are allowed, in any programming language. Standard loopholes are forbidden.

    Shortest code in bytes wins.

Test cases

    Input:

    8 4 5 6 5
    9 3 8 4 8
    0 8 6 1 5
    6 7 9 8 2
    8 8 7 4 2

    Output: 3

    Input

    8 8
    2 3

    Output: 0

    Input:

    5 3 4
    2 5 2

    Output: 0

    Input:

    5 8 3 8

    Output: 2

    Input:

    8
    0
    8

    Output: 2.

    Input:

    4 2 8 5
    2 6 1 8
    8 5 5 8

    Output: 1

    Input:

    4 5 4 3 8 1 8 2
    8 2 7 7 8 3 9 3
    9 8 7 8 5 4 2 8
    4 5 0 2 1 8 6 9
    1 5 4 3 4 5 6 1

    Output 3.

    Input:

    8

    Output: 1

    Input:

    8 5 8 1 6 8 7 7
    9 9 2 8 2 7 8 3
    2 8 4 9 7 3 2 7
    9 2 9 7 1 9 5 6
    6 9 8 7 3 1 5 2
    1 9 9 7 1 8 8 2
    3 5 6 8 1 4 7 5

    Output: 4.

    Input:

    8 1 8
    2 5 7
    8 0 1

    Output: 3.

Inputs in MATLAB format:

[8 4 5 6 5; 9 3 8 4 8; 0 8 6 1 5; 6 7 9 8 2; 8 8 7 4 2]
[8 8; 2 3]
[5 3 4; 2 5 2]
[5 8 3 8]
[8; 0; 8]
[4 2 8 5; 2 6 1 8; 8 5 5 8]
[4 5 4 3 8 1 8 2; 8 2 7 7 8 3 9 3; 9 8 7 8 5 4 2 8; 4 5 0 2 1 8 6 9; 1 5 4 3 4 5 6 1]
[8]
[8 5 8 1 6 8 7 7; 9 9 2 8 2 7 8 3; 2 8 4 9 7 3 2 7; 9 2 9 7 1 9 5 6; 6 9 8 7 3 1 5 2; 1 9 9 7 1 8 8 2; 3 5 6 8 1 4 7 5]
[8 1 8; 2 5 7; 8 0 1]

Inputs in Python format:

[[8, 4, 5, 6, 5], [9, 3, 8, 4, 8], [0, 8, 6, 1, 5], [6, 7, 9, 8, 2], [8, 8, 7, 4, 2]]
[[8, 8], [2, 3]]
[[5, 3, 4], [2, 5, 2]]
[[5, 8, 3, 8]]
[[8], [0], [8]]
[[4, 2, 8, 5], [2, 6, 1, 8], [8, 5, 5, 8]]
[[4, 5, 4, 3, 8, 1, 8, 2], [8, 2, 7, 7, 8, 3, 9, 3], [9, 8, 7, 8, 5, 4, 2, 8], [4, 5, 0, 2, 1, 8, 6, 9], [1, 5, 4, 3, 4, 5, 6, 1]]
[[8]]
[[8, 5, 8, 1, 6, 8, 7, 7], [9, 9, 2, 8, 2, 7, 8, 3], [2, 8, 4, 9, 7, 3, 2, 7], [9, 2, 9, 7, 1, 9, 5, 6], [6, 9, 8, 7, 3, 1, 5, 2], [1, 9, 9, 7, 1, 8, 8, 2], [3, 5, 6, 8, 1, 4, 7, 5]]
[[8, 1, 8], [2, 5, 7], [8, 0, 1]]

Outputs:

3, 0, 0, 2, 2, 1, 3, 1, 4, 3

*/

package main

func main() {
	assert(eights([][]int{
		{8, 4, 5, 6, 5},
		{9, 3, 8, 4, 8},
		{0, 8, 6, 1, 5},
		{6, 7, 9, 8, 2},
		{8, 8, 7, 4, 2},
	}) == 3)

	assert(eights([][]int{
		{8, 8},
		{2, 3},
	}) == 0)

	assert(eights([][]int{
		{5, 3, 4},
		{2, 5, 2},
	}) == 0)

	assert(eights([][]int{
		{5, 8, 3, 8},
	}) == 2)

	assert(eights([][]int{
		{8},
		{0},
		{8},
	}) == 2)

	assert(eights([][]int{
		{4, 2, 8, 5},
		{2, 6, 1, 8},
		{8, 5, 5, 8},
	}) == 1)

	assert(eights([][]int{
		{4, 5, 4, 3, 8, 1, 8, 2},
		{8, 2, 7, 7, 8, 3, 9, 3},
		{9, 8, 7, 8, 5, 4, 2, 8},
		{4, 5, 0, 2, 1, 8, 6, 9},
		{1, 5, 4, 3, 4, 5, 6, 1},
	}) == 3)

	assert(eights([][]int{
		{1},
	}) == 0)

	assert(eights([][]int{
		{8, 5, 8, 1, 6, 8, 7, 7},
		{9, 9, 2, 8, 2, 7, 8, 3},
		{2, 8, 4, 9, 7, 3, 2, 7},
		{9, 2, 9, 7, 1, 9, 5, 6},
		{6, 9, 8, 7, 3, 1, 5, 2},
		{1, 9, 9, 7, 1, 8, 8, 2},
		{3, 5, 6, 8, 1, 4, 7, 5},
	}) == 4)

	assert(eights([][]int{
		{8, 1, 8},
		{2, 5, 7},
		{8, 0, 1},
	}) == 3)
}

func assert(x bool) {
	if !x {
		panic("assertion failed")
	}
}

func eights(m [][]int) int {
	r := 0
	for y := range m {
		for x := range m[y] {
			c := at(m, x-1, y-1)
			c += at(m, x, y-1)
			c += at(m, x+1, y-1)
			c += at(m, x-1, y)
			c += at(m, x+1, y)
			c += at(m, x-1, y+1)
			c += at(m, x, y+1)
			c += at(m, x+1, y+1)
			if m[y][x] == 8 && c == 0 {
				r++
			}
		}
	}
	return r
}

func at(m [][]int, x, y int) int {
	if x < 0 || y < 0 || y >= len(m) || x >= len(m[y]) || m[y][x] != 8 {
		return 0
	}
	return 1
}
