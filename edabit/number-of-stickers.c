/*

Given a Rubik's Cube with a side length of n, return the number of individual stickers that are needed to cover the whole cube.

Pictures of Rubik's Cubes

    The Rubik's cube of side length 1 has 6 stickers.
    The Rubik's cube of side length 2 has 24 stickers.
    The Rubik's cube of side length 3 has 54 stickers.

Examples

howManyStickers(1) ➞ 6

howManyStickers(2) ➞ 24

howManyStickers(3) ➞ 54

Notes

    Keep in mind there are 6 faces to keep track of.
    Expect only positive whole numbers.

*/

#include <assert.h>
#include <stdio.h>

unsigned
stickers(unsigned n)
{
	return 6 * n * n;
}

int
main(void)
{
	assert(stickers(1) == 6);
	assert(stickers(2) == 24);
	assert(stickers(3) == 54);
	assert(stickers(4) == 96);
	assert(stickers(5) == 150);
	assert(stickers(6) == 216);
	assert(stickers(7) == 294);
	assert(stickers(8) == 384);
	assert(stickers(9) == 486);
	assert(stickers(10) == 600);
	assert(stickers(11) == 726);
	assert(stickers(12) == 864);
	assert(stickers(13) == 1014);
	assert(stickers(14) == 1176);
	assert(stickers(15) == 1350);

	return 0;
}
