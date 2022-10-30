/*

Happy St. Patrick's Day! Write a program that accepts a year as input and outputs what day St. Patrick's Day falls on.

Bonus: Print out the number of times St. Patrick's Day falls on a Saturday for this century.

Sample Run:

Enter Year: 2012

St. Patrick's Day is on a Saturday.

Enter Year: 2010

St. Patrick's Day is on a Wednesday.

*/

package main

import (
	"fmt"
	"time"
)

func main() {
	assert(patrick(2012) == "Saturday")
	assert(patrick(2010) == "Wednesday")

	n := 0
	for y := 2001; y <= 2100; y++ {
		if patrick(y) == "Saturday" {
			n++
		}
	}
	fmt.Println(n)
}

func assert(x bool) {
	if !x {
		panic("assertion failed")
	}
}

func patrick(y int) string {
	t := time.Date(y, time.March, 17, 0, 0, 0, 0, time.UTC)
	d := t.Weekday()
	return d.String()
}
