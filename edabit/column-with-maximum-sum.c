/*

Given an array of numbers and a value for n, split the numbers into n-sized groups. If we imagine that these groups are stacked on top of each other (see below), return the column number that has the greatest sum. If two or more columns have the same sum, return the one with the smallest column number.
Example

nums = [4, 14, 12, 7, 14, 16, 5, 13, 7, 16, 11, 19]
n = 4

Gives the array:

[[4, 14, 12,  7],
[14, 16, 5, 13],
[7, 16, 11, 19]]

// 1, 2, 3, 4 (column)
// 25, 46, 28, 39 (sum)

You would return 2, as the 2nd column has the greatest sum.
Notes

Nums will always divide into equal-length groups.

*/

#include <assert.h>
#include <stdio.h>
#include <limits.h>

#define nelem(x) (sizeof(x) / sizeof(x[0]))

size_t
colmax(int *a, size_t n, size_t c)
{
	size_t i, j, k, l;
	int s, t;

	s = INT_MIN;
	k = 1;
	l = n / c;
	for (i = 0; i < c; i++) {
		t = 0;
		for (j = 0; j < l; j++)
			t += a[j * c + i];

		if (t > s) {
			s = t;
			k = i + 1;
		}
	}

	return k;
}

int
main(void)
{
	int a1[] = { 14, 9, 19, 6, 13, 13, 3, 2, 12 };
	int a2[] = { 1, 13, 15, 5, 16, 1, 4, 9, 20 };
	int a3[] = { 15, 4, 6, 10, 6, 4 };
	int a4[] = { 7, 9, 13, 16, 17, 1, 10, 6, 3, 19, 6, 10, 8, 18, 20, 4 };
	int a5[] = { 4, 18, 14, 16, 7, 7, 20, 14, 9, 4, 8, 16, 1, 12, 18, 13 };
	int a6[] = { 5, 7, 2, 12, 20, 7, 1, 12, 8, 7, 12, 8 };
	int a7[] = { 18, 16, 6, 4, 18, 20, 9, 8, 1, 14, 20, 16 };
	int a8[] = { 5, 4, 20, 8, 8, 18 };
	int a9[] = { 2, 9, 12, 9, 17, 6, 8, 9, 8, 18, 2, 4 };
	int a10[] = { 15, 2, 16, 19, 3, 1, 15, 13, 19, 16, 2, 16 };
	int a11[] = { 4, 6, 18, 13, 19, 2, 7, 13, 19, 16, 12, 20, 17, 12, 4, 7 };
	int a12[] = { 10, 8, 6, 2, 2, 2, 18, 17, 17, 20, 17, 17 };
	int a13[] = { 3, 9, 14, 7, 6, 13, 9, 10, 1, 5, 10, 17, 16, 6, 3, 18 };
	int a14[] = { 2, 7, 8, 17, 15, 3 };
	int a15[] = { 8, 8, 6, 4, 8, 16, 4, 16, 18, 20, 20, 7 };
	int a16[] = { 19, 15, 1, 10, 2, 8 };
	int a17[] = { 5, 20, 8, 3, 5, 15 };
	int a18[] = { 10, 12, 15, 14, 17, 4, 18, 12, 17, 18, 18, 12 };
	int a19[] = { 5, 9, 12, 12, 7 };
	int a20[] = { 3, 18, 8, 15, 9, 15, 12, 8, 11, 5, 10, 8 };

	assert(colmax(a1, nelem(a1), 3) == 3);
	assert(colmax(a2, nelem(a2), 3) == 2);
	assert(colmax(a3, nelem(a3), 2) == 1);
	assert(colmax(a4, nelem(a4), 8) == 7);
	assert(colmax(a5, nelem(a5), 2) == 2);
	assert(colmax(a6, nelem(a6), 3) == 2);
	assert(colmax(a7, nelem(a7), 4) == 2);
	assert(colmax(a8, nelem(a8), 2) == 1);
	assert(colmax(a9, nelem(a9), 2) == 2);
	assert(colmax(a10, nelem(a10), 3) == 1);
	assert(colmax(a11, nelem(a11), 8) == 5);
	assert(colmax(a12, nelem(a12), 6) == 1);
	assert(colmax(a13, nelem(a13), 4) == 4);
	assert(colmax(a14, nelem(a14), 3) == 2);
	assert(colmax(a15, nelem(a15), 2) == 2);
	assert(colmax(a16, nelem(a16), 6) == 1);
	assert(colmax(a17, nelem(a17), 3) == 2);
	assert(colmax(a18, nelem(a18), 4) == 3);
	assert(colmax(a19, nelem(a19), 5) == 3);
	assert(colmax(a20, nelem(a20), 6) == 2);

	return 0;
}
