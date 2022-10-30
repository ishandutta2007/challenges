/*

Mubashir needs your help to find the Simple Numbers in a given range.

A number X, that has an N amount of digits (which we'll enumerate as d1, d2, ..., dN), is Simple if the following equation holds true:

X = d1^1 + d2^2 + ... + dN^N

Examples of Simple Numbers:

89 = 8^1 + 9^2

135 = 1^1 + 3^2 + 5^3

Create a function that returns an array of all the Simple Numbers that exist within a given range between a and b (both numbers are inclusive).

    Generate an array with the numbers from a to b.
    Filter the array so that only "simple numbers" are kept.
    To find out if a number is "simple":
        Generate an array of the individual digits of the number.
        For each digit, calculate digit ^ (indexOfTheDigit + 1).
        Sum the results of the calculations above and compare with the original number, if they're equal, the number is "simple".

Examples

simpleNumbers(1, 10) ➞ [1, 2, 3, 4, 5, 6, 7, 8, 9]

simpleNumbers(1, 100) ➞ [1, 2, 3, 4, 5, 6, 7, 8, 9, 89]

simpleNumbers(90, 100) ➞ []

Notes

N/A

*/

package main

import (
	"fmt"
	"reflect"
)

func main() {
	test(1, 10, []int{1, 2, 3, 4, 5, 6, 7, 8, 9})
	test(1, 100, []int{1, 2, 3, 4, 5, 6, 7, 8, 9, 89})
	test(10, 89, []int{89})
	test(10, 100, []int{89})
	test(90, 100, []int{})
	test(90, 150, []int{135})
	test(50, 150, []int{89, 135})
	test(10, 150, []int{89, 135})
	test(89, 135, []int{89, 135})
	test(100, 32253, []int{135, 175, 518, 598, 1306, 1676, 2427})
}

func test(a, b int, r []int) {
	p := simple(a, b)
	fmt.Println(p)
	if len(p) == 0 {
		assert(len(p) == len(r))
	} else {
		assert(reflect.DeepEqual(p, r))
	}
}

func assert(x bool) {
	if !x {
		panic("assertion failed")
	}
}

func simple(a, b int) []int {
	var p []int
	for i := a; i <= b; i++ {
		if valid(i) {
			p = append(p, i)
		}
	}
	return p
}

func valid(n int) bool {
	var d []int
	n = abs(n)
	for v := n; v != 0; v /= 10 {
		d = append(d, v%10)
	}

	r := 0
	for i := range d {
		r += ipow(d[i], len(d)-i)
	}

	return r == n
}

func abs(x int) int {
	if x < 0 {
		x = -x
	}
	return x
}

func ipow(x, y int) int {
	if y < 0 {
		return 0
	}

	p := 1
	for i := 0; i < y; i++ {
		p *= x
	}
	return p
}
