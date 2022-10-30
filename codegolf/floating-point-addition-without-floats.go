/*

Your task is to write a program, in any language, that adds two floating point numbers together WITHOUT using any fractional or floating point maths. Integer maths is allowed.

Format

The format for the numbers are strings containing 1's and 0's which represent the binary value of a IEEE 754 32-bit float. For example the number 2.54 would be represented by the string "01000000001000101000111101011100".

Goal

You program should input two numbers in the above mentioned format, add them together, and output the result in the same format. The shortest answer in any language wins!

Rules

Absolutly no floating point, decimal, or any kind of non-integer maths functions are allowed.

You can assume that the input is clean (i.e. contains only 1's and 0's).

You can assume that the inputs are numbers, and not Inf, -Inf, or NaN or subnormal. However, if the result is greater than the max value or smaller than the min value, you should return Inf and -Inf respectively. A subnormal (denormal) result may be flushed to 0.

You do not have to handle rounding properly. Don't worry if your results are a few bits out.

Tests

To test your programs, you can convert between decimal and floating point binary numbers using this tool.

1000 + 0.5 = 1000.5

01000100011110100000000000000000 + 00111111000000000000000000000000 = 01000100011110100010000000000000
float.MaxValue + float.MaxValue = Infinity

01111111011111111111111111111111 + 01111111011111111111111111111111 = 01111111100000000000000000000000
321.123 + -123.321 = 197.802

01000011101000001000111110111110 + 11000010111101101010010001011010= 01000011010001011100110101010000
Good luck!

*/

package main

import (
	"math"
)

func main() {
	test(0b01000100011110100000000000000000, 0b00111111000000000000000000000000, 0b01000100011110100010000000000000)
	test(0b01111111011111111111111111111111, 0b01111111011111111111111111111111, 0b01111111100000000000000000000000)
	test(0b01000011101000001000111110111110, 0b11000010111101101010010001011010, 0b01000011010001011100110101010000)
}

func assert(x bool) {
	if !x {
		panic("assertion failed")
	}
}

func test(x, y, r uint32) {
	z := add(x, y)
	assert(z == r || z+1 == r)
}

func add(x, y uint32) uint32 {
	return math.Float32bits(math.Float32frombits(x) + math.Float32frombits(y))
}
