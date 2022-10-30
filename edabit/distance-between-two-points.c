/*

In this challenge, you have to find the distance between two points placed on a Cartesian plane.
Knowing the coordinates of both the points, you have to apply the Pythagorean theorem to find the distance between them.

Two points on a Cartesian plane

Given two object literals a and b being the two points coordinates (x and y), implement a function that returns the distance between the points, rounded to the nearest thousandth.

Notes

    Take a look at the Resources tab if you need a refresher on the geometry related to this challenge.
    The "distance" is the shortest distance between the two points, or the straight line generated from a to b.

*/

#include <stdio.h>
#include <math.h>

typedef struct {
	double x, y;
} Point;

double
distance(Point a, Point b)
{
	double dx, dy;

	dx = b.x - a.x;
	dy = b.y - a.y;
	return sqrt(dx * dx + dy * dy);
}

int
main(void)
{
	printf("%.3f\n", distance((Point){-2, 1}, (Point){4, 3}));
	printf("%.3f\n", distance((Point){0, 0}, (Point){1, 1}));
	printf("%.3f\n", distance((Point){10, -5}, (Point){8, 16}));
	printf("%.3f\n", distance((Point){4, 3}, (Point){3, -2}));
	printf("%.3f\n", distance((Point){-1, -1}, (Point){10, 10}));
	printf("%.3f\n", distance((Point){100, 100}, (Point){100, 100}));
	printf("%.3f\n", distance((Point){14239, -11222}, (Point){-12301, 12888}));
	return 0;
}
