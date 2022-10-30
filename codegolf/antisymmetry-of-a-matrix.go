/*

A matrix is antisymmetric, or skew-symmetric, if its transpose equals its negative.

The transpose of a matrix can be obtained by reflecting its elements across the main diagonal.

Examples of transpositions can be seen here:

0 2 -1
-2 0 0
1 0 0

All antisymmetric matrices exhibit certain characteristics:

Antisymmetry can only be found on square matrices, because otherwise the matrix and its transpose would be of different dimensions.

Elements which lie on the main diagonal must equal zero because they do not move and consequently must be their own negatives, and zero is the only number which satisfies x=−x.

The sum of two antisymmetric matrices is also antisymmetric.

The Challenge
Given a square, non-empty matrix which contains only integers, check whether it is antisymmetric or not.

Rules
This is code-golf so the shortest program in bytes wins.

Input and output can assume whatever forms are most convenient as long as they are self-consistent (including output which is not truthy or falsy, or is truthy for non-antisymmetry and falsy for antisymmetry, etc).

Assume only valid input will be given.

Test Cases
In:
1 1 1
1 1 1
1 1 1

Out: False


In:
 0 0 1
 0 0 0
-1 0 0

Out: True


In:
0 -2
2  0

Out: True

*/

package main

func main() {
	assert(antisymmetric([][]int{
		{1, 1, 1},
		{1, 1, 1},
		{1, 1, 1},
	}) == false)

	assert(antisymmetric([][]int{
		{0, 0, 1},
		{0, 0, 0},
		{-1, 0, 0},
	}) == true)

	assert(antisymmetric([][]int{
		{0, -2},
		{2, 0},
	}) == true)

	assert(antisymmetric([][]int{
		{0, 2, -1},
		{-2, 0, 0},
		{1, 0, 0},
	}) == true)
}

func assert(x bool) {
	if !x {
		panic("assertion failed")
	}
}

func antisymmetric(m [][]int) bool {
	for i := range m {
		for j := range m[i] {
			if m[i][j] != -m[j][i] {
				return false
			}
		}
	}
	return true
}
