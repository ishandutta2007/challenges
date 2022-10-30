/*

Write a function that takes the coordinates of three points in the form of a 2d array and returns the perimeter of the triangle.
The given points are the vertices of a triangle on a two-dimensional plane.

Examples

perimeter( [ [15, 7], [5, 22], [11, 1] ] ) ➞ 47.08

perimeter( [ [0, 0], [0, 1], [1, 0] ] ) ➞ 3.42

perimeter( [ [-10, -10], [10, 10 ], [-10, 10] ] ) ➞ 68.28

Notes

    The given points always create a triangle.
    The numbers in the argument array can be positive or negative.
    Output should have 2 decimal places
    This challenge is easier than it looks.

*/

#include <assert.h>
#include <stdio.h>
#include <math.h>

typedef struct {
	int x, y;
} Point;

Point
sub(Point a, Point b)
{
	return (Point){a.x - b.x, a.y - b.y};
}

double
perimeter(Point p[3])
{
	size_t i;
	double r;
	Point v;

	r = 0;
	for (i = 0; i < 3; i++) {
		v = sub(p[(i + 1) % 3], p[i]);
		r += hypot(v.x, v.y);
	}
	return r;
}

void
test(Point p[3], double r)
{
	assert(fabs(perimeter(p) - r) < 1e-2);
}

int
main(void)
{
	Point p1[] = {{0, 0}, {1, 0}, {0, 1}};
	Point p2[] = {{15, 7}, {5, 22}, {11, 1}};
	Point p3[] = {{7, 6}, {0, 11}, {0, -3}};
	Point p4[] = {{-10, -10}, {10, 10}, {-10, 10}};
	Point p5[] = {{3, 4}, {4, 3}, {4, 5}};
	Point p6[] = {{-10, -20}, {-30, -40}, {-50, -60}};
	Point p7[] = {{382, 894}, {389, 312}, {500, 993}};

	test(p1, 3.41);
	test(p2, 47.08);
	test(p3, 34.00);
	test(p4, 68.28);
	test(p5, 4.83);
	test(p6, 113.14);
	test(p7, 1426.06);

	return 0;
}
