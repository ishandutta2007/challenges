/*

Write a function that calculates overtime and pay associated with overtime.

    Working 9 to 5: regular hours
    After 5pm is overtime

Your function gets an array with 4 values:

    Start of working day, in decimal format, (24-hour day notation)
    End of working day. (Same format)
    Hourly rate
    Overtime multiplier

Your function should spit out:

    $ + earned that day (rounded to the nearest hundreth)

Examples

over_time([9, 17, 30, 1.5]) ➞ "$240.00"

over_time([16, 18, 30, 1.8]) ➞ "$84.00"

over_time([13.25, 15, 30, 1.5]) ➞ "$52.50"

2nd example explained:

    From 16 to 17 is regular, so 1 * 30 = 30
    From 17 to 18 is overtime, so 1 * 30 * 1.8 = 54
    30 + 54 = $84.00

*/

package main

import (
	"fmt"
	"math"
)

func main() {
	assert(overtime([]float64{9, 17, 30, 1.5}) == "$240.00")
	assert(overtime([]float64{9, 18, 40, 2}) == "$400.00")
	assert(overtime([]float64{13, 20, 32.5, 2}) == "$325.00")
	assert(overtime([]float64{9, 13, 25, 1.5}) == "$100.00")
	assert(overtime([]float64{11.5, 19, 40, 1.8}) == "$364.00")
	assert(overtime([]float64{10, 17, 30, 1.5}) == "$210.00")
	assert(overtime([]float64{10.5, 17, 32.25, 1.5}) == "$209.63")
	assert(overtime([]float64{16, 18, 30, 1.8}) == "$84.00")
	assert(overtime([]float64{18, 20, 32.5, 2}) == "$130.00")
	assert(overtime([]float64{13.25, 15, 30, 1.5}) == "$52.50")
	assert(overtime([]float64{13, 21, 38.6, 1.8}) == "$432.32")
}

func overtime(a []float64) string {
	v := max((min(a[1], 17)-max(a[0], 9))*a[2], 0) + max((max(a[1], 17)-max(a[0], 17))*a[2]*a[3], 0)
	return fmt.Sprintf("$%.2f", v+0.001)
}

func assert(x bool) {
	if !x {
		panic("assertion failed")
	}
}

var (
	max = math.Max
	min = math.Min
)
