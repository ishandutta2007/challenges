/*

Mubashir (as always) needs your help to complete his assignment.

You are given two positive integers n and m. You have to perform some basic mathematical operations on n to obtain m. These are your options:

(n-1)/2   - if (n-1) is divisible by 2
n/2       - if n is divisible by 2
n*2

Create a function that returns the minimum number of steps required to transform n into m.
Examples

numberTransform(2, 8) ➞ 2
// 2 * 2 = 4
// 4 * 2 = 8

numberTransform(9, 2) ➞ 2
// (9-1) / 2 = 4
// 4 / 2 = 2

numberTransform(1024, 1024) ➞ 0

Notes

m will always be a power of 2.

*/

#include <assert.h>
#include <stdio.h>

int
transform(unsigned n, unsigned m)
{
	int r;

	if (n == m)
		return 0;
	if (!n || !m || (m & (m - 1)))
		return -1;

	r = 0;
	if ((n & 1) && n > 1) {
		n = (n - 1) >> 1;
		r++;
	}
	for (; n < m; r++)
		n <<= 1;
	for (; n > m; r++)
		n >>= 1;
	return r;
}

int
main(void)
{
	assert(transform(1, 1) == 0);
	assert(transform(2, 4) == 1);
	assert(transform(3, 8) == 4);
	assert(transform(4, 16) == 2);
	assert(transform(4, 1) == 2);
	assert(transform(1, 4) == 2);
	assert(transform(1024, 1024) == 0);
	assert(transform(2048, 1024) == 1);
	assert(transform(2048, 2) == 10);
	assert(transform(4096, 2) == 11);
	assert(transform(4096, 1) == 12);
	assert(transform(4096, 0) == -1);
	assert(transform(0, 43) == -1);
	assert(transform(0, 0) == 0);

	return 0;
}
