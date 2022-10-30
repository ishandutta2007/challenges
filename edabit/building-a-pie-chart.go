/*

A pie chart is a circular graphical representation of a dataset,
where each category frequency is represented by a slice (or circular sector)
with an amplitude in degrees given by the single frequency percentage over the total of frequencies.
You can obtain the degrees of sectors following these steps:

    Calculate frequencies total.
    Calculate percentage of every category frequency dividing it by the frequencies total.
    Transform every percentage in degrees multiplying it for 360.

You are given a dictionary data with keys being the data categories (represented by letters) and values being the data frequencies. Implement a function that returns a map to design a pie chart, like to say the same dictionary with values transformed in degrees instead of frequencies. Round final values to the nearest tenth.

Pie Chart
Examples

pie_chart({ "a": 1, "b": 2 }) ➞ { "a": 120, "b": 240 }

pie_chart({ "a": 30, "b": 15, "c": 55 }) ➞ { "a": 108, "b": 54, "c": 198 }

pie_chart({ "a": 8, "b": 21, "c": 12, "d": 5, "e": 4 }) ➞ { "a": 57.6, "b": 151.2, "c": 86.4, "d": 36, "e": 28.8 }

Notes

N/A

*/

package main

import (
	"math"
)

func main() {
	m1 := map[string]int{
		"a": 8, "b": 21, "c": 12, "d": 5, "e": 4,
	}
	p1 := map[string]float64{
		"a": 57.6, "b": 151.2, "c": 86.4, "d": 36, "e": 28.8,
	}

	m2 := map[string]int{
		"a": 30, "b": 15, "c": 55,
	}
	p2 := map[string]float64{
		"a": 108, "b": 54, "c": 198,
	}

	m3 := map[string]int{
		"a": 1, "b": 2,
	}
	p3 := map[string]float64{
		"a": 120, "b": 240,
	}

	m4 := map[string]int{
		"a": 10, "b": 33, "c": 2, "d": 48, "e": 9,
	}
	p4 := map[string]float64{
		"a": 35.3, "b": 116.5, "c": 7.1, "d": 169.4, "e": 31.8,
	}

	m5 := map[string]int{
		"a": 10000, "b": 10000, "c": 10000, "d": 10000,
	}
	p5 := map[string]float64{
		"a": 90, "b": 90, "c": 90, "d": 90,
	}

	m6 := map[string]int{
		"a": 1, "b": 10, "c": 100, "d": 1000, "e": 666,
	}
	p6 := map[string]float64{
		"a": 0.2, "b": 2, "c": 20.3, "d": 202.6, "e": 134.9,
	}

	m7 := map[string]int{
		"a": 110, "b": 462, "c": 0,
	}
	p7 := map[string]float64{
		"a": 69.2, "b": 290.8, "c": 0,
	}

	test(m1, p1)
	test(m2, p2)
	test(m3, p3)
	test(m4, p4)
	test(m5, p5)
	test(m6, p6)
	test(m7, p7)
}

func piechart(m map[string]int) map[string]float64 {
	p := make(map[string]float64)
	t := 0
	for _, v := range m {
		t += v
	}
	for k, v := range m {
		p[k] = float64(v) / float64(t) * 360
	}
	return p
}

func test(m map[string]int, r map[string]float64) {
	p := piechart(m)
	for k, _ := range p {
		assert(math.Abs(p[k]-r[k]) < 1e-1)
	}
}

func assert(x bool) {
	if !x {
		panic("assertion failed")
	}
}
