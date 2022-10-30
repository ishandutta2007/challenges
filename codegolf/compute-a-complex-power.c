/*

The Rundown
Given any input x and y, perform a complex operation, and print a corresponding result.

How your program should work
Given an input x and y in the form z = x+yi, find zi-z

If the absolute real value of zi-z is larger than the absolute imaginary part, print the real part; vice versa for the other way around. If both values are equal, print one of the values.

Example
x: 2
y: 0
Therefore:

z = 2
z^(i-z) ~= 0.192309 + 0.159740i
Since the real part has a larger absolute value than the imaginary part, the program returns

0.192309
More examples
z = 1+i >> 0.5
z = i >> 1
z = 0.5 >> 1.08787
z = -2+8i >> 2.22964E7
z = -10i >> 3.13112E7

*/

#include <assert.h>
#include <stdio.h>
#include <math.h>
#include <complex.h>

double
zpow(double complex z)
{
	z = cpow(z, I - z);
	return fmax(creal(z), cimag(z));
}

void
test(double complex z, double r)
{
	double p;

	p = zpow(z);
	assert(fabs(log10(p) - log10(r)) < 1e-5);
}

int
main(void)
{
	test(2, 0.192309);
	test(1 + I, 0.5);
	test(I, 1);
	test(0.5, 1.08787);
	test(-2 + 8 * I, 2.22964e7);
	test(-10 * I, 3.13112e7);

	return 0;
}
