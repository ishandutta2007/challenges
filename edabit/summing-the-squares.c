/*

Create a function where given the number n, return the sum of all square numbers up to and including n.

Notes

Remember that n is included in the total.

*/

#include <stdio.h>

unsigned
squaressum(unsigned n)
{
	return n * (n + 1) * (2 * n + 1) / 6;
}

int
main(void)
{
	unsigned i;

	for (i = 0; i <= 100; i++)
		printf("%u %u\n", i, squaressum(i));
	return 0;
}
