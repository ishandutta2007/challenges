/*

Create a function that accepts a list of dates (unsorted with possible duplicates) and returns the days of the week in one of the following formats:

    A format similar to MTWTFSS or SMTWTFS (i.e. beginning with Monday or Sunday), with non-days replaced by an underscore _, illustrated below.
    WEEKDAY if all the dates are between Monday to Friday (i.e. Monday, Tuesday, Wednesday, Thursday and Friday must all be present, no other days)
    WEEKEND if all the dates are on Saturday or Sunday (i.e. Saturday and Sunday must both be present, no other days)
    ALLWEEK if all the dates are on all days of the week!

Assume the list of dates to be in your language's date data type (e.g. List<LocalDate> for Java), else the ISO date string "YYYY-MM-DD".
Addition: After looking at 05AB1E's entry, I'm now also inclined to accept 'the most convenient representation', but please explain clearly why this would be used in lieu of the original rules.
I just don't want to open the flood gates here...

If it helps, you can further assume that all dates are within an arbitrary calendar non-leap-year.

Examples:
Input 	Output (starting Monday) 	Output (starting Sunday)
["2021-06-21"] 	M______ 	_M_____
["2021-06-21", "2021-06-28"] 	M______ 	_M_____
["2021-06-22", "2021-06-22"] 	_T_____ 	__T____
["2021-06-23", "2021-07-16"] 	__W_F__ 	___W_F_
["2021-06-27", "2021-07-02", "2021-05-01"] 	____FSS 	S____FS
["2021-06-21", "2021-06-22", "2021-06-23", "2021-06-24", "2021-06-25"] 	WEEKDAY 	WEEKDAY
["2021-06-27", "2021-06-26", "2021-06-27"] 	WEEKEND 	WEEKEND
["2021-06-21", "2021-06-23", "2021-06-22", "2021-06-26", "2021-06-25", "2021-06-24", "2021-06-27"] 	ALLWEEK 	ALLWEEK

Winning Criteria: Shortest code wins.

*/

package main

import (
	"time"
)

func main() {
	assert(days([]string{"2021-06-21"}) == "M______")
	assert(days([]string{"2021-06-21", "2021-06-28"}) == "M______")
	assert(days([]string{"2021-06-22", "2021-06-22"}) == "_T_____")
	assert(days([]string{"2021-06-23", "2021-07-16"}) == "__W_F__")
	assert(days([]string{"2021-06-27", "2021-07-02", "2021-05-01"}) == "____FSS")
	assert(days([]string{"2021-06-21", "2021-06-22", "2021-06-23", "2021-06-24", "2021-06-25"}) == "WEEKDAY")
	assert(days([]string{"2021-06-27", "2021-06-26", "2021-06-27"}) == "WEEKEND")
	assert(days([]string{"2021-06-21", "2021-06-23", "2021-06-22", "2021-06-26", "2021-06-25", "2021-06-24", "2021-06-27"}) == "ALLWEEK")
}

func assert(x bool) {
	if !x {
		panic("assertion failed")
	}
}

func days(s []string) string {
	m := 0
	for _, p := range s {
		t, err := time.Parse("2006-01-02", p)
		if err != nil {
			return err.Error()
		}
		m |= getmask(t.Weekday())
	}
	return getday(m)
}

func getmask(d time.Weekday) int {
	switch d {
	case time.Monday:
		return 0x1
	case time.Tuesday:
		return 0x2
	case time.Wednesday:
		return 0x4
	case time.Thursday:
		return 0x8
	case time.Friday:
		return 0x10
	case time.Saturday:
		return 0x20
	case time.Sunday:
		return 0x40
	}
	return 0
}

func getday(m int) (r string) {
	switch m & 0x7f {
	case 0x1f:
		return "WEEKDAY"
	case 0x60:
		return "WEEKEND"
	case 0x7f:
		return "ALLWEEK"
	}

	const wd = "MTWTFSS"
	for i := range wd {
		if m&(1<<i) != 0 {
			r += string(wd[i])
		} else {
			r += "_"
		}
	}
	return
}
