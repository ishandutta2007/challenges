/*

Write a method that when passed a date as "dd mm yyyy" and returns the date's weekday name in the Dutch culture.
Examples

weekdayDutch("21 9 1970") ➞ "maandag"

weekdayDutch(new DateTime("2 9 1945") ➞ "zondag"

weekdayDutch(new DateTime("9 11 2001") ➞ "dinsdag"

Notes

    Check the Resources tab for help.
    You can assume the specified date is valid.

*/

package main

import (
	"fmt"
	"time"
)

func main() {
	assert(dutchday("21 9 1970") == "maandag")
	assert(dutchday("22 9 1970") == "dinsdag")
	assert(dutchday("23 9 1970") == "woensdag")
	assert(dutchday("24 9 1970") == "donderdag")
	assert(dutchday("25 9 1970") == "vrijdag")
	assert(dutchday("26 9 1970") == "zaterdag")
	assert(dutchday("27 9 1970") == "zondag")
	assert(dutchday("10 12 2050") == "zaterdag")
	assert(dutchday("14 10 6010") == "donderdag")
	assert(dutchday("31 1 1000") == "vrijdag")
	assert(dutchday("8 12 2112") == "donderdag")
	assert(dutchday("12 12 1212") == "woensdag")
}

func dutchday(s string) string {
	tab := [...]string{
		time.Sunday:    "zondag",
		time.Monday:    "maandag",
		time.Tuesday:   "dinsdag",
		time.Wednesday: "woensdag",
		time.Thursday:  "donderdag",
		time.Friday:    "vrijdag",
		time.Saturday:  "zaterdag",
	}

	var d, m, y int
	n, _ := fmt.Sscanf(s, "%d %d %d", &d, &m, &y)
	if n != 3 {
		return ""
	}

	t := time.Date(y, time.Month(m), d, 0, 0, 0, 0, time.UTC)
	return tab[t.Weekday()]
}

func assert(x bool) {
	if !x {
		panic("assertion failed")
	}
}
