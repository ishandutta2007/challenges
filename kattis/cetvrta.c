/*

Mirko needs to choose four points in the plane so that they form a rectangle with sides parallel to the axes.
He has already chosen three points and is confident that he hasn’t made a mistake, but is having trouble locating the last point.
Help him.

Input

Each of the three points already chosen will be given on a separate line. All coordinates will be integers between 1 and 1000.

Output

Output the coordinates of the fourth vertex of the rectangle.

*/

#include <assert.h>
#include <stdio.h>

typedef struct {
	int x, y;
} Point;

int
outlier(int a, int b, int c)
{
	if (a == b)
		return c;
	if (b == c)
		return a;
	return b;
}

Point
coordinate(Point a, Point b, Point c)
{
	return (Point){
	    .x = outlier(a.x, b.x, c.x),
	    .y = outlier(a.y, b.y, c.y),
	};
}

void
test(Point a, Point b, Point c, Point r)
{
	Point d;

	d = coordinate(a, b, c);
	assert(d.x == r.x);
	assert(d.y == r.y);
}

int
main(void)
{
	test((Point){5, 5}, (Point){5, 7}, (Point){7, 5}, (Point){7, 7});
	test((Point){30, 20}, (Point){10, 10}, (Point){10, 20}, (Point){30, 10});
	return 0;
}
