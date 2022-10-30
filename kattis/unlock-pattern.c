/*

Mobile phones may require passcodes to unlock, but people sometimes forget their passcodes.
An alternative is the 9-pivot unlock pattern. Some people find such a graphical pattern easier to remember than a sequence of digits.
Formally, an unlock pattern is a single stroke that visits each of the nine pivots exactly once.
The pattern may start at any pivot. It may pass a pivot multiple times but only the first time counts as a visit.
The phone unlocks if the pivots are visited in a predefined secret order.

A pattern is more complex if the total length of the stroke is longer.
Given an unlock pattern, can you calculate its length?
We assume that the pivots are aligned on a unit grid, and the stroke moves in a straight line between two consecutive pivots.

The sample input corresponds to the unlock pattern in the image.

Input

The input has three lines.
Each line has three non-zero digits separated by a single space.
The digits describe the order in which the pivots are visited.
Every digit from 1 to 9 appears exactly once.

Output

Output the total length of the unlock pattern. Your answer is considered correct if it has an absolute or relative error of at most 10e-6 from the correct answer.

*/

#include <assert.h>
#include <stdio.h>
#include <string.h>
#include <math.h>

typedef struct {
	int x, y;
} Point;

double
distance(Point *p, Point *q)
{
	return hypot(p->x - q->x, p->y - q->y);
}

double
path(int a[3][3])
{
	Point p[9];
	double d;
	int i, x, y;

	memset(p, 0, sizeof(p));
	for (y = 0; y < 3; y++) {
		for (x = 0; x < 3; x++) {
			i = a[y][x] - 1;
			if (i < 0 || i >= 9)
				return -1;

			p[i] = (Point){x, y};
		}
	}

	d = 0;
	for (i = 0; i < 8; i++)
		d += distance(p + i, p + i + 1);

	return d;
}

void
test(int a[3][3], double r)
{
	double p;

	p = path(a);
	printf("%f\n", p);
	assert(fabs(p - r) < 1e-6);
}

int
main(void)
{
	int a1[3][3] = {
	    {6, 1, 9},
	    {5, 2, 8},
	    {4, 3, 7},
	};

	test(a1, 9.8284271247);

	return 0;
}
