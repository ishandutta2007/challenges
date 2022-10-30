// Given two integers l and r, find maximal value of a^b where l <= a,b <= r
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void
swap(unsigned *a, unsigned *b)
{
	unsigned t;
	t = *b;
	*b = *a;
	*a = t;
}

unsigned
xormax_slow(unsigned l, unsigned r)
{
	unsigned a, b, m;

	if (r < l)
		swap(&l, &r);
	m = 0;
	for (a = l; a <= r; a++) {
		for (b = l; b <= r; b++) {
			if (m < (a ^ b))
				m = a ^ b;
		}
	}
	return m;
}

unsigned
msb(unsigned x)
{
	unsigned p;

	for (p = 0; x != 0; x >>= 1)
		p++;
	return p;
}

/*

XOR is maximized A and B when most bits differ, so if we find the MSB
of A XOR B, the maximized value will also have that MSB be 1,
then every lower bit can be 1 since that will
still ensure A,B <= R

*/
unsigned
xormax(unsigned l, unsigned r)
{
	return (1u << msb(l ^ r)) - 1;
}

int
main(void)
{
	srand(time(NULL));
	printf("%u %u\n", xormax_slow(11, 12), xormax(11, 12));
	printf("%u %u\n", xormax_slow(10, 15), xormax(10, 15));
	printf("%u %u\n", xormax_slow(11, 100), xormax(11, 100));
	for (int i = 0; i <= 1000; i++) {
		unsigned a = rand() & 0xffff;
		unsigned b = rand() & 0xffff;
		printf("%u %u %u %u\n", a, b, xormax_slow(a, b), xormax(a, b));
	}
	return 0;
}
