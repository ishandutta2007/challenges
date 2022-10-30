/*

Slavko is learning about different numeral systems. Slavko is not the brightest when it comes to math, so he is starting out converting binary numerals to octal. The algorithm Slavko uses is this:

    Pad the binary numeral with zeros on the left until the number of digits is divisible by three.

    Group adjacent binary digits into groups of 3 digits.

    Replace each group of binary digits with the corresponding octal digit (as in Table 1).

000 0

001 1

010 2

011 3

100 4

101 5

110 6

111 7

Table 1: Binary to octal

Write a program that converts a binary numeral to octal so that Slavko can verify his results.

Input

The input contains a binary numeral. The number of digits will be less than 100, and the first digit will be 1.

Output

Output the number in octal.

*/

package main

func main() {
	assert(octal(0b1010) == 12)
	assert(octal(0b11001100) == 314)
}

func assert(x bool) {
	if !x {
		panic("assertion failed")
	}
}

func octal(n uint) uint {
	var x, y uint
	for ; n != 0; n /= 8 {
		x = (x * 10) + (n % 8)
	}
	for ; x != 0; x /= 10 {
		y = (y * 10) + (x % 10)
	}
	return y
}
