/*

Write a function which takes a date and returns the day of the week of the next February 29th after that date.

    The input is a string in the ISO Extended format: YYYY-MM-DD (e.g. May 27th, 2010 would be "2010-05-27").

    The output is a string which is the name of the day of the week (e.g. "Monday"). Capitalization doesn't matter, but do give the full name in English.

    If the given date is February 29th, then return the day of the week of the next Feburary 29th.

    Use the calculations for the Proleptic Gregorian Calendar (so, it uses the Gregorian leap year calculations for it's entire length). Don't worry about the Julian Calendar or when the switch from Julian to Gregorian occurred. Just assume Gregorian for everything.

    The function should work for at least the range of "0001-01-01" - "2100-01-01".

    Feel free to use whatever standard libraries your language of choice provides, but do not use 3rd party libraries unless you want to include that code as part of your solution.

    Shortest code (fewest characters) wins.

Examples:

    func("0001-01-01") -> "Sunday"
    func("1899-12-03") -> "Monday"
    func("1970-01-01") -> "Tuesday"
    func("1999-07-06") -> "Tuesday"
    func("2003-05-22") -> "Sunday"
    func("2011-02-17") -> "Wednesday"
    func("2100-01-01") -> "Friday"

(and no, you don't have to name the function func)

Hints:

    Remember that years ending in 00 which aren't divisable by 400 aren't leap years.
    January 1st, 0001 is a Monday.

*/

package main

import (
	"fmt"
	"math"
	"time"
)

func main() {
	assert(day("0001-01-01") == "Sunday")
	assert(day("1899-12-03") == "Monday")
	assert(day("1970-01-01") == "Tuesday")
	assert(day("1999-07-06") == "Tuesday")
	assert(day("2003-05-22") == "Sunday")
	assert(day("2011-02-17") == "Wednesday")
	assert(day("2100-01-01") == "Friday")
	assert(day("2020-02-29") == "Thursday")
}

func assert(x bool) {
	if !x {
		panic("assertion failed")
	}
}

func day(s string) string {
	const layout = "2006-01-02"

	t, err := time.Parse(layout, s)
	if err != nil {
		return err.Error()
	}
	if t.Month() == time.February && t.Day() == 29 {
		t = t.AddDate(1, 0, 0)
	}

	var u time.Time
	for i := 0; i < math.MaxUint8; i++ {
		l := fmt.Sprintf("%04d-02-29", t.Year()+i)
		u, err = time.Parse(layout, l)
		if err == nil {
			break
		}
	}
	if err != nil {
		return "no leap year found"
	}

	return fmt.Sprint(u.Weekday())
}
