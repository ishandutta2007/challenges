/*
In a single toss of 2 fair (evenly-weighted) 6-sided dice, find the probability of that their sum will be at most 9.
*/

#include <stdio.h>

unsigned
powi(unsigned x, unsigned n)
{
	unsigned y, m;

	if (n == 0)
		return 1;

	y = 1;
	while (n > 1) {
		if (!(n & 1)) {
			x *= x;
			n >>= 1;
		} else {
			y *= x;
			x *= x;
			n = (n - 1) >> 1;
		}
	}
	return x * y;
}

void
probrec(unsigned n, unsigned s, unsigned l, unsigned *p, unsigned v)
{
	unsigned i;

	if (n == 0) {
		if (v <= l)
			(*p)++;
		return;
	}

	for (i = 1; i <= s; i++)
		probrec(n - 1, s, l, p, i + v);
}

void
prob(unsigned n, unsigned s, unsigned l)
{
	unsigned p, q;

	p = 0;
	probrec(n, s, l, &p, 0);
	q = powi(s, n);
	printf("%u/%u\n", p, q);
}

int
main(void)
{
	prob(2, 6, 9);
	return 0;
}
