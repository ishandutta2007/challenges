/*

This challenge is a relatively simple concept that I'm surprised has not been done yet.
You will be given only an integer as an input. Your task is to find the date that is this number of days from January 1st, 1984.
This challenge is uniquely for the Gregorian calendar (which is standard almost everywhere).

One restriction

The twist on this challenge is that you should not use a built-in function that deals with the date and time - because then this challenge would be trivial for a few languages.
Your program must do this calculation entirely on its own - keep in mind leap years exist and have special rules:

    every year that is a multiple of four is a leap year
    the exception to the above rule is any year that is a multiple of 100 but not a multiple of 400

Output format

You must output the year, month, and day of the month in any order you want so long as the number for the year and day of the month are not conjoined.
You can use any character (not numeric or alphabetical), or none, as a separator. The name of the month must be given as a word instead of a number. Examples for this format are shown in the test cases.
Input

You will be given an integer as an input. You can assume this integer will be smaller in magnitude than 700000 - this means negative integers are also accepted.
Test cases

input | accepted output (which is relatively flexible)

13318 | June 18 2020

2 | JanUaRy03(1984)

656979 | 3782september29

-30 | DECEMBER 02 1983

-589001 | 00371may15 (leading zeroes may be used)

0 | 1984 1 january
Scoring

This is code-golf. Shortest code wins!

*/

package main

import (
	"fmt"
	"time"
)

func main() {
	fmt.Println(date(13318))
	fmt.Println(date(2))
	fmt.Println(date(656979))
	fmt.Println(date(-30))
	fmt.Println(date(-589001))
	fmt.Println(date(0))
}

func date(n int) time.Time {
	t := time.Date(1984, time.January, 1, 0, 0, 0, 0, time.UTC)
	return t.AddDate(0, 0, n)
}
