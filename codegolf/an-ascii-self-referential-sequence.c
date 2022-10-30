/*

The sequence A109648 starts with the following numbers

53, 51, 44, 32, 53, 49, 44, 32, 52, 52, 44, 32,
51, 50, 44, 32, 53, 51, 44, 32, 52, 57, 44, 32,
52, 52, 44, 32, 51, 50, 44, 32, 53, 50, 44, 32,
53, 50, 44, 32, 52, 52, 44, 32, 51, 50, 44, 32,
53, 49, 44, 32, 53, 48, 44, 32, 52, 52, 44, 32,
51, 50, 44, 32, 53, 51, 44, 32, 53, ...
and has the description of

Sequence is its own ASCII representation (including commas and spaces).

This is the unique sequence with the property. Your task is compute this sequence.

*/

#include <assert.h>
#include <stdio.h>

#define nelem(x) (sizeof(x) / sizeof(x[0]))

unsigned
seq(unsigned n)
{
	static const unsigned tab[] = {53, 51};

	if (n < nelem(tab))
		return tab[n];

	switch (n & 3) {
	case 0:
		return 48 + seq(n / 4) / 10;
	case 1:
		return 48 + seq(n / 4) % 10;
	case 2:
		return 44;
	default:
		return 32;
	}
}

int
main(void)
{
	static const unsigned tab[] = {53, 51, 44, 32, 53, 49, 44, 32, 52, 52, 44, 32, 51, 50, 44, 32, 53, 51, 44, 32, 52, 57, 44, 32, 52, 52, 44, 32, 51, 50, 44, 32, 53, 50, 44, 32, 53, 50, 44, 32, 52, 52, 44, 32, 51, 50, 44, 32, 53, 49, 44, 32, 53, 48, 44, 32, 52, 52, 44, 32, 51, 50, 44, 32, 53, 51, 44, 32, 53};

	size_t i;

	for (i = 0; i < nelem(tab); i++)
		assert(seq(i) == tab[i]);

	return 0;
}
