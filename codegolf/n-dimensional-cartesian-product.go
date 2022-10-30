/*

Introduction

The Cartesian product of two lists is calculated by iterating over every element in the first and second list and outputting points.
This is not a very good definition, so here are some examples: the Cartesian product of [1, 2] and [3, 4] is [(1, 3), (1, 4), (2, 3), (2, 4)].
The product of [1] and [2] is [(1, 2)]. However, no one said you could only use two lists. The product of [1, 2], [3, 4], and [5, 6] is [(1, 3, 5), (1, 4, 5), (1, 3, 6), (1, 4, 6), (2, 3, 5), (2, 4, 5), (2, 3, 6), (2, 4, 6)].

Challenge

Given a number of lists, your program must output the Cartesian product of the lists given.

    You can assume that there will always be more than 1 list, and that each list will have the same length. No list will ever be empty. If your language has no method of stdin, you may take input from command line arguments or a variable.
    Your program must output the Cartesian product of all the input lists. If your language has no stdout, you may store output in a variable or as a return value. The output should be a list of lists, or any other iterable type.

Example I/O

    Input: [1, 2] [3, 4]
    Output: [(1, 3), (1, 4), (2, 3), (2, 4)]

    Input: [1, 2] [3, 4] [5, 6]
    Output: [(1, 3, 5), (1, 4, 5), (1, 3, 6), (1, 4, 6), (2, 3, 5), (2, 4, 5), (2, 3, 6), (2, 4, 6)]

    Input: [1, 2, 3] [4, 5, 6]
    Output: [(1, 4), (1, 5), (1, 6), (2, 4), (2, 5), (2, 6), (3, 4), (3, 5), (3, 6)]

Rules

This is code-golf so shortest answer in bytes wins!

*/

package main

import "fmt"

func main() {
	fmt.Println(cartesian([]int{1, 2}, []int{3, 4}))
	fmt.Println(cartesian([]int{1, 2}, []int{3, 4}, []int{5, 6}))
	fmt.Println(cartesian([]int{1, 2, 3}, []int{4, 5, 6}))
	fmt.Println(cartesian([]int{1, 2, 3}))
	fmt.Println(cartesian([]int{1}))
	fmt.Println(cartesian([]int{}))
}

func cartesian(a ...[]int) (p [][]int) {
	recurse(a, &p, []int{})
	return
}

func recurse(a [][]int, p *[][]int, l []int) {
	if len(a) == 0 {
		*p = append(*p, l)
		return
	}

	for i := range a[0] {
		t := append(append([]int{}, l...), a[0][i])
		recurse(a[1:], p, t)
	}
}
