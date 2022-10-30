/*

The 19th century German mathematician Hermann Minkowski investigated a non-Euclidian geometry, called the taxicab geometry.
In taxicab geometry the distance between two points T1(x1,y1) and T2(x2,y2) is defined as:

D(T1,T2)=|x1−x2|+|y1−y2|

All other definitions are the same as in Euclidian geometry, including that of a circle:

A circle is the set of all points in a plane at a fixed distance (the radius) from a fixed point (the centre of the circle).

We are interested in the difference of the areas of two circles with radius R, one of which is in normal (Euclidian) geometry, and the other in taxicab geometry. The burden of solving this difficult problem has fallen onto you.

Input

The first and only line of input will contain the radius R, a positive integer smaller than or equal to 10000.

Output

On the first line you should output the area of a circle with radius R in normal (Euclidian) geometry. On the second line you should output the area of a circle with radius R in taxicab geometry.

Note: Outputs within ±0.0001 of the official solution will be accepted.

*/

#define _GNU_SOURCE
#include <assert.h>
#include <stdio.h>
#include <math.h>

void
herman(double r, double p[2])
{
	p[0] = M_PI * r * r;
	p[1] = 2 * r * r;
}

void
test(double r, double p[2])
{
	static const double eps = 1e-6;

	double v[2];

	herman(r, v);
	printf("%.7f %.7f\n", v[0], v[1]);
	assert(fabs(p[0] - v[0]) < eps);
	assert(fabs(p[1] - v[1]) < eps);
}

int
main(void)
{
	test(1, (double[]){3.141593, 2.000000});
	test(21, (double[]){1385.442360, 882.000000});
	test(42, (double[]){5541.769441, 3528.000000});

	return 0;
}
