/*

Create a function that takes an array as an argument and returns true or false depending on whether the average of all elements in the array is a whole number or not.

*/

#include <assert.h>
#include <stdio.h>

#define nelem(x) (sizeof(x) / sizeof(x[0]))

int
isavgwhole(int *a, size_t n)
{
	size_t i;
	int r;

	if (n == 0)
		return 0;

	r = 0;
	for (i = 0; i < n; i++)
		r += a[i];

	return r % n == 0;
}

int
main(void)
{
	int a1[] = { 1, 3 };
	int a2[] = { 1, 2, 3, 4 };
	int a3[] = { 1, 5, 6 };
	int a4[] = { 1, 1, 1 };
	int a5[] = { 9, 2, 2, 5 };
	int a6[] = { 3, 5, 9 };
	int a7[] = { 1, 1, 1, 1 };
	int a8[] = { 1, 2, 3, 4, 5 };
	int a9[] = { 5, 2, 4 };
	int a10[] = { 11, 12 };
	int a11[] = { 4, 1, 7, 9, 2, 5, 7, 2, 4 };

	assert(isavgwhole(a1, nelem(a1)) == 1);
	assert(isavgwhole(a2, nelem(a2)) == 0);
	assert(isavgwhole(a3, nelem(a3)) == 1);
	assert(isavgwhole(a4, nelem(a4)) == 1);
	assert(isavgwhole(a5, nelem(a5)) == 0);
	assert(isavgwhole(a6, nelem(a6)) == 0);
	assert(isavgwhole(a7, nelem(a7)) == 1);
	assert(isavgwhole(a8, nelem(a8)) == 1);
	assert(isavgwhole(a9, nelem(a9)) == 0);
	assert(isavgwhole(a10, nelem(a10)) == 0);
	assert(isavgwhole(a11, nelem(a11)) == 0);

	return 0;
}
