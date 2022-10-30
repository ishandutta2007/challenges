/*

Validating a CPR number
A Danish CPR number (Person Identification Number) is date of birth followed by 4 digits (the last one being a control digit): DDMMYY-XXXX

The final digit validates the CPR number using Modulo 11 by satisfying the following equation:

mod11

where the enter image description here are the ten digits of the complete ID number, and the coefficients (4, 3, 2, 7, …) are all nonzero in the finite field of order 11.

Input
A CPR number formatted like this DDMMYY-XXXX where YY indicates a year within the last 100 years (between 1917 and 2016).

Output
Indication whether CPR number is valid (1 or true) or invalid (0 or false)

Examples
  290215-2353 --> false
  140585-2981 --> true
  311217-6852 --> true
  121200-0004 --> false
  140322-5166 --> false
  111111-1118 --> true

Scoring
This is code-golf - fewest bytes win!

Date validation
All years refer to a period within the last 100 years. A valid date is a date that exists within it's calendar year.

290215 is not a valid date because 29/2 wasn't a date in 2015.

301216 is a valid date because 30/12 is a date in 2016.

*/

package main

import (
	"time"
)

func main() {
	assert(cpr("290215-2353") == false)
	assert(cpr("140585-2981") == true)
	assert(cpr("311217-6852") == true)
	assert(cpr("121200-0004") == false)
	assert(cpr("140322-5166") == false)
	assert(cpr("111111-1118") == true)
}

func assert(x bool) {
	if !x {
		panic("assertion failed")
	}
}

func cpr(s string) bool {
	x, ok := parse(s)
	if !ok {
		return false
	}

	_, err := time.Parse("020106", s[:6])
	if err != nil {
		return false
	}

	return checksum(x) == 0
}

func parse(s string) (x [10]int, ok bool) {
	const layout = "DDMMYY-XXXX"
	if len(s) != len(layout) {
		return
	}

	n := 0
	for i := range layout {
		switch layout[i] {
		case 'D', 'M', 'Y', 'X':
			if !('0' <= s[i] && s[i] <= '9') {
				return
			}
			x[n], n = int(s[i]-'0'), n+1

		default:
			if s[i] != layout[i] {
				return
			}
		}
	}
	return x, true
}

func checksum(x [10]int) int {
	c := [10]int{4, 3, 2, 7, 6, 5, 4, 3, 2, 1}
	r := 0
	for i := range x {
		r += x[i] * c[i]
	}
	return r % 11
}
