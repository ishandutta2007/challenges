/*

Given the parameters day, month and year, return whether that date is a valid date.

Examples

is_valid_date(35, 2, 2020) ➞ False
# February doesn't have 35 days.

is_valid_date(8, 3, 2020) ➞ True
# 8th March 2020 is a real date.

is_valid_date(31, 6, 1980) ➞ False
# June only has 30 days.

Notes

Try using the datetime module to complete this challenge (see the Resources tab for some tutorials on this).

*/

package main

import "time"

func main() {
	assert(validate(35, 2, 2020) == false)
	assert(validate(8, 3, 2020) == true)
	assert(validate(31, 6, 1980) == false)
	assert(validate(27, 9, 1822) == true)
	assert(validate(34, 7, 2008) == false)
	assert(validate(32, 12, 1932) == false)
	assert(validate(20, 3, 2019) == true)
	assert(validate(28, 3, 2004) == true)
	assert(validate(22, 5, 1962) == true)
	assert(validate(21, 11, 1875) == true)
	assert(validate(6, 12, 1982) == true)
	assert(validate(6, 10, 1873) == true)
	assert(validate(5, 6, 1852) == true)
	assert(validate(21, 4, 1809) == true)
	assert(validate(6, 15, 1969) == false)
	assert(validate(6, 7, 1893) == true)
	assert(validate(25, 4, 1826) == true)
	assert(validate(16, 6, 1922) == true)
	assert(validate(16, 10, 1803) == true)
	assert(validate(5, 6, 1980) == true)
	assert(validate(12, 15, 2018) == false)
	assert(validate(35, 12, 1972) == false)
	assert(validate(16, 11, 2028) == true)
	assert(validate(2, 6, 1947) == true)
	assert(validate(1, 10, 1904) == true)
	assert(validate(8, 13, 1954) == false)
	assert(validate(27, 14, 2012) == false)
	assert(validate(3, 6, 2018) == true)
	assert(validate(16, 3, 1992) == true)
	assert(validate(33, 14, 1878) == false)
	assert(validate(23, 10, 1841) == true)
	assert(validate(3, 12, 1865) == true)
	assert(validate(7, 14, 1901) == false)
	assert(validate(16, 11, 2042) == true)
	assert(validate(21, 1, 1837) == true)
	assert(validate(14, 11, 1945) == true)
	assert(validate(15, 9, 1913) == true)
	assert(validate(29, 8, 1892) == true)
	assert(validate(11, 15, 1936) == false)
	assert(validate(28, 5, 1957) == true)
	assert(validate(7, 4, 1864) == true)
	assert(validate(24, 8, 2011) == true)
	assert(validate(29, 15, 1930) == false)
	assert(validate(2, 5, 1970) == true)
	assert(validate(35, 6, 2013) == false)
	assert(validate(31, 12, 1863) == true)
	assert(validate(7, 14, 2026) == false)
	assert(validate(8, 2, 1809) == true)
	assert(validate(25, 4, 1996) == true)
	assert(validate(29, 5, 1854) == true)
	assert(validate(19, 7, 2034) == true)
	assert(validate(21, 10, 1950) == true)
	assert(validate(20, 10, 1926) == true)
	assert(validate(29, 2, 2020) == true)
	assert(validate(29, 2, 2019) == false)
}

func assert(x bool) {
	if !x {
		panic("assertion failed")
	}
}

func validate(d, m, y int) bool {
	if !(1 <= m && m <= 12) {
		return false
	}

	t := time.Date(y, time.Month(m), d, 0, 0, 0, 0, time.UTC)
	if t.Month() != time.Month(m) || t.Year() != y {
		return false
	}

	return true
}
