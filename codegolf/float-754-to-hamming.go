/*

You will be given as input an integer k in the range from -4503599627370496 (−252) to 4503599627370496 (252). As is well known, integers in this range can be represented exactly as double-precision floating-point values.

You should output the Hamming weight (number of ones) of the encoding of k in binary64 format. This uses 1 bit for the sign, 11 bits for the exponent (encoded with an offset), and 52 for the mantissa; see the above link for details.

As an example, number 22 is represented as

0 10000000011 0110000000000000000000000000000000000000000000000000

Since there are 5 ones, the output is 5.

Note that endianness doesn't affect the result, so you can safely use your machine's actual internal representation of double-precision values to compute the output.
Additional rules

    Programs or functions are allowed.
    Any programming language can be used.
    Standard loopholes are forbidden
    The input number will be in decimal. Other than that, input/output means and format are flexible as usual.
    Shortest code in bytes wins.

Test cases

22                ->   5
714               ->   6
0                 ->   0
1                 ->  10
4503599627370496  ->   5
4503599627370495  ->  55
1024              ->   3
-1024             ->   4
-4096             ->   5
1000000000        ->  16
-12345678         ->  16

*/

package main

import (
	"math"
	"math/bits"
)

func main() {
	assert(float754hamming(22) == 5)
	assert(float754hamming(714) == 6)
	assert(float754hamming(0) == 0)
	assert(float754hamming(1) == 10)
	assert(float754hamming(4503599627370496) == 5)
	assert(float754hamming(4503599627370495) == 55)
	assert(float754hamming(1024) == 3)
	assert(float754hamming(-1024) == 4)
	assert(float754hamming(-4096) == 5)
	assert(float754hamming(1000000000) == 16)
	assert(float754hamming(-12345678) == 16)
}

func float754hamming(x int64) int {
	b := math.Float64bits(float64(x))
	return bits.OnesCount64(b)
}

func assert(x bool) {
	if !x {
		panic("assertion failed")
	}
}
