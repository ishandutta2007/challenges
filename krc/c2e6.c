// Write a function setbits(x, p, n, y) that returns x with the n bits that begin
// at position p set to the rightmost n bits of y, leaving the other bits unchanged.
#include <stdio.h>

unsigned
setbits(unsigned x, int p, int n, unsigned y)
{
	return (x & ~(~(~0u << n) << (p + 1 - n))) | (y & ~(~0u << n)) << (p + 1 - n);
}

int
main(void)
{
	unsigned x, p, n, y;
	for (x = 0; x < 32; x++) {
		for (p = 0; p < 32; p++) {
			for (n = 0; n < 32; n++) {
				for (y = 0; y < 32; y++) {
					printf("%x %x %x %x: %x\n", x, p, n, y, setbits(x, p, n, y));
				}
			}
		}
	}
	return 0;
}
