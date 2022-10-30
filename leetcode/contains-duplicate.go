/*

Given an array of integers, find if the array contains any duplicates.

Your function should return true if any value appears at least twice in the array, and it should return false if every element is distinct.

*/
package main

import "fmt"

func main() {
	fmt.Println(contains([]int{1, 2, 3, 1}))
	fmt.Println(contains([]int{1, 2, 3, 4}))
	fmt.Println(contains([]int{1, 1, 1, 3, 3, 4, 3, 2, 4, 2}))
}

func contains(a []int) bool {
	m := make(map[int]int)
	for _, v := range a {
		if m[v] > 0 {
			return true
		}
		m[v]++
	}
	return false
}
