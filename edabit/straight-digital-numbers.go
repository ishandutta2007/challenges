/*

In this challenge, you have to establish if the digits of a given number form a straight arithmetic sequence (either increasing or decreasing). A straight sequence has an equal step between every pair of digits.

Given an integer n, implement a function that returns:

    "Not Straight" if n is lower than 100 or if its digits are not an arithmetic sequence.
    "Trivial Straight" if n has a single repeating digit.
    An integer being the step of the sequence if the n digits are a straight arithmetic sequence.

Examples

straightDigital(123) ➞ 1
// 2 - 1 = 1 | 3 - 2 = 1

straightDigital(753) ➞ -2
// 5 - 7 = -2 | 3 - 5 = -2

straightDigital(666) ➞ "Trivial Straight"
// There's a single repeating digit (step = 0).

straightDigital(124) ➞ "Not Straight"
// 2 - 1 = 1 | 4 - 2 = 2
// A valid sequence has always the same step between its digits.

straightDigital(99) ➞ "Not Straight"
// The number is lower than 100.

Notes

    The step of the sequence can be either positive or negative (see example #2).
    Trivia: there are infinite straight digital numbers, but only 96 of them are made of at least two different digits.

*/

package main

func main() {
	assert(straightdigital(123) == 1)
	assert(straightdigital(753) == -2)
	assert(straightdigital(666) == "Trivial Straight")
	assert(straightdigital(124) == "Not Straight")
	assert(straightdigital(99) == "Not Straight")
	assert(straightdigital(13579) == 2)
	assert(straightdigital(111111) == "Trivial Straight")
	assert(straightdigital(9630) == -3)
	assert(straightdigital(-123456789) == "Not Straight")
	assert(straightdigital(951) == -4)
	assert(straightdigital(24642) == "Not Straight")
	assert(straightdigital(147) == 3)
	assert(straightdigital(13579) == 2)
	assert(straightdigital(9876543210) == -1)
	assert(straightdigital(1313) == "Not Straight")
}

func straightdigital(n int64) interface{} {
	if n < 100 {
		return "Not Straight"
	}

	s := 0
	for f := 0; n/10 != 0; {
		t := int(n%10 - (n/10)%10)
		n /= 10
		if f == 0 {
			s, f = t, 1
		}
		if s != t {
			return "Not Straight"
		}
	}
	if s == 0 {
		return "Trivial Straight"
	}
	return s
}

func assert(x bool) {
	if !x {
		panic("assertion failed")
	}
}
