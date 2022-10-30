/*

Given latitude/longitude of two points on the Moon (lat1, lon1) and (lat2, lon2), compute the distance between the two points in kilometers, by using any formula that gives the same result as the haversine formula.

Input

    Four integer values lat1, lon1, lat2, lon2 in degree (angle) or
    four decimal values ϕ1, λ1, ϕ2, λ2 in radians.

Output

Distance in kilometers between the two points (decimal with any precision or rounded integer).
Haversine formula

d = 2 r \arcsin\left(\sqrt{\sin^2\left(\frac{\phi_2 - \phi_1}{2}\right) + \cos(\phi_1) \cos(\phi_2)\sin^2\left(\frac{\lambda_2 - \lambda_1}{2}\right)}\right)

where

    r is the radius of the sphere (assume that the Moon's radius is 1737 km),
    ϕ1 latitude of point 1 in radians
    ϕ2 latitude of point 2 in radians
    λ1 longitude of point 1 in radians
    λ2 longitude of point 2 in radians
    d is the circular distance between the two points

(source: https://en.wikipedia.org/wiki/Haversine_formula)
Other possible formulas

    d = r * acos(sin ϕ1 sin ϕ2 + cos ϕ1 cos ϕ2 cos(λ2 - λ1)) @miles' formula.
    d = r * acos(cos(ϕ1 - ϕ2) + cos ϕ1 cos ϕ2 (cos(λ2 - λ1) - 1)) @Neil's formula.

Example where inputs are degrees and output as rounded integer

42, 9, 50, 2  --> 284
50, 2, 42, 9  --> 284
4, -2, -2, 1  --> 203
77, 8, 77, 8  --> 0
10, 2, 88, 9  --> 2365

Rules

    The input and output can be given in any convenient format.
    Specify in the answer whether the inputs are in degrees or radians.
    No need to handle invalid latitude/longitude values
    Either a full program or a function are acceptable. If a function, you can return the output rather than printing it.
    If possible, please include a link to an online testing environment so other people can try out your code!
    Standard loopholes are forbidden.
    This is code-golf so all usual golfing rules apply, and the shortest code (in bytes) wins.

*/

#define _GNU_SOURCE
#include <assert.h>
#include <stdio.h>
#include <math.h>

#define deg2rad(x) ((x)*M_PI / 180)

double
dist(double p1, double t1, double p2, double t2)
{
	double sp, st;
	double r, x;

	r = 1737;
	sp = sin((p2 - p1) / 2);
	st = sin((t2 - t1) / 2);
	x = sp * sp + cos(p1) * cos(p2) * st * st;
	return 2 * r * asin(sqrt(x));
}

void
test(double p1, double p2, double t1, double t2, int r)
{
	int d;

	d = round(dist(deg2rad(p1), deg2rad(p2), deg2rad(t1), deg2rad(t2)));
	printf("%d\n", d);
	assert(d == r);
}

int
main(void)
{
	test(42, 9, 50, 2, 284);
	test(50, 2, 42, 9, 284);
	test(4, -2, -2, 1, 203);
	test(77, 8, 77, 8, 0);
	test(10, 2, 88, 9, 2365);

	return 0;
}
