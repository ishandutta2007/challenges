/*

In this challenge, the goal is to calculate what time it is in two different cities.
You're given a string cityA and the related string timestamp (time in cityA) with the date formatted in full U.S. notation, as in this example:

"July 21, 1983 23:01"

You have to return a new timestamp with date and corresponding time in cityB, formatted as in this example:

"1983-7-21 23:01"

See the table below for a list of given cities and their GMT (Greenwich Mean Time) hours offsets.
GMT	City
- 08:00	Los Angeles
- 05:00	New York
- 04:30	Caracas
- 03:00	Buenos Aires
00:00	London
+ 01:00	Rome
+ 03:00	Moscow
+ 03:30	Tehran
+ 05:30	New Delhi
+ 08:00	Beijing
+ 10:00	Canberra
Examples

timeDifference("Los Angeles", "April 1, 2011 23:23", "Canberra") ➞ "2011-4-2 17:23"
// Can be a new day.

timeDifference("London", "July 31, 1983 23:01", "Rome") ➞ "1983-8-1 00:01"
// Can be a new month.

timeDifference("New York", "December 31, 1970 13:40", "Beijing") ➞ "1971-1-1 02:40"
// Can be a new year.

Notes

    Pay attention to hours and minutes, a leading 0 is needed in the returned timestamp when they're a single digit (see examples #2 and #3).
    Pay attention to cities with half hours offsets.

*/

package main

import (
	"fmt"
	"time"
)

func main() {
	assert(timediff("Los Angeles", "April 1, 2011 23:23", "Canberra") == "2011-4-2 17:23")
	assert(timediff("London", "July 31, 1983 23:01", "Rome") == "1983-8-1 00:01")
	assert(timediff("New York", "December 31, 1970 13:40", "Beijing") == "1971-1-1 02:40")
	assert(timediff("London", "August 20, 1985 12:23", "Buenos Aires") == "1985-8-20 09:23")
	assert(timediff("Rome", "December 21, 1987 15:11", "New Delhi") == "1987-12-21 19:41")
	assert(timediff("Canberra", "March 1, 2009 18:32", "Caracas") == "2009-3-1 04:02")
	assert(timediff("Moscow", "September 14, 1953 19:54", "New York") == "1953-9-14 11:54")
	assert(timediff("Beijing", "November 18, 1999 02:03", "New Delhi") == "1999-11-17 23:33")
	assert(timediff("Tehran", "June 3, 1977 11:18", "Moscow") == "1977-6-3 10:48")
	assert(timediff("Caracas", "January 21, 1990 12:44", "London") == "1990-1-21 17:14")
	assert(timediff("New York", "February 21, 2016 17:56", "Rome") == "2016-2-21 23:56")
}

func assert(x bool) {
	if !x {
		panic("assertion failed")
	}
}

func timediff(a, d, b string) string {
	m := map[string]time.Duration{
		"Los Angeles":  -8 * time.Hour,
		"New York":     -5 * time.Hour,
		"Caracas":      -4*time.Hour - 30*time.Minute,
		"Buenos Aires": -3 * time.Hour,
		"London":       0 * time.Hour,
		"Rome":         1 * time.Hour,
		"Moscow":       3 * time.Hour,
		"Tehran":       3*time.Hour + 30*time.Minute,
		"New Delhi":    5*time.Hour + 30*time.Minute,
		"Beijing":      8 * time.Hour,
		"Canberra":     10 * time.Hour,
	}
	t, err := time.Parse("January 2, 2006 15:04", d)
	if err != nil {
		return err.Error()
	}

	da, fa := m[a]
	db, fb := m[b]
	if !fa || !fb {
		return fmt.Sprintf("cannot convert city %q time to city %q time", a, b)
	}

	t = t.Add(db - da)
	return t.Format("2006-1-2 15:04")
}
