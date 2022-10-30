/*

An integer is a divisor of an integer if the remainder of n%d = 0.

Given an integer, for each digit that makes up the integer determine whether it is a divisor. Count the number of divisors occurring within the integer.

Note: Each digit is considered to be unique, so each occurrence of the same digit should be counted (e.g. for
111, 1 is a divisor of each time it occurs so the answer is 3).

*/
#include <stdio.h>

unsigned
digits(unsigned n)
{
	unsigned c, d;

	for (c = 0; n != 0; n /= 10) {
		d = n % 10;
		if (d != 0 && n % d == 0)
			c++;
	}
	return c;
}

int
main(void)
{
	printf("%u\n", digits(111));
	printf("%u\n", digits(12));
	printf("%u\n", digits(1012));
	return 0;
}
