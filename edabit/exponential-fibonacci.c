/*

Write a function that efficiently calculates Fibonacci terms.

Examples

fibonacci(1) ➞ 1

fibonacci(2) ➞ 1

fibonacci(4) ➞ 3

fibonacci(64) ➞ 10610209857723

Notes

The input will always be a power of two.

*/

#include <assert.h>
#include <stdio.h>

typedef unsigned long long uvlong;

// https://en.wikipedia.org/wiki/Fibonacci_number
// F[2n-1] = F[n]^2 + F[n-1]^2
// F[2n] = (2F[n-1] + F[n])*F[n]
uvlong
expfib(uvlong n)
{
	uvlong a, b, r;

	if (n == 0)
		return 0;
	if (n == 1)
		return 1;

	b = expfib(n / 2);
	if (n & 1) {
		a = expfib((n + 1) / 2);
		r = a * a + b * b;
	} else {
		a = expfib((n / 2) - 1);
		r = (2 * a + b) * b;
	}
	return r;
}

int
main(void)
{
	assert(expfib(1) == 1);
	assert(expfib(2) == 1);
	assert(expfib(4) == 3);
	assert(expfib(8) == 21);
	assert(expfib(16) == 987);
	assert(expfib(32) == 2178309ull);
	assert(expfib(64) == 10610209857723ull);

	return 0;
}
