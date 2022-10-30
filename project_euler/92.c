/*

A number chain is created by continuously adding the square of the digits in a number to form a new number until it has been seen before.

For example,

44 → 32 → 13 → 10 → 1 → 1
85 → 89 → 145 → 42 → 20 → 4 → 16 → 37 → 58 → 89

Therefore any chain that arrives at 1 or 89 will become stuck in an endless loop. What is most amazing is that EVERY starting number will eventually arrive at 1 or 89.

How many starting numbers below ten million will arrive at 89?

*/

#include <stdio.h>

typedef unsigned long ulong;

ulong
digits(ulong n)
{
	ulong r, x;

	for (r = 0; n; n /= 10) {
		x = n % 10;
		r += x * x;
	}
	return r;
}

ulong
cycle(ulong n)
{
	if (n == 0)
		return 0;
	while (n != 1 && n != 89)
		n = digits(n);
	return n;
}

int
main(void)
{
	ulong i, c;

	c = 0;
	for (i = 0; i < 10000000ul; i++)
		c += (cycle(i) == 89);
	printf("%lu\n", c);

	return 0;
}
