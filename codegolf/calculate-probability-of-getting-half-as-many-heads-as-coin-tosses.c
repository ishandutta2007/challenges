/*

Write a program that, given a small positive even integer from standard input, calculates the probability that flipping that many coins will result in half as many heads.

For example, given 2 coins the possible outcomes are:

HH HT TH TT

where H and T are heads and tails. There are 2 outcomes (HT and TH) that are half as many heads as the number of coins.
There are a total of 4 outcomes, so the probability is 2/4 = 0.5.

This is simpler than it looks.

Test cases:

2 -> 0.5
4 -> 0.375
6 -> 0.3125
8 -> 0.2734375

*/

#include <assert.h>
#include <stdio.h>
#include <math.h>

#define min(a, b) (((a) < (b)) ? (a) : (b))

long
binomial(long n, long k)
{
	long i, c;

	if (k < 0 || k > n)
		return 0;
	if (k == 0 || k == n)
		return 1;

	k = min(k, n - k);
	c = 1;
	for (i = 0; i < k; i++)
		c = c * (n - i) / (i + 1);
	return c;
}

double
probability(long n)
{
	return (binomial(n, n / 2) * 1.0) / (1l << n);
}

void
test(long n, double r)
{
	double p;

	p = probability(n);
	printf("%f\n", p);
	assert(fabs(p - r) < 1e-8);
}

int
main(void)
{
	test(2, 0.5);
	test(4, 0.375);
	test(6, 0.3125);
	test(8, 0.2734375);

	return 0;
}
