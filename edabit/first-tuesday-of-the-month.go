/*

Every month, Microny™️ (a big entertainment corporation) publishes a few free videogames on their web store.
You are working on a script that will notify you whenever the new games are available for download.
There is not a fixed date for the new releases, but you know that it happens every first Tuesday of every month.

Write a function that, given a year and a month, returns a string with the date of when the new games will be available.

Examples

firstTuesdayOfTheMonth(1997, 1) ➞ "1997-01-07"

firstTuesdayOfTheMonth(2021, 2) ➞ "2021-02-02"

firstTuesdayOfTheMonth(2020, 3) ➞ "2020-03-03"

Notes

Months are given as numbers starting at 1 = January.

*/

package main

import (
	"time"
)

func main() {
	assert(tuesday(1997, 1) == "1997-01-07")
	assert(tuesday(2021, 2) == "2021-02-02")
	assert(tuesday(2020, 3) == "2020-03-03")
	assert(tuesday(1998, 4) == "1998-04-07")
	assert(tuesday(1992, 5) == "1992-05-05")
	assert(tuesday(2009, 6) == "2009-06-02")
	assert(tuesday(1987, 7) == "1987-07-07")
	assert(tuesday(2026, 8) == "2026-08-04")
	assert(tuesday(2020, 9) == "2020-09-01")
	assert(tuesday(2009, 10) == "2009-10-06")
	assert(tuesday(1998, 11) == "1998-11-03")
	assert(tuesday(1981, 12) == "1981-12-01")
}

func assert(x bool) {
	if !x {
		panic("assertion failed")
	}
}

func tuesday(y, m int) string {
	var r string
	for d := 1; d <= 31; d++ {
		t := time.Date(y, time.Month(m), d, 0, 0, 0, 0, time.UTC)
		if t.Weekday() == time.Tuesday {
			r = t.Format("2006-01-02")
			break
		}
	}
	return r
}
