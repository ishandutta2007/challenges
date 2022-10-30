/*

The Chi-Squared (χ²) goodness of fit test estimates if an empirical (observed) distribution fits a theoretical (expected) distribution within reasonable margins.
For example, to figure out if a die is loaded you could roll it many times and note the results.
Because of randomness, you can't expect to get the same frequency for all faces, but if one or more faces turn up much more frequently than some others, it is reasonable to assume the die is loaded.

The formula to calculate the Chi-Square parameter is:

Chi-squared

Below is an example of a die rolled 600 times:
Face	1	2	3	4	5	6
Observed frequency	101	116	89	108	97	89
Expected frequency	100	100	100	100	100	100
Difference	1	16	-11	8	-3	-11

In this example, the Chi-Square parameter has a value of:

χ² = ((1)^2 + (16)^2 + (-11)^2 + (8)^2 + (-3)^2 + (-11)^2) / 100 = 5.72

This parameter is then compared to a critical value, calculated taking into account the number of categories and the confidence level. Here, the critical value is 11.0705. Since 5.72 < 11.0705, it is safe to assume the die is unloaded.

Given a list with the six observed frequencies, write a function that returns true if a die is unloaded, or false if it is loaded. Take 11.0705 as the critical value for all cases.
Examples

FairDie([44, 52, 33, 40, 41, 30]) ➞ true
(χ² = 7.75) < 11.0705

FairDie([34, 27, 23, 20, 32, 28]) ➞ true
(χ² = 1.6) < 11.0705

FairDie([10, 20, 11, 5, 19, 16]) ➞ false
(χ² = 12.556) > 11.0705

Notes

N/A

*/

package main

func main() {
	assert(loaded([]float64{8, 10, 5, 15, 15, 10}) == true)
	assert(loaded([]float64{21, 22, 17, 31, 29, 30}) == true)
	assert(loaded([]float64{8, 16, 16, 9, 11, 3}) == false)
	assert(loaded([]float64{14, 10, 16, 14, 15, 15}) == true)
	assert(loaded([]float64{7, 18, 15, 21, 14, 28}) == false)
	assert(loaded([]float64{29, 34, 33, 38, 41, 35}) == true)
	assert(loaded([]float64{10, 20, 11, 5, 19, 16}) == false)
}

func assert(x bool) {
	if !x {
		panic("assertion failed")
	}
}

func loaded(a []float64) bool {
	return chisq(a) < 11.0705
}

func mean(a []float64) float64 {
	if len(a) == 0 {
		return 0
	}

	m := 0.0
	for _, v := range a {
		m += v
	}
	return m / float64(len(a))
}

func chisq(a []float64) float64 {
	r := 0.0
	m := mean(a)
	for _, v := range a {
		r += (v - m) * (v - m)
	}
	return r / m
}
