/*

Create a function that takes numbers b and m as arguments and returns the derivative of the function f(x)=x^b with respect to x evaluated at x=m, where b and m are constants.
Examples

derivative(1, 4) ➞ 1

derivative(3, -2) ➞ 12

derivative(4, -3) ➞ -108

Notes

^ in the context of this challenge means "to the power of", also known as the "exponent" operator.

*/

#include <assert.h>
#include <math.h>

double
derivative(int b, double m)
{
	return b * pow(m, b - 1);
}

void
asserteq(double a, double b)
{
	assert(fabs(a - b) < 1e-8);
}

int
main(void)
{
	asserteq(derivative(1, 4), 1);
	asserteq(derivative(3, -2), 12);
	asserteq(derivative(4, -3), -108);
	asserteq(derivative(9, -5), 3515625);
	asserteq(derivative(1254, 0), 0);
	asserteq(derivative(-2, 10), -0.002);

	return 0;
}
