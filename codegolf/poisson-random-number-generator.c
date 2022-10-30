/*

What is the shortest function (implemented in C) that will return a random draw from a Poisson distribution (given the mean or λ parameter)?

int random_poisson(double lambda);

*/

#define _XOPEN_SOURCE
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

// https://en.wikipedia.org/wiki/Poisson_distribution#Generating_Poisson-distributed_random_variables
double
poisson(double lambda)
{
	double L, k, p;

	L = exp(-lambda);
	k = 0;
	p = 1;
	do {
		k += 1;
		p *= drand48();
	} while (p > L);
	return k - 1;
}

int
main(void)
{
	unsigned long i;

	srand48(time(NULL));
	for (i = 0; i <= 100000ul; i++)
		printf("%f\n", poisson(100));

	return 0;
}
