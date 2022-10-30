/*

Given the Ullman's Puzzle

Write a function that makes that determination

This puzzle is due to Jeffrey Ullman:

Given a list of n real numbers, a real number t, and an integer k, determine if there exists a k-element subset of the original list of n real numbers that is less than t.

For instance, given the list of 25 real numbers 18.1, 55.1, 91.2, 74.6, 73.0, 85.9, 73.9, 81.4, 87.1, 49.3, 88.8, 5.7, 26.3, 7.1, 58.2, 31.7, 5.8, 76.9, 16.5, 8.1, 48.3, 6.8, 92.4, 83.0, 19.6, t = 98.2 and k = 3,
the 3-element subset 31.7, 16.5 and 19.6 sums to 67.8, which is less than 98.2, so the result is true.

*/

#include <assert.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

#define nelem(x) (sizeof(x) / sizeof(x[0]))

int
cmp(const void *a, const void *b)
{
	double x, y;

	x = *(double *)a;
	y = *(double *)b;
	if (x < y)
		return -1;
	if (x > y)
		return 1;
	return 0;
}

bool
subset(double *a, size_t n, double t, size_t k)
{
	size_t i;
	double v;

	if (k > n)
		return false;

	qsort(a, n, sizeof(*a), cmp);

	v = 0;
	for (i = 0; i < k; i++)
		v += a[i];
	return v < t;
}

int
main(void)
{
	double a1[] = {18.1, 55.1, 91.2, 74.6, 73.0, 85.9, 73.9, 81.4, 87.1, 49.3, 88.8, 5.7, 26.3, 7.1, 58.2, 31.7, 5.8, 76.9, 16.5, 8.1, 48.3, 6.8, 92.4, 83.0, 19.6};

	assert(subset(a1, nelem(a1), 98.2, 3) == true);

	return 0;
}
