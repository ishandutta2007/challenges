/*

Description

In this challenge, you will be given a set of circles, defined by their centers and radii. Your goal is to find the bounding rectangle which will contain all of the circles completely.

Write a program that determines the vertices of the bounding rectangle with sides parallel to the axes.
Input Description

Each line will contain a comma separated center and radius for a circle.
Output Description

The format of the output will be comma separated coordinates, rounded to 3 decimal places.
Challenge Input

1,1,2
2,2,0.5
-1,-3,2
5,2,1

input picture
Challenge Output

(-3.000, -5.000), (-3.000, 3.000), (6.000, 3.000), (6.000, -5.000)

output picture
Bonus

For the bonus, we will rotate the axis for the bounding rectangle. The first line of input will now be a vector determining the direction of one edge of the bounding rectangle.
Bonus Input

1,1
1,1,2
2,2,0.5
-1,-3,2
5,2,1

Bonus Output

(-4.828, -2.000), (2.793, 5.621), (6.621, 1.793), (-1.000, -5.828)

bonus output picture
Credit

This challenge was suggested by user /u/Preferencesoft, many thanks! If you have an idea for a challenge please share it on /r/dailyprogrammer_ideas and there's a good chance we'll use it.

*/

#include <assert.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>

#define nelem(x) (sizeof(x) / sizeof(x[0]))

typedef struct {
	double x, y;
} Point;

typedef struct {
	double x, y, r;
} Circle;

typedef struct {
	double x0, y0;
	double x1, y1;
} Rect;

int
pcmp(const void *a, const void *b)
{
	const Point *p, *q;

	p = a;
	q = b;
	if (p->x < q->x)
		return -1;
	if (p->x > q->x)
		return 1;
	if (p->y < q->y)
		return -1;
	if (p->y > q->y)
		return 1;
	return 0;
}

void
r2p(Rect r, Point p[4])
{
	double dx, dy;

	dx = r.x1 - r.x0;
	dy = r.y1 - r.y0;
	p[0] = (Point){r.x0, r.y0};
	p[1] = (Point){r.x0 + dx, r.y0};
	p[2] = (Point){r.x0, r.y0 + dy};
	p[3] = (Point){r.x0 + dx, r.y0 + dy};
}

void
printrect(Rect r)
{
	Point p[4];
	size_t i;

	r2p(r, p);
	for (i = 0; i < 4; i++)
		printf("(%.3f, %.3f) ", p[i].x, p[i].y);
	printf("\n");
}

Rect
bounds(Circle c)
{
	return (Rect){
	    .x0 = c.x - c.r,
	    .y0 = c.y - c.r,
	    .x1 = c.x + c.r,
	    .y1 = c.y + c.r,
	};
}

int
empty(Rect r)
{
	return r.x0 >= r.x1 || r.y0 >= r.y1;
}

Rect
unions(Rect r, Rect s)
{
	if (empty(r))
		return s;
	if (empty(s))
		return r;

	if (r.x0 >= s.x0)
		r.x0 = s.x0;
	if (r.y0 >= s.y0)
		r.y0 = s.y0;

	if (r.x1 < s.x1)
		r.x1 = s.x1;
	if (r.x1 < s.y1)
		r.y1 = s.y1;

	return r;
}

Rect
surround(Circle *c, size_t n)
{
	size_t i;
	Rect r;

	memset(&r, 0, sizeof(r));
	for (i = 0; i < n; i++)
		r = unions(r, bounds(c[i]));
	return r;
}

void
test(Circle *c, size_t n, Point p[4])
{
	static const double eps = 1e-3;

	Rect r;
	Point q[4];
	size_t i;

	r = surround(c, n);
	r2p(r, q);

	qsort(p, 4, sizeof(*p), pcmp);
	qsort(q, 4, sizeof(*q), pcmp);

	printrect(r);
	for (i = 0; i < 4; i++) {
		assert(fabs(p[i].x - q[i].x) < eps);
		assert(fabs(p[i].y - q[i].y) < eps);
	}
}

int
main(void)
{
	Circle c1[] = {
	    {1, 1, 2},
	    {2, 2, 0.5},
	    {-1, -3, 2},
	    {5, 2, 1},
	};
	Point p1[] = {{-3, -5}, {-3, 3}, {6, 3}, {6, -5}};

	test(c1, nelem(c1), p1);

	return 0;
}
