/*

Given an integer n, find x each such that:
0 <= x <= n
n + x = n ^ x

*/

#include <stdio.h>

unsigned
sumxor_slow(unsigned n)
{
	unsigned c, i;

	for (c = i = 0; i <= n; i++) {
		if ((n + i) == (n ^ i))
			c++;
	}
	return c;
}

unsigned
trailzero(unsigned n)
{
	unsigned c;

	for (c = 0; n != 0; n >>= 1) {
		if ((n & 1) == 0)
			c++;
	}
	return c;
}

// addition is equal to xor when there is no carry
// due to the fact that xor is addition without carry
// so gives the following constraint on the binary representation
// n -> 1 x -> 0
// n -> 0 x -> 0/1
// to find number of possible x by counting 0s in n before the msb 1 is set
// since any bits after the msb 1 will be the same in xor/sum form
// and then 2^p will give the number of combinations where p is the number
unsigned
sumxor(unsigned n)
{
	return 1u << trailzero(n);
}

int
main(void)
{
	unsigned i;
	for (i = 0; i <= 1000; i++)
		printf("%u %u %u\n", i, sumxor_slow(i), sumxor(i));
	return 0;
}
