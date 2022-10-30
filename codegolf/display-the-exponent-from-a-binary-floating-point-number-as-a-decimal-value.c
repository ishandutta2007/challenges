/*

Had my software final exams recently, one of the last questions had me thinking for a while after the exam had finished.

Background

IEEE754 numbers are according to the below layout Layout for a 32 bit floating point number

The exponent is stored as n + 127 so for an exponent of 20 the exponent in binary would be: 127 + 20 = 147 then 10010011
The Challange

Write a program that when given text representing a binary floating point number to the IEEE754 standard, returns the exponent given as a decimal value.
Example

Input: 00111101110011001100110011001101 (0.1)

Isolated exponent bits: 01111011

Convert to binary: 0 + 64 + 32 + 16 + 8 + 0 + 2 + 1 = 123

Remove offset: 123 - 127 = -4

Output -4

Input: 10111111110111101011100001010010 (-1.64)

Isolated exponent bits: 01111111

Convert to binary: 0 + 64 + 32 + 16 + 8 + 4 + 2 + 1 = 127

Remove offset: 127 - 127 = 0

Output 0
Rules

    Input must be text/string/equivalent indexable datatype, eg. strings not integer or numerical
    Output can be any type, as long as it is decimal
    Aim for shortest solutions

Adapted from the 2020 Software Design and Development HSC Paper: 30) d) ii

    Design an algorithm that takes in a string of 32 characters representing a floating point number, and displays the exponent as its signed decimal value.

Any feedback is appreciated as this is my first question

*/

#include <assert.h>
#include <stdio.h>
#include <string.h>
#include <stdint.h>

int
exponent(float x)
{
	uint32_t i;

	memcpy(&i, &x, sizeof(i));
	return ((i >> 23) & 0xff) - 127;
}

int
main(void)
{
	assert(exponent(0.1) == -4);
	assert(exponent(-1.64) == 0);

	return 0;
}
