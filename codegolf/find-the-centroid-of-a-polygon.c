/*

From Wikipedia:

The centroid of a non-self-intersecting closed polygon defined by n vertices (x0,y0), (x1,y1), ..., (xn﻿−﻿1,yn−1) is the point (Cx, Cy), where

Formula for Centroid

and where A is the polygon's signed area,

Formula for Area of Polygon

In these formulas, the vertices are assumed to be numbered in order of their occurrence along the polygon's perimeter.
Furthermore, the vertex ( xn, yn ) is assumed to be the same as ( x0, y0 ), meaning i + 1 on the last case must loop around to i = 0.
Note that if the points are numbered in clockwise order the area A, computed as above, will have a negative sign; but the centroid coordinates will be correct even in this case.

Given a list of vertices in order (either clockwise, or counter-clockwise), find the centroid of the non-self-intersecting closed polygon represented by the vertices.
If it helps, you may assume input to be only CW, or only CCW. Say so in your answer if you require this.
The coordinates are not required to be integers, and may contain negative numbers.
Input will always be valid and contain at least three vertices.
Inputs only need to be handled that fit in your language's native floating point data type.
You may assume that input numbers will always contain a decimal point.
You may assume that input integers end in . or .0.
You may use complex numbers for input.
Output should be accurate to the nearest thousandth.

Examples
[(0.,0.), (1.,0.), (1.,1.), (0.,1.)]        -> (0.5, 0.5)
[(-15.21,0.8), (10.1,-0.3), (-0.07,23.55)]  -> -1.727 8.017
[(-39.00,-55.94), (-56.08,-4.73), (-72.64,12.12), (-31.04,53.58), (-30.36,28.29), (17.96,59.17), (0.00,0.00), (10.00,0.00), (20.00,0.00), (148.63,114.32), (8.06,-41.04), (-41.25,34.43)]   -> 5.80104769975, 15.0673812762
Too see each polygon on a coordinate plane, paste the coordinates without the square brackets in the "Edit" menu of this page.

I confirmed my results using this Polygon Centroid Point Calculator, which is awful.
I couldn't find one that you can input all vertices at once, or that didn't try to erase your - sign when you type it first.
I'll post my Python solution for your use after people have had a chance to answer.

code-golf

*/

#include <assert.h>
#include <stdio.h>
#include <math.h>

#define nelem(x) (sizeof(x) / sizeof(x[0]))

typedef struct {
	double x, y;
} Point;

Point
centroid(Point *p, size_t n)
{
	size_t i, j;
	double a, d;
	Point c;

	c.x = c.y = a = 0;
	for (i = 0; i < n; i++) {
		j = (i + 1) % n;
		d = (p[i].x * p[j].y) - (p[j].x * p[i].y);

		c.x += (p[i].x + p[j].x) * d;
		c.y += (p[i].y + p[j].y) * d;
		a += d;
	}
	a *= 0.5;
	c.x /= (6 * a);
	c.y /= (6 * a);
	return c;
}

void
test(Point *p, size_t n, Point r)
{
	static const double eps = 1e-3;

	Point c;

	c = centroid(p, n);
	printf("%.3f %.3f\n", c.x, c.y);
	assert(fabs(c.x - r.x) < eps);
	assert(fabs(c.y - r.y) < eps);
}

int
main(void)
{
	Point p1[] = {
	    {0, 0},
	    {1, 0},
	    {1, 1},
	    {0, 1},
	};
	Point r1 = {0.5, 0.5};

	Point p2[] = {
	    {-15.21, 0.8},
	    {10.1, -0.3},
	    {-0.07, 23.55},
	};
	Point r2 = {-1.727, 8.017};

	Point p3[] = {
	    {-39, -55.94},
	    {-56.08, -4.73},
	    {-72.64, 12.12},
	    {-31.04, 53.58},
	    {-30.36, 28.29},
	    {17.96, 59.17},
	    {0.00, 0.00},
	    {10.00, 0.00},
	    {20.00, 0.00},
	    {148.63, 114.32},
	    {8.06, -41.04},
	    {-41.25, 34.43},
	};
	Point r3 = {5.80104769975, 15.0673812762};

	test(p1, nelem(p1), r1);
	test(p2, nelem(p2), r2);
	test(p3, nelem(p3), r3);

	return 0;
}
