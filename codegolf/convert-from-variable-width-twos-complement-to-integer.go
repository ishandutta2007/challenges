/*

Take an input, and convert it from Two's Complement notation (binary where the first bit is negated, but the rest are taken as normal) into decimal.
Input can be as a string, a list of digits, a number, or pretty much any other format which is recognizably Two's Complement. Leading zeroes must function properly.

Examples:

0 -> 0
1 -> -1
111 -> -3
011 -> 3
100 -> -4
1001 -> -7
0001 -> 1

Example conversion: Say our input is 1101. We can see that the first bit is in position 4, so has a positional value of 2^3.
Therefore, since it's a 1, we add -8 to our total.
Then, the rest of the bits are converted just the same as regular binary (with 101 being the same as 5), so the result is -3.

Example implementation (Mathematica, 40 characters): Rest@#~FromDigits~2 - 2^Length@#/2*#[[1]] & This implementation takes input as a list of digits.

If there's no better solution in Mathematica, feel free to use the solution here and post it as a community wiki.

*/

package main

import (
	"fmt"
	"strconv"
)

func main() {
	test("0", 0)
	test("1", -1)
	test("011", 3)
	test("100", -4)
	test("1001", -7)
	test("0001", 1)
}

func assert(x bool) {
	if !x {
		panic("assertion failed")
	}
}

func test(s string, r int64) {
	v, err := x2c(s)
	assert(err == nil)
	fmt.Printf("%s -> %d\n", s, v)
	assert(v == r)
}

func x2c(s string) (int64, error) {
	n := len(s)

	x, err := strconv.ParseInt(s, 2, 64)
	if err != nil {
		return 0, err
	}
	y := int64(1) << (n - 1)

	v := x
	if x >= y {
		v = -y + (x - y)
	}
	return v, nil
}
