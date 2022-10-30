/*

Create a function that takes two numbers as arguments and returns the GCD of the two numbers.
Examples

gcd(3, 5) ➞ 1

gcd(14, 28) ➞ 14

gcd(4, 18) ➞ 2

Notes

GCD looks at all the divisors of each number and finds the greatest one.

*/

#include <assert.h>
#include <stdlib.h>

long
gcd(long a, long b)
{
	long t;

	while (b) {
		t = b;
		b = a % b;
		a = t;
	}
	return a;
}

int
main(void)
{
	assert(gcd(6, 10) == 2);
	assert(gcd(17, 85) == 17);
	assert(gcd(18, 153) == 9);
	assert(gcd(14, 14) == 14);
	assert(gcd(6, 31) == 1);

	return 0;
}
