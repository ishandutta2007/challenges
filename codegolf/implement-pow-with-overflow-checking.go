/*

Implement a function or program which raises x to the power of y. Inputs are 16-bit signed integers.
That is, both are in the range [-32768, 32767]. The output should be in the same range.
I chose this range because it should make it possible to do exhaustive testing to ensure all edge-cases are covered.

If the output can't be represented (it's too negative, too positive or not an integer), do one of the following:

Throw an exception
Print an error message
Return a special value (-1, 0 or any other specific value)
Please document what your implementation does in case of error; the behavior should be identical for all error cases!

By definition, 0 to the power of 0 is 1 (not "error").

I am most interested in non-trivial solutions, but if your language has a suitable pow function, you are allowed to use it!

Test cases:

pow(-32768, -32768) = error
pow(-32768, -1) = error
pow(-32768, 0) = 1
pow(-32768, 1) = -32768
pow(-32768, 2) = error
pow(-32768, 32767) = error
pow(-100, 100) = error
pow(-180, 2) = 32400
pow(-8, 5) = -32768
pow(-3, -2) = error
pow(-3, 9) = -19683
pow(-2, 15) = -32768
pow(-1, -999) = -1
pow(-1, -100) = 1
pow(-1, 100) = 1
pow(-1, 999) = -1
pow(0, -100) = error
pow(0, -1) = error
pow(0, 0) = 1
pow(0, 999) = 0
pow(1, -999) = 1
pow(1, 10000) = 1
pow(1, 9999) = 1
pow(2, 14) = 16384
pow(2, 15) = error
pow(8, 5) = error
pow(4, 7) = 16384
pow(181, 2) = 32761
pow(182, 2) = error
pow(10000, 1) = 10000

*/

package main

import (
	"math"
	"math/big"
)

func main() {
	assert(pow(-32768, -32768) == "error")
	assert(pow(-32768, -1) == "error")
	assert(pow(-32768, 0) == int16(1))
	assert(pow(-32768, 1) == int16(-32768))
	assert(pow(-32768, 2) == "error")
	assert(pow(-32768, 32767) == "error")
	assert(pow(-100, 100) == "error")
	assert(pow(-180, 2) == int16(32400))
	assert(pow(-8, 5) == int16(-32768))
	assert(pow(-3, -2) == "error")
	assert(pow(-3, 9) == int16(-19683))
	assert(pow(-2, 15) == int16(-32768))
	assert(pow(-1, -999) == int16(-1))
	assert(pow(-1, -100) == int16(1))
	assert(pow(-1, 100) == int16(1))
	assert(pow(-1, 999) == int16(-1))
	assert(pow(0, -100) == "error")
	assert(pow(0, -1) == "error")
	assert(pow(0, 0) == int16(1))
	assert(pow(0, 999) == int16(0))
	assert(pow(1, -999) == int16(1))
	assert(pow(1, 10000) == int16(1))
	assert(pow(1, 9999) == int16(1))
	assert(pow(2, 14) == int16(16384))
	assert(pow(2, 15) == "error")
	assert(pow(8, 5) == "error")
	assert(pow(4, 7) == int16(16384))
	assert(pow(181, 2) == int16(32761))
	assert(pow(182, 2) == "error")
	assert(pow(10000, 1) == int16(10000))
}

func assert(x bool) {
	if !x {
		panic("assertion failed")
	}
}

func pow(x, y int16) any {
	if x == 1 {
		return int16(1)
	}
	if x == -1 {
		return int16(1 - 2*(y&1))
	}
	if y < 0 {
		return "error"
	}

	lo := big.NewInt(math.MinInt16)
	hi := big.NewInt(math.MaxInt16)

	p := big.NewInt(int64(x))
	q := big.NewInt(int64(y))
	p.Exp(p, q, nil)
	if p.Cmp(lo) < 0 || p.Cmp(hi) > 0 {
		return "error"
	}
	return int16(p.Int64())
}
