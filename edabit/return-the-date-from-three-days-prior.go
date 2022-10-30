/*

Given a Date() object, return the date from three days prior as a string: "2016-01-19".

Examples

threeDaysAgo(new Date(2018, 0, 1)) ➞ "2017-12-29"

threeDaysAgo(new Date(2015, 5, 17)) ➞ "2015-06-14"

threeDaysAgo(new Date(1965, 3, 15))➞ "1965-04-12"

Notes

	Your function must work in the past, present and future.
	JavaScript months are zero based.
	Your output should NOT be zero based: 2016, 0, 19 == "2016-01-19".

*/

package main

import (
	"fmt"
	"time"
)

func main() {
	assert(threes(2018, 0, 1) == "2017-12-29")
	assert(threes(2015, 5, 17) == "2015-06-14")
	assert(threes(2017, 1, 1) == "2017-01-29")
	assert(threes(1950, 6, 8) == "1950-07-05")
	assert(threes(1965, 3, 15) == "1965-04-12")
	assert(threes(2025, 4, 24) == "2025-05-21")
	assert(threes(1965, 3, 15) == "1965-04-12")
	assert(threes(2015, 5, 17) == "2015-06-14")
}

func threes(y, m, d int) string {
	t := time.Date(y, time.Month(m)+1, d-3, 0, 0, 0, 0, time.UTC)
	return fmt.Sprintf("%04d-%02d-%02d", t.Year(), int(t.Month()), t.Day())
}

func assert(x bool) {
	if !x {
		panic("assertion failed")
	}
}
