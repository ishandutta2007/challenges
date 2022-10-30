/*

Your function will get an array with a number sequence. However, one item will be missing. It's your job to find out which one is not in the array.

To illustrate, given the array [1, 3, 4, 5], 2 is missing so the output must be 2.
Examples

missing([1, 3, 4, 5]) ➞ 2

missing([2, 4, 6, 8, 10, 14, 16]) ➞ 12

missing([1.5, 2, 3]) ➞ 2.5

Notes

    The missing item will never be the smallest or largest number in the array.
    In every array, exactly one item is missing.

*/

#include <assert.h>
#include <stdio.h>
#include <math.h>

#define nelem(x) (sizeof(x) / sizeof(x[0]))

double
missing(double *a, size_t n)
{
	static const double eps = 1e-12;

	size_t i, j, l;
	size_t c[2], p[2];
	double v, x, y;
	double r[2];

	if (n < 3)
		return -1;

	c[0] = c[1] = 0;
	for (i = l = 0; i < n - 1; i++) {
		v = a[i + 1] - a[i];
		for (j = 0; j < l; j++) {
			if (fabs(r[j] - v) < eps)
				break;
		}
		if (j == l) {
			if (l >= nelem(r))
				return -1;

			r[l] = v;
			p[l] = i;
			l++;
		} else
			c[j]++;
	}

	x = a[p[0]] + r[1];
	y = a[p[1]] + r[0];
	if (c[0] == c[1])
		return (x <= a[0] || x >= a[n - 1]) ? y : x;
	if (c[0] < c[1])
		return x;
	return y;
}

void
test(double *a, size_t n, double r)
{
	assert(fabs(missing(a, n) - r) < 1e-12);
}

int
main(void)
{
	double a1[] = {1, 3, 4, 5};
	double a2[] = {2, 4, 6, 8, 10, 14, 16};
	double a3[] = {12, 15, 18, 21, 24, 30, 33};
	double a4[] = {0, 60, 180};
	double a5[] = {-1.25, 1.25, 2.5};
	double a6[] = {1, 19, 28};
	double a7[] = {100, 500, 900, 1300, 2100, 2500, 2900};
	double a8[] = {1.5, 2, 3};

	test(a1, nelem(a1), 2);
	test(a2, nelem(a2), 12);
	test(a3, nelem(a3), 27);
	test(a4, nelem(a4), 120);
	test(a5, nelem(a5), 0);
	test(a6, nelem(a6), 10);
	test(a7, nelem(a7), 1700);
	test(a8, nelem(a8), 2.5);

	return 0;
}
