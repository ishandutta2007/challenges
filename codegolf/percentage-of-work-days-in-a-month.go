/*

Given a year and a month, find out the percentage of work days in said month. Work days are Monday through Friday with no regard to holidays or other special things.
The Gregorian calendar is used.

Input

A year and month in ISO 8601 format (YYYY-MM). The year always has four digits, the month always has two digits. The given year will not be before 1582.

Output

Output is the percentage of work days (according to above definition) in the given month, rounded to a whole number. No percent sign or fractional digits follow.

Sample 1

Input                Output

2010-05              68

Sample 2

Input                Output

2010-06              73

Sample 3

Input                Output

1920-10              68

Sample 4

Input                Output

2817-12              68

A week has passed, an answer has been accepted. For the curious, the sizes of the submissions we got in our contest:

    129 – Z shell
    174 – VB.NET
    222 – C
    233 – C
    300 – C

As well as our own (unranked) solutions:

      75 – PowerShell
      93 – Ruby
    112 – Bourne shell

*/

package main

import (
	"math"
	"time"
)

func main() {
	assert(workdays("2010-05") == 68)
	assert(workdays("2010-06") == 73)
	assert(workdays("1920-10") == 68)
	assert(workdays("2817-12") == 68)
}

func assert(x bool) {
	if !x {
		panic("assertion failed")
	}
}

func workdays(s string) int {
	t, err := time.Parse("2006-01", s)
	if err != nil {
		return -1
	}

	n, d := 0, 0
	m := t.Month()
	for {
		switch t.Weekday() {
		case time.Monday, time.Tuesday, time.Wednesday, time.Thursday, time.Friday:
			n++
		}
		d++

		t = t.AddDate(0, 0, 1)
		if t.Month() != m {
			break
		}
	}
	p := float64(n) / float64(d)
	p = math.Round(p * 100)
	return int(p)
}
