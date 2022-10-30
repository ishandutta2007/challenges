/*

Take a matrix of positive integers as input, and output the individual sums of the elements on the diagonal lines through the matrix.

You shall only count the lines that goes diagonally down and to the right. You must start with the diagonal that contains only the bottom-left element,
then the length-two diagonal above that (if it exists) and so on through to the diagonal that contains only the top-right element, as illustrated below.

Example:

Input:
 8   14    5    1
10    5    5    8
 6    6    8   10
15   15    4   11

Output:
15, 21, 20, 32, 29, 13, 1
(Diagonals: {{15},{6,15},{10,6,4},{8,5,8,11},{14,5,10},{5,8},{1}})

Input:
1
Output:
1

Input:
1 5
Output:
1, 5

Input:
4
1

Output:
1, 4

Input:
17    4    5
24   16    5
 9   24   10
 1   14   22
 1   21   24
 4    4   17
24   25   17

Output:

24, 29, 22, 39, 47, 70, 43, 9, 5
Input and output formats are optional as always.

This is code-golf, so the shortest submission in each language wins.

*/

package main

import (
	"fmt"
	"reflect"
)

func main() {
	test([][]int{
		{8, 14, 5, 1},
		{10, 5, 5, 8},
		{6, 6, 8, 10},
		{15, 15, 4, 11},
	}, []int{15, 21, 20, 32, 29, 13, 1})

	test([][]int{
		{1},
	}, []int{1})

	test([][]int{
		{1, 5},
	}, []int{1, 5})

	test([][]int{
		{4},
		{1},
	}, []int{1, 4})

	test([][]int{
		{17, 4, 5},
		{24, 16, 5},
		{9, 24, 10},
		{1, 14, 22},
		{1, 21, 24},
		{4, 4, 17},
		{24, 25, 17},
	}, []int{24, 29, 22, 39, 47, 70, 43, 9, 5})
}

func assert(x bool) {
	if !x {
		panic("assertion failed")
	}
}

func test(m [][]int, r []int) {
	p := diagsum(m)
	fmt.Println(p)
	assert(reflect.DeepEqual(p, r))
}

func diagsum(m [][]int) []int {
	p := []int{}
	if len(m) == 0 || len(m[0]) == 0 {
		return p
	}

	r, c := len(m), len(m[0])
	for i := r - 1; i >= 0; i-- {
		p = append(p, sum(m, r, c, i, 0))
	}
	for i := 1; i < c; i++ {
		p = append(p, sum(m, r, c, 0, i))
	}
	return p
}

func sum(m [][]int, r, c, i, j int) int {
	v := 0
	for i < r && j < c {
		v, i, j = v+m[i][j], i+1, j+1
	}
	return v
}
