/*

We have a list of points on the plane.  Find the K closest points to the origin (0, 0).

(Here, the distance between two points on a plane is the Euclidean distance.)

You may return the answer in any order.  The answer is guaranteed to be unique (except for the order that it is in.)

Example 1:

Input: points = [[1,3],[-2,2]], K = 1
Output: [[-2,2]]
Explanation: 
The distance between (1, 3) and the origin is sqrt(10).
The distance between (-2, 2) and the origin is sqrt(8).
Since sqrt(8) < sqrt(10), (-2, 2) is closer to the origin.
We only want the closest K = 1 points from the origin, so the answer is just [[-2,2]].

Example 2:

Input: points = [[3,3],[5,-1],[-2,4]], K = 2
Output: [[3,3],[-2,4]]
(The answer [[-2,4],[3,3]] would also be accepted.)

Note:

1 <= K <= points.length <= 10000
-10000 < points[i][0] < 10000
-10000 < points[i][1] < 10000

*/

#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

typedef struct {
	int x, y;
} Point;

#define nelem(x) (sizeof(x) / sizeof(x[0]))

int
cmp(const void *a, const void *b)
{
	const Point *p, *q;
	int u, v;

	p = a;
	q = b;
	u = p->x * p->x + p->y * p->y;
	v = q->x * q->x + q->y * q->y;
	if (u < v)
		return -1;
	if (u > v)
		return 1;

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

Point *
kclosest(Point *p, size_t n, size_t k)
{
	Point *r;

	r = calloc(n, sizeof(*r));
	if (!r)
		return NULL;
	memcpy(r, p, sizeof(*p) * n);
	qsort(r, n, sizeof(*r), cmp);
	return r;

	(void)k;
}

void
test(Point *p, size_t np, Point *r, size_t nr)
{
	Point *q;

	q = kclosest(p, np, nr);
	assert(q && !memcmp(q, r, nr * sizeof(*r)));
	free(q);
}

int
main(void)
{
	Point p1[] = {
	    {1, 3},
	    {-2, 2},
	};
	Point r1[] = {
	    {-2, 2},
	};

	Point p2[] = {
	    {3, 3},
	    {5, -1},
	    {-2, 4},
	};
	Point r2[] = {
	    {3, 3},
	    {-2, 4},
	};

	test(p1, nelem(p1), r1, nelem(r1));
	test(p2, nelem(p2), r2, nelem(r2));

	return 0;
}
