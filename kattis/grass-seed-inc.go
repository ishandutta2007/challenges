/*

Many years ago after another unfruitful day in Cubicle Land, banging her head against yet another cutting edge, marketing buzzword-filled JavaScript framework, Janice the engineer looked out of the window and decided that time was ripe for a change.

So swapping her keyboard and mouse for a fork and a spade, she started her own gardening company.

After years of hard outdoor work Janice now has biceps like Van Damme and owns the premiere landscaping company in the whole of the South West, and has just been lucky enough to broker a large contract to sow lawns for landed gentry.

Each contract details the size of the lawns that need to be seeded, and the cost of seed per square metre. How much do you need to spend on seed?

Input

    One line containing a real number C (0<C≤100), the cost of seed to sow one square metre of lawn.

    One line containing an integer L (0<L≤100), the number of lawns to sow.

    L lines, each containing two positive real numbers: wi (0≤wi≤100), the width of the lawn, and li (0≤li≤100), the length of the lawn.

All real numbers are given with at most 8 decimals after the decimal point.

Output

    One line containing a real number: the cost to sow all of the lawns.

All output must be accurate to an absolute or relative error of at most 10^-6.

*/

package main

import (
	"fmt"
	"math"
)

func main() {
	test(2, [][2]float64{{2, 3}, {4, 5}, {5, 6}}, 112)
	test(0.75, [][2]float64{{2, 3.333}, {3.41, 4.567}}, 16.6796025)
}

func assert(x bool) {
	if !x {
		panic("assertion failed")

	}
}

func test(c float64, l [][2]float64, r float64) {
	p := cost(c, l)
	fmt.Println(p)
	assert(math.Abs(p-r) < 1e-8)
}

func cost(c float64, l [][2]float64) float64 {
	r := 0.0
	for _, v := range l {
		r += c * v[0] * v[1]
	}
	return r
}
