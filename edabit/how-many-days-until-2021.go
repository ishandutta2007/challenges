/*

Given a date, return how many days date is away from 2021 (end date not included). date will be in mm/dd/yyyy format.
Examples

daysUntil2021("12/28/2020") ➞ "4 days"

daysUntil2021("1/1/2020") ➞ "366 days"

daysUntil2021("2/28/2020") ➞ "308 days"

Notes

All given dates will be in the year 2020.

*/

package main

import (
	"fmt"
	"time"
)

func main() {
	assert(days("12/28/2020") == "4 days")
	assert(days("12/29/2020") == "3 days")
	assert(days("1/1/2020") == "366 days")
	assert(days("2/28/2020") == "308 days")
	assert(days("6/30/2020") == "185 days")
	assert(days("10/22/2020") == "71 days")
	assert(days("12/31/2020") == "1 day")
}

func assert(x bool) {
	if !x {
		panic("assertion failed")
	}
}

func days(s string) string {
	t, err := time.Parse("1/2/2006", s)
	if err != nil {
		return err.Error()
	}

	nt := time.Date(2021, 1, 1, 0, 0, 0, 0, time.UTC)
	if t.After(nt) {
		nt = time.Date(2021, 12, 31, 0, 0, 0, 0, time.UTC)
		t, nt = nt, t
	}

	dt := nt.Sub(t).Hours() / 24
	p := fmt.Sprintf("%v day", dt)
	if dt > 1 {
		p += "s"
	}
	return p
}
