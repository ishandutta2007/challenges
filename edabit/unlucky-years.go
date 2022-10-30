/*

Create a function which returns how many Friday 13ths there are in a given year.

Examples

how_unlucky(2020) ➞ 2

how_unlucky(2026) ➞ 3

how_unlucky(2016) ➞ 1

Notes

Check Resources for some helpful tutorials on the Python datetime module.

*/

package main

import "time"

func main() {
	assert(unlucky(2000) == 1)
	assert(unlucky(2001) == 2)
	assert(unlucky(2002) == 2)
	assert(unlucky(2003) == 1)
	assert(unlucky(2004) == 2)
	assert(unlucky(2005) == 1)
	assert(unlucky(2006) == 2)
	assert(unlucky(2007) == 2)
	assert(unlucky(2008) == 1)
	assert(unlucky(2009) == 3)
	assert(unlucky(2010) == 1)
	assert(unlucky(2011) == 1)
	assert(unlucky(2012) == 3)
	assert(unlucky(2013) == 2)
	assert(unlucky(2014) == 1)
	assert(unlucky(2015) == 3)
	assert(unlucky(2016) == 1)
	assert(unlucky(2017) == 2)
	assert(unlucky(2018) == 2)
	assert(unlucky(2019) == 2)
	assert(unlucky(2020) == 2)
	assert(unlucky(2021) == 1)
	assert(unlucky(2022) == 1)
	assert(unlucky(2023) == 2)
	assert(unlucky(2024) == 2)
	assert(unlucky(2025) == 1)
	assert(unlucky(2026) == 3)
	assert(unlucky(2027) == 1)
	assert(unlucky(2028) == 1)
	assert(unlucky(2029) == 2)
	assert(unlucky(2030) == 2)
	assert(unlucky(2031) == 1)
	assert(unlucky(2032) == 2)
	assert(unlucky(2033) == 1)
	assert(unlucky(2034) == 2)
	assert(unlucky(2035) == 2)
	assert(unlucky(2036) == 1)
	assert(unlucky(2037) == 3)
	assert(unlucky(2038) == 1)
	assert(unlucky(2039) == 1)
	assert(unlucky(2040) == 3)
	assert(unlucky(2041) == 2)
	assert(unlucky(2042) == 1)
	assert(unlucky(2043) == 3)
	assert(unlucky(2044) == 1)
	assert(unlucky(2045) == 2)
	assert(unlucky(2046) == 2)
	assert(unlucky(2047) == 2)
	assert(unlucky(2048) == 2)
	assert(unlucky(2049) == 1)
	assert(unlucky(2050) == 1)
}

func unlucky(y int) int {
	n := 0
	for m := 1; m <= 12; m++ {
		t := time.Date(y, time.Month(m), 13, 0, 0, 0, 0, time.UTC)
		if t.Weekday() == time.Friday {
			n++
		}
	}
	return n
}

func assert(x bool) {
	if !x {
		panic("assertion failed")
	}
}
