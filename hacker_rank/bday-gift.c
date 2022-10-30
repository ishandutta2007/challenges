/*

Isaac has to buy a new HackerPhone for his girlfriend Amy.
He is exploring the shops in the town to compare the prices whereupon he finds a shop located on the first floor of a building,
that has a unique pricing policy.

There are N steps leading to the shop. A numbered ball is placed on each of the steps. 

The shopkeeper gives Isaac a fair coin and asks him to toss the coin before climbing each step.
If the result of the toss is a 'Heads', Isaac should pick up the ball, else leave it and proceed to the next step.

The shopkeeper then asks Isaac to find the sum of all the numbers he has picked up (let's say S).
The price of the HackerPhone is then the expected value of S. Help Isaac find the price of the HackerPhone.

*/
#include <stdio.h>

#define nelem(x) (sizeof(x) / sizeof(x[0]))

double
expected(double *a, size_t n)
{
	size_t i;
	double e;

	e = 0;
	for (i = 0; i < n; i++) {
		e += a[i];
	}
	e *= 0.5;

	return e;
}

int
main(void)
{
	double a[] = {1, 1, 2};
	printf("%.1lf\n", expected(a, nelem(a)));

	double b[] = {1, 2, 2, 2};
	printf("%.1lf\n", expected(b, nelem(b)));

	return 0;
}
