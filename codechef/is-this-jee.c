/*

Everyone loves short problem statements.

Given a function f(x) find its minimum value over the range 0<x<π/2
f(x)=(x^2+b∗x+c)/sin(x)

Input:

First-line will contain T, the number of test cases. Then the test cases follow.
Each test case contains a single line of input, two real numbers b,c.

Output:

For each test case, output the minimum value of f(x) over the given range. Absolute error of 10^-6 is allowed.

Constraints
1≤T≤100000
1≤b,c≤20

*/

#define _XOPEN_SOURCE
#include <assert.h>
#include <stdio.h>
#include <math.h>
#include <float.h>

double
f(double x, double b, double c)
{
	return ((x * x) + (b * x) + c) / sin(x);
}

double
minimum(double b, double c)
{
	double l, r;
	double u, v;
	double x, y;
	double m;
	int i;

	l = 0;
	r = M_PI / 2;
	m = DBL_MAX;
	for (i = 0; i < 256; i++) {
		x = l + (1 * (r - l) / 3);
		y = l + (2 * (r - l) / 3);

		u = f(x, b, c);
		v = f(y, b, c);
		if (u > v)
			l = x;
		else
			r = y;

		m = fmin(m, fmin(u, v));
	}
	return m;
}

void
test(double b, double c, double r)
{
	double p;

	p = minimum(b, c);
	printf("%.6f\n", p);
	assert(fabs(p - r) < 1e-6);
}

int
main(void)
{
	test(2, 2, 5.8831725615);

	return 0;
}
