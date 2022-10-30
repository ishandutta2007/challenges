/*

Create a function that takes an angle in radians and returns the corresponding angle in degrees rounded to one decimal place.
Examples

radians_to_degrees(1) ➞ 57.3

radians_to_degrees(20) ➞ 1145.9

radians_to_degrees(50) ➞ 2864.8

Notes

The number π can be loaded from the math module with from math import pi.

*/

#define _GNU_SOURCE
#include <assert.h>
#include <math.h>

#define rad2deg(x) ((x)*180 / M_PI)

void
eq(double x, double y)
{
	assert(fabs(x - y) < 1e-1);
}

int
main(void)
{
	eq(rad2deg(1), 57.3);
	eq(rad2deg(20), 1145.9);
	eq(rad2deg(50), 2864.8);
	eq(rad2deg(5), 286.5);
	eq(rad2deg(7), 401.1);
	eq(rad2deg(60), 3437.7);
	eq(rad2deg(100), 5729.6);
	eq(rad2deg(180), 10313.2);

	return 0;
}
