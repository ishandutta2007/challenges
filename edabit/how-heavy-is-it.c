/*

Given radius r and height h (in cm), calculate the mass of a cylinder when it's filled with water and the cylinder itself doesn't weigh anything. The desired output should be given in kg and rounded to two decimal places.

How to solve:

    Calculate the volume of the cylinder.
    Convert cm³ into dm³.
    1dm³ = 1L, 1L is 1Kg.

Examples

weight(4, 10) ➞ 0.5

weight(30, 60) ➞ 169.65

weight(15, 10) ➞ 7.07

Notes

If you get stuck on a challenge, find help in Resources.

*/

#define _GNU_SOURCE
#include <assert.h>
#include <math.h>

double
weight(double r, double h)
{
	return r * r * h * M_PI * 1e-3;
}

void
test(double r, double h, double v)
{
	assert(fabs(weight(r, h) - v) <= 1e-2);
}

int
main(void)
{
	test(4, 10, 0.5);
	test(30, 60, 169.65);
	test(15, 10, 7.07);
	test(20, 40, 50.27);
	test(100, 30, 942.48);
	test(200, 300, 37699.11);
	test(15, 23, 16.26);
	test(22, 44, 66.9);

	return 0;
}
