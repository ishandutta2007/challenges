/*

A point on the screen (pt1) wants to move a certain distance (dist) closer to another point on the screen (pt2) The function has three arguments, two of which are objects with x & y values,
and the third being the distance, e.g. {x:50, y:60}, {x: 100, y: 100}, 10. The expected result is a similar object with the new co-ordinate.

Notes

    The returned x & y values should be rounded to the closest integer
    If the distance between the two points is less than distance wanting to be traveled,
	then the returned co-ordinate should overshoot the mark, e.g. {x: 50, y: 0}, {x: 70, y: 0}, 30) ➞ {x: 80, y: 0}.

*/

#include <stdio.h>
#include <math.h>

typedef struct {
	double x, y;
} Point;

Point
add(Point p, Point q)
{
	return (Point){ p.x + q.x, p.y + q.y };
}

Point
sub(Point p, Point q)
{
	return (Point){ p.x - q.x, p.y - q.y };
}

Point
scale(Point p, double s)
{
	return (Point){ p.x * s, p.y * s };
}

double
length(Point p)
{
	return hypot(p.x, p.y);
}

Point
normalize(Point p)
{
	double l;

	l = length(p);
	if (l == 0)
		return (Point){ 0, 0 };
	return (Point){ p.x / l, p.y / l };
}

Point
rnd(Point p)
{
	return (Point){ round(p.x), round(p.y) };
}

Point
nextpos(Point p, Point q, double l)
{
	return rnd(add(p, scale(normalize(sub(q, p)), l)));
}

void
test(Point p, Point q, double l)
{
	Point n;

	n = nextpos(p, q, l);
	printf("(%.0f,%.0f)\n", n.x, n.y);
}

int
main(void)
{
	test((Point){ 0, 0 }, (Point){ 100, 0 }, 10);
	test((Point){ 50, 60 }, (Point){ 100, 100 }, 10);
	test((Point){ 0, 0 }, (Point){ 100, 100 }, 10);
	test((Point){ 250, 10 }, (Point){ -20, 35 }, 55);
	test((Point){ 50, 0 }, (Point){ 70, 0 }, 30);
	return 0;
}
