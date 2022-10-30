/*

Given a triangle, find the minimum path sum from top to bottom. Each step you may move to adjacent numbers on the row below.

For example, given the following triangle

[
     [2],
    [3,4],
   [6,5,7],
  [4,1,8,3]
]

The minimum path sum from top to bottom is 11 (i.e., 2 + 3 + 5 + 1 = 11).

Note:

Bonus point if you are able to do this using only O(n) extra space, where n is the total number of rows in the triangle.

*/

package main

import "fmt"

func main() {
	t1 := [][]int{
		{2},
		{3, 4},
		{6, 5, 7},
		{4, 1, 8, 3},
	}
	fmt.Println(triangle(t1))

	t2 := [][]int{}
	fmt.Println(triangle(t2))

	t3 := [][]int{
		{1234},
		{12, 34},
	}
	fmt.Println(triangle(t3))
}

func triangle(t [][]int) int {
	if len(t) == 0 {
		return 0
	}

	s := make([]int, len(t))
	for i, n := 0, len(t)-1; i < len(t[n]); i++ {
		s[i] = t[n][i]
	}

	for i := len(t) - 2; i >= 0; i-- {
		for j := 0; j < len(t[i+1])-1; j++ {
			s[j] = t[i][j] + min(s[j], s[j+1])
		}
	}
	return s[0]
}

func min(a, b int) int {
	if a < b {
		return a
	}
	return b
}
