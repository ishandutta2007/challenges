/*

In this challenge, you have to establish if a given integer n is a Sastry number. If the number resulting from the concatenation of an integer n with its successor is a perfect square, then n is a Sastry Number.

Given a positive integer n, implement a function that returns true if n is a Sastry number, or false if it's not.
Examples

isSastry(183) ➞ true
// Concatenation of n and its successor = 183184
// 183184 is a perfect square (428 ^ 2)

isSastry(184) ➞ false
// Concatenation of n and its successor = 184185
// 184185 is not a perfect square

isSastry(106755) ➞ true
// Concatenation of n and its successor = 106755106756
// 106755106756 is a perfect square (326734 ^ 2)

Notes

    A perfect square is a number with a square root equals to a whole integer.
    You can expect only valid positive integers greater than 0 as input, without exceptions to handle. Zero is a perfect square, but the concatenation 00 isn't considered as a valid result to check.
    In JavaScript, despite the specific challenge the results are proofed, the method used to calculate if an integer greater of 2 ** 53 - 1 is a Sastry number can lead to errors due to the approximation of the JS engine.

*/

#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <stdbool.h>
#include <inttypes.h>

bool
issastry(uintmax_t n)
{
	char b[8 * sizeof(n)];
	long double i;

	if (n == 0)
		return false;

	snprintf(b, sizeof(b), "%ju%ju", n, n + 1);
	return modfl(sqrtl(strtold(b, NULL)), &i) == 0;
}

int
main(void)
{
	assert(issastry(UINTMAX_C(183)) == true);
	assert(issastry(UINTMAX_C(184)) == false);
	assert(issastry(UINTMAX_C(106755)) == true);
	assert(issastry(UINTMAX_C(129987253440921)) == false);
	assert(issastry(UINTMAX_C(157175907513603)) == true);
	assert(issastry(UINTMAX_C(206611570247935)) == true);
	assert(issastry(UINTMAX_C(338752188230098)) == false);
	assert(issastry(UINTMAX_C(433610247875715)) == true);
	assert(issastry(UINTMAX_C(652333983478884)) == false);
	assert(issastry(UINTMAX_C(718717107443715)) == true);
	assert(issastry(UINTMAX_C(752199872453889)) == false);
	assert(issastry(UINTMAX_C(786704531939448)) == true);

	return 0;
}
