/*

Create a function that takes an array and finds the integer which appears an odd number of times.
Examples

findOdd([1, 1, 2, -2, 5, 2, 4, 4, -1, -2, 5]) ➞ -1

findOdd([20, 1, 1, 2, 2, 3, 3, 5, 5, 4, 20, 4, 5]) ➞ 5

findOdd([10]) ➞ 10

Notes

There will always only be one integer that appears an odd number of times.

*/

#include <assert.h>
#include <stdio.h>

#define nelem(x) (sizeof(x) / sizeof(x[0]))

int
findodd(int *a, size_t n)
{
	size_t i;
	int v;

	v = 0;
	for (i = 0; i < n; i++)
		v ^= a[i];
	return v;
}

int
main(void)
{
	int a1[] = { 1, 1, 2, -2, 5, 2, 4, 4, -1, -2, 5 };
	int a2[] = { 20, 1, 1, 2, 2, 3, 3, 5, 5, 4, 20, 4, 5 };
	int a3[] = { 10 };
	int a4[] = { 20, 1, -1, 2, -2, 3, 3, 5, 5, 1, 2, 4, 20, 4, -1, -2, 5 };
	int a5[] = { 1, 1, 1, 1, 1, 1, 10, 1, 1, 1, 1 };
	int a6[] = { 5, 4, 3, 2, 1, 5, 4, 3, 2, 10, 10 };

	assert(findodd(a1, nelem(a1)) == -1);
	assert(findodd(a2, nelem(a2)) == 5);
	assert(findodd(a3, nelem(a3)) == 10);
	assert(findodd(a4, nelem(a4)) == 5);
	assert(findodd(a5, nelem(a5)) == 10);
	assert(findodd(a6, nelem(a6)) == 1);

	return 0;
}
