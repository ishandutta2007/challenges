/*

Here is a quick Monday morning challenge...

Write a function or program in the least number of bytes that:

Takes as input a list of [x,y] coordinates
Takes as input a list of the [x,y] coordinates' respective masses
Outputs the calculated center of mass in the form of [xBar,yBar].
Note:

Input can be taken in any form, as long as an array is used.
The center of mass can be calculated by the following formula: Center of Mass calculations

In plain English...

To find xBar, multiply each mass by its respective x coordinate, sum the resulting list, and divide it by the sum of all masses.
To find yBar, multiply each mass by its respective y coordinate, sum the resulting list, and divide it by the sum of all masses.
Trivial Python 2.7 example:

def center(coord, mass):
    sumMass = float(reduce(lambda a, b: a+b, mass))
    momentX = reduce(lambda m, x: m+x, (a*b for a, b in zip(mass, zip(*coord)[0])))
    momentY = reduce(lambda m, y: m+y, (a*b for a, b in zip(mass, zip(*coord)[1])))
    xBar = momentX / sumMass
    yBar = momentY / sumMass
    return [xBar, yBar]
Test Cases:

> center([[0, 2], [3, 4], [0, 1], [1, 1]], [2, 6, 2, 10])
[1.4, 2.0]

> center([[3, 1], [0, 0], [1, 4]], [2, 4, 1])
[1.0, 0.8571428571428571]
This is code-golf, so the least number of bytes wins!

*/

#include <assert.h>
#include <stdio.h>
#include <math.h>

#define nelem(x) (sizeof(x) / sizeof(x[0]))

typedef struct {
	double x, y;
} Point;

Point
ctm(Point *p, double *m, size_t n)
{
	size_t i;
	double t;
	Point c;

	c.x = c.y = t = 0;
	for (i = 0; i < n; i++) {
		c.x += (m[i] * p[i].x);
		c.y += (m[i] * p[i].y);
		t += m[i];
	}
	c.x /= t;
	c.y /= t;

	return c;
}

void
test(Point *p, double *m, size_t n, Point r)
{
	static const double eps = 1e-6;
	Point c;

	c = ctm(p, m, n);
	assert(fabs(c.x - r.x) < eps);
	assert(fabs(c.y - r.y) < eps);
}

int
main(void)
{
	Point p1[] = {{0, 2}, {3, 4}, {0, 1}, {1, 1}};
	double m1[] = {2, 6, 2, 10};
	Point r1 = {1.4, 2.0};

	Point p2[] = {{3, 1}, {0, 0}, {1, 4}};
	double m2[] = {2, 4, 1};
	Point r2 = {1.0, 0.8571428571428571};

	test(p1, m1, nelem(p1), r1);
	test(p2, m2, nelem(p2), r2);

	return 0;
}
