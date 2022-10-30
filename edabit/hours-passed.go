/*

Write a function that takes time t1 and time t2 and returns the numbers of hours passed between the two times.

Examples

hoursPassed("3:00 AM", "9:00 AM") ➞ "6 hours"

hoursPassed("2:00 PM", "4:00 PM") ➞ "2 hours"

hoursPassed("1:00 AM", "3:00 PM") ➞ "14 hours"

Notes

    Time t1 will always be the starting time and t2, the ending time.
    Return the string "No time has passed." if t1 is equal to t2.

*/

package main

import (
	"fmt"
	"time"
)

func main() {
	itab := [][]string{
		{"3:00 AM", "9:00 AM"}, {"2:00 PM", "4:00 PM"}, {"1:00 AM", "3:00 PM"}, {"2:00 AM", "3:00 PM"},
		{"8:00 AM", "8:00 PM"}, {"12:00 AM", "10:00 PM"}, {"1:00 AM", "1:00 AM"}, {"12:00 PM", "12:00 PM"},
	}
	otab := []string{"6 hours", "2 hours", "14 hours", "13 hours", "12 hours", "22 hours", "No time has passed.", "No time has passed."}

	for i, p := range itab {
		assert(hours(p[0], p[1]) == otab[i])
	}
}

func assert(x bool) {
	if !x {
		panic("assertion failed")
	}
}

func hours(s, t string) string {
	const format = "15:04 PM"

	a, err := time.Parse(format, s)
	if err != nil {
		return err.Error()
	}

	b, err := time.Parse(format, t)
	if err != nil {
		return err.Error()
	}

	if a.After(b) {
		a, b = b, a
	}

	c := b.Sub(a)
	if c == 0 {
		return "No time has passed."
	}
	return fmt.Sprintf("%.0f hours", c.Hours())
}
