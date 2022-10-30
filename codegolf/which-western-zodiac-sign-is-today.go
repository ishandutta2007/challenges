/*

Task:

With the minimum amount of bytes, determine today's Zodiac sign using the programming language of your choice.

Rules:

This is code golf, the answer with the fewest characters wins. The initialization of getting the current date into a variable (e.g. var now = new Date();) does not add to the count. Leap years must be handled correctly.

Limitations:

You cannot use any other library functions for handling dates, nor predefined lists. In particular, participants would have to calculate the ordinal day of the year themselves if needed.

Input:

The current date in the proleptic Gregorian calendar with numeric year, month (1–12) and day of the month (1–28…31).

Output:

A single Unicode symbol indicating the current one of the twelve Zodiac signs from Western astrology, as used in horoscopes and listed below:

♈︎ Aries: March 21 – April 19
♉︎ Taurus: April 20 – May 20
♊︎ Gemini: May 21 – June 21
♋︎ Cancer: June 22 – July 22
♌︎ Leo: July 23 – August 22
♍︎ Virgo: August 23 – September 22
♎︎ Libra: September 23 – October 22
♏︎ Scorpio: October 23 – November 22
♐︎ Sagittarius: November 23 – December 21
♑︎ Capricorn: December 22 – January 19
♒︎ Aquarius: January 20 – February 18
♓︎ Pisces: February 19 – March 20
The actual dates might differ by one day depending on the year, but for this task the above date ranges are considered accurate for every year.

Example

The sign for today, 28 February 2022, is Pisces, so the correct output would be ♓︎.

Related challenges
Chinese Zodiac of the year
What's the current zodiac? (hour)
Get the day of the year of a given date
ASCII Art of the Day #4 - Zodiac Signs

*/

package main

import (
	"time"
)

func main() {
	t := time.Date(2022, time.February, 28, 0, 0, 0, 0, time.UTC)
	assert(zodiac(t) == "♓︎")

	assert(zodiac(md(time.March, 21)) == "♈︎")
	assert(zodiac(md(time.June, 23)) == "♋︎")
	assert(zodiac(md(time.August, 22)) == "♌︎")
	assert(zodiac(md(time.January, 1)) == "♑︎")
	assert(zodiac(md(time.January, 19)) == "♑︎")
	assert(zodiac(md(time.January, 20)) == "♒︎")
	assert(zodiac(md(time.February, 29)) == "♓︎")
}

func assert(x bool) {
	if !x {
		panic("assertion failed")
	}
}

func zodiac(t time.Time) string {
	tab := []struct {
		t0, t1 time.Time
		sign   string
	}{
		{md(time.March, 21), md(time.April, 19), "♈︎"},
		{md(time.April, 20), md(time.May, 20), "♉︎"},
		{md(time.May, 21), md(time.June, 21), "♊︎"},
		{md(time.June, 22), md(time.July, 22), "♋︎"},
		{md(time.July, 23), md(time.August, 22), "♌︎"},
		{md(time.August, 23), md(time.September, 22), "♍︎"},
		{md(time.September, 23), md(time.October, 22), "♎︎"},
		{md(time.October, 23), md(time.November, 22), "♏︎"},
		{md(time.November, 23), md(time.December, 21), "♐︎"},
		{md(time.December, 22), md(time.January, 19), "♑︎"},
		{md(time.January, 20), md(time.February, 18), "♒︎"},
		{md(time.February, 19), md(time.March, 20), "♓︎"},
	}

	t = md(t.Month(), t.Day())
	for _, p := range tab {
		a := p.t0
		b := p.t1
		if b.After(a) {
			if geq(t, a) && leq(t, b) {
				return p.sign
			}
		} else if geq(t, a) || leq(t, b) {
			return p.sign
		}
	}
	return "?"
}

func leq(a, b time.Time) bool {
	return a.Before(b) || a.Equal(b)
}

func geq(a, b time.Time) bool {
	return a.After(b) || a.Equal(b)
}

func md(m time.Month, d int) time.Time {
	return time.Date(0, m, d, 0, 0, 0, 0, time.UTC)
}
