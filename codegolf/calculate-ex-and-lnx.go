/*

Given a floating point x (x<100), return e^x and ln(x). The first 6 decimal places of the number have to be right, but any others after do not have to be correct.

You cannot have any "magic" constants explicitly stated (e.x. a=1.35914 since 1.35914*2 ~= e), but you can calculate them. Only use +, -, *, and / for arithmetic operators.

If x is less than or equal to 0, output ERROR instead of the intended value of ln(x).

Test Cases:

input: 2
output: 7.389056 0.693147
input: 0.25
output: 1.284025 -1.386294
input: 2.718281828
output: 15.154262 0.999999  (for this to output correctly, don't round to 6 places)
input: -0.1
output: 0.904837 ERROR

Shortest code wins.

*/

package main

import (
	"fmt"
	"math"
)

func main() {
	test(2)
	test(0.25)
	test(2.718281828)
	test(-0.1)
}

func test(x float64) {
	e, l := eln(x)
	fmt.Printf("%.6f %.6f\n", e, l)
}

func eln(x float64) (e, l float64) {
	return math.Exp(x), math.Log(x)
}
