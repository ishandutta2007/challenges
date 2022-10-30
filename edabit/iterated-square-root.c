/*

The iterated square root of a number is the number of times the square root function must be applied to bring the number strictly under 2.

Given an integer, return its iterated square root. Return "invalid" if it is negative.

Examples

iSqrt(1) ➞ 0

iSqrt(2) ➞ 1

iSqrt(7) ➞ 2

iSqrt(27) ➞ 3

iSqrt(256) ➞ 4

iSqrt(-1) ➞ "invalid"

Notes

Idea for iterated square root by Richard Spence.

*/

#include <assert.h>
#include <stdio.h>
#include <math.h>

int
isqrt(long long n)
{
	if (n < 0)
		return -1;
	if (n < 2)
		return 0;
	return ceil(log2(log2(n))) + !(n & (n - 1));
}

int
main(void)
{
	assert(isqrt(1) == 0);
	assert(isqrt(2) == 1);
	assert(isqrt(7) == 2);
	assert(isqrt(27) == 3);
	assert(isqrt(256) == 4);
	assert(isqrt(-1) == -1);
	assert(isqrt(25) == 3);
	assert(isqrt(59) == 3);
	assert(isqrt(113) == 3);
	assert(isqrt(253) == 3);
	assert(isqrt(965) == 4);
	assert(isqrt(999) == 4);
	assert(isqrt(2746) == 4);
	assert(isqrt(2872) == 4);
	assert(isqrt(4069) == 4);
	assert(isqrt(6575) == 4);
	assert(isqrt(7985) == 4);
	assert(isqrt(8385) == 4);
	assert(isqrt(16943ll) == 4);
	assert(isqrt(26749ll) == 4);
	assert(isqrt(34665ll) == 4);
	assert(isqrt(44591ll) == 4);
	assert(isqrt(50320ll) == 4);
	assert(isqrt(66343ll) == 5);
	assert(isqrt(77632ll) == 5);
	assert(isqrt(97197ll) == 5);
	assert(isqrt(108787ll) == 5);
	assert(isqrt(229276ll) == 5);
	assert(isqrt(319228ll) == 5);
	assert(isqrt(426748ll) == 5);
	assert(isqrt(595996ll) == 5);
	assert(isqrt(652940ll) == 5);
	assert(isqrt(709442ll) == 5);
	assert(isqrt(881414ll) == 5);
	assert(isqrt(954281ll) == 5);
	assert(isqrt(4294967296ll) == 6);
	assert(isqrt(9852481428ll) == 6);
	assert(isqrt(-198329ll) == -1);
	assert(isqrt(-928437002ll) == -1);

	return 0;
}
