/*

In this challenge, you must verify the equality of two different given parameters: a and b.

Both the value and the type of parameters need to be tested in order to have an matching equality. The possible types of the given parameters are:

    Numbers
    Strings
    Booleans (false or true)
    Special values: undefined, null and NaN

What have you learnt so far that will permit you to do two different checks (value and type) with a single statement?

Implement a function that returns true if the parameters are equal, and false if they are different.
Examples

checkEquality(1, true) ➞ false
// A number and a boolean: their type is different

checkEquality(0, "0") ➞ false
// A number and a string: their type is different

checkEquality(1,  1) ➞ true
// A number and a number: their type and value are equal

*/

package main

import "math"

func main() {
	assert(equal(1, true) == false)
	assert(equal(0, "0") == false)
	assert(equal(1, 1) == true)
	assert(equal(0, "") == false)
	assert(equal(0, "1") == false)
	assert(equal(0, false) == false)
	assert(equal(math.NaN(), math.NaN()) == false)
	assert(equal(nil, "undefined") == false)
	assert(equal("undefined", "undefined") == true)
	assert(equal(false, "undefined") == false)
}

func equal(a, b interface{}) bool {
	return a == b
}

func assert(x bool) {
	if !x {
		panic("assertion failed")
	}
}
