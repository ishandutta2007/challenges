/*

When resistors are connected together in series, the same current passes through each resistor in the chain and the total resistance, RT, of the circuit must be equal to the sum of all the individual resistors added together. That is:

RT = R1 + R2 + R3 ...

Create a function that takes an array of values resistance that are connected in series, and calculates the total resistance of the circuit in ohms. The ohm is the standard unit of electrical resistance in the International System of Units ( SI ).
Examples

seriesResistance([1, 5, 6, 3]) ➞ "15 ohms"

seriesResistance([16, 3.5, 6]) ➞ "25.5 ohms"

seriesResistance([0.5, 0.5]) ➞ "1.0 ohm"

Notes

    All inputs will be valid.
    Notice the singular ohm for values <= 1.
    This challenge was inspired by Joshua Señoron's Python Sum of Resistance in Parallel Circuits challenge. You can find it here.

*/

package main

import (
	"fmt"
	"strings"
)

func main() {
	assert(series([]float64{1, 5, 6, 3}) == "15 ohms")
	assert(series([]float64{0.2, 0.3, 0.4}) == "0.9 ohm")
	assert(series([]float64{10, 12, 1, 10}) == "33 ohms")
	assert(series([]float64{10, 13, 3.8, 20, 10}) == "56.8 ohms")
	assert(series([]float64{0.5, 0.5}) == "1 ohm")
	assert(series([]float64{16, 30, 22.8, 4}) == "72.8 ohms")
	assert(series([]float64{20, 15, 32.5, 2}) == "69.5 ohms")
	assert(series([]float64{52, 22, 20, 30}) == "124 ohms")
	assert(series([]float64{10, 12, 32, 4.9, 5, 6, 71}) == "140.9 ohms")
}

func series(r []float64) string {
	v := 0.0
	for i := range r {
		v += r[i]
	}

	s := fmt.Sprintf("%.1f", v)
	if strings.HasSuffix(s, ".0") {
		s = s[:len(s)-2]
	}
	s += " ohm"
	if v > 1 {
		s += "s"
	}

	return s
}

func assert(x bool) {
	if !x {
		panic("assertion failed")
	}
}
