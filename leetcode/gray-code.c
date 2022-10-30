/*

The gray code is a binary numeral system where two successive values differ in only one bit.

Given a non-negative integer n representing the total number of bits in the code, print the sequence of gray code. A gray code sequence must begin with 0.

For a given n, a gray code sequence may not be uniquely defined.
For example, [0,2,3,1] is also a valid gray code sequence.

*/

#include <stdio.h>
#include <stdint.h>

typedef unsigned long long uvlong;

uvlong
bin2gray(uvlong n)
{
	return n ^ (n >> 1);
}

void
printbin(uvlong b, uvlong v)
{
	if (b == 0)
		printf("0");
	for (; b; b--)
		printf("%d", !!(v & (1ULL << (b - 1))));
}

void
test(uvlong n)
{
	uvlong i, g;
	for (i = 0; i < 1ULL << n; i++) {
		g = bin2gray(i);
		printbin(n, g);
		printf(" - %llu\n", g);
	}
	printf("\n");
}

int
main(void)
{
	test(2);
	test(0);
	test(16);
	return 0;
}
