// Write a function rightrot(x,n) that returns the value of the integer x rotated to the right by n bit positions.
#include <stdio.h>

unsigned
rightrot(unsigned x, unsigned n)
{
	for (; n; n--) {
		if (x & 1)
			x = (x >> 1) | ~(~0u >> 1);
		else
			x >>= 1;
	}
	return x;
}

int
main(void)
{
	unsigned i, j;

	printf("%x\n", rightrot(0, 1));
	for (i = 0; i < 8; i++) {
		for (j = 0; j < 16; j++)
			printf("%u %u %x\n", i, j, rightrot(i, j));
	}
	return 0;
}
