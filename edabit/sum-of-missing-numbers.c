/*

Create a function that returns the sum of missing numbers.
Examples

sumMissingNumbers([1, 3, 5, 7, 10]) ➞ 29
// 2 + 4 + 6 + 8 + 9

sumMissingNumbers([10, 7, 5, 3, 1]) ➞ 29

sumMissingNumbers([10, 20, 30, 40, 50, 60]) ➞ 1575

Notes

The minimum and maximum value of the given array are the inclusive bounds of the numeric range to consider when searching for missing numbers.

Test.assertEquals(sumMissingNumbers([1, 3, 5, 7, 10]), 29)

Test.assertEquals(sumMissingNumbers([10, 20, 30, 40, 50, 60]), 1575)

Test.assertEquals(sumMissingNumbers([7, 3, 8, 5, 12]), 40)

Test.assertEquals(sumMissingNumbers([99, 2, 45, 4, 17]), 4782)

Test.assertEquals(sumMissingNumbers([10, 7, 5, 3, 1]), 29)

Test.assertEquals(sumMissingNumbers([7, 8, 9, 10]), 0)

*/

#include <assert.h>
#include <stdio.h>
#include <stdlib.h>

#define nelem(x) (sizeof(x) / sizeof(x[0]))

int
cmp(const void *a, const void *b)
{
	unsigned x, y;

	x = *(unsigned *)a;
	y = *(unsigned *)b;
	if (x < y)
		return -1;
	if (x == y)
		return 0;
	return 1;
}

unsigned
count(unsigned n)
{
	return n * (n + 1) / 2;
}

unsigned
sum(unsigned *a, size_t n)
{
	unsigned r, x, y;
	size_t i;

	r = 0;
	qsort(a, n, sizeof(*a), cmp);
	for (i = 1; i < n; i++) {
		x = a[i - 1];
		y = a[i] - !!a[i];
		if (x < y)
			r += count(y) - count(x);
	}
	return r;
}

int
main(void)
{
	unsigned a1[] = {1, 3, 5, 7, 10};
	unsigned a2[] = {10, 20, 30, 40, 50, 60};
	unsigned a3[] = {7, 3, 8, 5, 12};
	unsigned a4[] = {99, 2, 45, 4, 17};
	unsigned a5[] = {10, 7, 5, 3, 1};
	unsigned a6[] = {7, 8, 9, 10};
	unsigned a7[] = {0, 0, 0};
	unsigned a8[] = {33, 33, 33};

	assert(sum(a1, nelem(a1)) == 29);
	assert(sum(a2, nelem(a2)) == 1575);
	assert(sum(a3, nelem(a3)) == 40);
	assert(sum(a4, nelem(a4)) == 4782);
	assert(sum(a5, nelem(a5)) == 29);
	assert(sum(a6, nelem(a6)) == 0);
	assert(sum(a7, nelem(a7)) == 0);
	assert(sum(a8, nelem(a8)) == 0);

	return 0;
}
