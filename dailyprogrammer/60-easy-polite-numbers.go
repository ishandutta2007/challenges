/*

A polite number n is an integer that is the sum of two or more consecutive nonnegative integers in at least one way.

Here is an article helping in understanding Polite numbers

Your challenge is to write a function to determine the ways if a number is polite or not.

*/

package main

import "fmt"

func main() {
	for i := 0; i <= 100; i++ {
		fmt.Println(i, polite(i))
	}
}

// https://en.wikipedia.org/wiki/Polite_number
func polite(n int) [][]int {
	r := [][]int{}
	for i := 1; i < n; i++ {
		for j := i + 1; j < n; j++ {
			if (j+i)*(j-i+1)/2 == n {
				r = append(r, enum(i, j-i+1))
			}
		}
	}
	return r
}

func enum(x, n int) []int {
	p := []int{}
	for i := 0; i < n; i++ {
		p = append(p, x+i)
	}
	return p
}
