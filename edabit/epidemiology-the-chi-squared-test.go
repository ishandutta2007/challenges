/*

The Edabit Medical Industries are developing a new drug, the Edabitin™, which will (hopefully) increase the programming skills of patients.
Various tests are carried out on different programmers: for a week some are given the Edabitin™, while others are supplied simple generic Tutorial powder.
After a week, the number of programmers able to solve ten exercises of an average level in half an hour and the number of those that instead take two hours is recorded for both control groups.

You are asked to establish if Edabitin™ has a statistical influence over performances with a Chi-Squared Test.

Look at the table below:
Treatment	2 Hours	½ Hour
Edabitin	207	282
Tutorial	231	242

The first thing to do is to calculate the total population of programmers involved in the test, so you have to sum all the four cells' values.
Then you must calculate the totals of the rows: the Edabitin™ total treatments and the Tutorial total treatments.
Calculate the totals also for the columns: normal programmers that spent 2 hours solving the exercises and improved programmers that spent just 1/2 hour. The new table now is:

Treatment	2 Hours	½ Hour	Row Tot
Edabitin	207	282	489
Tutorial	231	242	473
Col Tot	438	524	962

The value in the lower-right corner is the overall total.
Each cell now has to be transformed into the corresponding expected result: multiply the row total for the column total (crossing them), and divide the result by the overall total.
The table now is:

Treatment	2 Hours	½ Hour	Row Tot
Edabitin	(489 * 438) / 962	(489 * 524) / 962	489
Tutorial	(473 * 438) / 962	(473 * 524) / 962	473
Col Tot	438	524	962

Now for each cell you have to subtract the obtained expected value from the original cell value, square the result, and divide it by the expected value: The table now is:
Treatment	2 Hours	½ Hour
Edabitin	(207 - 222.64)² / 222.64	(282 - 266.36)² / 266.36
Tutorial	(231 - 215.36)² / 215.36	(242 - 257.64)² / 257.64

Finally, you can sum all cell values and get the Chi-Squared value (χ²) rounded to the nearest tenth:

χ² = 1.099 + 0.918 + 1.136 + 0.949 = 4.1

To establish if the effect of Edabitin is statistically significant, you must confront the Chi-Squared value with two different alpha values (or levels of confidence): alpha1 and alpha5.

If the Chi-Squared value is greater than 6.635 (alpha1), than there is the 1% of possibilities that the Edabitin™ effect is a false positive, but the 99% of possibilities that it actually works;
if it is lower than alpha1 but greater than 3.841 (alpha5), then the possibilities of an effective improvement are equals to the 95% (with the 5% of false positives possibilities).
If the Chi-Squared value is lower than alpha5 than the effect of Edabitin™ is not statistically relevant for the programming performances.

For the example table above, the Chi-Squared value is lower than alpha1 and greater than alpha5, so we can assert that: improvements in programmers treated with Edabitin™ are caused by 95% by the drug effectiveness.

Given an object data being the table containing the results to analyze
("E" is the Edabitin's row, "T" is the Tutorial's row, with the two columns being the "2 hours passed" and "1/2 hour passed" registered cases, as in the tables above)
implement a function that returns an array containing two elements:

    The Chi-Squared value rounded to the nearest tenth.
    A string with the final analysis being:
        "Edabitin effectiveness = 99%" if the Chi-Squared value is greater than alpha1.
        "Edabitin effectiveness = 95%" if the Chi-Squared value is lower than alpha1 and greater than alpha5.
        "Edabitin is ininfluent" if the Chi-Squared value is lower than alpha5.

Examples

chiSquaredTest({"E": [207, 282], "T": [231, 242]}) ➞ [4.1, "Edabitin effectiveness = 95%"]

chiSquaredTest({"E": [100, 50], "T": [100, 20]}) ➞ [9.6, "Edabitin effectiveness = 99%"]

chiSquaredTest({"E": [90, 50], "T": [80, 40]}) ➞ [0.2, "Edabitin is ininfluent"]

Notes

    Round just the final result to the nearest tenth, values of the example are actually rounded for readability scopes.
    Besides epidemiology, the Chi-Squared Test is used also in agriculture, surveys, economics and in cases where "categorical" data is implied instead of "numerical" data.
	This test is used for medium-to-large recorded cases: for smaller numbers, other tests are used. The alpha1 and alpha5 values are constants related
	to this specific exercise's tables with two rows and two columns (1 degree of freedom results), so they change for different sized tables. For more info look at the specific links in the Resources tab.
    No programmers were harmed in the making of this challenge!

*/

