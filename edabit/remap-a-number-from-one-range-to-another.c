/*

Create a function similar to Processings "map" function (check the Resources tab), in which a value and its range is taken and remapped to a new range.

The function takes 5 numbers:

    Value: value
    Range: low1 and high1
    Range: low2 and high2

Examples

remap(7, 2, 12, 0, 100) ➞ 50

remap(17, 5, 55, 100, 30) ➞ 83.2

remap(50, 1, 51, 0, 100) ➞ 98

Notes

    Test input will always be numbers.
    If the input range is 0, return 0.

*/

#include <assert.h>
#include <stdio.h>
#include <math.h>

double
lerp(double t, double a, double b)
{
	return a + t * (b - a);
}

double
unlerp(double t, double a, double b)
{
	return (t - a) / (b - a);
}

double
remap(double x, double a, double b, double c, double d)
{
	if (a == b)
		return 0;
	return lerp(unlerp(x, a, b), c, d);
}

void
test(double x, double a, double b, double c, double d, double r)
{
	double v;

	v = remap(x, a, b, c, d);
	assert(fabs(v - r) < 1e-2);
}

int
main(void)
{
	test(7, 2, 12, 0, 100, 50);
	test(17, 5, 55, 100, 30, 83.2);
	test(2.5, 2, 3, -80, 80, 0);
	test(50, 1, 51, 0, 100, 98);
	test(0, 0, 0, 0, 0, 0);
	test(20, 10, 50, 50, 10, 40);
	test(0, 5, -20, 60, 1000, 248);
	test(17, 17, 17, 519, 1085, 0);

	return 0;
}
