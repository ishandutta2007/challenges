/*

In this challenge, sort a list containing a series of dates given as strings. Each date is given in the format DD-MM-YYYY_HH:MM:

"12-02-2012_13:44"

The priority of criteria used for sorting will be:

    Year
    Month
    Day
    Hours
    Minutes

Given a list lst and a string mode, implement a function that returns:

    if mode is equal to "ASC", the list lst sorted in ascending order.
    if mode is equal to "DSC", the list lst sorted in descending order.

Examples

sort_dates(["10-02-2018_12:30", "10-02-2016_12:30", "10-02-2018_12:15"], "ASC") ➞ ["10-02-2016_12:30", "10-02-2018_12:15", "10-02-2018_12:30"]

sort_dates(["10-02-2018_12:30", "10-02-2016_12:30", "10-02-2018_12:15"], "DSC") ➞ ["10-02-2018_12:30", "10-02-2018_12:15", "10-02-2016_12:30"]

sort_dates(["09-02-2000_10:03", "10-02-2000_18:29", "01-01-1999_00:55"], "ASC") ➞ ["01-01-1999_00:55", "09-02-2000_10:03", "10-02-2000_18:29"]

Notes

    Remember: the date is in the format DD-MM-YYYY_HH:MM.
    You can expect only valid formatted dates, without exceptions to handle.

*/

package main

import (
	"fmt"
	"reflect"
	"sort"
	"time"
)

func main() {
	s1 := []string{
		"18-10-2016_12:09", "01-12-2017_20:32", "18-10-2016_12:04",
		"19-10-2017_16:20", "18-10-2017_16:19", "18-10-2016_16:19",
	}
	r1_1 := []string{
		"18-10-2016_12:04", "18-10-2016_12:09", "18-10-2016_16:19",
		"18-10-2017_16:19", "19-10-2017_16:20", "01-12-2017_20:32",
	}
	r1_2 := []string{
		"01-12-2017_20:32", "19-10-2017_16:20", "18-10-2017_16:19",
		"18-10-2016_16:19", "18-10-2016_12:09", "18-10-2016_12:04",
	}

	s2 := []string{
		"11-02-2011_00:01", "21-04-2013_11:43", "02-09-2018_11:00",
		"02-09-2018_10:00", "02-09-2018_10:30", "11-02-2011_00:00",
	}
	r2_1 := []string{
		"02-09-2018_11:00", "02-09-2018_10:30", "02-09-2018_10:00",
		"21-04-2013_11:43", "11-02-2011_00:01", "11-02-2011_00:00",
	}
	r2_2 := []string{
		"11-02-2011_00:00", "11-02-2011_00:01", "21-04-2013_11:43",
		"02-09-2018_10:00", "02-09-2018_10:30", "02-09-2018_11:00",
	}

	s3 := []string{
		"03-04-1982_12:11", "09-08-2010_09:11", "14-12-2004_10:32",
		"08-12-2004_08:00", "08-12-2004_08:45", "12-02-1985_00:58",
	}
	r3_1 := []string{
		"03-04-1982_12:11", "12-02-1985_00:58", "08-12-2004_08:00",
		"08-12-2004_08:45", "14-12-2004_10:32", "09-08-2010_09:11",
	}
	r3_2 := []string{
		"09-08-2010_09:11", "14-12-2004_10:32", "08-12-2004_08:45",
		"08-12-2004_08:00", "12-02-1985_00:58", "03-04-1982_12:11",
	}

	test(s1, "ASC", r1_1)
	test(s1, "DSC", r1_2)
	test(s2, "DSC", r2_1)
	test(s2, "ASC", r2_2)
	test(s3, "ASC", r3_1)
	test(s3, "DSC", r3_2)
}

func test(s []string, m string, r []string) {
	p := sortdates(s, m)
	fmt.Println(p)
	assert(reflect.DeepEqual(p, r))
}

func assert(x bool) {
	if !x {
		panic("assertion failed")
	}
}

func sortdates(s []string, m string) []string {
	const layout = "02-01-2006_15:04"

	var err error
	t := make([]time.Time, len(s))
	for i := range s {
		t[i], err = time.Parse(layout, s[i])
		if err != nil {
			return nil
		}
	}
	sort.Slice(t, func(i, j int) bool {
		if m == "ASC" {
			return t[i].Before(t[j])
		}
		return t[i].After(t[j])
	})

	r := make([]string, len(t))
	for i := range t {
		r[i] = t[i].Format(layout)
	}
	return r
}