package main

import (
	"fmt"
	"math"
)

func main() {
	m1 := map[rune][2]float64{
		'E': {207, 282},
		'T': {231, 242},
	}
	m2 := map[rune][2]float64{
		'E': {100, 50},
		'T': {100, 20},
	}
	m3 := map[rune][2]float64{
		'E': {90, 50},
		'T': {80, 40},
	}
	m4 := map[rune][2]float64{
		'E': {366, 181},
		'T': {249, 112},
	}
	m5 := map[rune][2]float64{
		'E': {112, 201},
		'T': {77, 90},
	}
	m6 := map[rune][2]float64{
		'E': {239, 198},
		'T': {190, 100},
	}

	test(m1, 4.1, "Edabitin effectiveness = 95%")
	test(m2, 9.6, "Edabitin effectiveness = 99%")
	test(m3, 0.2, "Edabitin is ininfluent")
	test(m4, 0.4, "Edabitin is ininfluent")
	test(m5, 4.9, "Edabitin effectiveness = 95%")
	test(m6, 8.4, "Edabitin effectiveness = 99%")
}

func test(m map[rune][2]float64, cv float64, ef string) {
	ncv, nef := chi(m)
	fmt.Println(ncv, nef)
	assert(math.Abs(ncv-cv) < 1e-1)
	assert(nef == ef)
}

func assert(x bool) {
	if !x {
		panic("assertion failed")
	}
}

func chi(m map[rune][2]float64) (cv float64, ef string) {
	x := m['E']
	y := m['T']

	A := tally(x, y)
	B := average(A)
	C := coef(A, B)

	cv = sum(C)
	switch {
	case cv > 6.635:
		ef = "Edabitin effectiveness = 99%"
	case cv > 3.841:
		ef = "Edabitin effectiveness = 95%"
	default:
		ef = "Edabitin is ininfluent"
	}
	return
}

func tally(x, y [2]float64) [3][3]float64 {
	a := x[0] + x[1]
	b := y[0] + y[1]
	c := x[0] + y[0]
	d := x[1] + y[1]
	e := a + b
	return [3][3]float64{
		{x[0], x[1], a},
		{y[0], y[1], b},
		{c, d, e},
	}
}

func average(m [3][3]float64) [3][3]float64 {
	a := m[0][2] * m[2][0] / m[2][2]
	b := m[0][2] * m[2][1] / m[2][2]
	c := m[1][2] * m[2][0] / m[2][2]
	d := m[1][2] * m[2][1] / m[2][2]
	return [3][3]float64{
		{a, b, m[0][2]},
		{c, d, m[1][2]},
		{m[2][0], m[2][1], m[2][2]},
	}
}

func coef(m, n [3][3]float64) [2][2]float64 {
	a := (m[0][0] - n[0][0]) * (m[0][0] - n[0][0]) / n[0][0]
	b := (m[0][1] - n[0][1]) * (m[0][1] - n[0][1]) / n[0][1]
	c := (m[1][0] - n[1][0]) * (m[1][0] - n[1][0]) / n[1][0]
	d := (m[1][1] - n[1][1]) * (m[1][1] - n[1][1]) / n[1][1]
	return [2][2]float64{
		{a, b},
		{c, d},
	}
}

func sum(m [2][2]float64) float64 {
	return m[0][0] + m[0][1] + m[1][0] + m[1][1]
}
