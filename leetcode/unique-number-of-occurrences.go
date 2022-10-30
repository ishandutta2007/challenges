// Given an array of integers arr, write a function that returns true if
// and only if the number of occurrences of each value in the array is unique.

package main

import "fmt"

func main() {
	fmt.Println(uniq([]int{1, 2, 2, 1, 1, 3}))
	fmt.Println(uniq([]int{1, 2}))
	fmt.Println(uniq([]int{-3, 0, 1, -3, 1, 1, 1, -3, 10, 0}))
}

func uniq(a []int) bool {
	m := make(map[int]int)
	for _, v := range a {
		m[v]++
	}

	u := make(map[int]bool)
	for _, v := range m {
		if u[v] {
			return false
		}
		u[v] = true
	}
	return true
}
