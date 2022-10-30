/*

In this challenge you have to find out which nth second it is now in this year, current date and time now. Or in other words, how many seconds have passed since New Year.

An example current Date is (it's not given, you'll have to find the current Date):

March 5, 2021 1:42:44 AM

For which the answer is 5449364 (or optionally 5449365 if you count January 1, 2021 0:00:00 as the first second).

So you should return or output which 'th second it is now in this year. Standard loopholes apply, shortest code wins. You may keep fractional seconds in output optionally.

*/

package main

import (
	"fmt"
	"time"
)

func main() {
	fmt.Println(nthsec())
}

func nthsec() int64 {
	t1 := time.Now()
	t0 := time.Date(t1.Year(), time.January, 1, 0, 0, 0, 0, time.UTC)
	dt := t1.Sub(t0)
	return int64(dt.Seconds())
}
