// Write a function invert(x,p,n) that returns x with the n bits
// that begin at position p inverted (i.e., 1 changed into 0
// and vice versa), leaving the others unchanged.

#include <stdio.h>

unsigned
invert(unsigned x, unsigned p, unsigned n)
{
	return x ^ (~(~0u << n) << (p + 1 - n));
}

int
main(void)
{
	printf("%x\n", invert(0xf, 1, 0xff));
	printf("%x\n", invert(0xf, 3, 0xff));
	return 0;
}
