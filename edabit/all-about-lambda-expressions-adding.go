/*

Write a function that returns a lambda expression, which adds n to its input

Examples

adds1 = adds_n(1)

adds1(3) ➞ 4
adds1(5.7) ➞ 6.7

adds10 = adds_n(10)

adds10(44) ➞ 54
adds10(20) ➞ 30

Notes

N/A

*/

package main

import "math"

func main() {
	add1 := addn(1)
	add10 := addn(10)
	add5neg := addn(-5)
	add0 := addn(0)

	test(add1, 3, 4)
	test(add1, 5.7, 6.7)
	test(add10, 44, 54)
	test(add10, 20, 30)
	test(add5neg, 0, -5)
	test(add5neg, 77, 72)
	test(add0, 77, 77)
}

func addn(n float64) func(float64) float64 {
	return func(m float64) float64 {
		return n + m
	}
}

func test(add func(float64) float64, n, r float64) {
	assert(math.Abs(add(n)-r) < 1e-8)
}

func assert(x bool) {
	if !x {
		panic("assertion failed")
	}
}
