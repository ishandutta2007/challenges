/*

Write a function that takes coordinates of two points on a two-dimensional plane and returns the length of the line segment connecting those two points.
Examples

lineLength([15, 7], [22, 11]) ➞ 8.06

lineLength([0, 0], [0, 0]) ➞ 0

lineLength([0, 0], [1, 1]) ➞ 1.41

Notes

    The order of the given numbers is X, Y.
    This challenge is easier than it looks.
    Round your result to two decimal places.

*/

#include <assert.h>
#include <stdio.h>
#include <string.h>
#include <math.h>

typedef struct {
	int x, y;
} Point;

double
length(Point a, Point b)
{
	return hypot(a.x - b.x, a.y - b.y);
}

void
test(Point a, Point b, double l)
{
	assert(fabs(length(a, b) - l) <= 1e-2);
}

int
main(void)
{
	test((Point){15, 7}, (Point){22, 11}, 8.06);
	test((Point){0, 0}, (Point){0, 0}, 0);
	test((Point){0, 0}, (Point){1, 1}, 1.41);
	test((Point){30, 10}, (Point){13, -5}, 22.67);
	return 0;
}
