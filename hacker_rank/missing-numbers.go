/*
Numeros the Artist had two lists that were permutations of one another. He was very proud.
Unfortunately, while transporting them from one exhibition to another, some numbers were lost out of the first list. Can you find the missing numbers?

As an example, the array with some numbers missing, arr = [7 2 5 3 5 3]. The original array of numbers [7 2 5 4 6 3 5 3].
The numbers missing are [4 6].
*/
package main

import (
	"fmt"
	"sort"
)

func main() {
	a := []int{7, 2, 5, 3, 5, 3}
	b := []int{7, 2, 5, 4, 6, 3, 5, 3}
	fmt.Println(missing(a, b))

	a = []int{203, 204, 205, 206, 207, 208, 203, 204, 205, 206}
	b = []int{203, 204, 204, 205, 206, 207, 205, 208, 203, 206, 205, 206, 204}
	fmt.Println(missing(a, b))
}

func missing(a, b []int) []int {
	n := make(map[int]int)
	m := make(map[int]int)
	for _, x := range a {
		n[x]++
	}
	for _, x := range b {
		m[x]++
	}

	var p []int
	for k, _ := range m {
		if m[k] != n[k] {
			p = append(p, k)
		}
	}
	sort.Ints(p)
	return p
}
