/*

Given an integer n

(n≥1), return/output the total number of set bits between 1 and n inclusive. To make the problem more interesting, your solution must run with a time complexity of O((logn)k) or better, for some constant k

(AKA poly-logarithmic time complexity).

This is OEIS A000788, not including n=0

. Here are the first 100 numbers:

1, 2, 4, 5, 7, 9, 12, 13, 15, 17, 20, 22, 25, 28, 32, 33, 35, 37, 40, 42, 45, 48, 52, 54, 57, 60, 64, 67, 71, 75, 80, 81, 83, 85, 88, 90, 93, 96, 100, 102, 105, 108, 112, 115, 119, 123, 128, 130, 133, 136, 140, 143, 147, 151, 156, 159, 163, 167, 172, 176, 181, 186, 192, 193, 195, 197, 200, 202, 205, 208, 212, 214, 217, 220, 224, 227, 231, 235, 240, 242, 245, 248, 252, 255, 259, 263, 268, 271, 275, 279, 284, 288, 293, 298, 304, 306, 309, 312, 316, 319


*/

package main

import (
	"fmt"
)

func main() {
	for i := 0; i <= 100; i++ {
		fmt.Println(i, sum(i))
	}
}

// https://oeis.org/A000788
func sum(n int) int {
	if n <= 0 {
		return 0
	}
	m := ilog2(n)
	r := n % (1 << m)
	if m != 0 {
		m *= (1 << (m - 1))
	}
	return m + r + 1 + sum(r)
}

func ilog2(n int) int {
	r := 0
	p := 1
	for ; p < n; p <<= 1 {
		r++
	}
	if p > n {
		r--
	}
	return r
}
