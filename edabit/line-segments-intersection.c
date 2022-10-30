/*

Write a function that takes coordinates of four points (A, B, C, D) on a two-dimensional plane and returns true if the segment AB intersects segment CD.

Examples

intersection(arr[0]={2, 4}, arr[1]={5, 1}, arr[2]={4, 1}, arr[3]={4, 4}) ➞ true

intersection(arr[0]={1, 2}, arr[1]={3, 4}, arr[2]={5, 6}, arr[3]={7, 8}) ➞ false

intersection(arr[0]={1, 1}, arr[1]={1, 7}, arr[2]={-3, 3}, arr[3]={6, 3}) ➞ true

Notes

    The given points always create two line segments.
    The order of the given numbers is X, Y.
    The numbers in the argument array can be positive or negative.
    This challenge isn't easy, but don't give up!

Check my profile for other challenges in the series.

*/

#include <assert.h>
#include <stdbool.h>
#include <stdio.h>

typedef struct {
	int x, y;
} Point;

bool
intersection(Point p[4])
{
	int x1, x2, x3, x4;
	int y1, y2, y3, y4;
	int d, x, y;

	x1 = p[0].x;
	x2 = p[1].x;
	x3 = p[2].x;
	x4 = p[3].x;

	y1 = p[0].y;
	y2 = p[1].y;
	y3 = p[2].y;
	y4 = p[3].y;

	// consider only integer coordinates for intersection
	x = (x1 * y2 - y1 * x2) * (x3 - x4) - (x1 - x2) * (x3 * y4 - y3 * x4);
	y = (x1 * y2 - y1 * x2) * (y3 - y4) - (y1 - y2) * (x3 * y4 - y3 * x4);
	d = (x1 - x2) * (y3 - y4) - (y1 - y2) * (x3 - x4);
	return d != 0 && x % d == 0 && y % d == 0;
}

int
main(void)
{
	Point p1[] = {
	    {2, 4},
	    {5, 1},
	    {4, 1},
	    {4, 4},
	};
	Point p2[] = {
	    {1, 1},
	    {5, 5},
	    {5, 1},
	    {1, 5},
	};
	Point p3[] = {
	    {-7, 1},
	    {-3, 22},
	    {1, 1},
	    {-30, -10},
	};
	Point p4[] = {
	    {0, 0},
	    {-10, -10},
	    {3, -3},
	    {-3, 3},
	};
	Point p5[] = {
	    {0, 1},
	    {3, 6},
	    {1, 1},
	    {5, 5},
	};
	Point p6[] = {
	    {2, 1},
	    {2, 7},
	    {-1, 3},
	    {6, 3},
	};
	Point p7[] = {
	    {1, 2},
	    {3, 4},
	    {5, 6},
	    {7, 8},
	};
	Point p8[] = {
	    {1, 1},
	    {1, 7},
	    {-3, 3},
	    {6, 3},
	};

	assert(intersection(p1) == true);
	assert(intersection(p2) == true);
	assert(intersection(p3) == false);
	assert(intersection(p4) == true);
	assert(intersection(p5) == false);
	assert(intersection(p6) == true);
	assert(intersection(p7) == false);
	assert(intersection(p8) == true);

	return 0;
}
