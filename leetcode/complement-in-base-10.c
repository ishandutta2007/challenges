/*

Every non-negative integer N has a binary representation. 
For example, 5 can be represented as "101" in binary, 11 as "1011" in binary, and so on.
Note that except for N = 0, there are no leading zeroes in any binary representation.

The complement of a binary representation is the number in binary you get when changing every 1 to a 0 and 0 to a 1.
For example, the complement of "101" in binary is "010" in binary.

For a given number N in base-10, return the complement of it's binary representation as a base-10 integer.

*/

#include <stdio.h>

unsigned
nextpow2(unsigned n)
{
	unsigned i, s;

	n--;
	for (i = 0, s = 1; i < sizeof(n) - 1; i++) {
		n |= n >> s;
		s <<= 1;
	}
	n++;
	return n;
}

unsigned
bitcomp(unsigned n)
{
	if (n == 0)
		return 1;
	return ~n & (nextpow2(n) - 1);
}

int
main(void)
{
	printf("%u\n", bitcomp(0));
	printf("%u\n", bitcomp(5));
	printf("%u\n", bitcomp(7));
	printf("%u\n", bitcomp(10));
	printf("%u\n", bitcomp(11));
	printf("%u\n", bitcomp(255));
	printf("%u\n", bitcomp(256));
	return 0;
}
