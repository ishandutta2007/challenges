/*

Generate the following list of lists consisting of the unique last digits of the powers from 1 to 9 for the numbers [0..9]

[[0], [1], [2, 4, 8, 6], [3, 9, 7, 1], [4, 6], [5], [6], [7, 9, 3, 1], [8, 4, 2, 6], [9, 1]]

e.g. For the number 2 we have: 21,22,23,24,25,...→2,4,8,16,32,64,128,...→2,4,8,6,4,8,...→[2,4,8,6]

This is code-golf, so shortest answer (as measured in bytes) wins and the usual golfing rules apply.

*/

package main

import (
	"fmt"
	"math"
)

func main() {
	fmt.Println(gen())
}

func gen() [][]int {
	var r [][]int
	for i := 0; i <= 9; i++ {
		var h [10]int
		var p []int
		for j := 1; j <= 9; j++ {
			d := ipow(i, j) % 10
			if h[d]++; h[d] == 1 {
				p = append(p, d)
			}
		}
		r = append(r, p)
	}
	return r
}

func ipow(x, y int) int {
	return int(math.Pow(float64(x), float64(y)))
}
