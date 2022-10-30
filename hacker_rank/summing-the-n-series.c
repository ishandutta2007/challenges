/*

You are given a sequence whose nth term is
Tn = n^2 - (n-1)^2

evaluate series
Sn = T1 + T2 ... + Tn

Find Sn mod(10^9 + 7)

*/

#include <stdio.h>
#include <stdint.h>
#include <inttypes.h>

uint64_t
T(uint64_t n)
{
	return (n * n) - (n - 1) * (n - 1);
}

uint64_t
S(uint64_t n)
{
	const uint64_t m = 1000000007;

	uint64_t i, s;

	s = 0;
	for (i = 1; i <= n; i++)
		s = ((s % m) + (T(i) % m)) % m;

	return s;
}

uint64_t
SS(uint64_t n)
{
	const uint64_t m = 1000000007;
	uint64_t a, b, c;

	// closed form for sum i^2 =
	// n(n+1)(2n + 1)/6
	// separate T(n) into 2 parts n*n and (n-1)*(n-1)
	// and use closed form to evaluate it
	a = n * (n + 1) * (2 * n + 1);
	b = (n - 1) * n * (2 * (n - 1) + 1);
	c = (a - b) / 6;
	c %= m;
	return c;
}

int
main(void)
{
	int i;

	for (i = 0; i < 100000; i++)
		printf("%d: %" PRIu64 " %" PRIu64 "\n", i, S(i), SS(i));
	return 0;
}
