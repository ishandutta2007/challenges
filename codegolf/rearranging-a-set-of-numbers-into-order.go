/*

The Question

Given a set of 9 numbers, m[], which contains only numbers 1 through 9 in a random order, with no two numbers being the same, create a program in any language which rearranges the number to be in numerical order (1, 2, 3, etc. etc.) by only switching two numbers which are next to each other (ie. 1, 3, 2 → 1, 2, 3).
Rules

    You may only modify the set by switching two numbers which are next to each other
    The ending numbers (1 through 9 in order) should be contained in m[]
    You can use any language you would like
    The answer with the smallest amount of bytes wins

Edit:

Your code does not have to print the output, but the rearranged array must be in m[].

*/

package main

import (
	"fmt"
	"math/rand"
	"time"
)

func main() {
	rand.Seed(time.Now().UnixNano())
	test()
}

func test() {
	p := rand.Perm(9)
	fmt.Println(p)
	bubblesort(p)
	fmt.Println(p)
}

func bubblesort(a []int) []int {
	n := len(a)
	for i := 0; i < n-1; i++ {
		for j := 0; j < n-i-1; j++ {
			if a[j] > a[j+1] {
				a[j], a[j+1] = a[j+1], a[j]
			}
		}
	}
	return a
}
