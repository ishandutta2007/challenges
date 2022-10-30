/*

Given an array of integers, return indices of the two numbers such that they add up to a specific target.

You may assume that each input would have exactly one solution, and you may not use the same element twice.

*/

package main

import (
	"fmt"
)

func main() {
	fmt.Println(find([]int{2, 7, 11, 15}, 9))
}

func find(a []int, t int) (int, int) {
	m := make(map[int]int)
	for i, v := range a {
		if j, f := m[t-v]; f {
			return j, i
		}
		m[v] = i
	}
	return -1, -1
}
