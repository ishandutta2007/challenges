/*

The GolfScript language has one serious lack, no float or fixed point handling.
Remedy this by creating a function F for converting an integer number, given as a string, to a string representing 1 / 10 000 000 000 of it's value.
The function must handle both positive and negative values as well as leading 0s.

The following pretty-print rules apply:

No trailing 0s.
No . if the result is integer.
No leading 0s, except for numbers with no integer part, they should have 1 leading 0.
The result must be output as a single string.

Examples:

123 -> 0.0000000123
-00 -> 0
012345678901234567890 -> 1234567890.123456789
-123 -> -0.0000000123
10000000000001 -> 1000.0000000001
123000000000000 -> 12300

The competition is only between GolfScript submissions using no Ruby functionality. Solutions in other languages may be posted, but they are not eligible for winning,
these may not use any fixed or float point functionality that the language offers, and must accept arbitrarily large inputs.

*/

package main

import (
	"math/big"
)

func main() {
	assert(F("123") == "0.0000000123")
	assert(F("-00") == "0")
	assert(F("012345678901234567890") == "1234567890.123456789")
	assert(F("-123") == "-0.0000000123")
	assert(F("10000000000001") == "1000.0000000001")
	assert(F("123000000000000") == "12300")
}

func assert(x bool) {
	if !x {
		panic("assertion failed")
	}
}

func F(s string) string {
	x := new(big.Float)
	y := new(big.Float)

	x.SetString(s)
	y.SetString("10000000000")
	x.Quo(x, y)

	i, acc := x.Int64()
	if i == 0 && acc == big.Exact {
		return "0"
	}

	return x.Text('f', -1)
}
