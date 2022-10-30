/*

The ubiquitous 7-segment numerical display can unambiguously display all 16 hexadecimal digits as show in this wikipedia .gif

Entries for this challenge will create a circuit diagram using NAND logic gates which transforms the four bits of a hex digit to the inputs for the seven segments.
The inputs for the 7 segment display are typically labelled as follows: (DP (decimal point) is ignored for this challenge)

A 7-segment display with the segments labeled as follows: DP (for the decimal point), A-F (clockwise, starting from the top, with B, C, E, F being vertical and half the total height), G (center horizontal line)

Thus your circuit will need to conform to the following truth table:

Hex   | Hex Input Bit | Output to Segment line:
digit |  3  2  1  0   |  A  B  C  D  E  F  G
------+---------------+-----------------------
   0  |  0  0  0  0   |  1  1  1  1  1  1  0
   1  |  0  0  0  1   |  0  1  1  0  0  0  0
   2  |  0  0  1  0   |  1  1  0  1  1  0  1
   3  |  0  0  1  1   |  1  1  1  1  0  0  1
   4  |  0  1  0  0   |  0  1  1  0  0  1  1
   5  |  0  1  0  1   |  1  0  1  1  0  1  1
   6  |  0  1  1  0   |  1  0  1  1  1  1  1
   7  |  0  1  1  1   |  1  1  1  0  0  0  0
   8  |  1  0  0  0   |  1  1  1  1  1  1  1
   9  |  1  0  0  1   |  1  1  1  1  0  1  1
   A  |  1  0  1  0   |  1  1  1  0  1  1  1
   b  |  1  0  1  1   |  0  0  1  1  1  1  1
   C  |  1  1  0  0   |  1  0  0  1  1  1  0
   d  |  1  1  0  1   |  0  1  1  1  1  0  1
   E  |  1  1  1  0   |  1  0  0  1  1  1  1
   F  |  1  1  1  1   |  1  0  0  0  1  1  1

   I think this table is accurate, but please let me know if you spot any errors.

Your score is determined by the number of 2-input NAND gates you use (1 point per gate). To simplify things, you may use AND, OR, NOT, and XOR gates in your diagram, with the following corresponding scores:

NOT: 1
AND: 2
OR: 3
XOR: 4

*/

package main

import "fmt"

func main() {
	tab := [][2]int{
		{0b0000, 0b1111110},
		{0b0001, 0b0110000},
		{0b0010, 0b1101101},
		{0b0011, 0b1111001},
		{0b0100, 0b0110011},
		{0b0101, 0b1011011},
		{0b0110, 0b1011111},
		{0b0111, 0b1110000},
		{0b1000, 0b1111111},
		{0b1001, 0b1111011},
		{0b1010, 0b1110111},
		{0b1100, 0b1001110},
		{0b1101, 0b0111101},
		{0b1110, 0b1001111},
		{0b1111, 0b1000111},
	}

	for _, v := range tab {
		fmt.Printf("%04b %07b\n", v[0], seg7(v[0]))
		assert(seg7(v[0]) == v[1])
	}
}

func assert(x bool) {
	if !x {
		panic("assertion failed")
	}
}

/*

https://notesformsc.org/sum-of-minterms-product-of-maxterms/
https://en.wikipedia.org/wiki/Canonical_normal_form#Minterm
https://en.wikipedia.org/wiki/Karnaugh_map

Use sum of products (minterms) to generate a boolean expression of the form:
f(a, b, c, d) -> (A, B, C, D, E, F, G) where the variables are [0, 1]

The boolean expression generated using this method is the simplest way to get the correct mapping, but far from optimal.
This expression can be minimized using things like Karnaugh maps.

The idea of minterms is the following:

Enumerate all combinations of the input and outputs

a b c d | X Y
0 0 0 0   0 0
0 0 0 1   1 1
0 0 1 0   1 0
0 0 1 1   1 1
...

For the output, look for any location where the output is 1 and then write down the boolean expression for that location.

Example:
X = SOP(1, 2, 3)
Y = SOP(2, 3)

Where SOP is the sum of product expression generator

X = (!a & !b & !c & d) |
	(!a & !b & c & !d) |
	(!a & !b & c & d)

Y = (!a & !b & !c & d) |
    (!a & !b & c & d)

The sum is bitwise OR and the product is bitwise AND
A binary 0 in the input table represents not(variable)
A binary 1 in the input table represents variable

*/

func seg7(x int) int {
	A := sop4(x, 0, 2, 3, 5, 6, 7, 8, 9, 10, 12, 14, 15)
	B := sop4(x, 0, 1, 2, 3, 4, 7, 8, 9, 10, 13)
	C := sop4(x, 0, 1, 3, 4, 5, 6, 7, 8, 9, 10, 11, 13)
	D := sop4(x, 0, 2, 3, 5, 6, 8, 9, 11, 12, 13, 14)
	E := sop4(x, 0, 2, 6, 8, 10, 11, 12, 13, 14, 15)
	F := sop4(x, 0, 4, 5, 6, 8, 9, 10, 11, 12, 14, 15)
	G := sop4(x, 2, 3, 4, 5, 6, 8, 9, 10, 11, 13, 14, 15)
	return A<<6 | B<<5 | C<<4 | D<<3 | E<<2 | F<<1 | G<<0
}

func sop4(x int, t ...int) int {
	r := 0
	for _, b := range t {
		v := 1
		for i := 0; i < 4; i++ {
			p := (x >> i)
			if b&(1<<i) == 0 {
				p = ^p
			}
			v &= (p & 1)
		}
		r |= v
	}
	return r
}
