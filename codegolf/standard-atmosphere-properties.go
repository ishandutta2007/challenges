/*

The International Standard Atmosphere (ISA) is a model of the Earth's atmosphere at "reference" conditions. It includes information on pressure, temperature, and density change vs. altitude.

The ISA tabulates these properties at various layers, and an estimation of the value of interest can by found by the following procedure:

Find the highest layer A which has a base altitude lower than or equal to the altitude of interest.
Linearly interpolate between layers A and A+1 to find the properties at the altitude of interest.
For example, suppose you want to find the temperature at a geometric altitude above MSL of 40000m. Thus, A=3, and the temperature is (in degrees C):

T = (-2.5+44.5)*(40000-32000)/(47000-32000)-44.5 = -22.1
The goal of this challenge is given a geometric altitude above MSL, find the standard temperature, pressure, and density at that altitude.

For the purposes of this challenge, use the table of the 1976 ISA model (presented on Wikipedia). Here is a link a Gist containing the data in CSV format. Note that the CSV file includes the missing density values from Wikipedia's page.

Input
The input is a single finite real number representing the geometric altitude above MSL in meters. This number is guaranteed to be between [-611,86000) (i.e. it is greater than or equal to -611, and is strictly less than 86000).

The input may come from any source desired (function input, stdio, etc.)

Output
The output are the 3 real numbers representing the standard temperature, pressure, and density at the input altitude.
The answer should be accurate to within 0.1%. The answer may be in order desired, as long as it is obvious which value represents which quantity
(ex.: the first number is always temperature, the second number is always density, and the third number is always pressure).
Note that the magnitude of the quantity does not count as make it obvious what the value represents.

You are welcome to choose any units to output your answers in as long as they properly describe the quantity of interest.
Ex.: you may output temperature in degrees Fahrenheit, Celsius, Kelvin, etc., but you can't output the temperature in meters.
Your code does not need to output the units abbreviation if it is always the same for a given quantity, but you should specify in your answer what units your answer uses.

The output may be to any sink desired (stdio, return value, output parameter, etc.).

Examples
All examples use meters for input, and output in the order temperature (C), pressure (Pa), density (kg/m^3).

-611
19, 108900, 1.2985

0
15.0335, 104368, 1.24943

12000
-56.5, 20771, 0.333986

47350
-2.5, 110.91, 0.0014276

71803
-58.502, 3.95614764, 6.42055e-5

Scoring
This is code golf; shortest answer in bytes wins. Standard loopholes are prohibited. You may use any built-ins desired.
If you are using any external resources to store the tabulated data, you must include the size of the resource (in bytes) as read into your program as part of your score.

Ex.: Say you read in a compressed version of the CSV table I linked which is 100 bytes long (uncompressed is 333 bytes), and your code is 126 bytes long. Then your net score is 100+126=226.

*/

package main

import (
	"encoding/csv"
	"fmt"
	"math"
	"strconv"
	"strings"
)

func main() {
	test(-611, 19, 108900, 1.2985)
	test(0, 15.0335, 104368, 1.24943)
	test(12000, -56.5, 20771, 0.333986)
	test(47350, -2.5, 110.91, 0.0014276)
	test(71803, -58.502, 3.95614764, 6.42055e-5)
	test(1e6, -1, -1, -1)
	test(-1e6, -1, -1, -1)
}

func assert(x bool) {
	if !x {
		panic("assertion failed")
	}
}

func test(h float64, RT, RP, RD float64) {
	const eps = 1
	a, err := parseisa(isa1976)
	if err != nil {
		panic(err)
	}

	T, P, D := atmosphere(a, h)
	fmt.Println(T, P, D)
	fmt.Println(RT, RP, RD)
	fmt.Println()
	assert(math.Abs(T-RT) < eps)
	assert(math.Abs(P-RP) < eps)
	assert(math.Abs(D-RD) < eps)
}

func lerp(t, a, b float64) float64 {
	return a + t*(b-a)
}

func unlerp(t, a, b float64) float64 {
	return (t - a) / (b - a)
}

func remap(x, a, b, c, d float64) float64 {
	return lerp(unlerp(x, a, b), c, d)
}

func atmosphere(a [][4]float64, h float64) (T, P, D float64) {
	T, P, D = -1, -1, -1
	i, j, n := 0, 0, len(a)

	for j = i + 1; j < n; i, j = i+1, j+1 {
		if a[i][0] <= h && h <= a[j][0] {
			break
		}
	}
	if j >= n || h < a[i][0] || h > a[j][0] {
		return
	}

	t := remap(h, a[i][0], a[j][0], 0, 1)
	T = lerp(t, a[i][1], a[j][1])
	P = lerp(t, a[i][2], a[j][2])
	D = lerp(t, a[i][3], a[j][3])
	return
}

func parseisa(s string) (a [][4]float64, err error) {
	r := strings.NewReader(s)
	c := csv.NewReader(r)
	p, err := c.ReadAll()
	n := len(p)
	if err != nil || n < 1 {
		return
	}

	a = make([][4]float64, n-1)
	for i := 1; i < n; i++ {
		m := len(p[i])
		if m != 5 {
			err = fmt.Errorf("invalid number of columns: %d", m)
			return
		}

		for j := range a[i] {
			a[i-1][j], _ = strconv.ParseFloat(p[i][j+1], 64)
		}
	}
	return
}

const isa1976 = `Layer,Altitude(m),Temperature(C),Pressure(Pa),Density(kg/m^3)
0,-611,19,108900,1.29853103694
1,11019,-56.5,22632,3.639105e-1
2,20063,-56.5,5474.9,8.80334745e-2
3,32162,-44.5,868.02,1.32247926e-2
4,47350,-2.5,110.91,1.42755556e-3
5,51413,-2.5,66.939,8.62248191e-4
6,71802,-58.5,3.9564,6.42095529e-5
7,86000,-86.28,0.3734,6.96089485e-6`
