/*

Create a function that returns the string "Burp" with the amount of "r's" determined by the input parameters of the function.
Examples

longBurp(3) ➞ "Burrrp"

longBurp(5) ➞ "Burrrrrp"

longBurp(9) ➞ "Burrrrrrrrrp"

Notes

    Expect num to always be >= 1.
    Remember to use a capital "B".
    Don't forget to return the result.

*/

package main

import "strings"

func main() {
	assert(burp(3) == "Burrrp")
	assert(burp(5) == "Burrrrrp")
	assert(burp(9) == "Burrrrrrrrrp")
	assert(burp(10) == "Burrrrrrrrrrp")
	assert(burp(13) == "Burrrrrrrrrrrrrp")
	assert(burp(18) == "Burrrrrrrrrrrrrrrrrrp")
	assert(burp(1) == "Burp")
}

func burp(n int) string {
	return "Bu" + strings.Repeat("r", n) + "p"
}

func assert(x bool) {
	if !x {
		panic("assertion failed")
	}
}
