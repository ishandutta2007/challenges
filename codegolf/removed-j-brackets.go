/*

For a 2 dimensional array we will call the elements in either the first row or the last column the "J-Bracket" of the array. For example in the following array elements in the J-bracket are highlighted:

1 2 4 8
9 3 6 7
3 3 2 9

The J-bracket is given in order starting from the first element of the first row and going clockwise. The element that is in both the row and the column is not repeated. So for the above that is:

[1,2,4,8,7,9]

Your task is to take as input a 2 dimensional array of positive integers, and repeatedly remove J-brackets from it until the remaining array has no more elements. Your output should be all the J-brackets removed in this process in the order they were removed.

The input will always be perfectly rectangular, and both dimensions will be at least 1. You may take input in any reasonable format.

This is code-golf so the goal is to minimize the size of your source code as measured in bytes.

Test cases
[[2]] -> [[2]]
[[1,2],[3,4]] -> [[1,2,4],[3]]
[[1,2,4,8],[9,3,6,7],[3,3,2,9]] -> [[1,2,4,8,7,9],[9,3,6,2],[3,3]]
[[1,2],[3,4],[5,6]] -> [[1,2,4,6], [3,5]]
[[1,2],[3,4],[5,6],[7,9]] -> [[1,2,4,6,9], [3,5,7]]

*/

package main

import (
	"fmt"
	"reflect"
)

func main() {
	test([][]int{{2}}, [][]int{{2}})
	test([][]int{{1, 2}, {3, 4}}, [][]int{{1, 2, 4}, {3}})
	test([][]int{{1, 2, 4, 8}, {9, 3, 6, 7}, {3, 3, 2, 9}}, [][]int{{1, 2, 4, 8, 7, 9}, {9, 3, 6, 2}, {3, 3}})
	test([][]int{{1, 2}, {3, 4}, {5, 6}}, [][]int{{1, 2, 4, 6}, {3, 5}})
	test([][]int{{1, 2}, {3, 4}, {5, 6}, {7, 9}}, [][]int{{1, 2, 4, 6, 9}, {3, 5, 7}})
}

func assert(x bool) {
	if !x {
		panic("assertion failed")
	}
}

func test(m, r [][]int) {
	b := jbrackets(m)
	fmt.Println(b)
	assert(reflect.DeepEqual(b, r))
}

func jbrackets(m [][]int) [][]int {
	b := [][]int{}
	r, c := 0, 0
	for {
		p := jdeck(m, r, c)
		if len(p) == 0 {
			break
		}
		b = append(b, p)
		r, c = r+1, c+1
	}
	return b
}

func jdeck(m [][]int, r, c int) []int {
	p := []int{}
	if r >= len(m) || c >= len(m[0]) {
		return p
	}

	j := len(m[0]) - c - 1
	k := len(m)
	for i := 0; i <= j; i++ {
		p = append(p, m[r][i])
	}
	for i := r + 1; i < k; i++ {
		p = append(p, m[i][j])
	}
	return p
}
