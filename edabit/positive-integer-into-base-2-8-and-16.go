/*

Create a function that takes a positive integer number (one of base2, base8, or base16) and converts the integer into the given base and returns a string using recursion.

Examples

integerToString(10 , 2) ➞ "1010"
// Base = 2

integerToString(1642 , 8) ➞ "3152"
// Base = 8

integerToString(212 , 16) ➞ "d4"
// Base = 16

Notes

    Input is a positive integer and base = 2, 8, or 16.
    Please use recursion to solve this.

*/

package main

import "fmt"

func main() {
	assert(itos(10, 2) == "1010")
	assert(itos(1642, 8) == "3152")
	assert(itos(102, 2) == "1100110")
	assert(itos(212, 16) == "d4")
	assert(itos(18, 2) == "10010")
	assert(itos(3162, 16) == "c5a")
	assert(itos(10, 8) == "12")
	assert(itos(162, 8) == "242")
	assert(itos(27, 2) == "11011")
	assert(itos(4321, 16) == "10e1")
	assert(itos(1622, 16) == "656")
}

func assert(x bool) {
	if !x {
		panic("assertion failed")
	}
}

func itos(n, b uint) string {
	f := "%v"
	switch b {
	case 2:
		f = "%b"
	case 8:
		f = "%o"
	case 16:
		f = "%x"
	}
	return fmt.Sprintf(f, n)
}
