// find point reflection r of point p and q (rotate p around q 180 degree for point r)
#include <stdio.h>

typedef struct Point Point;

struct Point {
	int x, y;
};

Point
reflect(Point p, Point q)
{
	return (Point){
	    -p.x + 2 * q.x,
	    -p.y + 2 * q.y,
	};
}

int
main(void)
{
	Point p = {0, 0};
	Point q = {1, 1};
	Point r = reflect(p, q);
	printf("%d %d\n", r.x, r.y);

	p = (Point){1, 1};
	q = (Point){2, 2};
	r = reflect(p, q);
	printf("%d %d\n", r.x, r.y);
	return 0;
}
