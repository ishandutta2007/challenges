/*

June 2020 is a month in which June 1st corresponds to Monday, June 2nd corresponds to Tuesday, ... June 7th corresponds to Sunday. For reference, here's the cal of June 2020.

      June 2020
Su Mo Tu We Th Fr Sa
    1  2  3  4  5  6
 7  8  9 10 11 12 13
14 15 16 17 18 19 20
21 22 23 24 25 26 27
28 29 30

Given a year and a month in the format [year, month], output two distinct values that tell whether this month starts on a Monday.
Test cases

[2020,6] -> True
[2021,2] -> True
[1929,4] -> True

[1969,1] -> False
[1997,5] -> False
[2060,1] -> False

Specification

    The input can be in any format you prefer for your answer, e.g. numeric list, numeric tuple, etc. It doesn't have to be taken in this rigid format (it's JSON by the way).
    However, making the input a Date object is a loophole here. You shouldn't make the input a Date object.
    The month in the input doesn't have to be 1-indexed - it can also be 0-indexed.
    You need to support all years after 1582 (the start of the Proleptic Gregorian calendar), up to the year 9999.

*/

package main

import (
	"time"
)

func main() {
	assert(monday(2020, 6) == true)
	assert(monday(2021, 2) == true)
	assert(monday(1929, 4) == true)
	assert(monday(1969, 1) == false)
	assert(monday(1997, 5) == false)
	assert(monday(2060, 1) == false)
}

func assert(x bool) {
	if !x {
		panic("assertion failed")
	}
}

func monday(y, m int) bool {
	t := time.Date(y, time.Month(m), 1, 0, 0, 0, 0, time.UTC)
	return t.Weekday() == time.Monday
}
