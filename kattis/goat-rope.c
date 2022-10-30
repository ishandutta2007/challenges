/*

You have a fence post located at the point (x,y) in the plane, to which a goat is tethered by a rope.
You also have a house, which you model as an axis-aligned rectangle with diagonally opposite corners at the points (x1,y1) and (x2,y2).
You want to pick a length of rope that guarantees the goat cannot reach the house.

Determine the minimum distance from the fence post to the house, so that you can make sure to use a shorter rope.

Input

The input consists of a single line containing six space-separated integers x, y, x1, y1, x2, and y2, each in the range [−999,999].

It is guaranteed that x1<x2 and y1<y2, and that (x,y) is strictly outside the axis-aligned rectangle with corners at (x1,y1) and (x2,y2).

Output

Print the minimum distance from the goat’s post to the house, with a relative or absolute error no more than 0.001.

*/

#include <assert.h>
#include <stdio.h>
#include <math.h>

double
distance(double x, double y, double x1, double y1, double x2, double y2)
{
	double dx, dy;
	double cx, cy;
	double hw, hh;

	hw = (x2 - x1) / 2.0;
	hh = (y2 - y1) / 2.0;

	cx = (x1 + x2) / 2.0;
	cy = (y1 + y2) / 2.0;

	dx = fmax(fabs(x - cx) - hw, 0);
	dy = fmax(fabs(y - cy) - hh, 0);

	return hypot(dx, dy);
}

void
test(double x, double y, double x1, double y1, double x2, double y2, double r)
{
	double p;

	p = distance(x, y, x1, y1, x2, y2);
	printf("%.3f\n", p);
	assert(fabs(p - r) < 1e-3);
}

int
main(void)
{
	test(7, 3, 0, 0, 5, 4, 2.0);
	test(6, 0, 0, 2, 7, 6, 2.0);
	test(3, -4, -3, -1, -1, 2, 5.0);

	return 0;
}
