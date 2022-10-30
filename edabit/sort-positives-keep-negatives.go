/*

Write a function that sorts the positive numbers in ascending order, and keeps the negative numbers untouched.

Notes

    If given an empty array, you should return an empty array.
    Integers will always be either positive or negative (0 isn't included in the tests).

*/

package main

import (
	"fmt"
	"sort"
)

func main() {
	fmt.Println(posnegsort([]int{6, 3, -2, 5, -8, 2, -2}))
	fmt.Println(posnegsort([]int{6, 5, 4, -1, 3, 2, -1, 1}))
	fmt.Println(posnegsort([]int{-5, -5, -5, -5, 7, -5}))
	fmt.Println(posnegsort([]int{-5, -5, -5, -5, -4, -5}))
	fmt.Println(posnegsort([]int{-5, 4, -8, 3, -1, 2, 1, -7}))
	fmt.Println(posnegsort([]int{-5, 4, 3}))
	fmt.Println(posnegsort([]int{}))
}

func posnegsort(a []int) []int {
	t := make([]int, len(a))
	n := 0
	for i := range a {
		if a[i] >= 0 {
			t[n], n = a[i], n+1
		}
	}
	t = t[:n]

	sort.Ints(t)

	p := make([]int, len(a))
	j := 0
	for i := range a {
		p[i] = a[i]
		if a[i] >= 0 {
			p[i], j = t[j], j+1
		}
	}

	return p
}
