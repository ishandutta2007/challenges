/*

In special relativity, the velocity of a moving object relative to another object that is moving in the opposite direction is given by the formula:

s=v+u1+vu/c2.

s = ( v + u ) / ( 1 + v * u / c ^ 2)

In this formula, v
and u are the magnitudes of the velocities of the objects, and c is the speed of light (which is approximately 3.0×108m/s

, a close enough approximation for this challenge).

For example, if one object was moving at v = 50,000 m/s, and another object was moving at u = 60,000 m/s, the velocity of each object relative to the other would be approximately s = 110,000 m/s. This is what you would expect under Galilean relativity (where velocities simply add). However, if v = 50,000,000 m/s and u = 60,000,000 m/s, the relative velocity would be approximately 106,451,613 m/s, which is significantly different than the 110,000,000 m/s predicted by Galilean relativity.
The Challenge

Given two integers v and u such that 0 <= v,u < c, calculate the relativistic additive velocity, using the above formula, with c = 300000000. Output must be either a decimal value or a reduced fraction. The output must be within 0.001 of the actual value for a decimal value, or exact for a fraction.
Test Cases

Format: v, u -> exact fraction (float approximation)

50000, 60000 -> 3300000000000/30000001 (109999.99633333346)
50000000, 60000000 -> 3300000000/31 (106451612.90322581)
20, 30 -> 7500000000000000/150000000000001 (49.999999999999666)
0, 20051 -> 20051 (20051.0)
299999999, 299999999 -> 53999999820000000000000000/179999999400000001 (300000000.0)
20000, 2000000 -> 4545000000000/2250001 (2019999.1022226212)
2000000, 2000000 -> 90000000000/22501 (3999822.2301231055)
1, 500000 -> 90000180000000000/180000000001 (500000.9999972222)
1, 50000000 -> 90000001800000000/1800000001 (50000000.972222224)
200000000, 100000000 -> 2700000000/11 (245454545.45454547)

*/

#include <assert.h>
#include <stdio.h>
#include <math.h>

double
velocity(double v, double u)
{
	static const double c = 300000000;
	return (v + u) / (1 + v * u / (c * c));
}

void
test(double v, double u, double r)
{
	double s;

	s = velocity(v, u);
	printf("%f\n", s);
	assert(fabs(s - r) < 1e-7);
}

int
main(void)
{
	test(50000, 60000, 109999.99633333346);
	test(50000000, 60000000, 106451612.90322581);
	test(20, 30, 49.999999999999666);
	test(0, 20051, 20051.0);
	test(299999999, 299999999, 300000000.0);
	test(20000, 2000000, 2019999.1022226212);
	test(2000000, 2000000, 3999822.2301231055);
	test(1, 500000, 500000.9999972222);
	test(1, 50000000, 50000000.972222224);
	test(200000000, 100000000, 245454545.45454547);

	return 0;
}
