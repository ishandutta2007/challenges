/*

Given a list of floating point numbers, standardize it.

Details
A list x1,x2,…,xn is standardized if the mean of all values is 0, and the standard deviation is 1.
One way to compute this is by first computing the mean μ and the standard deviation σ and then computing the standardization by replacing every xi with (xi−μ)/σ.

You can assume that the input contains at least two distinct entries (which implies σ≠0).
Note that some implementations use the sample standard deviation, which is not equal to the population standard deviation σ we are using here.
There is a CW answer for all trivial solutions.

Examples
[1,2,3] -> [-1.224744871391589,0.0,1.224744871391589]
[1,2] -> [-1,1]
[-3,1,4,1,5] -> [-1.6428571428571428,-0.21428571428571433,0.8571428571428572,-0.21428571428571433,1.2142857142857144]
(These examples have been generated with this script.)

*/

package main

import (
	"fmt"
	"math"
)

func main() {
	test([]float64{1, 2, 3}, []float64{-1.224744871391589, 0.0, 1.224744871391589})
	test([]float64{1, 2}, []float64{-1, 1})
	test([]float64{-3, 1, 4, 1, 5}, []float64{-1.6428571428571428, -0.21428571428571433, 0.8571428571428572, -0.21428571428571433, 1.2142857142857144})
}

func assert(x bool) {
	if !x {
		panic("assertion failed")
	}
}

func test(x, r []float64) {
	y := standardize(x)
	fmt.Println(y)
	for i := range r {
		assert(math.Abs(y[i]-r[i]) < 1e-3)
	}
}

func standardize(x []float64) []float64 {
	m := mean(x)
	o := stddev(x)
	y := make([]float64, len(x))
	for i := range x {
		y[i] = (x[i] - m) / o
	}
	return y
}

func mean(x []float64) float64 {
	m := 0.0
	for i := range x {
		m += x[i]
	}
	return m / float64(len(x))
}

func stddev(x []float64) float64 {
	m := mean(x)
	s := 0.0
	for i := range x {
		s += (x[i] - m) * (x[i] - m)
	}
	return math.Sqrt(s / float64(len(x)))
}
