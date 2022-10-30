/*

To calculate the circumference of a circle seems to be an easy task — provided you know its diameter.
But what if you don’t?
You are given the cartesian coordinates of three non-collinear points in the plane.
Your job is to calculate the circumference of the unique circle that intersects all three points.

Input
The input file will contain one or more test cases. Each test case consists of one line containing six
real numbers x1, y1, x2, y2, x3, y3, representing the coordinates of the three points. The diameter of the
circle determined by the three points will never exceed a million. Input is terminated by end of file.

Output
For each test case, print one line containing one real number telling the circumference of the circle
determined by the three points. The circumference is to be printed accurately rounded to two decimals.
The value of π is approximately 3.141592653589793.

Sample Input
0.0 -0.5 0.5 0.0 0.0 0.5
0.0 0.0 0.0 1.0 1.0 1.0
5.0 5.0 5.0 7.0 4.0 6.0
0.0 0.0 -1.0 7.0 7.0 7.0
50.0 50.0 50.0 70.0 40.0 60.0
0.0 0.0 10.0 0.0 20.0 1.0
0.0 -500000.0 500000.0 0.0 0.0 500000.0

Sample Output
3.14
4.44
6.28
31.42
62.83
632.24
3141592.65

*/

#define _GNU_SOURCE
#include <assert.h>
#include <stdio.h>
#include <math.h>

double
circumference(double x1, double y1, double x2, double y2, double x3, double y3)
{
	double a, b, c, r;

	a = sqrt(pow(x1 - x2, 2) + pow(y1 - y2, 2));
	b = sqrt(pow(x1 - x3, 2) + pow(y1 - y3, 2));
	c = sqrt(pow(x3 - x2, 2) + pow(y3 - y2, 2));
	r = (a * b * c) / sqrt((a + b + c) * (a + b - c) * (b + c - a) * (c + a - b));
	return 2 * M_PI * r;
}

void
test(double x1, double y1, double x2, double y2, double x3, double y3, double r)
{
	double p;

	p = circumference(x1, y1, x2, y2, x3, y3);
	printf("%.2f\n", p);
	assert(fabs(p - r) < 1e-2);
}

int
main(void)
{
	test(0.0, -0.5, 0.5, 0.0, 0.0, 0.5, 3.14);
	test(0.0, 0.0, 0.0, 1.0, 1.0, 1.0, 4.44);
	test(5.0, 5.0, 5.0, 7.0, 4.0, 6.0, 6.28);
	test(0.0, 0.0, -1.0, 7.0, 7.0, 7.0, 31.42);
	test(50.0, 50.0, 50.0, 70.0, 40.0, 60.0, 62.83);
	test(0.0, 0.0, 10.0, 0.0, 20.0, 1.0, 632.24);
	test(0.0, -500000.0, 500000.0, 0.0, 0.0, 500000.0, 3141592.65);

	return 0;
}
