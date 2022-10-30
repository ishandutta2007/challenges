/*

Create a function that takes a list containing nested lists as an argument. Each sublist has 2 elements. The first element is the numerator and the second element is the denominator. Return the sum of the fractions rounded to the nearest whole number.
Examples

sum_fractions([[18, 13], [4, 5]]) ➞ 2

sum_fractions([[36, 4], [22, 60]]) ➞ 9

sum_fractions([[11, 2], [3, 4], [5, 4], [21, 11], [12, 6]]) ➞ 11

Notes

Your result should be a number not string.

Test.assert_equals(sum_fractions([[36, 4], [22, 60]]), 9)

Test.assert_equals(sum_fractions([[-11, 12], [18, 13], [4, 5]]), 1)

Test.assert_equals(sum_fractions([[11, 12], [18, 13], [4, 5]]), 3)

Test.assert_equals(sum_fractions([[18, 13], [4, 5]]), 2)

Test.assert_equals(sum_fractions([[41, 14], [10, 91]]), 3)

Test.assert_equals(sum_fractions([[11, 2], [3, 4], [5, 4], [21, 11], [12, 6]]), 11)

*/

package main

import (
	"math/big"
	"strconv"
)

func main() {
	assert(fractions([][2]int{{36, 4}, {22, 60}}) == 9)
	assert(fractions([][2]int{{-11, 12}, {18, 13}, {4, 5}}) == 1)
	assert(fractions([][2]int{{11, 12}, {18, 13}, {4, 5}}) == 3)
	assert(fractions([][2]int{{18, 13}, {4, 5}}) == 2)
	assert(fractions([][2]int{{41, 14}, {10, 91}}) == 3)
	assert(fractions([][2]int{{11, 2}, {3, 4}, {5, 4}, {21, 11}, {12, 6}}) == 11)

}

func fractions(a [][2]int) int {
	s := big.NewRat(0, 1)
	for _, v := range a {
		r := big.NewRat(int64(v[0]), int64(v[1]))
		s.Add(s, r)
	}
	f := s.FloatString(0)
	n, _ := strconv.Atoi(f)
	return n
}

func assert(x bool) {
	if !x {
		panic("assertion failed")
	}
}
