/*

You are given an array coordinates, coordinates[i] = [x, y], where [x, y] represents the coordinate of a point. Check if these points make a straight line in the XY plane.

Constraints:

2 <= coordinates.length <= 1000
coordinates[i].length == 2
-10^4 <= coordinates[i][0], coordinates[i][1] <= 10^4
coordinates contains no duplicate point.

*/

#include <stdio.h>

#define nelem(x) (sizeof(x) / sizeof(x[0]))

typedef struct {
	int x, y;
} Point;

int
collinear(Point a, Point b, Point c)
{
	return (b.x - a.x) * (c.y - a.y) - (b.y - a.y) * (c.x - a.x) == 0;
}

int
straightline(Point *p, size_t n)
{
	size_t i;

	if (n < 2)
		return 0;
	if (n == 2)
		return 1;

	for (i = 2; i < n; i++) {
		if (!collinear(p[0], p[1], p[i]))
			return 0;
	}
	return 1;
}

int
main(void)
{
	Point p1[] = {{1, 2}, {2, 3}, {3, 4}, {4, 5}, {5, 6}, {6, 7}};
	Point p2[] = {{1, 1}, {2, 2}, {3, 4}, {4, 5}, {5, 6}, {7, 7}};
	printf("%d\n", straightline(p1, nelem(p1)));
	printf("%d\n", straightline(p2, nelem(p2)));

	Point p3[1024];
	for (size_t i = 0; i < nelem(p3); i++)
		p3[i] = (Point){i, 7 * i + 4};
	printf("%d\n", straightline(p3, nelem(p3)));
	p3[0].y = -204;
	printf("%d\n", straightline(p3, nelem(p3)));

	return 0;
}
