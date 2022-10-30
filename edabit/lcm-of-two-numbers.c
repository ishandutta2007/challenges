/*

Write a function that returns the least common multiple (LCM) of two integers.
Examples

lcm(9, 18) ➞ 18

lcm(8, 5) ➞ 40

lcm(17, 11) ➞ 187

Notes

    Both values will be positive.
    The LCM is the smallest integer that divides both numbers such that the remainder is zero.

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

long
lcm(long a, long b)
{
	return labs(a * b) / gcd(a, b);
}

int
main(void)
{
	assert(lcm(9, 18) == 18);
	assert(lcm(8, 5) == 40);
	assert(lcm(17, 11) == 187);
	assert(lcm(17, 5) == 85);
	assert(lcm(3, 12) == 12);
	assert(lcm(9, 9) == 9);

	return 0;
}
