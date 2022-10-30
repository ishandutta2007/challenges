/*

Keko has  dots in a 2-D coordinate plane. He wants to measure the gap between the most distant two dots.
To make the problem easier, Keko decided to change each dot's x or y coordinate to zero.

Help Keko calculate the distance!

*/

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <limits.h>

typedef struct {
	int x, y;
} Point;

#define nelem(x) (sizeof(x) / sizeof(x[0]))

#define max(a, b) (((a) > (b)) ? (a) : (b))
#define min(a, b) (((a) < (b)) ? (a) : (b))

double
distant(Point *p, size_t n)
{
	int x0, x1, y0, y1, f;
	double d1, d2, d3;
	size_t i;

	x0 = y0 = INT_MAX;
	x1 = y1 = INT_MIN;
	f = 0;
	for (i = 0; i < n; i++) {
		if (p[i].x != 0 && p[i].y != 0)
			return -1;

		if (p[i].x != 0) {
			x0 = min(x0, p[i].x);
			x1 = max(x1, p[i].x);
			f |= 1;
		}
		if (p[i].y != 0) {
			y0 = min(y0, p[i].y);
			y1 = max(y1, p[i].y);
			f |= 2;
		}
	}

	d1 = d2 = d3 = 0;
	if (f & 1)
		d1 = abs(x1 - x0);
	if (f & 2)
		d2 = abs(y1 - y0);
	if ((f & 3) == 3)
		d3 = hypot(max(abs(x0), abs(x1)), max(abs(y0), abs(y1)));

	return max(d1, max(d2, d3));
}

int
main(void)
{
	Point a[] = {
	    {-1, 0},
	    {1, 0},
	    {0, 1},
	    {0, -1},
	};
	printf("%lf\n", distant(a, nelem(a)));

	Point b[] = {
	    {3, 0},
	    {4, 0},
	    {5, 0},
	};
	printf("%lf\n", distant(b, nelem(b)));

	Point c[] = {
		{3, 0},
		{0, 4},
	};
	printf("%lf\n", distant(c, nelem(c)));

	return 0;
}
