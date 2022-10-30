/*

Python's range function can only generate a list of integers, your task is to generate a list of floats.
Generate a list of values between 0 and an endpoint n spaced at i intervals.

Examples

genValues(2, 0.25) ➞ [0.0, 0.25, 0.5, 0.75, 1.0, 1.25, 1.5, 1.75, 2.0]

genValues(1, 0.1) ➞ [0.0, 0.1, 0.2, 0.3, 0.4, 0.5, 0.6, 0.7, 0.8, 0.9, 1.0]

genValues(20, 2) ➞ [0, 2, 4, 6, 8, 10, 12, 14, 16, 18, 20]

Notes

    The endpoint will always be a positive integer.
    This function should also work for generating integers (last example).

*/

#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define nelem(x) (sizeof(x) / sizeof(x[0]))

double *
gen(double n, double s)
{
	double *p, x;
	size_t i, l;

	if (s == 0)
		return NULL;

	l = n / s + 1;
	p = calloc(l, sizeof(*p));
	if (!p)
		return NULL;

	for (i = 0; i < l; i++) {
		p[i] = x;
		x += s;
	}
	return p;
}

void
test(double n, double s, double *a, size_t l)
{
	double *p;
	size_t i;

	p = gen(n, s);
	assert(p);
	for (i = 0; i < l; i++)
		assert(fabs(p[i] - a[i]) <= 1e-8);
	free(p);
}

int
main(void)
{
	double a1[] = {0.0, 0.25, 0.5, 0.75, 1.0, 1.25, 1.5, 1.75, 2.0};
	double a2[] = {0.0, 0.1, 0.2, 0.3, 0.4, 0.5, 0.6, 0.7, 0.8, 0.9, 1.0};
	double a3[] = {0, 2, 4, 6, 8, 10, 12, 14, 16, 18, 20};
	double a4[] = {0.0, 0.5, 1.0, 1.5, 2.0, 2.5, 3.0, 3.5, 4.0, 4.5, 5.0, 5.5, 6.0, 6.5, 7.0, 7.5, 8.0, 8.5, 9.0, 9.5, 10.0};
	double a5[] = {0.0, 0.25, 0.5, 0.75, 1.0, 1.25, 1.5, 1.75, 2.0, 2.25, 2.5, 2.75, 3.0, 3.25, 3.5, 3.75, 4.0, 4.25, 4.5, 4.75, 5.0};
	double a6[] = {0.0, 1.5, 3.0, 4.5, 6.0, 7.5, 9.0};
	double a7[] = {0.0, 0.04, 0.08, 0.12, 0.16, 0.2, 0.24, 0.28, 0.32, 0.36, 0.4, 0.44, 0.48, 0.52, 0.56, 0.6, 0.64, 0.68, 0.72, 0.76, 0.8, 0.84, 0.88, 0.92, 0.96, 1.0};
	double a8[] = {0.0, 0.09, 0.18, 0.27, 0.36, 0.45, 0.54, 0.63, 0.72, 0.81, 0.9, 0.99};
	double a9[] = {0.0, 1.5, 3.0};
	double a10[] = {0, 2, 4, 6, 8, 10, 12, 14, 16, 18, 20};
	double a11[] = {0, 2, 4, 6, 8, 10, 12, 14, 16, 18, 20};

	test(2, 0.25, a1, nelem(a1));
	test(1, 0.1, a2, nelem(a2));
	test(20, 2, a3, nelem(a3));
	test(10, 0.5, a4, nelem(a4));
	test(5, 0.25, a5, nelem(a5));
	test(9, 1.5, a6, nelem(a6));
	test(1, 0.04, a7, nelem(a7));
	test(1, 0.09, a8, nelem(a8));
	test(4, 1.5, a9, nelem(a9));
	test(20, 2, a10, nelem(a10));
	test(21, 2, a11, nelem(a11));

	return 0;
}
