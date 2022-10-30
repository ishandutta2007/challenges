/*

Given an integer, create a function that returns the next prime.
If the number is prime, return the number itself.

Examples

next_prime(12) ➞ 13

next_prime(24) ➞ 29

next_prime(11) ➞ 11
# 11 is a prime, so we return the number itself.

Notes

N/A

*/

#include <assert.h>
#include <stdio.h>
#include <math.h>

int
isprime(unsigned n)
{
	unsigned i, l;

	if (n <= 1)
		return 0;
	if (n == 2)
		return 1;
	if (n % 2 == 0)
		return 0;
	l = sqrt(n);
	for (i = 3; i <= l; i += 2) {
		if (n % i == 0)
			return 0;
	}
	return 1;
}

unsigned
nextprime(unsigned n)
{
	while (!isprime(n))
		n += 1 + (n & 1);
	return n;
}

int
main(void)
{
	unsigned i;

	assert(nextprime(12) == 13);
	assert(nextprime(24) == 29);
	assert(nextprime(11) == 11);
	assert(nextprime(13) == 13);
	assert(nextprime(14) == 17);
	assert(nextprime(33) == 37);
	assert(nextprime(100) == 101);
	assert(nextprime(102) == 103);
	assert(nextprime(105) == 107);
	assert(nextprime(524) == 541);
	for (i = 2; i <= 1000; i++) {
		i = nextprime(i);
		printf("%u\n", i);
	}

	return 0;
}
