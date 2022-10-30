/*

Given an array of integers, replace every number with the mean of all numbers.
Examples

flattenCurve([1, 2, 3, 4, 5]) ➞ [3, 3, 3, 3, 3]

flattenCurve([0, 0, 0, 2, 7, 3]) ➞ [2, 2, 2, 2, 2, 2]

flattenCurve([4]) ➞ [4]

flattenCurve([]) ➞ []

Notes

    Round averages to 1 decimal point.
    Return an empty array if given an empty array (see example #4).

*/

#include <assert.h>
#include <stdio.h>
#include <math.h>

#define nelem(x) (sizeof(x) / sizeof(x[0]))

double
mean(double *x, size_t n)
{
	size_t i;
	double m;

	if (n == 0)
		return 0;

	m = 0;
	for (i = 0; i < n; i++)
		m += x[i];
	m /= n;

	return m;
}

void
flatten(double *x, size_t n)
{
	double m;
	size_t i;

	m = mean(x, n);
	for (i = 0; i < n; i++)
		x[i] = m;
}

void
test(double *x, size_t n, double *r)
{
	size_t i;

	flatten(x, n);
	for (i = 0; i < n; i++)
		assert(fabs(x[i] - r[i]) < 1e-1);
}

int
main(void)
{
	double x1[] = {1, 2, 3, 4, 5};
	double y1[] = {3, 3, 3, 3, 3};

	double x2[] = {0, 0, 0, 2, 7, 3};
	double y2[] = {2, 2, 2, 2, 2, 2};

	double x3[] = {4};
	double y3[] = {4};

	double x4[] = {7, 4, 2, 1};
	double y4[] = {3.5, 3.5, 3.5, 3.5};

	double x5[] = {-13, 0, -18};
	double y5[] = {-10.3, -10.3, -10.3};

	double x6[] = {24, 9, 18, -26, -4};
	double y6[] = {4.2, 4.2, 4.2, 4.2, 4.2};

	double x7[] = {-16, -4, -8, 28, 26};
	double y7[] = {5.2, 5.2, 5.2, 5.2, 5.2};

	double x8[] = {21, 2, 10};
	double y8[] = {11.0, 11.0, 11.0};

	double x9[] = {-19, 20};
	double y9[] = {0.5, 0.5};

	double x10[] = {1, -24, 19};
	double y10[] = {-1.3, -1.3, -1.3};

	double x11[] = {-7, -4};
	double y11[] = {-5.5, -5.5};

	double x12[] = {23, -13, -13, -15, 13};
	double y12[] = {-1.0, -1.0, -1.0, -1.0, -1.0};

	double x13[] = {22, -12, 0, -19, 2, 17, -11, 6};
	double y13[] = {0.6, 0.6, 0.6, 0.6, 0.6, 0.6, 0.6, 0.6};

	double x14[] = {-18, -1, 28, -29, -7, 12, -11};
	double y14[] = {-3.7, -3.7, -3.7, -3.7, -3.7, -3.7, -3.7};

	double x15[] = {-7, 13, 18};
	double y15[] = {8.0, 8.0, 8.0};

	double x16[] = {-19, 29, -15, 30, -17};
	double y16[] = {1.6, 1.6, 1.6, 1.6, 1.6};

	double x17[] = {26, -15, 4, -7, 30, 25, -16, -10, -15};
	double y17[] = {2.4, 2.4, 2.4, 2.4, 2.4, 2.4, 2.4, 2.4, 2.4};

	double x18[] = {-24, 19, -25, -2, 12, 22, -3, 8, 29};
	double y18[] = {4.0, 4.0, 4.0, 4.0, 4.0, 4.0, 4.0, 4.0, 4.0};

	double x19[] = {-10, 23, -4, -29, -3, -17, -17, 18};
	double y19[] = {-4.9, -4.9, -4.9, -4.9, -4.9, -4.9, -4.9, -4.9};

	double x20[] = {2, -13, -20, -25, 24, -18, -30, -4, 14, -21};
	double y20[] = {-9.1, -9.1, -9.1, -9.1, -9.1, -9.1, -9.1, -9.1, -9.1, -9.1};

	double x21[] = {-10, 26, 14, 1, 14, -8, 3, -19};
	double y21[] = {2.6, 2.6, 2.6, 2.6, 2.6, 2.6, 2.6, 2.6};

	double x22[] = {8, -16, 28, 8, 16, 30, -4};
	double y22[] = {10.0, 10.0, 10.0, 10.0, 10.0, 10.0, 10.0};

	test(x1, nelem(x1), y1);
	test(x2, nelem(x2), y2);
	test(x3, nelem(x3), y3);
	test(x3, 0, NULL);
	test(x4, nelem(x4), y4);
	test(x5, nelem(x5), y5);
	test(x6, nelem(x6), y6);
	test(x7, nelem(x7), y7);
	test(x8, nelem(x8), y8);
	test(x9, nelem(x9), y9);
	test(x10, nelem(x10), y10);
	test(x11, nelem(x11), y11);
	test(x12, nelem(x12), y12);
	test(x13, nelem(x13), y13);
	test(x14, nelem(x14), y14);
	test(x15, nelem(x15), y15);
	test(x16, nelem(x16), y16);
	test(x17, nelem(x17), y17);
	test(x18, nelem(x18), y18);
	test(x19, nelem(x19), y19);
	test(x20, nelem(x20), y20);
	test(x21, nelem(x21), y21);
	test(x22, nelem(x22), y22);

	return 0;
}
