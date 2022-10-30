/*

According to Gregorian Calendar, it was Monday on the date 01/01/2001. If any year is input,
Write a program to display what is the day on the 1st January of this year.

Input

The first line contains an integer T, total number of testcases. Then follow T lines, each line contains an integer year.

Output

For each test case, display the day on the 1st January of that year in lowercase letters, in a new line.

Constraints
1 ≤ T ≤ 1000
1900 ≤ year ≤ 5000

*/

package main

import (
	"strings"
	"time"
)

func main() {
	assert(day(1994) == "saturday")
	assert(day(1991) == "tuesday")
	assert(day(2014) == "wednesday")
}

func assert(x bool) {
	if !x {
		panic("assertion failed")
	}
}

func day(y int) string {
	t := time.Date(y, time.January, 1, 0, 0, 0, 0, time.UTC)
	w := t.Weekday()
	s := w.String()
	return strings.ToLower(s)
}
