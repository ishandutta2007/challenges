/*
A prime is a natural number greater than that has no positive divisors other than and itself. Given p integers, determine the primality of each integer
and print whether it is Prime or Not prime on a new line.

Note: If possible, try to come up with an O(sqrt(n)) primality algorithm, or see what sort of optimizations you can come up with for an O(n) algorithm.
Be sure to check out the Editorial after submitting your code!
*/

#include <stdio.h>
#include <math.h>

const char *
isprime(unsigned n)
{
	unsigned i, l;

	if (n <= 1)
		return "Not prime";
	if (n == 2)
		return "Prime";
	if (n % 2 == 0)
		return "Not prime";
	l = sqrt(n);
	for (i = 3; i <= l; i += 2) {
		if (n % i == 0)
			return "Not prime";
	}
	return "Prime";
}

int
main(void)
{
	unsigned i;
	for (i = 0; i <= 100; i++)
		printf("%d %s\n", i, isprime(i));
	return 0;
}
