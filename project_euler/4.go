/*

A palindromic number reads the same both ways. The largest palindrome made from the product of two 2-digit numbers is 9009 = 91 × 99.

Find the largest palindrome made from the product of two 3-digit numbers.

*/
package main

import (
	"flag"
	"fmt"
	"math"
	"strconv"
)

func main() {
	N := 3
	flag.Parse()
	if flag.NArg() >= 1 {
		N, _ = strconv.Atoi(flag.Arg(0))
	}
	s := int(math.Pow(10, float64(N-1)))
	e := int(math.Pow(10, float64(N-1+1)))

	x, y, m := 0, 0, 0
	for a := s; a < e; a++ {
		for b := s; b < e; b++ {
			n := a * b
			if isPalindrome(n) && n > m {
				x, y, m = a, b, n
			}
		}
	}
	fmt.Println(x, y, m)
}

func isPalindrome(n int) bool {
	t := fmt.Sprintf("%d", n)
	for i := 0; i < len(t)/2; i++ {
		if t[i] != t[len(t)-1-i] {
			return false
		}
	}
	return true
}
