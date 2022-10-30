/*

Create a function that expands a number into a string as shown below:

25 ➞ "20 + 5"
70701 ➞ "70000 + 700 + 1"
685 ➞ "600 + 80 + 5"

Examples

expanded_form(70304) ➞ "70000 + 300 + 4"

expanded_form(1037903) ➞ "1000000 + 30000 + 7000 + 900 + 3"

expanded_form(802539) ➞ "800000 + 2000 + 500 + 30 + 9"

Notes

N/A

*/

package main

import "fmt"

func main() {
	assert(expand(12) == "10 + 2")
	assert(expand(42) == "40 + 2")
	assert(expand(70304) == "70000 + 300 + 4")
	assert(expand(1037903) == "1000000 + 30000 + 7000 + 900 + 3")
	assert(expand(802539) == "800000 + 2000 + 500 + 30 + 9")
	assert(expand(3307098) == "3000000 + 300000 + 7000 + 90 + 8")
	assert(expand(2736692) == "2000000 + 700000 + 30000 + 6000 + 600 + 90 + 2")
	assert(expand(5030708) == "5000000 + 30000 + 700 + 8")
	assert(expand(903305) == "900000 + 3000 + 300 + 5")
	assert(expand(2900837) == "2000000 + 900000 + 800 + 30 + 7")
	assert(expand(607805) == "600000 + 7000 + 800 + 5")
	assert(expand(2070504) == "2000000 + 70000 + 500 + 4")
	assert(expand(700681) == "700000 + 600 + 80 + 1")
	assert(expand(70903) == "70000 + 900 + 3")
	assert(expand(0) == "0")
}

func expand(n uint) string {
	if n == 0 {
		return "0"
	}

	var s string
	for p := uint(1); n != 0; n, p = n/10, p*10 {
		v := n % 10
		if v != 0 {
			s = fmt.Sprintf("%d + %s", v*p, s)
		}
	}
	s = s[:len(s)-3]

	return s
}

func assert(x bool) {
	if !x {
		panic("assertion failed")
	}
}
