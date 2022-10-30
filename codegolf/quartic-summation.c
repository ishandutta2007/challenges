/*

Guidelines

Task

Given two non-negative integers, find the sum of both numbers... to the power of 4.
Examples

2, 3 -> 97 (2^4 + 3^4 = 97)

14, 6 -> 39712 (14^4 + 6^4 = 39712)

0, 25 -> 390625 (0^4 + 25^4 = 390625)
Rules

    You will only ever receive two non-negative integers as input (bonus points if you get it to work with negative integer input).
    You can take the input however you would like (arrays, list, two separate arguments, comma-separated string)
    You can either output your answer as a number or a string.
    As this is code golf, the shortest answer in bytes will win.

*/

#include <assert.h>
#include <stdio.h>

typedef unsigned long long uvlong;

uvlong
sum(uvlong x, uvlong y)
{
	return (x * x * x * x) + (y * y * y * y);
}

int
main(void)
{
	assert(sum(2, 3) == 97ull);
	assert(sum(14, 6) == 39712ull);
	assert(sum(0, 25) == 390625ull);

	return 0;
}
