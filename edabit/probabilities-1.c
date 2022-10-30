/*

Given an array of numbers and a value n, write a function that returns the probability of choosing a number greater than or equal to n from the array.
The probability should be expressed as a percentage, rounded to one decimal place.

Examples

probability([5, 1, 8, 9], 6) ➞ 50.0

probability([7, 4, 17, 14, 12, 3], 16) ➞ 16.7

probability([4, 6, 2, 9, 15, 18, 8, 2, 10, 8], 6) ➞ 70.0

Notes

Precent probability of event = 100 * (num of favourable outcomes) / (total num of possible outcomes)

*/

#include <assert.h>
#include <stdio.h>
#include <math.h>

#define nelem(x) (sizeof(x) / sizeof(x[0]))

double
probability(double *a, size_t n, double p)
{
	size_t i, m;

	if (n == 0)
		return 0;

	m = 0;
	for (i = 0; i < n; i++) {
		if (a[i] >= p)
			m++;
	}
	return m * 100.0 / n;
}

void
test(double *a, size_t n, double p, double r)
{
	assert(fabs(probability(a, n, p) - r) < 1e-1);
}

int
main(void)
{
	double a1[] = {5, 1, 8, 9};
	double a2[] = {7, 4, 17, 14, 12, 3};
	double a3[] = {4, 6, 2, 9, 15, 18, 8, 2, 10, 8};
	double a4[] = {14, 19, 2, 6};
	double a5[] = {11, 10, 9, 18, 16, 18, 4, 3, 5};
	double a6[] = {2, 13, 1, 11, 6, 9, 11, 14, 3};
	double a7[] = {11, 6, 17, 2, 1, 16, 20, 15};
	double a8[] = {12, 15, 12, 8, 20, 16, 1};
	double a9[] = {15, 8, 12, 1, 11, 4};
	double a10[] = {14, 11, 16, 3, 13, 14, 3};
	double a11[] = {1, 4, 18, 19, 15, 3, 3, 11};
	double a12[] = {9, 8, 17, 13, 17};
	double a13[] = {4, 6, 2, 9, 15, 18, 8, 2, 10, 8};
	double a14[] = {15, 4, 6, 11, 11, 17, 9, 16, 7, 4, 5, 10};
	double a15[] = {7, 1, 5, 7, 15, 15, 16, 14};
	double a16[] = {11, 4, 6, 7, 14, 4, 4};
	double a17[] = {10, 10, 3, 18, 14, 1, 2, 19, 17, 2, 4, 11, 18, 6, 3};

	test(a1, nelem(a1), 6, 50);
	test(a2, nelem(a2), 16, 16.7);
	test(a3, nelem(a3), 6, 70.0);
	test(a4, nelem(a4), 12, 50.0);
	test(a5, nelem(a5), 13, 33.3);
	test(a6, nelem(a6), 15, 0.0);
	test(a7, nelem(a7), 7, 62.5);
	test(a8, nelem(a8), 1, 100.0);
	test(a9, nelem(a9), 4, 83.3);
	test(a10, nelem(a10), 8, 71.4);
	test(a11, nelem(a11), 23, 0.0);
	test(a12, nelem(a12), 8, 100.0);
	test(a13, nelem(a13), 6, 70.0);
	test(a14, nelem(a14), 12, 25.0);
	test(a15, nelem(a15), 2, 87.5);
	test(a16, nelem(a16), 8, 28.6);
	test(a17, nelem(a17), 11, 40.0);

	return 0;
}
