/*

A company asks a small-scale manufacturer to produce packaging in which they can ship their cooking oil.
The company also gives the design for how the vessel should look (the shaded portion filled in the image below).
Depending upon the volume of oil to be packaged, the company requires vessels of varying height.

Create a function to determine what the height of the vessel should be, depending on the given volume of oil.
Return height of the vessel in centimeters, with up to two decimals of precision.

Cone in Cylinder

Examples

height_needed(0.5) ➞ 19.1

height_needed(5) ➞ 190.99

height_needed(10) ➞ 381.97

Notes

    Assume the radius (5cm) will stay constant for all different volume vessels.
    volume will be given in the unit of litre.

*/

#define _GNU_SOURCE
#include <assert.h>
#include <math.h>

double
height(double v)
{
	double r, h;

	r = 0.05;
	h = v * 3 / (M_PI * r * r);
	return h * 0.1;
}

void
test(double v, double r)
{
	assert(fabs(height(v) - r) < 1e-2);
}

int
main(void)
{
	test(0.5, 19.1);
	test(5, 190.99);
	test(10, 381.97);
	test(1, 38.2);
	test(3, 114.59);
	test(0.5, 19.1);
	test(10, 381.97);
	test(5, 190.99);

	return 0;
}
