/*

Given the radius and x-y positions of the center of a circle, write a function randPoint which generates a uniform random point in the circle.

Note:

    input and output values are in floating-point.
    radius and x-y position of the center of the circle is passed into the class constructor.
    a point on the circumference of the circle is considered to be in the circle.
    randPoint returns a size 2 array containing x-position and y-position of the random point, in that order.

*/

#define _GNU_SOURCE
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

typedef struct {
	double x, y;
} Point;

// https://stackoverflow.com/questions/5837572/generate-a-random-point-within-a-circle-uniformly
Point
randpoint(Point p, double r)
{
	double rad, phi;

	rad = r * sqrt(drand48());
	phi = drand48() * 2 * M_PI;
	return (Point){p.x + rad * cos(phi), p.y + rad * sin(phi)};
}

int
main(void)
{
	Point p;
	size_t i;

	srand48(time(NULL));
	for (i = 0; i < 4; i++) {
		p = randpoint((Point){0, 0}, 1);
		printf("%lf %lf\n", p.x, p.y);
	}

	for (i = 0; i < 4; i++) {
		p = randpoint((Point){5, -7.5}, 10);
		printf("%lf %lf\n", p.x, p.y);
	}
	return 0;
}
