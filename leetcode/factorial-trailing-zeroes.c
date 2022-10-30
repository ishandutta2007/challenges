/*

Given an integer n, return the number of trailing zeroes in n!.

Note: Your solution should be in logarithmic time complexity.

*/

#include <stdio.h>

unsigned long
fact(unsigned long n)
{
	unsigned long i, r;

	if (n <= 1)
		return 1;

	r = 1;
	for (i = 2; i <= n; i++)
		r *= i;
	return r;
}

unsigned long
trailingzeroes(unsigned long n)
{
	unsigned long i, c;

	if (n <= 1)
		return 0;

	c = 0;
	for (i = 5; n / i > 0; i *= 5)
		c += n / i;
	return c;
}

int
main(void)
{
	unsigned long i;
	for (i = 0; i < 16; i++)
		printf("%lu %lu %lu\n", i, fact(i), trailingzeroes(i));
	return 0;
}
