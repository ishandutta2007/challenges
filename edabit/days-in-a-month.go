/*

Create a function that takes the month and year (as integers) and returns the number of days in that month.

Examples

days(2, 2018) ➞ 28

days(4, 654) ➞ 30

days(2, 200) ➞ 28

days(2, 1000) ➞ 28

Notes

Don't forget about leap years!

*/

package main

import (
	"time"
)

func main() {
	assert(days(1, 2018) == 31)
	assert(days(2, 2018) == 28)
	assert(days(3, 2018) == 31)
	assert(days(4, 2018) == 30)
	assert(days(5, 2018) == 31)
	assert(days(6, 2018) == 30)
	assert(days(7, 2018) == 31)
	assert(days(8, 2018) == 31)
	assert(days(9, 2018) == 30)
	assert(days(10, 2018) == 31)
	assert(days(11, 2018) == 30)
	assert(days(12, 2018) == 31)
	assert(days(2, 2004) == 29)
	assert(days(2, 1800) == 28)
	assert(days(2, 1600) == 29)
}

func assert(x bool) {
	if !x {
		panic("assertion failed")
	}
}

func days(m, y int) int {
	t := time.Date(y, time.Month(m+1), 0, 0, 0, 0, 0, time.UTC)
	return t.Day()
}
