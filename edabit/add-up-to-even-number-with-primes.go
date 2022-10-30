/*

Create a function that takes an even number (will always be greater than 4) and return an array of all pairs of prime numbers which add up to the given number.

Examples

primePairArr(10) ➞ ["3+7", "5+5"]

primePairArr(50) ➞ ["3+47", "7+43", "13+37", "19+31"]

primePairArr(100) ➞ ["3+97", "11+89", "17+83", "29+71", "41+59", "47+53"]

Notes

N/A

*/

package main

import (
	"fmt"
	"math"
	"reflect"
)

func main() {
	test(10, []string{"3+7", "5+5"})
	test(20, []string{"3+17", "7+13"})
	test(30, []string{"7+23", "11+19", "13+17"})
	test(50, []string{"3+47", "7+43", "13+37", "19+31"})
	test(80, []string{"7+73", "13+67", "19+61", "37+43"})
	test(100, []string{"3+97", "11+89", "17+83", "29+71", "41+59", "47+53"})
}

func test(n uint, r []string) {
	assert(reflect.DeepEqual(primepair(n), r))
}

func assert(x bool) {
	if !x {
		panic("assertion failed")
	}
}

func primepair(n uint) []string {
	var r []string
	p := eratosthenes(n)
	for i := 0; i < len(p); i++ {
		for j := i; j < len(p); j++ {
			if p[i]+p[j] == n {
				r = append(r, fmt.Sprintf("%v+%v", p[i], p[j]))
			}
		}
	}
	return r
}

func eratosthenes(n uint) []uint {
	l := uint(math.Sqrt(float64(n)))
	p := make([]bool, n)
	for i := uint(2); i <= l; i++ {
		for j := i + i; j < n; j += i {
			p[j] = true
		}
	}

	var r []uint
	for i := uint(2); i < n; i++ {
		if !p[i] {
			r = append(r, i)
		}
	}
	return r
}
