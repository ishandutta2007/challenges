/*

Introduction

In a standard* (e.g. not 2020) tax year, estimated payments are due quarterly according to the schedule outlined in Publication 505.
Payment Period 	Due Date
January 1 – March 31 	April 15
April 1 – May 31 	June 15
June 1 – August 31 	September 15
September 1 – December 31 	January 15

* Saturday, Sunday, holiday rule, fiscal year taxpayers, and January payment exceptions can be ignored for the purpose of this question; use the standard table provided.

Challenge

Input:

A date/timestamp, either provided as input to your solution (function parameter or stdin) as a string (at a minimum specifying a specific year, month, an day of month) or native Date object (or equivalent) or the current (dynamically updated) date/time based on the clock of the executing machine.

Output:

The most specific payment period, one of Q1, Q2, Q3, or Q4 as a string, either printed to stdout/console or programmatically returned from the function, to which a timely payment made on the input date would be applied.
Input 	Output
January 16 - April 15 	Q1
April 16 - June 15 	Q2
June 16 - September 15 	Q3
September 16 - January 15 	Q4

A day shall commence at 00:00 (midnight) and cover time periods up to but not including 00:00 (midnight) of the following day. The last moment of a given day, to a ms granularity is 23:59:59.999.

*/

package main

import (
	"time"
)

func main() {
	assert(quarter("January 16") == "Q1")
	assert(quarter("April 15") == "Q1")
	assert(quarter("April 16") == "Q2")
	assert(quarter("June 15") == "Q2")
	assert(quarter("June 16") == "Q3")
	assert(quarter("September 15") == "Q3")
	assert(quarter("September 16") == "Q4")
	assert(quarter("January 15") == "Q4")
}

func assert(x bool) {
	if !x {
		panic("assertion failed")
	}
}

func quarter(s string) string {
	switch t := date(s); {
	case t.Before(date("January 16")):
		return "Q4"
	case t.Before(date("April 16")):
		return "Q1"
	case t.Before(date("June 16")):
		return "Q2"
	case t.Before(date("September 16")):
		return "Q3"
	default:
		return "Q4"
	}
}

func date(s string) time.Time {
	t, err := time.Parse("January 02", s)
	if err != nil {
		panic(err)
	}
	return t
}
