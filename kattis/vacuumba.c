/*

You are developing software for a new generation of robotic floor vacuums.
Being an inexpensive, mass market robot, this device has a fairly simple way of navigating around the room.
It can turn by some angle to the left or right and then move forward in a straight line.
A plan for the robot consists of a sequence of these straight-line segments.
The robot starts at the origin, facing in the positive Y direction.
Your job is to try to predict where the robot will be after following a plan.

Input

Input consists of several test cases. The first line contains an integer 1≤n≤25 telling how many.
Each of the following test cases begins with an integer, 1≤m≤10, giving the number of segments in the robot’s plan.
This is followed by m lines, each describing a segment in the plan.
Each segment is described by a pair of real numbers, a rotation angle in degrees followed by a distance.
The angle is in the range [−360,360] and the distance is in the range [−100,100].
The rotation angle tells how much the robot should turn before moving forward the given distance.
A positive rotation angle indicates a counter-clockwise turn. A negative angle indicates a clockwise turn.
All real numbers have at most 8 digits past the decimal.

Output

For each test case, print out the expected XY location of the robot after following the path.
Your answer should be accurate to within 10^-3 for each coordinate.

*/

#define _GNU_SOURCE
#include <assert.h>
#include <stdio.h>
#include <math.h>

#define nelem(x) (sizeof(x) / sizeof(x[0]))
#define deg2rad(x) ((x)*M_PI / 180)

typedef struct {
	double x, y;
} Point;

Point
location(double a[][2], size_t n)
{
	double x, y, t;
	size_t i;

	x = y = 0;
	t = M_PI / 2;
	for (i = 0; i < n; i++) {
		t += deg2rad(a[i][0]);
		x += a[i][1] * cos(t);
		y += a[i][1] * sin(t);
	}
	return (Point){x, y};
}

void
test(double a[][2], size_t n, Point r)
{
	static const double eps = 1e-6;
	Point p;

	p = location(a, n);
	printf("%f %f\n", p.x, p.y);
	assert(fabs(p.x - r.x) < eps);
	assert(fabs(p.y - r.y) < eps);
}

int
main(void)
{
	double a1[][2] = {
	    {0, 10.5},
	    {90, 5},
	};
	double a2[][2] = {
	    {-45, 10},
	};

	test(a1, nelem(a1), (Point){-5.000000, 10.500000});
	test(a2, nelem(a2), (Point){7.071068, 7.071068});
	return 0;
}
