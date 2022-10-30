/*

Given the number of dices and the sum we want to get the chance of, return the chance rounded to 2 decimals, formatted as shown (with the % at the end).

Examples

chance(3, 6) ➞ "4.63%"
// There is approximately 4.63% chance for rolling 6 with 3 dice.

chance(5, 20) ➞ "8.37%"

chance(2, 7) ➞ "16.67%"

Notes

N/A

*/

package main

import (
	"fmt"
	"math"
)

func main() {
	test(3, 6, "4.63%")
	test(5, 20, "8.37%")
	test(2, 7, "16.67%")
	test(4, 9, "4.32%")
	test(3, 9, "11.57%")
	test(6, 7, "0.01%")
	test(1, 5, "16.67%")
	test(5, 16, "9.45%")
	test(2, 6, "13.89%")
	test(2, 11, "5.56%")
	test(0, 0, "100.00%")
}

func test(n, s int, r string) {
	p := chance(n, s)
	fmt.Println(p)
	assert(p == r)
}

func assert(x bool) {
	if !x {
		panic("assertion failed")
	}
}

func chance(n, s int) string {
	if n < 0 || s < 0 {
		return "0.00%"
	}
	x := recurse(n, s, 0)
	y := math.Pow(6, float64(n))
	p := fmt.Sprintf("%.2f%%", float64(x)*100/y)
	return p
}

func recurse(n, s, v int) int {
	if n < 0 || v > s {
		return 0
	}
	if n == 0 && v == s {
		return 1
	}
	r := 0
	for i := 1; i <= 6; i++ {
		r += recurse(n-1, s, v+i)
	}
	return r
}
