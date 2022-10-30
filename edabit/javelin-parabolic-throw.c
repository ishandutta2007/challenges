/*

Write a function that takes initial speed (v in m/s) and throw angle (a in degrees) and returns the maximum height and maximum range reached by javelin as a string.
Examples

javelinThrow(36.7, 45) ➞ "Ymax=34m, Xmax=137m"

javelinThrow(51.3, 20) ➞ "Ymax=16m, Xmax=172m"

javelinThrow(100.1, 89) ➞ "Ymax=511m, Xmax=36m"

Notes

    Javelin starts moving at h=0m.
    Gravitational acceleration is g=9.81 m/s^2.
    All results should be rounded to the nearest whole number.
    You can find all mathematical equations in Resources.
    Remember that Math.sin() and Math.cos() methods don't take degree as an argument.

*/

#define _GNU_SOURCE
#include <assert.h>
#include <stdio.h>
#include <string.h>
#include <math.h>

#define deg2rad(x) ((x)*M_PI / 180.0)

// https://en.wikipedia.org/wiki/Projectile_motion
char *
javelinthrow(double v, double a, char *b)
{
	static const double g = 9.81;
	double x, y, s, c, r;

	r = deg2rad(a);
	s = sin(r);
	c = cos(r);
	x = (v * v * 2 * s * c) / g;
	y = (v * v * s * s) / (2 * g);
	sprintf(b, "Ymax=%.0fm, Xmax=%.0fm", y, x);
	return b;
}

void
test(double v, double a, const char *r)
{
	char b[80];

	javelinthrow(v, a, b);
	assert(!strcmp(b, r));
}

int
main(void)
{
	test(36.7, 45, "Ymax=34m, Xmax=137m");
	test(51.3, 20, "Ymax=16m, Xmax=172m");
	test(100.1, 89, "Ymax=511m, Xmax=36m");
	test(100.0, 37, "Ymax=185m, Xmax=980m");
	test(36.7, 45, "Ymax=34m, Xmax=137m");
	test(51.3, 20, "Ymax=16m, Xmax=172m");
	test(11.1, 25, "Ymax=1m, Xmax=10m");
	test(75.5, 40, "Ymax=120m, Xmax=572m");
	test(250.0, 42, "Ymax=1426m, Xmax=6336m");
	test(100.1, 89, "Ymax=511m, Xmax=36m");

	return 0;
}
