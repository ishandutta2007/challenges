/*

You are given an array of dates in the format Dec 11 and a month in the format Dec as arguments.
Each date represent a video that was uploaded on that day. Return the number of uploads for a given month.

Examples

uploadCount(["Sept 22", "Sept 21", "Oct 15"], "Sept") ➞ 2

uploadCount(["Sept 22", "Sept 21", "Oct 15"], "Oct") ➞ 1

Notes

If you only pay attention to the month and ignore the day, the challenge will become easier.

*/

package main

import "strings"

func main() {
	assert(uploads([]string{"Sept 22", "Sept 21", "Oct 15"}, "Sept") == 2)
	assert(uploads([]string{"Sept 22", "Sept 21", "Oct 15"}, "Oct") == 1)

	date := []string{
		"Dec 10", "Dec 10", "Dec 9", "Dec 9", "Dec 9", "Dec 8", "Dec 8",
		"Dec 8", "Dec 8", "Dec 8", "Dec 8", "Dec 8", "Dec 8", "Dec 7",
		"Dec 7", "Dec 7", "Dec 7", "Dec 7", "Dec 5", "Dec 5", "Dec 5",
		"Dec 4", "Dec 4", "Dec 4", "Dec 4", "Dec 4", "Dec 3", "Dec 3",
		"Dec 3", "Dec 2", "Dec 2", "Dec 2", "Dec 1", "Dec 1", "Dec 1",
		"Dec 1", "Nov 30", "Nov 30", "Nov 28", "Nov 28", "Nov 27", "Nov 27",
		"Nov 27", "Nov 26", "Nov 26", "Nov 25", "Nov 25", "Nov 25", "Nov 25",
		"Nov 24", "Nov 24", "Nov 23", "Nov 23", "Nov 23", "Nov 21", "Nov 21", "Nov 20",
		"Nov 20", "Nov 20", "Nov 19", "Nov 19", "Nov 19", "Nov 18", "Nov 18", "Nov 17",
		"Nov 17", "Nov 17", "Nov 16", "Nov 16", "Nov 16", "Nov 16", "Nov 15", "Nov 15",
		"Nov 14", "Nov 14", "Nov 14", "Nov 13", "Nov 13", "Nov 13", "Nov 13", "Nov 12",
		"Nov 12", "Nov 12", "Nov 11", "Nov 11", "Nov 11", "Nov 11", "Nov 10", "Nov 10",
		"Nov 10", "Nov 9", "Nov 9", "Nov 9", "Nov 9", "Nov 9", "Nov 8", "Nov 7", "Nov 7",
		"Nov 7", "Nov 6", "Nov 6", "Nov 5", "Nov 5", "Nov 4", "Nov 4", "Nov 4", "Nov 4",
		"Nov 3", "Nov 3", "Nov 3", "Nov 2", "Nov 2", "Nov 2", "Nov 2", "Nov 1", "Oct 31",
		"Oct 31", "Oct 31", "Oct 31", "Oct 31", "Oct 30", "Oct 29", "Oct 29", "Oct 28",
		"Oct 28", "Oct 28", "Oct 27", "Oct 27", "Oct 26", "Oct 26", "Oct 26", "Oct 25",
		"Oct 24", "Oct 24", "Oct 24", "Oct 23", "Oct 23", "Oct 23", "Oct 22", "Oct 22",
		"Oct 22", "Oct 21", "Oct 20", "Oct 20", "Oct 20", "Oct 20", "Oct 19", "Oct 19",
		"Oct 19", "Oct 18", "Oct 17", "Oct 17", "Oct 17", "Oct 17", "Oct 16", "Oct 16",
		"Oct 15", "Oct 15", "Oct 14", "Oct 14", "Oct 13", "Oct 13", "Oct 13", "Oct 12",
		"Oct 12", "Oct 10", "Oct 10", "Oct 10", "Oct 9", "Oct 9", "Oct 9", "Oct 8", "Oct 8",
		"Oct 7", "Oct 7", "Oct 6", "Oct 6", "Oct 5", "Oct 5", "Oct 3", "Oct 3", "Oct 3",
		"Oct 2", "Oct 2", "Oct 2", "Oct 2", "Oct 1", "Oct 1",
		"Sept 30", "Sept 30", "Sept 29", "Sept 29", "Sept 29", "Sept 28", "Sept 28", "Sept 26",
		"Sept 26", "Sept 25", "Sept 24", "Sept 24", "Sept 23", "Sept 23", "Sept 23", "Sept 22",
		"Sept 22", "Sept 22", "Sept 21", "Sept 21", "Sept 20", "Sept 19", "Sept 19", "Sept 19",
		"Sept 18", "Sep 18",
	}
	assert(uploads(date, "Nov") == 79)
	assert(uploads(date, "Dec") == 36)
	assert(uploads(date, "Sept") == 25)
	assert(uploads(date, "Oct") == 73)
}

func assert(x bool) {
	if !x {
		panic("assertion failed")
	}
}

func uploads(s []string, q string) int {
	m := make(map[string]int)
	for i := range s {
		t := strings.Split(s[i], " ")
		if len(t) == 0 {
			continue
		}
		m[t[0]]++
	}
	return m[q]
}
