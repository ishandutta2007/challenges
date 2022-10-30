/*

Jim is doing his discrete maths homework which requires him to repeatedly calculate nCr(n choose r) for different values of n.
Knowing that this is time consuming, he goes to his sister June for help. June, being a computer science student
knows how to convert this into a computer program and generate the answers quickly.
She tells him, by storing the lower values of nCr(n choose r), one can calculate the higher values using a very simple formula.

If you are June, how will you calculate nCr values for different values of n?

Since values will be large you have to calculate them modulo 10**9.

*/
#include <stdio.h>
#include <stdint.h>
#include <inttypes.h>

uint64_t
factorial(uint64_t n)
{
	uint64_t i, v;

	v = 1;
	for (i = 2; i <= n; i++)
		v *= i;
	return v;
}

uint64_t
ncr(uint64_t n, uint64_t r)
{
	return factorial(n) / (factorial(r) * factorial(n - r));
}

void
ncrtable(uint64_t n)
{
	uint64_t i, m;

	m = 1000000000ull;
	for (i = 0; i <= n; i++)
		printf("%" PRIu64 " ", ncr(n, i) % m);
	printf("\n");
}

int
main(void)
{
	uint64_t i;

	for (i = 0; i <= 20; i++)
		ncrtable(i);
	return 0;
}
