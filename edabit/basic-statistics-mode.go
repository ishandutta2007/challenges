/*

The mode of a group of numbers is the value (or values) that occur most often (values have to occur more than once).
Given a sorted array of numbers, return an array of all modes in ascending order.

Notes

In this challenge, all group of numbers will have at least one mode.

*/

package main

import (
	"fmt"
)

func main() {
	fmt.Println(mode([]int{1, 2, 3, 3, 6, 7, 8, 9}))
	fmt.Println(mode([]int{2, 3, 3, 4, 4, 6, 7, 8}))
	fmt.Println(mode([]int{1, 6, 6, 7, 7, 8, 9}))
	fmt.Println(mode([]int{4, 4, 4, 6, 8, 9, 10, 10}))
	fmt.Println(mode([]int{1, 4, 6, 7, 9, 9}))
	fmt.Println(mode([]int{2, 2, 2, 3, 7, 8, 9, 9}))
	fmt.Println(mode([]int{2, 4, 5, 5, 7, 8, 10, 10}))
	fmt.Println(mode([]int{1, 1, 4, 4, 5, 7, 9}))
	fmt.Println(mode([]int{2, 3, 3, 3, 4, 7, 9}))
	fmt.Println(mode([]int{1, 1, 2, 4, 4, 6, 6, 9}))
	fmt.Println(mode([]int{1, 2, 3, 3, 3, 7, 9, 10}))
	fmt.Println(mode([]int{1, 2, 5, 6, 6, 6, 7, 10}))
	fmt.Println(mode([]int{2, 2, 6, 9, 10, 10, 10}))
	fmt.Println(mode([]int{1, 1, 5, 6, 6, 10, 10}))
	fmt.Println(mode([]int{2, 2, 3, 3, 4, 8}))
	fmt.Println(mode([]int{2, 3, 8, 10, 10, 10, 10}))
	fmt.Println(mode([]int{2, 2, 3, 4, 6, 9}))
	fmt.Println(mode([]int{1, 2, 5, 8, 9, 9, 10, 10}))
	fmt.Println(mode([]int{2, 3, 3, 4, 4, 5}))
	fmt.Println(mode([]int{2, 2, 3, 3, 4, 5, 10, 10}))
	fmt.Println(mode([]int{1, 3, 3, 5, 5, 9, 10, 10}))
}

func mode(a []int) []int {
	var p []int
	m := 0
	for n := 0; n < 2; n++ {
		for i := 0; i < len(a); {
			v := a[i]
			c := 1
			for ; i+1 < len(a) && a[i] == a[i+1]; i++ {
				c++
			}
			if c == 1 {
				i++
			}

			if n == 0 {
				m = max(m, c)
			} else if m == c {
				p = append(p, v)
			}
		}
	}
	return p
}

func max(a, b int) int {
	if a > b {
		return a
	}
	return b
}
