/*

Create a function that takes a temperature scale and a temperature measurement as arguments and returns an array with the conversion of such measurement to different scales.

Name	Input	Symbol
Celsius	cel	degC
Fahrenheit	fah	degF
Kelvin	kel	K
Rankine	ran	degR
Delisle	del	degDe
Newton	new	degN
Réaumur	rea	degRe
Rømer	rom	degRo

The resulting array should follow the order informed in the table above, and each corresponding temperature value should display two decimal digits.
Examples

temperature("cel", 0) ➞ ["0.00 degC", "32.00 degF", "273.15 K", "491.67 degR", "150.00 degDe", "0.00 degN", "0.00 degRe", "7.50 degRo"]

temperature("fah", -202) ➞ ["-130.00 degC", "-202.00 degF", "143.15 K", "257.67 degR", "345.00 degDe", "-42.90 degN", "-104.00 degRe", "-60.75 degRo"]

temperature("rom", 217.50) ➞ ["400.00 degC", "752.00 degF", "673.15 K", "1211.67 degR", "-450.00 degDe", "132.00 degN", "320.00 degRe", "217.50 degRo"]

Notes

    Check the Resources tab to understand how to convert the measurement using different scales.
    All measurements will be valid temperatures according to the scale.

*/

package main

import (
	"fmt"
	"reflect"
)

func main() {
	test("cel", 400, [8]string{"400.00 degC", "752.00 degF", "673.15 K", "1211.67 degR", "-450.00 degDe", "132.00 degN", "320.00 degRe", "217.50 degRo"})
	test("fah", 752, [8]string{"400.00 degC", "752.00 degF", "673.15 K", "1211.67 degR", "-450.00 degDe", "132.00 degN", "320.00 degRe", "217.50 degRo"})
	test("kel", 673.15, [8]string{"400.00 degC", "752.00 degF", "673.15 K", "1211.67 degR", "-450.00 degDe", "132.00 degN", "320.00 degRe", "217.50 degRo"})
	test("ran", 1211.67, [8]string{"400.00 degC", "752.00 degF", "673.15 K", "1211.67 degR", "-450.00 degDe", "132.00 degN", "320.00 degRe", "217.50 degRo"})
	test("del", -450, [8]string{"400.00 degC", "752.00 degF", "673.15 K", "1211.67 degR", "-450.00 degDe", "132.00 degN", "320.00 degRe", "217.50 degRo"})
	test("new", 132, [8]string{"400.00 degC", "752.00 degF", "673.15 K", "1211.67 degR", "-450.00 degDe", "132.00 degN", "320.00 degRe", "217.50 degRo"})
	test("rea", 320, [8]string{"400.00 degC", "752.00 degF", "673.15 K", "1211.67 degR", "-450.00 degDe", "132.00 degN", "320.00 degRe", "217.50 degRo"})
	test("rom", 217.50, [8]string{"400.00 degC", "752.00 degF", "673.15 K", "1211.67 degR", "-450.00 degDe", "132.00 degN", "320.00 degRe", "217.50 degRo"})
	test("cel", 0, [8]string{"0.00 degC", "32.00 degF", "273.15 K", "491.67 degR", "150.00 degDe", "0.00 degN", "0.00 degRe", "7.50 degRo"})
	test("fah", -202, [8]string{"-130.00 degC", "-202.00 degF", "143.15 K", "257.67 degR", "345.00 degDe", "-42.90 degN", "-104.00 degRe", "-60.75 degRo"})
	test("kel", 3.15, [8]string{"-270.00 degC", "-454.00 degF", "3.15 K", "5.67 degR", "555.00 degDe", "-89.10 degN", "-216.00 degRe", "-134.25 degRo"})
	test("ran", 851.67, [8]string{"200.00 degC", "392.00 degF", "473.15 K", "851.67 degR", "-150.00 degDe", "66.00 degN", "160.00 degRe", "112.50 degRo"})
	test("del", 525, [8]string{"-250.00 degC", "-418.00 degF", "23.15 K", "41.67 degR", "525.00 degDe", "-82.50 degN", "-200.00 degRe", "-123.75 degRo"})
	test("rea", 0, [8]string{"0.00 degC", "32.00 degF", "273.15 K", "491.67 degR", "150.00 degDe", "0.00 degN", "0.00 degRe", "7.50 degRo"})
	test("new", -33, [8]string{"-100.00 degC", "-148.00 degF", "173.15 K", "311.67 degR", "300.00 degDe", "-33.00 degN", "-80.00 degRe", "-45.00 degRo"})
}

func test(s string, v float64, r [8]string) {
	p := temperature(s, v)
	assert(reflect.DeepEqual(p, r))
}

func assert(x bool) {
	if !x {
		panic("assertion failed")
	}
}

func temperature(s string, v float64) (p [8]string) {
	u := []string{"degC", "degF", "K", "degR", "degDe", "degN", "degRe", "degRo"}
	c := convf(s, v)
	t := convt(c)

	for i := range t {
		p[i] = fmt.Sprintf("%.2f %s", t[i], u[i])
	}
	return
}

func convf(s string, v float64) (c float64) {
	switch s {
	case "cel":
		c = v
	case "fah":
		c = 5.0 / 9 * (v - 32)
	case "kel":
		c = v - 273.15
	case "ran":
		c = (v - 491.67) / 1.8
	case "del":
		c = 100 - v*2/3
	case "new":
		c = v / 0.33
	case "rea":
		c = v / 0.8
	case "rom":
		c = (v - 7.5) / 0.525
	}
	return
}

func convt(c float64) (t [8]float64) {
	t[0] = c
	t[1] = c*9/5 + 32
	t[2] = c + 273.15
	t[3] = c*1.8 + 491.67
	t[4] = (100 - c) * 1.5
	t[5] = c * 0.33
	t[6] = c * 0.8
	t[7] = c*0.525 + 7.5
	return
}
