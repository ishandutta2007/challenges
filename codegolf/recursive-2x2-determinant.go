/*

The determinant of a 2 by 2 matrix

a b
c d

is given by ad - bc.

Given a matrix of digits with dimensions 2n by 2n, n ≥ 1, output the result obtained by recursively computing the determinant of each 2 by 2 sub-block until we reach a single number.

For example, given the input

3 1 4 1
5 9 2 6
5 3 5 8
9 7 9 3

After one step, we obtain:

(3*9 - 1*5)    (4*6 - 1*2)    =    22  22
(5*7 - 3*9)    (5*3 - 8*9)         8  -57

And iterating once more, we get:

(22*-57 - 22*8) = -1430

Hence, the output should be -1430.
Rules

    The elements of the matrix will always be single digit integers, i.e. 0 to 9.
    You may take input in any convenient list or string format, as long as no preprocessing of data is done. Since the matrix is always square, you may take input as a single 1D list instead of a 2D list if you wish.
    Input can be via function input, STDIN, command-line argument or closest alternative.
    Output should be a single integer to function output, STDOUT or closest alternative. You may not output the single integer in a list or matrix.
    You may use builtin determinant and matrix manipulation methods if your language happens to support them.
    Your algorithm must work in theory for any valid input.
    Standard code-golf rules apply.

Test cases

The following test cases are given as Python-style lists:

[[1,0],[0,1]] -> 1
[[1,9],[8,4]] -> -68
[[0,1,2,3],[4,5,6,7],[8,9,0,1],[2,3,4,5]] -> 40
[[3,1,4,1],[5,9,2,6],[5,3,5,8],[9,7,9,3]] -> -1430
[[9,0,0,9],[0,9,9,0],[9,0,9,0],[0,9,0,9]] -> 13122
[[1,0,0,0,0,0,0,0],[2,1,0,0,0,0,0,0],[3,2,1,0,0,0,0,0],[4,3,2,1,0,0,0,0],[5,4,3,2,1,0,0,0],[6,5,4,3,2,1,0,0],[7,6,5,4,3,2,1,0],[8,7,6,5,4,3,2,1]] -> 1
[[7,1,0,5,8,0,1,5],[9,9,6,6,1,2,4,8],[4,8,7,3,8,7,4,7],[4,6,1,9,7,0,1,7],[7,6,7,1,9,4,1,6],[8,0,0,8,5,5,9,9],[4,6,4,8,9,4,8,6],[9,0,8,7,6,2,1,5]] -> 2937504
[[1,2,3,4,5,6,7,8],[2,3,4,5,6,7,8,1],[3,4,5,6,7,8,1,2],[4,5,6,7,8,1,2,3],[5,6,7,8,1,2,3,4],[6,7,8,1,2,3,4,5],[7,8,1,2,3,4,5,6],[8,1,2,3,4,5,6,7]] -> -10549504
[[1,1,1,0,1,1,1,1,1,1,1,1,1,1,1,0],[0,1,1,1,1,0,0,1,0,1,1,1,1,1,1,0],[1,1,0,1,1,0,1,1,1,1,1,1,1,1,1,0],[0,1,1,1,1,0,0,0,0,1,1,1,1,1,0,1],[1,0,1,0,1,1,1,0,0,1,1,1,1,0,1,0],[0,0,1,1,1,0,1,1,1,1,1,1,1,0,0,0],[1,1,1,1,1,0,1,0,1,1,1,1,1,1,1,1],[1,1,0,1,1,1,1,1,1,1,1,1,0,1,0,1],[1,1,1,1,1,1,1,1,1,1,0,1,1,1,1,1],[0,1,1,1,1,1,1,1,1,0,0,1,0,1,0,1],[1,0,1,1,1,1,1,1,1,1,1,1,1,1,1,1],[1,1,0,1,1,0,1,1,1,1,1,0,0,1,1,0],[1,1,1,1,1,1,1,1,0,1,1,1,1,1,1,0],[1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1],[1,0,1,0,0,1,0,1,0,1,1,1,1,1,0,1],[1,1,1,1,1,1,1,1,1,0,0,1,1,1,0,1]] -> -8

(Thanks to @MartinBüttner for help with this challenge)

*/

package main

