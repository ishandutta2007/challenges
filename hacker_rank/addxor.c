#include <stdio.h>

// implement addition using xor
unsigned
add1(unsigned x)
{
	unsigned y;

	for (y = 1;; y <<= 1) {
		x ^= y;
		if ((x & y) != 0)
			break;
	}
	return x;
}

unsigned
addn(unsigned x, unsigned n)
{
	unsigned i;

	for (i = 0; i < n; i = add1(i))
		x = add1(x);
	return x;
}

int
main(void)
{
	printf("%u\n", addn(20, 3));
	printf("%u\n", addn(255, 2555));
	return 0;
}
