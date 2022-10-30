/*

Create a function that will take a HEX number and returns the binary equivalent (as a string).

Examples

toBinary(0xFF) ➞ "11111111"

toBinary(0xAA) ➞ "10101010"

toBinary(0xFA) ➞ "11111010"

Notes

The number will be always an 8-bit number.

*/

package main

import "fmt"

func main() {
	assert(hex2bin(0xff) == "11111111")
	assert(hex2bin(0xaa) == "10101010")
	assert(hex2bin(0xfa) == "11111010")
}

func assert(x bool) {
	if !x {
		panic("assertion failed")
	}
}

func hex2bin(v uint8) string {
	return fmt.Sprintf("%0b", v)
}
