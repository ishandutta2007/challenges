/*

Create a function that returns the smallest number of changes it takes to transform one number into one with identical digits.
A step is incrementing or decrementing a digit by one.

Examples

SmallestTransform(399) ➞ 6
// 399 transformed to 999 in 6 steps.

SmallestTransform(1234) ➞ 4
// 1234 can be transformed to either 2222 or 3333 using 4 steps.

SmallestTransform(153) ➞ 4

SmallestTransform(33338) ➞ 5

SmallestTransform(7777) ➞ 0

Notes

If a number already has identical digits, return 0.

*/

#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

typedef unsigned long long uvlong;

#define min(a, b) (((a) < (b)) ? (a) : (b))

int
smallest(uvlong x)
{
	int d[sizeof(x) * CHAR_BIT];
	int i, j, n, r, v;

	n = 0;
	do {
		d[n++] = x % 10;
		x /= 10;
	} while (x);

	r = INT_MAX;
	for (i = 0; i <= 9; i++) {
		v = 0;
		for (j = 0; j < n; j++)
			v += abs(d[j] - i);
		r = min(r, v);
	}
	return r;
}

int
main(void)
{
	assert(smallest(399) == 6);
	assert(smallest(1234) == 4);
	assert(smallest(153) == 4);
	assert(smallest(33338ul) == 5);
	assert(smallest(7777) == 0);
	assert(smallest(977) == 2);
	assert(smallest(589) == 4);
	assert(smallest(0) == 0);
	assert(smallest(4) == 0);

	return 0;
}
