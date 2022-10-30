/*

Each year has 365 or 366 days. Given a string date representing a Gregorian calendar date formatted as month/day/year, return the day-number of the year.

Examples

dayOfYear("12/13/2020") ➞ 348

dayOfYear("12/17/2020") ➞ 352

dayOfYear("11/16/2020") ➞ 321

dayOfYear("1/9/2019") ➞ 9

dayOfYear("3/1/2004") ➞ 61

dayOfYear("12/31/2000") ➞ 366

Notes

All input strings in the tests are valid dates.

*/

package main

import (
	"time"
)

func main() {
	tab := []struct {
		date    string
		yearday int
	}{
		{"12/13/2020", 348},
		{"12/17/2020", 352},
		{"11/16/2020", 321},
		{"1/9/2019", 9},
		{"3/1/2004", 61},
		{"12/31/2000", 366},
		{"7/25/2015", 206},
		{"10/15/1985", 288},
		{"2/29/1904", 60},
		{"8/29/1900", 241},
		{"10/7/2050", 280},
		{"4/1/3024", 92},
		{"2/29/1600", 60},
		{"3/31/1999", 90},
		{"5/3/0002", 123},
		{"9/11/2001", 254},
		{"7/1/1996", 183},
		{"11/3/2020", 308},
	}
	for _, p := range tab {
		assert(yearday(p.date) == p.yearday)
	}
}

func assert(x bool) {
	if !x {
		panic("assertion failed")
	}
}

func yearday(s string) int {
	t, err := time.Parse("1/2/2006", s)
	if err != nil {
		return -1
	}
	return t.YearDay()
}
