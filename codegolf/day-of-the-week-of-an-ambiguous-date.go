/*

Goal

Write a program or function that returns the day of the week for a date, eg.

01/06/2020  ->  Mon

However, it's unknown if the date is in the format mm/dd/yyyy or dd/mm/yyyy. If you can be certain of the day of the week, return it. If there is uncertainty, return an error.

02/07/2020  ->  Err  (Thu? Fri?)

Input

A date in the format #/#/####.

    The numbers can optionally have leading zeros.
    The year should be read verbatim, assume that 19 = 19 AD, not 19 = 2019 AD.
    The separators can be any non-digit character.
    Assume the input date is valid in at least one format (ie. not 13/13/2020).
    At a minimum, support dates from 2000 through 2030 (which are likely covered by any modern OS and language with a date library.)

Requirements

    If the first and second numbers:
        are the same (03/03/2020), the date is unambiguous.
        either is greater than 12 (13/09/2020, 09/13/2020), the date is unambiguous.
        are different and both 12 or less (09/11/2020), the date is ambiguous.

Output

    If the date is unambiguous, return the day of the week.
    If the date is ambiguous:
        If both versions of the date have the same day of the week, return the day of the week.
        If both versions of the date have a different day of the week, return an error.
    A day of the week should be returned as a string of the day's three-letter abbreviation ("Mon"), case-insensitive.
    An error should be returned as any other three-character string, not all whitespace, eg. "Err", "NaN", "???".

Test Cases

02/07/2020  ->  Err
01/06/2020  ->  Mon
05/05/2020  ->  Tue
24/06/2020  ->  Wed
05/09/2030  ->  Thu
03/13/2020  ->  Fri
29/02/2020  ->  Sat
03/12/2000  ->  Sun

Scoring

The code with the least byte count in a week wins the tick.

*/

package main

import (
	"time"
)

func main() {
	assert(day("02/07/2020") == "Err")
	assert(day("01/06/2020") == "Mon")
	assert(day("05/05/2020") == "Tue")
	assert(day("24/06/2020") == "Wed")
	assert(day("05/09/2030") == "Thu")
	assert(day("03/13/2020") == "Fri")
	assert(day("29/02/2020") == "Sat")
	assert(day("03/12/2000") == "Sun")
	assert(day("09/11/2020") == "Err")
	assert(day("13/09/2020") == "Sun")
	assert(day("09/13/2020") == "Sun")
}

func assert(x bool) {
	if !x {
		panic("assertion failed")
	}
}

func day(s string) string {
	a, err := time.Parse("02/01/2006", s)
	b, xerr := time.Parse("01/02/2006", s)
	if err != nil && xerr != nil {
		return "Err"
	}

	r := "Err"
	wa := a.Weekday()
	wb := b.Weekday()
	da := a.Day()
	db := b.Day()
	switch {
	case err == nil && xerr != nil:
		r = wa.String()
	case err != nil && xerr == nil:
		r = wb.String()

	case wa == wb:
		r = wa.String()

	case da < 8 && db >= 8:
		r = wa.String()
	case da >= 8 && db < 8:
		r = wb.String()
	}

	return r[:3]
}
