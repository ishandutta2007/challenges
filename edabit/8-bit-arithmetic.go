/*

You will be given a simple string expression representing an addition or subtraction in 8-bit 2's complement arithmetic.
Write a function that returns the result in base 10 followed by a binary representation. If any of the values are outside the range of 8-bit 2's complement, return "Overflow".

Examples

eightBit("3 + 12") ➞ [15, "11 + 1100 = 1111"]

eightBit("3 - 12") ➞ [-9, "11 - 1100 = 11110111"]

eightBit(-18 - 6) ➞ [-24, "11101110 - 110 = 11101000"]

eightBit(65 + 70) ➞ "Overflow"

eightBit(-127 + 127) ➞ [0, "10000001 + 1111111 = 0"]

Notes

Numbers in 8-bit 2's complement notation can range from -128 to 127. The eighth (leftmost) bit signifies a negative number. See Resources for details.

*/

package main

import (
	"fmt"
	"math"
	"reflect"
	"strings"
)

func main() {
	test("0 + 0", []interface{}{0, "0 + 0 = 0"})
	test("0 - 1", []interface{}{-1, "0 - 1 = 11111111"})
	test("1 + 126", []interface{}{127, "1 + 1111110 = 1111111"})
	test("128 - 56", "Overflow")
	test("92 - 108", []interface{}{-16, "1011100 - 1101100 = 11110000"})
	test("111 - 39", []interface{}{72, "1101111 - 100111 = 1001000"})
	test("-99 - 30", "Overflow")
	test("-45 + 100", []interface{}{55, "11010011 + 1100100 = 110111"})
	test("-10 - 118", []interface{}{-128, "11110110 - 1110110 = 10000000"})
	test("-128 + 127", []interface{}{-1, "10000000 + 1111111 = 11111111"})
}

func test(s string, r interface{}) {
	assert(reflect.DeepEqual(eightbit(s), r))
}

func assert(x bool) {
	if !x {
		panic("assertion failed")
	}
}

func eightbit(s string) interface{} {
	var (
		x, y int
		op   rune
	)
	s = strings.Join(strings.Fields(s), "")
	n, _ := fmt.Sscanf(s, "%d%c%d", &x, &op, &y)
	if n != 3 {
		return nil
	}

	var z int
	switch op {
	case '+':
		z = x + y
	case '-':
		z = x - y
	default:
		return nil
	}
	if overflow(x) || overflow(y) || overflow(z) {
		return "Overflow"
	}

	p := fmt.Sprintf("%b %c %b = %b", uint8(x), op, uint8(y), uint8(z))
	return []interface{}{z, p}
}

func overflow(x int) bool {
	return x < math.MinInt8 || x > math.MaxInt8
}
