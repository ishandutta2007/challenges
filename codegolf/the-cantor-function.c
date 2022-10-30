/*

The Cantor function is continuous everywhere and constant almost everywhere, but has an average slope of 1:

fncantor

The function can be found recursively:

f[0](x)=x
f[n+1](x) = 1/2*f[n](3x)             if x [0, 1/3]
            1/2                      if x [1/3, 2/3]
            1/2 + 1/2*f[n](3x - 2)   if x [2/3, 1]
 
The Cantor function is the limit of this process, limn→∞ f[n](x):

iteration limit
The Challenge

Given real x (which can assume the form of a float or rational number) of the interval [0,1]
and nonnegative integer n, return fn(x).

Rules

    This is code-golf so the shortest answer in bytes wins.

    Assume only valid input will be given.

    Error should be under one ten-thousandth (±0.0001) for the test cases.

Test Cases

In: 0.3 3
Out: 0.3875

In: 0.1 0
Out: 0.1

In: 0.29 4
Out: 0.375

In: 0.11 5
Out: 0.2415625

*/

#include <assert.h>
#include <stdio.h>
#include <math.h>

double
clamp(double x, double a, double b)
{
	if (x < a)
		x = a;
	else if (x > b)
		x = b;
	return x;
}

double
cantor(double x, unsigned n)
{
	x = clamp(x, 0, 1);
	if (n == 0)
		return x;
	if (0 <= x && x < 1.0 / 3)
		return 0.5 * cantor(3 * x, n - 1);
	if (1.0 / 3 <= x && x < 2.0 / 3)
		return 0.5;
	if (2.0 / 3 <= x && x <= 1)
		return 0.5 + 0.5 * cantor(3 * x - 2, n - 1);
	return x;
}

void
test(double x, unsigned n, double r)
{
	double p;

	p = cantor(x, n);
	printf("%f\n", p);
	assert(fabs(p - r) < 1e-6);
}

int
main(void)
{
	test(0.3, 3, 0.3875);
	test(0.1, 0, 0.1);
	test(0.29, 4, 0.375);
	test(0.11, 5, 0.2415625);

	return 0;
}
