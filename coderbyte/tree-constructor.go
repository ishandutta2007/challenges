/*

Tree Constructor

Have the function TreeConstructor(strArr) take the array of strings stored in strArr, which will contain pairs of integers in the following format: (i1,i2),
where i1 represents a child node in a tree and the second integer i2 signifies that it is the parent of i1. For example: if strArr is ["(1,2)", "(2,4)", "(7,2)"], then this forms the following tree:

which you can see forms a proper binary tree.

Your program should, in this case, return the string true because a valid binary tree can be formed.
If a proper binary tree cannot be formed with the integer pairs, then return the string false.
All of the integers within the tree will be unique, which means there can only be one node in the tree with the given integer value.

Examples
Input: ["(1,2)", "(2,4)", "(5,7)", "(7,2)", "(9,5)"]
Output: true
Input: ["(1,2)", "(3,2)", "(2,12)", "(5,2)"]
Output: false

*/

package main

import "fmt"

func main() {
	assert(bintree([]string{"(1,2)", "(2,4)", "(7,2)"}) == true)
	assert(bintree([]string{"(1,2)", "(2,4)", "(5,7)", "(7,2)", "(9,5)"}) == true)
	assert(bintree([]string{"(1,2)", "(3,2)", "(2,12)", "(5,2)"}) == false)
}

func assert(x bool) {
	if !x {
		panic("assertion failed")
	}
}

func bintree(s []string) bool {
	h := make(map[int][]int)
loop:
	for i := range s {
		var x, y int
		n, _ := fmt.Sscanf(s[i], "(%d,%d)", &x, &y)
		if n != 2 {
			return false
		}

		for i := range h[y] {
			if h[y][i] == x {
				continue loop
			}
		}
		if len(h[y]) == 2 {
			return false
		}
		h[y] = append(h[y], x)
	}
	return true
}
