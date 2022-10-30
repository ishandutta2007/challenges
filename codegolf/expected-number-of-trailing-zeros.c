/*

Input
A bound m <= 4294967295.

Output
Consider values sampled uniformly at random from integers in the range 0 to m, inclusive.

Your output should be the expected (average) number of trailing zeros in the binary representation of the sampled value. Your answer should be exact, for example given as a fraction.

Example
m = 0. The answer is 1. 0 will be sampled with prob 1.
m = 1. The answer is 1/2. 0 with prob 1/2 and 1 with prob 1/2.
m = 2. The answer is 2/3. 0 and 2 have one trailing zero.
m = 3. The answer is 1/2. 0 and 2 have one trailing zero.

*/

#include <assert.h>
#include <stdio.h>

typedef unsigned long long uvlong;

uvlong
gcd(uvlong a, uvlong b)
{
	uvlong t;

	while (b) {
		t = b;
		b = a % b;
		a = t;
	}
	return a;
}

// https://www.johndcook.com/blog/2020/02/21/popcount/
uvlong
popcnt(uvlong x)
{
	uvlong y;

	y = x * 0x0002000400080010ULL;
	y = y & 0x1111111111111111ULL;
	y = y * 0x1111111111111111ULL;
	y = y >> 60;
	return y;
}

/*

@xnor:
Formula:
f(m) = 1 - (#ones in bin(m) / (m+1)) = m + 1 - (#ones in bin(m)) / (m + 1)

https://oeis.org/A011371

*/

void
expectation(uvlong m, uvlong *n, uvlong *d)
{
	uvlong c;

	*n = m + 1 - popcnt(m);
	*d = m + 1;
	c = gcd(*n, *d);
	*n /= c;
	*d /= c;
}

void
test(uvlong m, uvlong rn, uvlong rd)
{
	uvlong n, d;

	expectation(m, &n, &d);
	printf("%llu/%llu\n", n, d);
	assert(n == rn);
	assert(d == rd);
}

int
main(void)
{
	test(0, 1, 1);
	test(1, 1, 2);
	test(2, 2, 3);
	test(3, 1, 2);

	return 0;
}
