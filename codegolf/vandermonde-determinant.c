/*

Given a vector of n values (x1,x2,x3,…,xn) return the determinant of the corresponding Vandermonde matrix

V(x1,x2,…,xn)=

[ 1 x1 x1^2 ... x1^(n-1) ]
[ 1 x2 x2^2 ... x2^(n-1) ]
[ 1 x3 x3^3 ... x3^(n-1) ]
[ ...................... ]
[ 1 xn xn^2 ... xn^(n-1) ]

This determinant can be written as:

detV(x1,x2,…xn)=∏1⩽i<j⩽n(xj−xi)

Details

Your program/function has to accept a list of floating point numbers in any convenient format that allows for a variable length, and output the specified determinant.

You can assume that the input as well as the output is within the range of the values your language supports. If you language does not support floating point numbers, you may assume integers.

Some test cases

Note that whenever there are two equal entries, the determinant will be 0 as there are two equal rows in the corresponding Vandermonde matrix. Thanks to @randomra for pointing out this missing testcase.

[1,2,2,3]            0
[-13513]             1
[1,2]                1
[2,1]               -1
[1,2,3]              2
[3,2,1]             -2
[1,2,3,4]           12
[1,2,3,4,5]        288
[1,2,4]              6
[1,2,4,8]         1008
[1,2,4,8,16]  20321280
[0, .1, .2,...,1]   6.6586e-028
[1, .5, .25, .125]  0.00384521
[.25, .5, 1, 2, 4]  19.3798828

*/

#include <assert.h>
#include <stdio.h>
#include <math.h>

#define nelem(x) (sizeof(x) / sizeof(x[0]))

double
det(double *x, size_t n)
{
	size_t i, j;
	double r;

	if (n == 0)
		return 0;

	r = 1;
	for (i = 0; i < n; i++) {
		for (j = i + 1; j < n; j++)
			r *= x[j] - x[i];
	}
	return r;
}

void
test(double *x, size_t n, double r)
{
	double p;

	p = det(x, n);
	printf("%f\n", p);
	assert(fabs(p - r) < 1e-7);
}

int
main(void)
{
	double x1[] = {1, 2, 2, 3};
	double x2[] = {-13513};
	double x3[] = {1, 2};
	double x4[] = {2, 1};
	double x5[] = {1, 2, 3};
	double x6[] = {3, 2, 1};
	double x7[] = {1, 2, 3, 4};
	double x8[] = {1, 2, 3, 4, 5};
	double x9[] = {1, 2, 4};
	double x10[] = {1, 2, 4, 8};
	double x11[] = {1, 2, 4, 8, 16};
	double x12[] = {0, .1, .2, .3, .4, .5, .6, .7, .8, .9, 1};
	double x13[] = {1, .5, .25, .125};
	double x14[] = {.25, .5, 1, 2, 4};

	test(x1, nelem(x1), 0);
	test(x2, nelem(x2), 1);
	test(x3, nelem(x3), 1);
	test(x4, nelem(x4), -1);
	test(x5, nelem(x5), 2);
	test(x6, nelem(x6), -2);
	test(x7, nelem(x7), 12);
	test(x8, nelem(x8), 288);
	test(x9, nelem(x9), 6);
	test(x10, nelem(x10), 1008);
	test(x11, nelem(x11), 20321280.0);
	test(x12, nelem(x12), 6.6586e-028);
	test(x13, nelem(x13), 0.00384521);
	test(x14, nelem(x14), 19.3798828);

	return 0;
}
