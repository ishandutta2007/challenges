/*

Given the month and year as numbers, return whether that month contains a Friday 13th.

Examples

has_friday_13(3, 2020) ➞ True

has_friday_13(10, 2017) ➞ True

has_friday_13(1, 1985) ➞ False

Notes

    January will be given as 1, February as 2, etc ...
    Check Resources for some helpful tutorials on Python's datetime module.

*/

package main

import "time"

func main() {
	assert(friday13(3, 2020) == true)
	assert(friday13(10, 2017) == true)
	assert(friday13(1, 1985) == false)
	assert(friday13(5, 1619) == false)
	assert(friday13(6, 1614) == true)
	assert(friday13(8, 1767) == false)
	assert(friday13(6, 1589) == false)
	assert(friday13(2, 2015) == true)
	assert(friday13(3, 2015) == true)
	assert(friday13(11, 2015) == true)
	assert(friday13(2, 1759) == false)
	assert(friday13(8, 1612) == false)
	assert(friday13(8, 1612) == false)
	assert(friday13(10, 2029) == false)
	assert(friday13(1, 1590) == false)
	assert(friday13(7, 1812) == false)
	assert(friday13(1, 1785) == false)
	assert(friday13(11, 1961) == false)
	assert(friday13(9, 1706) == false)
	assert(friday13(5, 2016) == true)
	assert(friday13(11, 2020) == true)
	assert(friday13(1, 2023) == true)
	assert(friday13(10, 2023) == true)
	assert(friday13(2, 2043) == true)
	assert(friday13(4, 2043) == false)
	assert(friday13(3, 2043) == true)
	assert(friday13(11, 2043) == true)
}

func friday13(m, y int) bool {
	t := time.Date(y, time.Month(m), 13, 0, 0, 0, 0, time.UTC)
	return t.Weekday() == time.Friday
}

func assert(x bool) {
	if !x {
		panic("assertion failed")
	}
}
