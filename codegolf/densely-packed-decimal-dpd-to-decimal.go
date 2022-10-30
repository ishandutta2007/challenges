/*

Background
Densely packed decimal (DPD) is a way to efficiently store decimal digits in binary. It stores three decimal digits (000 to 999) in 10 bits, which is much more efficient than naive BCD (which stores one digit in 4 bits).

Notations
The lowercase letters a to i are the bits that are copied to the decimal representation.
0 and 1 are the exact bits in the input or output bit patterns.
x bits are ignored in the conversion.
Conversion table
The following is the conversion table from 10 bits of DPD to three decimal digits. Each decimal digit is represented as 4-bit binary (BCD). Both sides are written left to right from the most significant digit to the least.

Bits                 =>  Decimal         (Digit range)
a b c d e f 0 g h i  =>  0abc 0def 0ghi  (0-7) (0-7) (0-7)
a b c d e f 1 0 0 i  =>  0abc 0def 100i  (0–7) (0–7) (8–9)
a b c g h f 1 0 1 i  =>  0abc 100f 0ghi  (0–7) (8–9) (0–7)
g h c d e f 1 1 0 i  =>  100c 0def 0ghi  (8–9) (0–7) (0–7)
g h c 0 0 f 1 1 1 i  =>  100c 100f 0ghi  (8–9) (8–9) (0–7)
d e c 0 1 f 1 1 1 i  =>  100c 0def 100i  (8–9) (0–7) (8–9)
a b c 1 0 f 1 1 1 i  =>  0abc 100f 100i  (0–7) (8–9) (8–9)
x x c 1 1 f 1 1 1 i  =>  100c 100f 100i  (8–9) (8–9) (8–9)
Task
Convert 10 bits of DPD to 3 digits of decimal.

Test cases
DPD           Decimal
0000000101    005
0001100011    063
0001111001    079
0000011010    090
0001011110    098
1010111010    592
0011001101    941
1100111111    879
1110001110    986
0011111111    999
1111111111    999  * Output is same regardless of the `x` bits
Input
The default input format is a list of 10 bits. The bits should follow the exact order above, or the reverse of it.
You may choose to use an equivalent string or integer representation instead. Unlike my other challenges, reordering or using nested structures is not allowed.

For the input [1, 1, 0, 0, 0, 1, 0, 1, 0, 0], the following formats are allowed:

List of bits: [1, 1, 0, 0, 0, 1, 0, 1, 0, 0]
String: "1100010100"
Binary integer: 788 or 0b1100010100
Decimal integer: 1100010100
Reversed: [0, 0, 1, 0, 1, 0, 0, 0, 1, 1] and reversed in any other formats above
The following formats are NOT allowed:

Arbitrary reordering of bits: [0, 0, 0, 0, 0, 1, 1, 1, 0, 1]
Nested structures: [[1, 1, 0], [0, 0, 1], [0, 1, 0, 0]] or [0b110, 0b001, 0b0100]
Output
The default output format is a list of 3 decimal digits. Each digit should be represented as 0 to 9, either an integer or a character.
As in input, you can choose string or integer representation. If you choose integer representation, leading zeroes can be omitted.

Scoring & winning criterion
Standard code-golf rules apply. The shortest program or function in bytes for each language wins.

*/

package main

func main() {
	assert(dpd2dec(0b000_000_0101) == 5)
	assert(dpd2dec(0b000_110_0011) == 63)
	assert(dpd2dec(0b000_111_1001) == 79)
	assert(dpd2dec(0b000_001_1010) == 90)
	assert(dpd2dec(0b000_101_1110) == 98)
	assert(dpd2dec(0b101_011_1010) == 592)
	assert(dpd2dec(0b001_100_1101) == 941)
	assert(dpd2dec(0b110_011_1111) == 879)
	assert(dpd2dec(0b111_000_1110) == 986)
	assert(dpd2dec(0b001_111_1111) == 999)
	assert(dpd2dec(0b111_111_1111) == 999)

	assert(dpd2dec(0b000_000_1001) == 9)
	assert(dpd2dec(0b000_101_0101) == 55)
	assert(dpd2dec(0b000_000_1010) == 80)
	assert(dpd2dec(0b000_101_1111) == 99)
	assert(dpd2dec(0b101_101_0101) == 555)
}

func assert(x bool) {
	if !x {
		panic("assertion failed")
	}
}

func dpd2dec(n int) int {
	d0 := n & 7
	d1 := (n >> 4) & 7
	d2 := (n >> 7) & 7

	c0 := (n >> 1) & 7
	c1 := (n >> 5) & 3
	switch c0 {
	case 0b000, 0b001, 0b010, 0b011:
	case 0b100:
		d0 = 0b1000 | d0&1
	case 0b101:
		d0 = d1&6 | d0&1
		d1 = 0b1000 | d1&1
	case 0b110:
		d0 = d2&6 | d0&1
		d2 = 0b1000 | d2&1
	case 0b111:
		switch c1 {
		case 0b00:
			d0 = d2&6 | d0&1
			d1 = 0b1000 | d1&1
			d2 = 0b1000 | d2&1
		case 0b01:
			d0 = 0b1000 | d0&1
			d1 = d2&6 | d1&1
			d2 = 0b1000 | d2&1
		case 0b10:
			d0 = 0b1000 | d0&1
			d1 = 0b1000 | d1&1
		case 0b11:
			d0 = 0b1000 | d0&1
			d1 = 0b1000 | d1&1
			d2 = 0b1000 | d2&1
		}
	}
	return 100*d2 + 10*d1 + d0
}
