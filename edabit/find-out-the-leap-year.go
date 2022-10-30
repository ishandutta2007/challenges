/*

A leap year happens every four years, so it's a year that is perfectly divisible by four. However, if the year is a multiple of 100 (1800, 1900, etc), the year must be divisible by 400.

Write a function that determines if the year is a leap year or not.
Examples

leapYear(2020) ➞ true

leapYear(2021) ➞ false

leapYear(1968) ➞ true

Notes

N/A

*/

package main

func main() {
	assert(isleap(2004) == true)
	assert(isleap(8) == true)
	assert(isleap(4) == true)
	assert(isleap(2019) == false)
	assert(isleap(1970) == false)
	assert(isleap(2021) == false)
	assert(isleap(1934) == false)
	assert(isleap(1874) == false)
	assert(isleap(1968) == true)
	assert(isleap(2024) == true)
	assert(isleap(1900) == false)
	assert(isleap(2100) == false)
	assert(isleap(2200) == false)
}

func isleap(y uint) bool {
	if y%4 != 0 {
		return false
	}

	if y%100 == 0 && y%400 != 0 {
		return false
	}

	return true
}

func assert(x bool) {
	if !x {
		panic("assertion failed")
	}
}
