/*

Challenge

Weirdly, this hasn't been done yet: output the current date.

Rules

The date format you should follow is as follows:

YYYY-MM-DD

Where the month and day should be padded by zeroes if they are less than 10.

For example, if the program is run on the 24th May 2017, it should output

2017-05-24

The date can either be always in UTC or in the local date.

You must handle leaps years. i.e. in leap years, February has 29 days but 28 days in a normal year.
Winning

Shortest code in bytes wins.

*/

package main

import (
	"fmt"
	"time"
)

func main() {
	fmt.Println(date())
}

func date() string {
	t := time.Now()
	return t.Format("2006-01-02")
}
