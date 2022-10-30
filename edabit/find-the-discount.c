/*

Create a function that takes two arguments: the original price and the discount
percentage as integers and returns the final price after the discount.

Alternative Text
Examples

dis(1500, 50) ➞ 750

dis(89, 20) ➞ 71.2

dis(100, 75) ➞ 25

Notes

Your answer should be rounded to two decimal places.

*/

#include <assert.h>
#include <stdio.h>
#include <math.h>

#define max(a, b) (((a) > (b)) ? (a) : (b))

double
dis(double p, double d)
{
	return max(p - (p * d / 100.0), 0);
}

void
test(double p, double d, double r)
{
	assert(fabs(dis(p, d) - r) < 1e-2);
}

int
main(void)
{
	test(1500, 50, 750);
	test(89, 20, 71.2);
	test(100, 75, 25);
	test(211, 50, 105.5);
	test(593, 61, 231.27);
	test(1693, 80, 338.6);
	test(700, 10, 630);

	return 0;
}
