/*

Create a Circle() constructor that takes the radius as a single argument and has the following properties and methods:

    .radius
    .diameter
    .getC() (get circumference)
    .getA() (get area)

Instantiate this constructor with two circles:

    c1 has radius 3
    c2 has radius 5

For example, if I used the Circle constructor to instantiate a new instance called c0 with a radius of 1, I would have:
Examples

c0.radius ➞ 1

c0.diameter ➞ 2

c0.getC() ➞ 6.28

c0.getA() ➞ 3.14

Notes

    Circumference: 2πr. Area: πr^2.
    Use Math.PI for calculating circumference and area.
    Round the perimeter and area results to the nearest hundredths place.

*/

#define _GNU_SOURCE
#include <assert.h>
#include <stdio.h>
#include <math.h>

typedef struct Circle Circle;

struct Circle {
	double r;
	double (*radius)(Circle *);
	double (*diameter)(Circle *);
	double (*circumference)(Circle *);
	double (*area)(Circle *);
};

double
radius(Circle *c)
{
	return c->r;
}

double
diameter(Circle *c)
{
	return c->r * 2;
}

double
circumference(Circle *c)
{
	return c->r * 2 * M_PI;
}

double
area(Circle *c)
{
	return c->r * c->r * M_PI;
}

void
newcircle(Circle *c, double r)
{
	c->r = r;
	c->radius = radius;
	c->diameter = diameter;
	c->circumference = circumference;
	c->area = area;
}

void
eq(double x, double y)
{
	assert(fabs(x - y) < 1e-2);
}

int
main(void)
{
	Circle c0[1], c1[1], c2[1];

	newcircle(c0, 1);
	newcircle(c1, 3);
	newcircle(c2, 5);

	eq(c0->radius(c0), 1);
	eq(c0->diameter(c0), 2);
	eq(c0->circumference(c0), 6.28);
	eq(c0->area(c0), 3.14);

	eq(c1->radius(c1), 3);
	eq(c1->diameter(c1), 6);
	eq(c1->circumference(c1), 18.85);
	eq(c1->area(c1), 28.27);

	eq(c2->radius(c2), 5);
	eq(c2->diameter(c2), 10);
	eq(c2->circumference(c2), 31.42);
	eq(c2->area(c2), 78.54);

	return 0;
}
