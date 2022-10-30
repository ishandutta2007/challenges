/*

Write a function that returns the smallest N-digit number which is a multiple of the specified value.

Examples

smallest(3, 8) ➞ 104
// Smallest 3-digit integer that is a multiple of 8

smallest(5, 12) ➞ 10008

smallest(7, 1) ➞ 1000000

smallest(2, 3) ➞ 12

Notes

N/A

*/

#include <assert.h>
#include <stdio.h>
#include <math.h>

typedef unsigned long long uvlong;

uvlong
smallest(uvlong n, uvlong m)
{
	uvlong r;

	if (n == 0 || m == 0)
		return 0;

	r = pow(10, n - 1);
	return (r + m - 1) / m * m;
}

int
main(void)
{
	assert(smallest(3, 8) == 104ull);
	assert(smallest(5, 12) == 10008ull);
	assert(smallest(7, 1) == 1000000ull);
	assert(smallest(2, 3) == 12ull);
	assert(smallest(9, 33) == 100000032ull);
	assert(smallest(8, 17) == 10000012ull);
	assert(smallest(4, 67) == 1005ull);
	assert(smallest(4, 432) == 1296ull);
	assert(smallest(3, 432) == 432ull);
	assert(smallest(3, 77) == 154ull);

	return 0;
}
