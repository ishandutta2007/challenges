/*

Create a function that returns a number which can block the player from reaching 3 in a row in a game of Tic Tac Toe.
The number given as an argument will correspond to a grid of Tic Tac Toe: topleft is 0, topright is 2, bottomleft is 6, and bottomright is 8.

    Create a function that takes two numbers a, b and returns another number.
    This number should be the final one in a line to block the player from winning.

Examples

blockPlayer(0, 3) ➞ 6

blockPlayer(0, 4) ➞ 8

blockPlayer(3, 5) ➞ 4

Notes

The values given will always have two filled squares in a line.

*/

#include <assert.h>
#include <stdio.h>
#include <string.h>

#define nelem(x) (sizeof(x) / sizeof(x[0]))

int
block(unsigned a, unsigned b)
{
	static const unsigned tab[] = {
	    0x07,
	    0x38,
	    0x1c0,
	    0x49,
	    0x92,
	    0x124,
	    0x54,
	    0x111,
	};

	unsigned i, j, p;

	p = (1 << a) | (1 << b);
	for (i = 0; i < 9; i++) {
		for (j = 0; j < nelem(tab); j++) {
			if ((tab[j] & (p | (1 << i))) == tab[j])
				return i;
		}
	}

	return -1;
}

int
main(void)
{
	assert(block(0, 3) == 6);
	assert(block(0, 8) == 4);
	assert(block(4, 8) == 0);
	assert(block(2, 5) == 8);
	assert(block(1, 7) == 4);
	assert(block(0, 4) == 8);
	assert(block(3, 5) == 4);

	return 0;
}
