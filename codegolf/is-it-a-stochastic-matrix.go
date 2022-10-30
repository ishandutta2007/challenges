/*

A stochastic matrix is a matrix of probabilities used in the context of Markov chains.

A right stochastic matrix is a matrix where each row sums to 1.

A left stochastic matrix is a matrix where each column sums to 1.

A doubly stochastic matrix is a matrix where each row and each column sums to 1.

In this challenge, we will represent the probabilities in percent using integers. A row or column must in that case sum to 100 and not 1.

Your goal is to write a program or function which, given a square matrix of integers as input, outputs one of four values indicating that the matrix is either right stochastic, left stochastic, doubly stochastic or none of those.

Input
You may use any proper representation of a matrix that is natural for your language for the input. For example, a list of lists, a string of comma separated values with rows separated by linebreaks, etc.

The input matrix will always be square and will only contain non-negative integers. The input matrix will always be at least 1×1.

You may pass the input using STDIN, as a function argument, or anything similar.

Output
You must choose four distinct outputs that correspond to right stochastic, left stochastic, doubly stochastic or none of those.
Those outputs must be constant regardless of what input is passed. Your program may not return different outputs for the same case, e.g. saying that any negative number corresponds to none of those is not valid.

In short, there must be a 1-to-1 correspondence between your output an the four possible cases. Some examples of those four outputs would be {1, 2, 3, 4} or {[1,0], [0,1], [1,1], [0,0]} or even {right, left, doubly, none}.

Please indicate in your answer the four outputs your program uses.

If a matrix is doubly stochastic, then you must return the output corresponding to doubly stochastic, and not right or left stochastic.

You may print the output to STDOUT, return it from a function, or anything similar.

Test cases
[100]               => Doubly stochastic

[42]                => None of those

[100  0  ]          => Doubly stochastic
[0    100]

[4   8   15]
[16  23  42]        => Left stochastic
[80  69  43]

[99  1 ]            => Right stochastic
[2   98]

[1   2   3   4 ]
[5   6   7   8 ]    => None of those
[9   10  11  12]
[13  14  15  16]

Scoring
This is code-golf, so the shortest answer in bytes wins.

*/

package main

func main() {
	assert(classify([][]int{{100}}) == "doubly")
	assert(classify([][]int{{42}}) == "none")

	assert(classify([][]int{
		{100, 0},
		{0, 100},
	}) == "doubly")

	assert(classify([][]int{
		{4, 8, 15},
		{16, 23, 42},
		{80, 69, 43},
	}) == "left")

	assert(classify([][]int{
		{99, 1},
		{2, 98},
	}) == "right")

	assert(classify([][]int{
		{1, 2, 3, 4},
		{5, 6, 7, 8},
		{9, 10, 11, 12},
		{13, 14, 15, 16},
	}) == "none")
}

func assert(x bool) {
	if !x {
		panic("assertion failed")
	}
}

func classify(m [][]int) string {
	tab := []string{"none", "right", "left", "doubly"}
	f := 3
	for i := range m {
		r, c := 0, 0
		for j := range m[i] {
			r += m[i][j]
			c += m[j][i]
		}
		if r != 100 {
			f &^= 1
		}
		if c != 100 {
			f &^= 2
		}
	}
	return tab[f]
}
