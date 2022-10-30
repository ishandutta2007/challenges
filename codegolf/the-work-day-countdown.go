/*

I just had a genius idea for making the work-life easier - a countdown to a specific date which only counts workdays.

The basic task is to create a countdown to a specific date which only includes the workdays in the countdown.

As workday counts Monday, Tuesday, Wednesday, Thursday and Friday.

The Input should be a specific date in the "unofficial" European standard format dd.MM.yyyy and must be today or a day in the future.

The Output should only be the number of days left.

As it's code-golf the shortest code wins.

Test case:

  Today    |   Input    | Output
10.12.2018 | 17.12.2018 |    5
02.10.2018 | 16.10.2018 |   10
If I missed a few things in the question, please forgive me - it's my first question :)

EDIT:

You can use false as output instead of 0 <- but it's not beautiful
No need for respecting DST

*/

package main

import "time"

func main() {
	assert(countdown(date("10.12.2018"), date("17.12.2018")) == 5)
	assert(countdown(date("02.10.2018"), date("16.10.2018")) == 10)
	assert(countdown(date("02.10.2018"), date("16.10.2017")) == 0)
}

func assert(x bool) {
	if !x {
		panic("assertion failed")
	}
}

func countdown(a, b time.Time) int {
	c := 0
	for a.Before(b) {
		a = a.AddDate(0, 0, 1)
		d := a.Weekday()
		if d != time.Saturday && d != time.Sunday {
			c++
		}
	}
	return c
}

func date(s string) time.Time {
	t, err := time.Parse("02.01.2006", s)
	if err != nil {
		panic(err)
	}
	return t
}
