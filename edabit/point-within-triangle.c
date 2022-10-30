/*

Create a function that takes four integer arrays of 2 elements. The first three are (x, y) coordinates of three corners of a triangle.
Return True if the fourth array — the (x, y) coordinates of a test point — lies within the triangle, False if it doesn't.

Examples

WithinTriangle((1, 4), (5, 6), (6, 1), (4, 5)) ➞ True

WithinTriangle((1, 4), (5, 6), (6, 1), (3, 2)) ➞ False

WithinTriangle((-6, 2), (-2, -2), (8, 4), (4, 2)) ➞ True

*/

#include <assert.h>
#include <stdbool.h>
#include <stdio.h>

typedef struct {
	int x, y;
} Point;

int
sign(Point a, Point b, Point c)
{
	return (a.x - c.x) * (b.y - c.y) - (b.x - c.x) * (a.y - c.y);
}

bool
intri(Point p[4])
{
	bool b1, b2, b3;

	b1 = sign(p[3], p[0], p[1]) < 0;
	b2 = sign(p[3], p[1], p[2]) < 0;
	b3 = sign(p[3], p[2], p[0]) < 0;
	return b1 == b2 && b2 == b3;
}

int
main(void)
{
	Point p1[] = {
	    {1, 4},
	    {5, 6},
	    {6, 1},
	    {4, 5},
	};

	Point p2[] = {
	    {1, 4},
	    {5, 6},
	    {6, 1},
	    {3, 2},
	};

	Point p3[] = {
	    {1, 7},
	    {2, 4},
	    {9, 3},
	    {2, 6},
	};

	Point p4[] = {
	    {1, 7},
	    {2, 4},
	    {9, 3},
	    {6, 5},
	};

	Point p5[] = {
	    {-2, 6},
	    {12, -3},
	    {1, 7},
	    {9, -1},
	};

	Point p6[] = {
	    {-2, 6},
	    {12, -3},
	    {1, 7},
	    {4, 2},
	};

	Point p7[] = {
	    {-6, 2},
	    {-2, -2},
	    {8, 4},
	    {4, 2},
	};

	Point p8[] = {
	    {-6, 2},
	    {-2, -2},
	    {8, 4},
	    {0, -4},
	};

	assert(intri(p1) == true);
	assert(intri(p2) == false);
	assert(intri(p3) == true);
	assert(intri(p4) == false);
	assert(intri(p5) == true);
	assert(intri(p6) == false);
	assert(intri(p7) == true);
	assert(intri(p8) == false);

	return 0;
}
