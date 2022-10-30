/*

Write a function that returns the greatest common divisor (GCD) of two integers.
Examples

gcd(32, 8) ➞ 8

gcd(8, 12) ➞ 4

gcd(17, 13) ➞ 1

Notes

    Both values will be positive.
    The GCD is the largest factor that divides both numbers.

*/

#include <assert.h>

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
	assert(gcd(32, 8) == 8);
	assert(gcd(8, 12) == 4);
	assert(gcd(17, 13) == 1);
	assert(gcd(14, 7) == 7);
	assert(gcd(32, 16) == 16);
	assert(gcd(17, 100) == 1);
	assert(gcd(55, 20) == 5);
	assert(gcd(55, 22) == 11);

	return 0;
}
