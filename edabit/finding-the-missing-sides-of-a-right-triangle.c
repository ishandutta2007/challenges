/*

Consider a right triangle. Its area and hypotenuse are known.

Create a function that returns the two missing sides. The first input is the area and the second input is the hypotenuse.
Return your answer as an array (the shorter side first). If there is no such right triangle, return "Does not exist".
Examples

f(3, 6) ➞ [1.015, 5.914]

f(30, 12) ➞ [5.675, 10.574]

f(30, 10) ➞ "Does not exist"

Notes

Round your answer to three decimal places.

*/

#include <assert.h>
#include <stdio.h>
#include <string.h>
#include <math.h>

int
quadratic(int a, int b, int c, double r[2])
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

int
sides(int a, int h, double s[2])
{
	double r[2];

	if (quadratic(-1, h * h, -4 * a * a, r) < 0)
		return -1;
	s[0] = sqrt(r[0]);
	s[1] = sqrt(r[1]);
	return 0;
}

void
test(int a, int h, void *u)
{
	static const double eps = 1e-3;
	double s[2], *r;

	if (sides(a, h, s) < 0)
		assert(!strcmp(u, "Does not exist"));
	else {
		r = u;
		assert(fabs(r[0] - s[0]) < eps);
		assert(fabs(r[1] - s[1]) < eps);
	}
}

int
main(void)
{
	double s1[] = {1.015, 5.914};
	double s2[] = {5.675, 10.574};

	test(3, 6, s1);
	test(30, 12, s2);
	test(30, 10, "Does not exist");

	return 0;
}
