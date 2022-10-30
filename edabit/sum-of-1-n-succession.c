/*

In this challenge you must create a program which takes a number n and returns the length or number of digits in all numbers from 1 to n concatenated.
Examples

concatenationSum(5) ➞ 5

concatenationSum(10) ➞ 11

concatenationSum(13) ➞ 17

Notes

Keep in mind that the output is the number of digits in the concatenated number.
For example, if the input was 5, the output would be 5 because 12345 has 5 digits.
Similarly when the input is 13 the ouput is 17 because 12345678910111213 has 17 digits.

*/

#include <assert.h>
#include <stdio.h>
#include <math.h>

typedef unsigned long long uvlong;

// https://oeis.org/A058183
uvlong
catsum(uvlong n)
{
	if (n == 0)
		return 0;
	return (n + 1) * floor(log10(10 * n)) - (pow(10, floor(log10(10 * n))) - 1) / (10 - 1);
}

int
main(void)
{
	assert(catsum(0ull) == 0ull);
	assert(catsum(1ull) == 1ull);
	assert(catsum(5ull) == 5ull);
	assert(catsum(9ull) == 9ull);
	assert(catsum(10ull) == 11ull);
	assert(catsum(13ull) == 17ull);
	assert(catsum(999ull) == 2889ull);
	assert(catsum(1000ull) == 2893ull);
	assert(catsum(4525ull) == 16993ull);
	assert(catsum(14122352ull) == 101867713ull);
	assert(catsum(114453454235252ull) == 1605690702417684ull);

	return 0;
}
