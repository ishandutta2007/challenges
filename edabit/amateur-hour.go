/*

Write a function that takes time t1 and time t2 and returns the number of hours passed between the two times.

Examples

hoursPassed("3:00 AM", "9:00 AM") ➞ "6 hours"

hoursPassed("2:00 PM", "4:00 PM") ➞ "2 hours"

hoursPassed("1:00 AM", "3:00 PM") ➞ "14 hours"

Notes

    Time t1 will always be the starting time and t2, the ending time.
    Return the string "no time passed" if t1 is equal to t2.

*/

package main

import (
	"fmt"
	"time"
)

func main() {
	itab := [][2]string{
		{"3:00 AM", "9:00 AM"},
		{"2:00 PM", "4:00 PM"},
		{"1:00 AM", "3:00 PM"},
		{"2:00 AM", "3:00 PM"},
		{"8:00 AM", "8:00 PM"},
		{"12:00 AM", "10:00 PM"},
		{"1:00 AM", "1:00 AM"},
		{"12:00 PM", "12:00 PM"},
	}
	otab := []string{
		"6 hours", "2 hours", "14 hours", "13 hours", "12 hours", "22 hours", "no time passed", "no time passed",
	}
	for i := range itab {
		assert(hours(itab[i][0], itab[i][1]) == otab[i])
	}
}

func assert(x bool) {
	if !x {
		panic("assertion failed")
	}
}

func hours(a, b string) string {
	const format = "15:04 PM"

	x, err := time.Parse(format, a)
	if err != nil {
		return err.Error()
	}
	y, err := time.Parse(format, b)
	if err != nil {
		return err.Error()
	}

	if x.Equal(y) {
		return "no time passed"
	}

	if x.After(y) {
		x, y = y, x
	}
	t := y.Sub(x)
	return fmt.Sprintf("%v hours", t.Hours())
}
