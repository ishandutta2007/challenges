/*

Write a function that takes an integer n, reverses the binary representation of that integer, and returns the new integer from the reversed binary.

Examples

reversedBinaryInteger(10) ➞ 5
// 10 = 1010 -> 0101 = 5

reversedBinaryInteger(12) ➞ 3
// 12 = 1100 -> 0011 = 3

reversedBinaryInteger(25) ➞ 19
// 25 = 11001 -> 10011 = 19

reversedBinaryInteger(45) ➞ 45
// 45 = 101101 -> 101101 = 45

Notes

All values of n will be positive.

*/

#include <assert.h>
#include <stdio.h>
#include <limits.h>

#define nelem(x) (sizeof(x) / sizeof(x[0]))

typedef unsigned long long uvlong;

uvlong
revbits(uvlong x)
{
	uvlong v;

	for (v = 0; x; x >>= 1)
		v = (v << 1) | (x & 1);
	return v;
}

int
main(void)
{
	static const uvlong tab[][2] = {
	    {1, 1},
	    {4, 1},
	    {5, 5},
	    {31, 31},
	    {82, 37},
	    {90, 45},
	    {255, 255},
	    {446, 251},
	    {451, 391},
	    {634, 377},
	    {776, 67},
	    {898, 263},
	    {1103, 1937},
	    {3801, 2487},
	    {4096, 1},
	    {8505, 10017},
	    {428293ull, 328843ull},
	    {547643ull, 904609ull},
	    {612965ull, 681385ull},
	    {999999ull, 1033263ull},
	};

	size_t i;

	for (i = 0; i < nelem(tab); i++)
		assert(revbits(tab[i][0]) == tab[i][1]);

	return 0;
}
