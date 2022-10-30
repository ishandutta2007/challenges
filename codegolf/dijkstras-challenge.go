/*

Background
Ken [Iverson] presented his paper Formalism in Programming Languages in August 1963 at a Working Conference on Mechanical Language Structures, Princeton, N.J.
The list of conferees is full of famous and soon-to-be famous names, and a few future Turing Award winners (Backus, Curry, Dijkstra, Floyd, Iverson, Newell, Perlis, Wilkes).
The paper also records the discussion that occurred after the presentation, ending with an exchange between Ken and [Edsger] Dijkstra, in which Ken’s reply to Dijkstra’s question was a one-liner.

Challenge
How would you represent a more complex operation, for example, the summation of all elements of a matrix M which are equal to the summation of the corresponding row and column indices?

Write a snippet or expression (no need for a full program or function) to calculate the summation of each element in a given integer matrix which is equal to the summation of its indices.
Or, as FryAmTheEggman puts it: given a matrix M with elements aij return the summation of each a[i,j] where a[i,j] = i + j.

You may assummatione the matrix already being in a variable or memory location, or you may take it as an argument or input. You may use either 0 or 1 based indices.

Test cases

0 for empty matrix

2
0 for 0 based indices or 2 for 1-based

1 5 2
9 4 2
5 9 6
2 for 0 based or 10 for 1 based

 0 3  0  4
 0 4  1  4
 4 3  1  2
-2 4 -2 -1
11

3 -1 3 3
3 -1 3 1
6 for 0 based or 3 for 1 based

Anecdote
Iverson's answer was ++/(M = ⍳¹ ⨢ ⍳¹)//M, which is neither valid in the Iverson Notation as defined in A Programming Language, nor in what eventually became APL.
In Iverson notation, it would have been +/(M = ⍳¹(μ(M)) ⨢ ⍳¹(ν(M)))/M. In the very first versions of APL it was +/(,M=(⍳1↑⍴M)∘.+⍳1↓⍴M)/,M.

*/

package main

func main() {
	assert(summation([][]int{{}}) == 0)
	assert(summation([][]int{{2}}) == 0)

	assert(summation([][]int{
		{1, 5, 2},
		{9, 4, 2},
		{5, 9, 6},
	}) == 2)

	assert(summation([][]int{
		{0, 3, 0, 4},
		{0, 4, 1, 4},
		{4, 3, 1, 2},
		{-2, 4, -2, -1},
	}) == 11)

	assert(summation([][]int{
		{3, -1, 3, 3},
		{3, -1, 3, 1},
	}) == 6)
}

func assert(x bool) {
	if !x {
		panic("assertion failed")
	}
}

func summation(m [][]int) int {
	r := 0
	for i := range m {
		for j := range m[i] {
			if m[i][j] == i+j {
				r += m[i][j]
			}
		}
	}
	return r
}
