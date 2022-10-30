/*

This challenge is more about geometry and trig than code-writing, but some may find it interesting.

A circle has a circumference of 100 meters. A regular polygon, let's say a square, inscribed inside this circle has a perimeter of about 90 meters.
As you increase the number of sides of the regular polygon, it's perimeter will become arbitrarily close to 100 meters.

Write a function whose argument is the number of sides of the inscribed regular polygon. The function returns the polygon's perimeter. Round your answer to 3 decimal places.

*/

#define _GNU_SOURCE
#include <stdio.h>
#include <math.h>

double
circle(int n)
{
	double C, r;

	if (n <= 0)
		return 0;

	C = 100;
	r = C / (2 * M_PI);
	return 2 * n * r * sin(M_PI / n);
}

int
main(void)
{
	printf("%.3f\n", circle(3));
	printf("%.3f\n", circle(4));
	printf("%.3f\n", circle(8));
	printf("%.3f\n", circle(12));
	printf("%.3f\n", circle(90));
	printf("%.3f\n", circle(100));
	printf("%.3f\n", circle(600));
	printf("%.3f\n", circle(1000));
	return 0;
}