func main() {
	assert(det2x2r([][]int{
		{1, 0},
		{0, 1},
	}) == 1)

	assert(det2x2r([][]int{
		{1, 9},
		{8, 4},
	}) == -68)

	assert(det2x2r([][]int{
		{0, 1, 2, 3},
		{4, 5, 6, 7},
		{8, 9, 0, 1},
		{2, 3, 4, 5},
	}) == 40)

	assert(det2x2r([][]int{
		{3, 1, 4, 1},
		{5, 9, 2, 6},
		{5, 3, 5, 8},
		{9, 7, 9, 3},
	}) == -1430)

	assert(det2x2r([][]int{
		{9, 0, 0, 9},
		{0, 9, 9, 0},
		{9, 0, 9, 0},
		{0, 9, 0, 9},
	}) == 13122)

	assert(det2x2r([][]int{
		{1, 0, 0, 0, 0, 0, 0, 0},
		{2, 1, 0, 0, 0, 0, 0, 0},
		{3, 2, 1, 0, 0, 0, 0, 0},
		{4, 3, 2, 1, 0, 0, 0, 0},
		{5, 4, 3, 2, 1, 0, 0, 0},
		{6, 5, 4, 3, 2, 1, 0, 0},
		{7, 6, 5, 4, 3, 2, 1, 0},
		{8, 7, 6, 5, 4, 3, 2, 1},
	}) == 1)

	assert(det2x2r([][]int{
		{7, 1, 0, 5, 8, 0, 1, 5},
		{9, 9, 6, 6, 1, 2, 4, 8},
		{4, 8, 7, 3, 8, 7, 4, 7},
		{4, 6, 1, 9, 7, 0, 1, 7},
		{7, 6, 7, 1, 9, 4, 1, 6},
		{8, 0, 0, 8, 5, 5, 9, 9},
		{4, 6, 4, 8, 9, 4, 8, 6},
		{9, 0, 8, 7, 6, 2, 1, 5},
	}) == 2937504)

	assert(det2x2r([][]int{
		{1, 2, 3, 4, 5, 6, 7, 8},
		{2, 3, 4, 5, 6, 7, 8, 1},
		{3, 4, 5, 6, 7, 8, 1, 2},
		{4, 5, 6, 7, 8, 1, 2, 3},
		{5, 6, 7, 8, 1, 2, 3, 4},
		{6, 7, 8, 1, 2, 3, 4, 5},
		{7, 8, 1, 2, 3, 4, 5, 6},
		{8, 1, 2, 3, 4, 5, 6, 7},
	}) == -10549504)

	assert(det2x2r([][]int{
		{1, 1, 1, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0},
		{0, 1, 1, 1, 1, 0, 0, 1, 0, 1, 1, 1, 1, 1, 1, 0},
		{1, 1, 0, 1, 1, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0},
		{0, 1, 1, 1, 1, 0, 0, 0, 0, 1, 1, 1, 1, 1, 0, 1},
		{1, 0, 1, 0, 1, 1, 1, 0, 0, 1, 1, 1, 1, 0, 1, 0},
		{0, 0, 1, 1, 1, 0, 1, 1, 1, 1, 1, 1, 1, 0, 0, 0},
		{1, 1, 1, 1, 1, 0, 1, 0, 1, 1, 1, 1, 1, 1, 1, 1},
		{1, 1, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 1, 0, 1},
		{1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 1, 1, 1, 1, 1},
		{0, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 1, 0, 1, 0, 1},
		{1, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
		{1, 1, 0, 1, 1, 0, 1, 1, 1, 1, 1, 0, 0, 1, 1, 0},
		{1, 1, 1, 1, 1, 1, 1, 1, 0, 1, 1, 1, 1, 1, 1, 0},
		{1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
		{1, 0, 1, 0, 0, 1, 0, 1, 0, 1, 1, 1, 1, 1, 0, 1},
		{1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 1, 1, 1, 0, 1},
	}) == -8)
}

func assert(x bool) {
	if !x {
		panic("assertion failed")
	}
}

func det2x2r(m [][]int) int {
	n := len(m)
	p := alloc(n)
	q := alloc(n)
	copy(p, m)
	for ; n > 1; n /= 2 {
		for i, k := 0, 0; i < n; i, k = i+2, k+1 {
			for j, l := 0, 0; j < n; j, l = j+2, l+1 {
				q[k][l] = p[i][j]*p[i+1][j+1] - p[i+1][j]*p[i][j+1]
			}
		}
		p, q = q, p
	}
	return p[0][0]
}

func alloc(n int) [][]int {
	m := make([][]int, n)
	t := make([]int, n*n)
	for i := range m {
		m[i] = t[i*n : (i+1)*n]
	}
	return m
}
