/*

An array is positive dominant if it contains strictly more unique positive values than unique negative values.

Write a function that returns true if an array is positive dominant.

Notes

0 neither counts as a positive nor a negative value.

*/

package main

import "fmt"

func main() {
	fmt.Println(isposdom([]int{1, 1, 1, 1, -3, -4}))
	fmt.Println(isposdom([]int{5, 99, 832, -3, -4}))
	fmt.Println(isposdom([]int{5, 0}))
	fmt.Println(isposdom([]int{0, -4, -1}))
	fmt.Println(isposdom([]int{1, 2, 3, -1}))
	fmt.Println(isposdom([]int{1, 0, 0, -1}))
	fmt.Println(isposdom([]int{5, 4, 3, 0, 0, -1, -1, -2, -2}))
	fmt.Println(isposdom([]int{52, 52, 52, -3, 2, 2, 2, -4}))
	fmt.Println(isposdom([]int{3, 3, 3, 3, -1, -1, -1}))
}

func isposdom(a []int) bool {
	m := make(map[int]bool)
	x, y := 0, 0
	for _, v := range a {
		if m[v] {
			continue
		}
		m[v] = true
		if v > 0 {
			x++
		} else if v < 0 {
			y++
		}
	}
	return x > y
}
