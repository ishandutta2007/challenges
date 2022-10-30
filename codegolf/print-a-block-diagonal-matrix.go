/*

Here is a simple, bite-sized (byte-sized?) code golf: given a non-empty list of positive integers less than 10, print a block-diagonal matrix, where the list specifies the size of the blocks, in order. The blocks must consist of positive integers less than 10. So if you're given as input

[5 1 1 2 3 1]

Your output could be, for instance,

1 1 1 1 1 0 0 0 0 0 0 0 0
1 1 1 1 1 0 0 0 0 0 0 0 0
1 1 1 1 1 0 0 0 0 0 0 0 0
1 1 1 1 1 0 0 0 0 0 0 0 0
1 1 1 1 1 0 0 0 0 0 0 0 0
0 0 0 0 0 1 0 0 0 0 0 0 0
0 0 0 0 0 0 1 0 0 0 0 0 0
0 0 0 0 0 0 0 1 1 0 0 0 0
0 0 0 0 0 0 0 1 1 0 0 0 0
0 0 0 0 0 0 0 0 0 1 1 1 0
0 0 0 0 0 0 0 0 0 1 1 1 0
0 0 0 0 0 0 0 0 0 1 1 1 0
0 0 0 0 0 0 0 0 0 0 0 0 1

or

1 2 3 4 5 0 0 0 0 0 0 0 0
6 7 8 9 1 0 0 0 0 0 0 0 0
2 3 4 5 6 0 0 0 0 0 0 0 0
7 8 9 1 2 0 0 0 0 0 0 0 0
3 4 5 6 7 0 0 0 0 0 0 0 0
0 0 0 0 0 8 0 0 0 0 0 0 0
0 0 0 0 0 0 9 0 0 0 0 0 0
0 0 0 0 0 0 0 1 2 0 0 0 0
0 0 0 0 0 0 0 3 4 0 0 0 0
0 0 0 0 0 0 0 0 0 5 6 7 0
0 0 0 0 0 0 0 0 0 8 9 1 0
0 0 0 0 0 0 0 0 0 2 3 4 0
0 0 0 0 0 0 0 0 0 0 0 0 5

or something like that. The elements in the matrix must be separated by (single) spaces, and the rows separated by (single) newlines. There must not be leading or trailing spaces on any lines. You may or may not print a trailing newline.

You may write a function or program, taking input via STDIN (or closest alternative), command-line argument or function argument, in any convenient string or list format (as long as it isn't preprocessed). However, the result must be printed to STDOUT (or closest alternative), as opposed to returned from a function, say.

You must not use any built-in functions designed to create block-diagonal matrices.

This is code golf, so the shortest submission (in bytes) wins.
Leaderboards

I expect the array-based languages (like J and APL) to have the edge here, but I don't want that to discourage people from trying to do as well as they can in their language of choice. So here is a Stack Snippet to generate both a regular leaderboard and an overview of winners by language. So why not try and grab a spot on the latter?

To make sure that your answer shows up, please start your answer with a headline, using the following Markdown template:

# Language Name, N bytes

where N is the size of your submission. If you improve your score, you can keep old scores in the headline, by striking them through. For instance:

# Ruby, <s>104</s> <s>101</s> 96 bytes

*/

package main

import "fmt"

func main() {
	dump(block([]int{5, 1, 1, 2, 3, 1}))
}

func block(a []int) [][]int {
	n := 0
	for _, l := range a {
		n += l
	}

	m := make([][]int, n)
	t := make([]int, n*n)
	for i := range m {
		m[i] = t[i*n : (i+1)*n]
	}

	d := 0
	for _, l := range a {
		for i := 0; i < l; i++ {
			for j := 0; j < l; j++ {
				m[i+d][j+d] = 1
			}
		}
		d += l
	}

	return m
}

func dump(m [][]int) {
	for i := range m {
		for j := range m[i] {
			fmt.Printf("%d ", m[i][j])
		}
		fmt.Println()
	}
}
