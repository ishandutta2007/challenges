/*

Given an array of numbers and a positive value for n, return the sum of every nth number in the array.

Examples

sumEveryNth([4, 8, 6, 6, 7, 9, 3], 1) ➞ 43
// 4+8+6+6+7+9+3 = 43

sumEveryNth([7, 3, 10, 4, 5, 8, 4, 9, 6, 9, 10, 1, 4], 4) ➞ 14
// 4+9+1 = 14

sumEveryNth([10, 6, 5, 4, 5, 2, 3, 3, 8, 10, 7, 2], 8) ➞ 3
// 3

sumEveryNth([6, 8, 9, 4, 6, 4, 7, 1, 5, 6, 10, 2], 13) ➞ 0
// only 12 numbers in array

Notes

N/A

*/

#include <assert.h>
#include <stdio.h>

#define nelem(x) (sizeof(x) / sizeof(x[0]))

int
nthsum(int *a, size_t n, size_t m)
{
	size_t i;
	int r;

	if (m == 0)
		return 0;

	r = 0;
	for (i = m - 1; i < n; i += m)
		r += a[i];
	return r;
}

int
main(void)
{
	int a1[] = {2, 5, 3, 9, 5, 7, 10, 7, 3, 3, 3};
	int a2[] = {10, 9, 2, 5, 9, 6, 4, 6, 7, 10, 9, 9, 9, 9, 2, 1, 2};
	int a3[] = {4, 5, 8, 7, 8, 1, 7, 9, 7, 4, 6, 2, 8, 8, 9, 9, 1, 7, 4};
	int a4[] = {8, 3, 5, 2, 6, 1, 5, 4, 3, 6, 6, 8, 5, 10, 7, 3, 7, 3, 5};
	int a5[] = {8, 9, 4, 8, 7, 5, 2, 9, 1, 8, 3, 8, 4, 9, 9, 6};
	int a6[] = {8, 2, 2, 7, 10, 6, 3, 5, 4, 4};
	int a7[] = {7, 4, 4, 10, 2, 6, 1, 9, 5, 10, 6, 4, 6, 6, 5, 9, 4, 10, 9};
	int a8[] = {5, 10, 10, 9, 10, 3, 5, 6, 6, 2, 10, 2, 9, 6, 8, 9, 10, 9, 4};
	int a9[] = {10, 4, 8, 4, 3, 9, 1, 1, 10, 7, 1, 4, 5, 5, 6, 1, 9};
	int a10[] = {2, 6, 3, 10, 6, 5, 4, 7, 9, 4, 1, 8, 9, 10, 8, 7, 2, 3, 6};
	int a11[] = {10, 9, 7, 8, 5, 7, 9, 5, 3, 3, 1};
	int a12[] = {7, 2, 9, 6, 1, 8, 8, 10, 2, 5, 5, 7, 3, 10, 1};
	int a13[] = {3, 10, 3, 8, 10, 9, 1, 3, 7, 2};
	int a14[] = {6, 5, 7, 9, 4, 2, 2, 9, 8, 10, 5, 2, 8};
	int a15[] = {9, 3, 7, 10, 3, 10, 2, 8, 8, 7, 1};
	int a16[] = {4, 6, 10, 8, 4, 7, 10, 10, 4, 4, 9, 2, 1, 9, 9, 8, 6, 6, 10};
	int a17[] = {3, 3, 2, 6, 4, 4, 10, 2, 10, 5, 5, 8, 6};
	int a18[] = {10, 1, 10, 8, 3, 2, 10, 8, 2, 3, 8, 7, 6, 4, 8};
	int a19[] = {5, 1, 4, 7, 3, 9, 4, 5, 9, 6, 1, 6, 9, 6, 7, 6, 8, 1};
	int a20[] = {2, 1, 7, 4, 2, 6, 2, 4, 6, 1, 2, 2, 10, 10};

	assert(nthsum(a1, nelem(a1), 9) == 3);
	assert(nthsum(a2, nelem(a2), 7) == 13);
	assert(nthsum(a3, nelem(a3), 6) == 10);
	assert(nthsum(a4, nelem(a4), 11) == 6);
	assert(nthsum(a5, nelem(a5), 11) == 3);
	assert(nthsum(a6, nelem(a6), 12) == 0);
	assert(nthsum(a7, nelem(a7), 8) == 18);
	assert(nthsum(a8, nelem(a8), 16) == 9);
	assert(nthsum(a9, nelem(a9), 6) == 13);
	assert(nthsum(a10, nelem(a10), 8) == 14);
	assert(nthsum(a11, nelem(a11), 7) == 9);
	assert(nthsum(a12, nelem(a12), 2) == 48);
	assert(nthsum(a13, nelem(a13), 2) == 32);
	assert(nthsum(a14, nelem(a14), 7) == 2);
	assert(nthsum(a15, nelem(a15), 11) == 1);
	assert(nthsum(a16, nelem(a16), 7) == 19);
	assert(nthsum(a17, nelem(a17), 1) == 68);
	assert(nthsum(a18, nelem(a18), 6) == 9);
	assert(nthsum(a19, nelem(a19), 14) == 6);
	assert(nthsum(a20, nelem(a20), 2) == 28);

	return 0;
}
