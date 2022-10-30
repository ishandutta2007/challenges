/*

Happy Pi Day everyone! For no reason at all, I'm trying to construct a Monte Carlo estimator of Pi that is as short as possible. Can we construct one that can fit in a tweet?

To clarify, what I have in mind is the typical approach of drawing random points from the unit square and calculating the ratio that fall within the unit circle.
The number of samples can be hard coded or not. If you hardcode them, you must use at least 1000 samples.
The result may be returned or printed as a floating point, fixed point or rational number.

No trig functions or Pi constants, must be a Monte Carlo approach.

This is code golf, so the shortest submission (in bytes) wins.

*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

double
drand(void)
{
	return rand() * 1.0 / RAND_MAX;
}

double
mcpi(unsigned long n)
{
	unsigned long i, c;
	double x, y, d;

	c = 0;
	for (i = 0; i < n; i++) {
		x = drand();
		y = drand();
		d = (x * x) + (y * y);
		if (d <= 1)
			c++;
	}
	return (4.0 * c) / n;
}

int
main(void)
{
	srand(time(NULL));

	printf("%f\n", mcpi(10000000ul));
	return 0;
}
