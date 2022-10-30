/*

Write a program/function that takes two integers in the range 0 to 255

inclusive, and returns whether the binary forms of the numbers are exactly one bit different.

For example, 1
and 0 have binary forms 00000001 and 00000000, which are one bit apart. Similarly, 152 and 24

are 010011000 and 000011000, so they return true.

However, your code must be pristine, such that if any one bit in your program is flipped, it should throw an error. For example, if your program was the single byte a (01100001), then all the 8 possible modified programs:

á ! A q i e c `

must throw an error. Make sure you are modifying by bytes (e.g. the á up there is actually representing the byte 225

, not the actual two byte character á).
Test cases:

0,1     => Truthy
1,0     => Truthy
152,24  => Truthy
10,10   => Falsey
10,11   => Truthy
11,12   => Falsey
255,0   => Falsey

Rules:

    Provide a testing framework that can verify that your program is properly pristine, since there will be a lot of possible programs (number of bytes*8), or else a complete proof of pristineness.
        Please make sure your program is valid before you post it.
    Output needs to be either truthy/falsey (either way around is fine), or else two distinct non-error values
    Errors can be runtime, compiler, interpreter etc.

*/

#include <assert.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

int
popcnt(uint8_t x)
{
	x = (x & 0x55) + ((x >> 1) & 0x55);
	x = (x & 0x33) + ((x >> 2) & 0x33);
	x = (x & 0x0F) + ((x >> 4) & 0x0F);
	return x;
}

bool
pristine(uint8_t x, uint8_t y)
{
	uint8_t p, r;

	p = x ^ y;
	r = p & -p;
	return r == p && r != 0;
}

int
main(void)
{
	int i, j;

	assert(pristine(0, 1) == true);
	assert(pristine(1, 0) == true);
	assert(pristine(152, 24) == true);
	assert(pristine(10, 10) == false);
	assert(pristine(10, 11) == true);
	assert(pristine(11, 12) == false);
	assert(pristine(255, 0) == false);
	assert(pristine(7, 8) == false);
	assert(pristine(6, 7) == true);

	for (i = 0; i < 256; i++) {
		for (j = 0; j < 256; j++) {
			if (pristine(i, j))
				assert(popcnt(i ^ j) == 1);
			else
				assert(popcnt(i ^ j) != 1);
		}
	}

	return 0;
}
