/*

Given a non-empty array of integers, every element appears twice except for one.
Find that single one.

Note:

Your algorithm should have a linear runtime complexity. Could you implement it without using extra memory?

*/

package main

import "fmt"

func main() {
	fmt.Println(single([]int{2, 2, 1}))
	fmt.Println(single([]int{4, 1, 2, 1, 2}))
}

func single(a []int) int {
	v := 0
	for i := range a {
		v ^= a[i]
	}
	return v
}
