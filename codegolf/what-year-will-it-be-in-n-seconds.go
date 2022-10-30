/*

You are given an integer n as input, and, regardless of the current date, must return the calendar year (Gregorian calendar, other calendars not allowed) taking place n seconds from now.
Rules

    You may not assume that the current year is 2021. In other words, imagine a user testing your solution in five years.
    Standard loopholes forbidden.
    Shortest answer in bytes wins.
    Built-in date functions are allowed.
    You must also support negative numbers.
    On the topic of the year zero: Your answer must follow the ISO specifications, meaning there is a year zero.
    You may assume that the input is always an integer within bounds of your language number system.
    If your language's date functions take leap seconds into account, then follow your language, otherwise do not take leap seconds into account.

Examples (in this case, measured at the time of writing, which is February 15, 2021)

100000000000 -> 5190
1000 -> 2021
54398643 -> 2022
54398643234 -> 3744
-100000000000 -> -1148

*/

package main

import (
	"fmt"
	"time"
)

func main() {
	now := time.Date(2021, time.February, 15, 23, 59, 59, 0, time.UTC)
	fmt.Println(yearn(now, 100000000000))
	fmt.Println(yearn(now, 1000))
	fmt.Println(yearn(now, 54398643))
	fmt.Println(yearn(now, 54398643234))
	fmt.Println(yearn(now, -100000000000))
}

func assert(x bool) {
	if !x {
		panic("assertion failed")
	}
}

func yearn(now time.Time, sec int64) int {
	sign := int64(1)
	if sec < 0 {
		sec = -sec
		sign = -1
	}

	t := now
	for sec > 0 {
		dt := sec
		if dt > 1e9 {
			dt = 1e9
		}

		t = t.Add(time.Duration(dt*sign) * time.Second)
		sec -= dt
	}
	return t.Year()
}
