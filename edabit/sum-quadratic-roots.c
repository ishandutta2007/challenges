/*

Given a, b and c, find the roots of the equation ax^2 +bx +c = 0 and then add them together.

Round your answer to two decimal places.
If there is only one real root return 1.
If there are no real roots, return 0.

Examples

findRootsSum(2, 4, -6) ➞ -2.00

findRootsSum(3, 4, -3) ➞ -1.33

findRootsSum(4, 3, -8) ➞ -0.75

Notes

The Discriminant of a quadratic equation is b^2-4(a)(c).

*/

#include <assert.h>
#include <stdio.h>
#include <math.h>

double
quadratic(double a, double b, double c, double r[2])
{
	double d, s;

	d = b * b - 4 * a * c;
	if (d < 0)
		return d;

	s = sqrt(d);
	r[0] = (-b + s) / (2.0 * a);
	r[1] = (-b - s) / (2.0 * a);
	return d;
}

double
sumroots(double a, double b, double c)
{
	double d, r[2];

	d = quadratic(a, b, c, r);
	if (d < 0)
		return 0;
	if (d == 0)
		return 1;
	return r[0] + r[1];
}

void
eq(double a, double b, double c, double r)
{
	assert(fabs(sumroots(a, b, c) - r) < 1e-2);
}

int
main(void)
{
	eq(2, 4, -6, -2.00);
	eq(3, 4, -3, -1.33);
	eq(4, 3, -8, -0.75);
	eq(5, 7, -2, -1.40);
	eq(2, 4, 2, 1.00);
	eq(3, 4, 3, 0.00);

	return 0;
}
