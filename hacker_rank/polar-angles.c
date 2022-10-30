/*

A point (x,y), on the cartesian plane, makes an angle theta with the positive direction of the x-axis.
Theta varies in the interval [0 ,2PI) radians, i.e, greater than or equal to zero; but less than 2*PI radians.

For example, the polar angle of the point (1,2) as marked in this plane below,
is (approximately) 63.4 degrees (multiply by PI/180 to convert to radians)

Given a list of points in the 2D plane, sort them in ascending order of their polar angle.
In case multiple points share exactly the same polar angle, the one with lesser distance
from the origin (0,0) should occur earlier in the sorted list.

*/

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define nelem(x) (sizeof(x) / sizeof(x[0]))

typedef struct {
	int x, y;
} Point;

double
angle(Point p)
{
	double d;

	d = atan2(p.y, p.x) * 180 / M_PI;
	if (d < 0)
		d += 360;
	return d;
}

int
cmp(const void *a, const void *b)
{
	const double eps = 1e-4;
	Point *p, *q;
	double x, y;

	p = (Point *)a;
	q = (Point *)b;

	if (p->x == q->x && p->y == q->y)
		return 0;

	x = angle(*p);
	y = angle(*q);
	if (fabs(x - y) <= eps) {
		x = hypot(p->x, p->y);
		y = hypot(q->x, q->y);
	}
	if (fabs(x - y) <= eps)
		return 0;

	if (x < y)
		return -1;
	return 1;
}

void
printsorted(Point *p, size_t n)
{
	size_t i;

	qsort(p, n, sizeof(*p), cmp);
	for (i = 0; i < n; i++)
		printf("%d %d\n", p[i].x, p[i].y);
}

int
main(void)
{
	Point a[] = {
	    {1, 0},
	    {0, 1},
	    {-1, 0},
	    {0, -1},
	};
	printsorted(a, nelem(a));

	Point b[] = {
	    {-25, -99},
	    {37, -100},
	    {-80, 4},
	    {-83, 11},
	    {12, -28},
	};
	printsorted(b, nelem(b));

	return 0;
}
