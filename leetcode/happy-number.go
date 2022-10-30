/*

Write an algorithm to determine if a number is "happy".

A happy number is a number defined by the following process: Starting with any positive integer, replace the number by the sum of the squares of its digits, and repeat the process until the number equals 1 (where it will stay), or it loops endlessly in a cycle which does not include 1. Those numbers for which this process ends in 1 are happy numbers.

*/

package main

import "fmt"

func main() {
	for i := uint(0); i < 1024; i++ {
		fmt.Println(i, happy(i))
	}
}

func happy(n uint) bool {
	if n == 0 {
		return false
	}
	m := make(map[uint]int)
	for n != 1 {
		s := uint(0)
		for ; n > 0; n /= 10 {
			v := n % 10
			s += v * v
		}
		n = s

		if m[n]++; m[n] > 1 {
			return false
		}
	}
	return true
}
