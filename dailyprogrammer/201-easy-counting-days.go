/*

Description:

Sometimes you wonder. How many days I have left until.....Whatever date you are curious about. Maybe a holiday. Maybe a vacation. Maybe a special event like a birthday.

So today let us do some calendar math. Given a date that is in the future how many days until that date from the current date?
Input:

The date you want to know about in 3 integers. I leave it to you to decide if you want to do yyyy mm dd or mm dd yyyy or whatever.
For my examples I will be using yyyy mm dd. Your solution should have 1 comment saying what format you are using for people reading your code. (Note you will need to convert your inputs to your format from mine if not using yyyy mm dd)
Output:

The number of days until that date from today's date (the time you run the program)
Example Input: 2015 2 14
Example Output: 5 days from 2015 2 9 to 2015 2 14
Challenge Inputs:

 2015 7 4
 2015 10 31
 2015 12 24
 2016 1 1
 2016 2 9
 2020 1 1
 2020 2 9
 2020 3 1
 3015 2 9

Challenge Outputs:

Vary from the date you will run the solution and I leave it to you all to compare results.

*/

package main

import (
	"fmt"
	"time"
)

func main() {
	test(2015, 2, 9, 2015, 2, 14, 5)
}

func assert(x bool) {
	if !x {
		panic("assertion failed")
	}
}

func test(y0, m0, d0, y1, m1, d1, r int) {
	d := days(date(y0, m0, d0), date(y0, m1, d1))
	fmt.Println(d)
	assert(d == r)
}

func days(t0, t1 time.Time) int {
	d := t1.Sub(t0)
	return int(d.Hours() / 24)
}

func date(y, m, d int) time.Time {
	return time.Date(y, time.Month(m), d, 0, 0, 0, 0, time.UTC)
}
