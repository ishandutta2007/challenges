/*

disclaimer: the Mean mean is made up by me

Define the arithmetic mean of n numbers as
M1(x1,...,xn) = (x1 + x2 +... + xn)/ n

Define the geometric mean of n numbers as
M0(x1,...,xn) = pow(x1 * x2 * ... * xn, 1/n)

Define the harmonic mean of n numbers as
M-1(x1,...,xn) = n / (1/x1 + 1/x2 + ... + 1 / xn)

Define the quadratic mean of n numbers as
M2(x1,...,xn) = sqrt((x1^2 + x2^2 ... xn^2) / n)

The Mean mean (MM) is defined as follows: Define four sequences (ak,bk,ck,dk) as
a0=M1(x1,...,xn),
b0=M0(x1,...,xn),
c0=M−1(x1,...,xn),
d0=M2(x1,...,xn),
ak+1=M1(ak,bk,ck,dk),
bk+1=M0(ak,bk,ck,dk),
ck+1=M−1(ak,bk,ck,dk),
dk+1=M2(ak,bk,ck,dk)
All four sequences converge to the same number, MM(x1,x2,...,xn).

Challenge
Given two positive real numbers, a and b (a<b), calculate their Mean mean MM(a,b).

Test cases
1 1 => 1
1 2 => 1.45568889
100 200 => 145.568889
2.71 3.14 => 2.92103713
0.57 1.78 => 1.0848205
1.61 2.41 => 1.98965438
0.01 100 => 6.7483058

Notes
Your program is valid if the difference between its output and the correct output is not greater than 1/100000 of the absolute value of the difference between input numbers.
The output should be a single number.
This is code-golf, so the shortest code wins!

*/

#include <assert.h>
#include <stdio.h>
#include <string.h>
#include <math.h>

double
arithmetic(double *a, size_t n)
{
	double m;
	size_t i;

	if (n == 0)
		return 0;

	m = 0;
	for (i = 0; i < n; i++)
		m += a[i];
	return m / n;
}

double
geometric(double *a, size_t n)
{
	double m;
	size_t i;

	if (n == 0)
		return 0;

	m = a[0];
	for (i = 1; i < n; i++)
		m *= a[i];
	return pow(m, 1.0 / n);
}

double
harmonic(double *a, size_t n)
{
	double m;
	size_t i;

	m = 0;
	for (i = 0; i < n; i++)
		m += 1.0 / a[i];
	return n / m;
}

double
quadratic(double *a, size_t n)
{
	double m;
	size_t i;

	if (n == 0)
		return 0;

	m = 0;
	for (i = 0; i < n; i++)
		m += (a[i] * a[i]);
	return sqrt(m / n);
}

int
eq(double *a, size_t n)
{
	size_t i;

	for (i = 1; i < n; i++) {
		if (!(fabs(a[i] - a[i - 1]) < 1e-6))
			return 0;
	}
	return 1;
}

double
mean(double a, double b)
{
	double x[4], y[4];
	double c[2];

	c[0] = a;
	c[1] = b;

	x[0] = arithmetic(c, 2);
	x[1] = geometric(c, 2);
	x[2] = harmonic(c, 2);
	x[3] = quadratic(c, 2);
	for (;;) {
		y[0] = arithmetic(x, 4);
		y[1] = geometric(x, 4);
		y[2] = harmonic(x, 4);
		y[3] = quadratic(x, 4);
		if (eq(y, 4))
			break;
		memcpy(x, y, sizeof(y));
	}
	return y[0];
}

void
test(double a, double b, double r)
{
	double p;

	p = mean(a, b);
	printf("%f %f\n", p, r);
	assert(fabs(p - r) < 1e-6);
}

int
main(void)
{
	test(1, 1, 1);
	test(1, 2, 1.45568889);
	test(100, 200, 145.568889);
	test(2.71, 3.14, 2.92103713);
	test(0.57, 1.78, 1.0848205);
	test(1.61, 2.41, 1.98965438);
	test(0.01, 100, 6.7483058);

	return 0;
}
