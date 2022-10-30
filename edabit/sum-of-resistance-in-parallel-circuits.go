/*

If two or more resistors are connected in parallel, the overall resistance of the circuit reduces. It is possible to calculate the total resistance of a parallel circuit by using this formula:

1/RTotal = 1/R1 + 1/R2 + 1/R3 ...

Create a function that takes an array of resistance values, and calculates the total resistance of the circuit.
Worked Example

parallelResistance([6, 3, 6]) ➞ 1.5

// 1/RTotal = 1/6 + 1/3 + 1/6
// 1/RTotal = 2/3
// RTotal = 3/2 = 1.5

Examples

parallelResistance([6, 3]) ➞ 2

parallelResistance([10, 20, 10]) ➞ 4

parallelResistance([500, 500, 500]) ➞ 166.6
// Round to the nearest decimal place

Notes

    Note that you should rearrange to return the Resistance Total, not 1 / Resistance Total.
	Round to the nearest decimal place.
	All inputs will be valid.

*/

package main

import "math"

func main() {
	test([]float64{6, 3}, 2)
	test([]float64{6, 3, 6}, 1.5)
	test([]float64{10, 10}, 5)
	test([]float64{10, 20, 10}, 4)
	test([]float64{60, 30, 20}, 10)
	test([]float64{16, 4}, 3.2)
	test([]float64{20, 5}, 4)
	test([]float64{500, 500, 500}, 166.7)
	test([]float64{1, 2, 3, 4, 5, 6, 7, 8, 9, 10}, 0.3)
}

func assert(x bool) {
	if !x {
		panic("assertion failed")
	}
}

func test(r []float64, v float64) {
	assert(math.Abs(parallel(r)-v) < 1e-1)
}

func parallel(r []float64) float64 {
	v := 0.0
	for i := range r {
		v += 1 / r[i]
	}
	return 1 / v
}
