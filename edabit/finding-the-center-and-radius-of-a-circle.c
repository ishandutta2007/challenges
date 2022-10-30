/*

The general form of the equation of a circle is x²+y²+ax+by+c=0 where a, b, and c are constants.

Create a function that takes numbers a, b and c as arguments, and returns a list [(x_c, y_c), r] where (x_c, y_c) is the center and r is the radius.

Examples

circle(-4, -6, -12) ➞ [(2, 3), 5]

circle(8, -2, -32) ➞ [(-4, 1), 7]

circle(16, 4, 67) ➞ [(-8, -2), 1]

Notes

N/A

*/

#include <assert.h>
#include <stdio.h>
#include <math.h>

/*

Rewrite expanded form into standard form
x^2 + y^2 + ax + by + c = 0
(x-h)^2 + (y-k)^2 - r^2 = 0

Equating the variables, we get
a = -2h
b = -2k
c = h^2 - r^2 + k^2

*/

void
circle(double a, double b, double c, double p[3])
{
	p[0] = -a / 2;
	p[1] = -b / 2;
	p[2] = sqrt(p[0] * p[0] + p[1] * p[1] - c);
}

void
test(double a, double b, double c, double r[3])
{
	double p[3];
	int i;

	circle(a, b, c, p);
	for (i = 0; i < 3; i++)
		assert(fabs(p[i] - r[i]) < 1e-8);
}

int
main(void)
{
	test(-4, -6, -12, (double[3]){2, 3, 5});
	test(8, -2, -32, (double[3]){-4, 1, 7});
	test(16, 4, 67, (double[3]){-8, -2, 1});
	test(-2, -2, 1, (double[3]){1, 1, 1});
	test(-14, -24, 129, (double[3]){7, 12, 8});
	test(6, 14, 49, (double[3]){-3, -7, 3});
	test(-10, 28, 121, (double[3]){5, -14, 10});
	test(0, 0, -9, (double[3]){0, 0, 3});

	return 0;
}
