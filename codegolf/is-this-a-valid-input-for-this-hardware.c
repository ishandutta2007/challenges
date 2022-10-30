/*

The (slightly harder, but still easy) sequel of Generate input for this hardware.

Background
I have a hardware that has a 32-bit input register. The register has the following characteristics:

The 32-bit register consists of eight 4-bit fields.
Each 4-bit field holds a value in signed-magnitude; it can hold an integer between -7 and +7 inclusive, including -0 and +0 (signed zeroes).
For example, the hexadecimal value 0xABCD1234 represents the field values [-2, -3, -4, -5, +1, +2, +3, +4]. In fact, one hex digit represents one 4-bit value with the following mapping:

Hex    |  Input value
---------------------
0 ~ 7  |  +0 ~ +7
8 ~ F  |  -0 ~ -7
In order to correctly operate this hardware, the 8 field values must be strictly increasing from left (most significant) to right (least significant). For signed zeros, -0 is considered to be less than +0.

The following are the examples of valid inputs:

field values for 8 fields        => 32-bit register value
[-7, -6, -5, -4, -3, -2, -1, -0] => 0xFEDCBA98
[+0, +1, +2, +3, +4, +5, +6, +7] => 0x01234567
[-7, -4, -3, -2, -0, +1, +3, +4] => 0xFCBA8134
[-2, -1, -0, +0, +3, +4, +5, +7] => 0xA9803457
The following are the examples of invalid ones:

field values for 8 fields        => 32-bit register value
[+7, +6, +5, +4, +3, +2, +1, +0] => 0x76543210 // not increasing
[-2, -1, -0, -0, +1, +2, +3, +4] => 0xA9881234 // not strictly increasing, due to duplicates
[-3, -2, -1, +0, -0, +1, +2, +3] => 0xBA908123 // +0 is greater than -0
Task
Given the register value, determine if it is a valid input to the hardware.

Input and output
The input (the register value) is an unsigned 32-bit integer. You can take it as an integer, a string, or a list of digits.
A string or list of digits can be in base 2, 8, 10 or 16, least-significant-digit-first or most-significant-digit-first, with or without leading zeros or base prefixes.

For example, if an input value is 0x01234567, possible representations in base 16 include "0x01234567", "01234567", "1234567", "76543210" (reversed order of digits), [0, 1, 2, 3, 4, 5, 6, 7], [7, 6, 5, 4, 3, 2, 1, 0].

The output is a boolean, indicating whether the given input is valid or not. You can choose to output either:

Any of the truthy/falsy values as defined by the language of your choice
The actual result values may differ between inputs (e.g. output 1 for a truthy input and 2 for another truthy one).
Swapping truthy and falsy values is not allowed.
Any two distinct constant values for true/false respectively
In this case, the result values should exactly be one of the two constant values.
Scoring
The standard code-golf rules apply. The shortest code in bytes wins.

Test cases
Expected output: Valid
0xFEDCBA98
0xEDCBA980
0x80123456
0x01234567
0xFCB98037
0xEDB12345

Expected output: Invalid
0x76543210
0x1A2B3C4D
0x12345678
0xBA988123
0xBA908123
0x00123456
0xB9882347
0xDC914556

*/

#include <assert.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdint.h>

int
cmp(uint32_t x, uint32_t y)
{
	uint32_t s0, s1;
	uint32_t v0, v1;

	if (x == y)
		return 0;

	s0 = (x >> 3) & 1;
	s1 = (y >> 3) & 1;

	v0 = x & 7;
	v1 = y & 7;

	switch (s0 | (s1 << 1)) {
	case 0:
		return (v0 < v1) ? -1 : 1;
	case 1:
		return -1;
	case 2:
		return 1;
	case 3:
		return (v0 > v1) ? -1 : 1;
	}
	return 0;
}

bool
increasing(uint32_t x)
{
	uint32_t i;

	for (i = 0; i < 7; i++) {
		if (cmp(x & 0xf, (x >> 4) & 0xf) <= 0)
			return false;
		x >>= 4;
	}
	return true;
}

int
main(void)
{
	assert(increasing(UINT32_C(0xFEDCBA98)) == true);
	assert(increasing(UINT32_C(0xEDCBA980)) == true);
	assert(increasing(UINT32_C(0x80123456)) == true);
	assert(increasing(UINT32_C(0x01234567)) == true);
	assert(increasing(UINT32_C(0xFCB98037)) == true);
	assert(increasing(UINT32_C(0xEDB12345)) == true);
	assert(increasing(UINT32_C(0xFCBA8134)) == true);
	assert(increasing(UINT32_C(0xA9803457)) == true);

	assert(increasing(UINT32_C(0x76543210)) == false);
	assert(increasing(UINT32_C(0x1A2B3C4D)) == false);
	assert(increasing(UINT32_C(0x12345678)) == false);
	assert(increasing(UINT32_C(0xBA988123)) == false);
	assert(increasing(UINT32_C(0xBA908123)) == false);
	assert(increasing(UINT32_C(0x00123456)) == false);
	assert(increasing(UINT32_C(0xB9882347)) == false);
	assert(increasing(UINT32_C(0xDC914556)) == false);
	assert(increasing(UINT32_C(0xA9881234)) == false);

	return 0;
}
