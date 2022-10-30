/*

Note: the first half of this challenge comes from Martin Ender's previous challenge, Visualize Bit Weaving.

The esoteric programming language evil has an interesting operation on byte values which it calls "weaving".

It is essentially a permutation of the eight bits of the byte (it doesn't matter which end we start counting from, as the pattern is symmetric):

    Bit 0 is moved to bit 2
    Bit 1 is moved to bit 0
    Bit 2 is moved to bit 4
    Bit 3 is moved to bit 1
    Bit 4 is moved to bit 6
    Bit 5 is moved to bit 3
    Bit 6 is moved to bit 7
    Bit 7 is moved to bit 5

For convenience, here are three other representations of the permutation. As a cycle:

(02467531)

As a mapping:

57361402 -> 76543210 -> 64725031

And as a list of pairs of the mapping:

[[0,2], [1,0], [2,4], [3,1], [4,6], [5,3], [6,7], [7,5]]

After 8 weavings, the byte is essentially reset.

For example, weaving the number 10011101 (which is 157 in base 10) will produce 01110110 (which is 118 in base 10).
Input

There are only 256 valid inputs, namely all the integers between 0 and 255 inclusive. That may be taken in any base, but it must be consistent and you must specify it if the base you choose is not base ten.

You may not zero-pad your inputs.
Output

You should output the result of the bit weaving, in any base, which must also be consistent and specified if not base ten.

You may zero-pad your outputs.

Related: Visualize Bit Weaving

*/

#include <stdio.h>
#include <stdint.h>

#define nelem(x) (sizeof(x) / sizeof(x[0]))

uint8_t weavetab[256];

void
init(void)
{
	static const uint8_t tab[] = {2, 0, 4, 1, 6, 3, 7, 5};

	size_t i, j;
	uint8_t r;

	for (i = 0; i < nelem(weavetab); i++) {
		r = 0;
		for (j = 0; j < nelem(tab); j++)
			r |= !!(i & (1 << j)) << tab[j];
		weavetab[i] = r;
	}
}

uint8_t
weave(uint8_t x)
{
	return weavetab[x];
}

int
main(void)
{
	int i, j, v;

	init();
	for (i = 0; i < 256; i++) {
		j = 1;
		v = i;
		while ((v = weave(v)) != i)
			j++;

		printf("%d %d %d\n", i, v, j);
	}
	return 0;
}
