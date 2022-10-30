/*

In this challenge, you are given a date and you have to determine the correspondent season in a certain hemisphere of Earth.

You have to use the ranges given by the meteorological seasons definition, accordingly to the following table:

Start	End	North Hemisphere	South Hemisphere
March, 1	May, 31	Spring	Autumn
June, 1	August, 31	Summer	Winter
September, 1	November, 30	Autumn	Spring
December, 1	February, 28***	Winter	Summer

Given two strings hemisphere (can be "N" for the North hemisphere or "S" for the South hemisphere) and date (name and day of the month),
implement a function that returns a string with the season name, accordingly to the above table.

Examples

hemisphereSeason("N", "June, 30") ➞ "Summer"

hemisphereSeason("N", "March, 1") ➞ "Spring"

hemisphereSeason("S", "September, 22") ➞ "Spring"

Notes

During leap years the end date of Winter in the northern hemisphere is the 29th day of February (last day of Summer in the southern hemisphere).
In this challenge, years are not used, so the last day of February will always be the 28th.

*/

package main

import (
	"time"
)

func main() {
	assert(season("N", "June, 30") == "Summer")
	assert(season("N", "March, 1") == "Spring")
	assert(season("S", "September, 2") == "Spring")
	assert(season("S", "April, 20") == "Autumn")
	assert(season("N", "November, 20") == "Autumn")
	assert(season("S", "May, 8") == "Autumn")
	assert(season("N", "February, 28") == "Winter")
	assert(season("S", "August, 6") == "Winter")
	assert(season("N", "July, 28") == "Summer")
	assert(season("S", "October, 12") == "Spring")
	assert(season("N", "December, 31") == "Winter")
	assert(season("S", "January, 2") == "Summer")
}

func assert(x bool) {
	if !x {
		panic("assertion failed")
	}
}

func season(h, s string) string {
	tab := []struct {
		north string
		south string
		start time.Time
		end   time.Time
	}{
		{"Spring", "Autumn", date(time.March, 1), date(time.May, 31)},
		{"Summer", "Winter", date(time.June, 1), date(time.August, 31)},
		{"Autumn", "Spring", date(time.September, 1), date(time.November, 30)},
		{"Winter", "Summer", date(time.December, 1), date(time.December, 31)},
		{"Winter", "Summer", date(time.January, 1), date(time.February, 29)},
	}
	t, err := time.Parse("January, 2 2006", s+" 2000")
	if err != nil {
		return err.Error()
	}

	n := -1
	for i, p := range tab {
		if cmp(t, p.start) >= 0 && cmp(t, p.end) <= 0 {
			n = i
			break
		}
	}
	if n < 0 {
		return "Invalid Date"
	}

	switch h {
	case "N":
		return tab[n].north
	case "S":
		return tab[n].south
	}
	return "Invalid Season"
}

func date(m time.Month, d int) time.Time {
	return time.Date(2000, m, d, 0, 0, 0, 0, time.UTC)
}

func cmp(a, b time.Time) int {
	if a.Before(b) {
		return -1
	}
	if a.After(b) {
		return 1
	}
	return 0
}
