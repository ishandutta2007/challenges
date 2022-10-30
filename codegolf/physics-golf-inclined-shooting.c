/*

An angry bird is shot at an angle β to the horizontal at a speed u. The ground is steep, inclined at an angle α. Find the horizontal distance q that the bird traveled before it hit the ground.

diagram showing an inclined plane at angle α and an angry bird being fired at angle β at speed u

Make a function f(α,β,u) that returns the length q: the horizontal distance that the bird traveled before it hit the ground.

Constraints and notes:

−90°<α<90°.
0°<β<180°.
α<β.
0≤u<10^9.

Assume acceleration due to gravity g=10.
You may use radians instead of degrees for α, β.
Dimensions of u are irrelevant as long as they are consistent with g and q.
No air resistance or anything too fancy.
Shortest code wins.

See the Wikipedia article on projectile motion for some equations.

Samples:

f(0, 45, 10) = 10
f(0, 90, 100) = 0
f(26.565, 45, 10) = 5
f(26.565, 135, 10) = 15

*/

#define _GNU_SOURCE
#include <assert.h>
#include <stdio.h>
#include <math.h>

#define deg2rad(x) ((x)*M_PI / 180)

double
f(double a, double b, double u)
{
	double q, z;

	b = deg2rad(b);
	a = deg2rad(a);
	z = u * cos(b);
	q = (tan(b) - tan(a)) * z * z / 5.0;
	return fabs(q);
}

void
test(double a, double b, double u, double rq)
{
	double q;

	q = f(a, b, u);
	printf("%f\n", q);
	assert(fabs(q - rq) < 1e-4);
}

int
main(void)
{
	test(0, 45, 10, 10);
	test(0, 90, 100, 0);
	test(26.565, 45, 10, 5);
	test(26.565, 135, 10, 15);

	return 0;
}
