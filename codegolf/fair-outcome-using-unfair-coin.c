/*

I have been thinking a lot about the following puzzle, but could not arrive at a solution.

Can someone explain to me how can you get a fair (equal probability) outcome using only an unfair coin (where unfair means that it will land head with probability p and tails 1-p where p != .5)?

*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef unsigned long long uvlong;

int
toss(double bias)
{
	double r;

	r = rand() * 1.0 / RAND_MAX;
	return r < bias;
}

int
fairize(double bias)
{
	static const uvlong tries = 1000ull;
	uvlong i;
	int x, y;

	for (i = 0; i < tries; i++) {
		x = toss(bias);
		y = toss(bias);
		if (x != y)
			return x;
	}
	return 2;
}

void
sim(double bias, uvlong iters)
{
	uvlong i, r[3];

	r[0] = r[1] = r[2] = 0;
	for (i = 0; i < iters; i++)
		r[fairize(bias)]++;
	printf("%f: %f %f %f\n", bias, r[0] * 1.0 / iters, r[1] * 1.0 / iters, r[2] * 1.0 / iters);
}

int
main(void)
{
	double i;

	srand(time(NULL));
	for (i = 0.0; i <= 1.0; i += 0.001)
		sim(i, 100000ul);

	return 0;
}
