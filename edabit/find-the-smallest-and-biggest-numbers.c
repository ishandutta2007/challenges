/*

Create a function that takes an array of numbers and return both the minimum and maximum numbers, in that order.

Examples

minMax([1, 2, 3, 4, 5]) ➞ [1, 5]

minMax([2334454, 5]) ➞ [5, 2334454]

minMax([1]) ➞ [1, 1]

Notes

All test arrays will have at least one element and are valid.

*/

#include <assert.h>
#include <stdio.h>
#include <string.h>
#include <float.h>

#define nelem(x) (sizeof(x) / sizeof(x[0]))
#define min(a, b) (((a) < (b)) ? (a) : (b))
#define max(a, b) (((a) > (b)) ? (a) : (b))

void
minmax(double *a, size_t n, double r[2])
{
	size_t i;

	r[0] = DBL_MAX;
	r[1] = -DBL_MAX;
	for (i = 0; i < n; i++) {
		r[0] = min(r[0], a[i]);
		r[1] = max(r[1], a[i]);
	}
}

void
test(double *a, size_t n, double r[2])
{
	double p[2];

	minmax(a, n, p);
	assert(!memcmp(r, p, sizeof(p)));
}

int
main(void)
{
	double a1[] = {1, 2, 3, 4, 5};
	double b1[] = {1, 5};

	double a2[] = {2334454, 5};
	double b2[] = {5, 2334454};

	double a3[] = {1};
	double b3[] = {1, 1};

	double a4[] = {14, 35, 6, 1, 34, 54};
	double b4[] = {1, 54};

	double a5[] = {1.346, 1.6532, 1.8734, 1.8723};
	double b5[] = {1.346, 1.8734};

	double a6[] = {0.432, 0.874, 0.523, 0.984, 0.327, 0.2345};
	double b6[] = {0.2345, 0.984};

	double a7[] = {13, 72, 98, 43, 24, 65, 31};
	double b7[] = {13, 98};

	double a8[] = {-54, -23, -54, -21};
	double b8[] = {-54, -21};

	double a9[] = {-0.473, -0.6834, -0.1287, 0.5632};
	double b9[] = {-0.6834, 0.5632};

	double a10[] = {0, 0, 0, 0};
	double b10[] = {0, 0};

	test(a1, nelem(a1), b1);
	test(a2, nelem(a2), b2);
	test(a3, nelem(a3), b3);
	test(a4, nelem(a4), b4);
	test(a5, nelem(a5), b5);
	test(a6, nelem(a6), b6);
	test(a7, nelem(a7), b7);
	test(a8, nelem(a8), b8);
	test(a9, nelem(a9), b9);
	test(a10, nelem(a10), b10);

	return 0;
}
