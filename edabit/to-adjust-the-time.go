/*

In this challenge, you have to add a variable amount of hours, minutes and seconds to a given time, obtaining, in turn, a new adjusted time.

Given a string now being a timestamp in the format hh:mm:ss, and three integers hrs, mins and sec being the hours, minutes and seconds to add,
implement a function that returns a string being the newly adjusted timestamp (maintaining the same format).

Examples

time_adjust("01:00:00", 1, 30, 10) ➞ "02:30:10"

time_adjust("18:22:30", 4, 60, 30) ➞ "23:23:00"

time_adjust("00:00:00", 72, 120, 120) ➞ "02:02:00"

Notes

    The amounts of hrs, mins and sec can be any positive integer, and you have to correctly add them to the corresponding unit if they exceed their scale.
	See example #2: sixty minutes is one hour, and sixty seconds (30 + 30) is one minute.
    If the amount of time to add exceeds the 24 hours, then the time will start again from "00:00:00".
	See example #3: 72 hours are 3 exact days so that after three cycles of 24 hours, the hour will be again "00" (and becomes "02" because we are adding also 120 minutes or 2 hours).

*/

package main

import (
	"time"
)

func main() {
	assert(adjust("01:00:00", 1, 30, 10) == "02:30:10")
	assert(adjust("18:22:30", 4, 60, 30) == "23:23:00")
	assert(adjust("00:00:00", 72, 120, 120) == "02:02:00")
	assert(adjust("23:59:59", 0, 0, 1) == "00:00:00")
	assert(adjust("12:17:43", 0, 0, 0) == "12:17:43")
	assert(adjust("14:11:29", 1000, 23466, 171626) == "12:57:55")
	assert(adjust("21:02:55", 39, 62525, 332) == "22:13:27")
}

func assert(x bool) {
	if !x {
		panic("assertion failed")
	}
}

func adjust(fmt string, h, m, s int) string {
	t, err := time.Parse("15:04:05", fmt)
	if err != nil {
		return ""
	}
	t = t.Add(time.Duration(h) * time.Hour)
	t = t.Add(time.Duration(m) * time.Minute)
	t = t.Add(time.Duration(s) * time.Second)
	return t.Format("15:04:05")
}
