/*

You are given the following information, but you may prefer to do some research for yourself.

    1 Jan 1900 was a Monday.
    Thirty days has September,
    April, June and November.
    All the rest have thirty-one,
    Saving February alone,
    Which has twenty-eight, rain or shine.
    And on leap years, twenty-nine.
    A leap year occurs on any year evenly divisible by 4, but not on a century unless it is divisible by 400.

How many Sundays fell on the first of the month during the twentieth century (1 Jan 1901 to 31 Dec 2000)?

*/

package main

import (
	"fmt"
	"time"
)

func main() {
	fmt.Println(solve(1901, 2000, time.January, time.December, time.Sunday))
}

func solve(y0, y1 int, m0, m1 time.Month, d time.Weekday) int {
	n := 0
	for y := y0; y <= y1; y++ {
		for m := m0; m <= m1; m++ {
			t := time.Date(y, m, 1, 0, 0, 0, 0, time.UTC)
			if t.Weekday() == d {
				n++
			}
		}
	}
	return n
}
