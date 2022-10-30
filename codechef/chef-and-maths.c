/*

Chef is solving mathematics problems. He is preparing for Engineering Entrance exam. He's stuck in a problem.

f(n)=1n∗2n−1∗3n−2∗…∗n1

Help Chef to find the value of f(n). Since this number could be very large, compute it modulo 1000000007.

*/

#include <assert.h>
#include <stdio.h>
#include <math.h>

unsigned long
ipowm(unsigned long x, unsigned long p, unsigned long m)
{
	unsigned long i, v;

	v = 1;
	for (i = 0; i < p; i++)
		v = ((v % m) * (x % m)) % m;
	return v;
}

// https://oeis.org/A000178
unsigned long
f(unsigned long n)
{
	unsigned long i, r, m;

	if (n == 0)
		return 0;

	m = 1000000007ul;
	r = 1;
	for (i = 1; i <= n; i++)
		r = ((r % m) * ipowm(i, n - i + 1, m)) % m;
	return r;
}

int
main(void)
{
	assert(f(3) == 12);
	return 0;
}
