/*

Given a series of arrays, with each individual array containing the time of the alarm set and the sleep duration, return what time to sleep.
Examples

bedTime(["07:50", "07:50"]) ➞ ["00:00"]
// The second argument means 7 hours, 50 minutes sleep duration.

bedTime(["06:15", "10:00"], ["08:00", "10:00"], ["09:30", "10:00"]) ➞ ["20:15", "22:00", "23:30"]
// The second argument of each sub list means 10 hours sleep duration.

bedTime(["05:45", "04:00"], ["07:10", "04:30"]) ➞ ["01:45", "02:40"]
// Sleep duration can be different among the arrays.

Notes

    Times should be given in 24-hrs (i.e. "23:25" as opposed to "11:25PM").
    Return an array of strings.

*/

package main

import (
	"fmt"
	"reflect"
)

func main() {
	test([][2]string{{"07:50", "07:50"}}, []string{"00:00"})
	test([][2]string{{"06:15", "10:00"}, {"08:00", "10:00"}, {"09:30", "10:00"}}, []string{"20:15", "22:00", "23:30"})
	test([][2]string{{"05:45", "04:00"}, {"07:10", "04:30"}}, []string{"01:45", "02:40"})
}

func test(s [][2]string, r []string) {
	p := bedtime(s)
	fmt.Println(p)
	if len(p) == 0 {
		assert(len(p) == len(r))
	} else {
		assert(reflect.DeepEqual(p, r))
	}
}

func assert(x bool) {
	if !x {
		panic("assertion failed")
	}
}

func bedtime(s [][2]string) []string {
	p := make([]string, len(s))
	for i, t := range s {
		var r [4]int
		fmt.Sscanf(t[0], "%d:%d", &r[0], &r[1])
		fmt.Sscanf(t[1], "%d:%d", &r[2], &r[3])

		d := 0
		if r[1] < r[3] {
			d = 1
		}
		h := mod(r[0]-r[2]-d, 24)
		m := mod(r[1]-r[3], 60)
		p[i] = fmt.Sprintf("%02d:%02d", h, m)
	}
	return p
}

func mod(x, m int) int {
	x %= m
	if x < 0 {
		x += m
	}
	return x
}
