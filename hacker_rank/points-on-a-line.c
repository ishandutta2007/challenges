/*

Given  two-dimensional points in space, determine whether they lie on some vertical or horizontal line.
If yes, print YES; otherwise, print NO.

*/

#include <stdio.h>

#define nelem(x) (sizeof(x) / sizeof(x[0]))

typedef struct {
	int x, y;
} Point;

const char *
onlinehv(Point *p, size_t n)
{
	size_t i;
	int v, h;

	if (n == 0)
		return "NO";

	v = h = 1;
	for (i = 0; i < n - 1; i++) {
		if (p[i].x != p[i + 1].x)
			h = 0;
		if (p[i].y != p[i + 1].y)
			v = 0;

		if (v == 0 && h == 0)
			return "NO";
	}
	return "YES";
}

int
main(void)
{
	Point a[] = {
	    {0, 1},
	    {0, 2},
	    {0, 3},
	    {0, 4},
	    {0, 5},
	};
	printf("%s\n", onlinehv(a, nelem(a)));

	Point b[] = {
	    {0, 1},
	    {0, 2},
	    {1, 3},
	    {0, 4},
	    {0, 5},
	};
	printf("%s\n", onlinehv(b, nelem(b)));

	Point c[] = {
	    {1, 12},
	    {2, 12},
	    {3, 12},
	    {4, 12},
	};
	printf("%s\n", onlinehv(c, nelem(c)));

	return 0;
}
