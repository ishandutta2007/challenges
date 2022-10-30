// In a two's complement number system, x &= (x-1) deletes the rightmost 1-bit in x.
// Explain why. Use this observation to write a faster version of bitcount.

#include <stdio.h>

int
bitcount(unsigned x)
{
	int b;

	for (b = 0; x; x &= (x - 1))
		b++;
	return b;
}

int
main(void)
{
	int i;

	printf("%d\n", bitcount(0xff));
	printf("%d\n", bitcount(~0));
	printf("%d\n", bitcount(25));
	for (i = 0; i < 100; i++)
		printf("%d %d\n", i, bitcount(i));
	return 0;
}
