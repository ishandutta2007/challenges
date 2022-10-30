/*

Create a function which adds zeros to the start of a binary string, so that its length is a mutiple of 8.

Examples

completeBinary("1100") ➞ "00001100"

completeBinary("1101100") ➞ "01101100"

completeBinary("110010100010") ➞ "0000110010100010"

Notes

Return the same string if its length is already a multiple of 8.

*/

package main

import (
	"strings"
)

func main() {
	test("1100", "00001100")
	test("1101100", "01101100")
	test("110010100010", "0000110010100010")
	test("1001110001111011100101", "001001110001111011100101")
	test("111101100011001111100111010001001110010101011001000000001101100", "0111101100011001111100111010001001110010101011001000000001101100")
	test("1100110111000000010000110011001", "01100110111000000010000110011001")
	test("011001100101100100100001110101110", "0000000011001100101100100100001110101110")
	test("10000010100000011", "000000010000010100000011")
	test("0010100101011110000000101010010", "00010100101011110000000101010010")
	test("1111000010000101010011001110110000", "0000001111000010000101010011001110110000")
	test("100111110111011110101100", "100111110111011110101100")
	test("1111011011010101000001010001000011110000001100100001111110111110001100", "001111011011010101000001010001000011110000001100100001111110111110001100")
	test("000101011101010110000011100011000001001111001001000101111101011", "0000101011101010110000011100011000001001111001001000101111101011")
	test("01000000011101110001100011101111111011100110011", "001000000011101110001100011101111111011100110011")
	test("0001001100011100111101000111111011001001111100100000", "00000001001100011100111101000111111011001001111100100000")
	test("11011111000001001000", "000011011111000001001000")
	test("111011100010111000", "000000111011100010111000")
	test("11000011100111000001110100", "00000011000011100111000001110100")
	test("010001100100001110000001001000000001111111101010010111", "00010001100100001110000001001000000001111111101010010111")
	test("110101101100010110010000100100110110010010000000101000110101010101100", "000110101101100010110010000100100110110010010000000101000110101010101100")
	test("1010", "00001010")
	test("11010010010", "0000011010010010")
	test("1010010101001010011000110101101101100011100010111101110110", "0000001010010101001010011000110101101101100011100010111101110110")
	test("10011101001100001", "000000010011101001100001")
	test("1011001110011101010011101110001000010011011", "000001011001110011101010011101110001000010011011")
	test("111110101111100011010001111110100001101110101011001110111001", "0000111110101111100011010001111110100001101110101011001110111001")
	test("000100110001110011011111101101000110010101", "000000000100110001110011011111101101000110010101")
	test("01101000110000111100110001", "00000001101000110000111100110001")
	test("110011010", "0000000110011010")
	test("10100000100", "0000010100000100")
	test("01110110101101110000111000010100", "01110110101101110000111000010100")
	test("00111101101110001111010100011000011101111110110000001110", "00111101101110001111010100011000011101111110110000001110")
	test("1000101011011110110100001010000111100010001111110", "00000001000101011011110110100001010000111100010001111110")
	test("00110001001110111010111000100101011011100110101010", "00000000110001001110111010111000100101011011100110101010")
	test("11100110010001110111111000100000011011011110110", "011100110010001110111111000100000011011011110110")
	test("001111010010101111101001111100010110011001000011101011100101", "0000001111010010101111101001111100010110011001000011101011100101")
	test("00110001000110011100", "000000110001000110011100")
	test("10011101101011111101101010", "00000010011101101011111101101010")
	test("0110000001001010101100111101010100010010", "0110000001001010101100111101010100010010")
	test("01001111001110010001010111101000", "01001111001110010001010111101000")
	test("00111000010010110111001111011010001010000111010000011110111", "0000000111000010010110111001111011010001010000111010000011110111")
	test("1101100011100110101000000010101011100001001001101", "00000001101100011100110101000000010101011100001001001101")
	test("0101110010100001111", "000000101110010100001111")
	test("01010", "00001010")
	test("0110010000001010110111011110101111000011111101000001110", "00110010000001010110111011110101111000011111101000001110")
	test("10100110110110000101011010111101000111100", "000000010100110110110000101011010111101000111100")
	test("001101011110011111011010111000001", "0000000001101011110011111011010111000001")
	test("111000011001101100110010101010110100101", "0111000011001101100110010101010110100101")
	test("1010000111001010001001011110000110000010", "1010000111001010001001011110000110000010")
	test("1001100111111001010101110", "00000001001100111111001010101110")
	test("11101010001011011010001101000001010000000101", "000011101010001011011010001101000001010000000101")
	test("0101000", "00101000")
	test("100101000000000001101100001111100", "0000000100101000000000001101100001111100")
}

func completebinary(s string) string {
	return strings.Repeat("0", (8-len(s)&7)&7) + s
}

func test(s, r string) {
	assert(completebinary(s) == r)
}

func assert(x bool) {
	if !x {
		panic("assertion failed")
	}
}