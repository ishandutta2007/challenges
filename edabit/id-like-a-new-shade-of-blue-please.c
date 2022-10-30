/*

I have a bucket containing an amount of navy blue paint and I'd like to paint as many walls as possible. Create a function that returns the number of complete walls that I can paint, before I need to head to the shops to buy more.

    n is the number of square meters I can paint.
    w and h are the widths and heights of a single wall in meters.

Examples

howManyWalls(100, 4, 5) ➞ 5

howManyWalls(10, 15, 12) ➞ 0

howManyWalls(41, 3, 6) ➞ 2

Notes

    Don't count a wall if I don't manage to finish painting all of it before I run out of paint.
    All walls will have the same dimensions.
    All numbers will be positive integers.

*/

#include <assert.h>
#include <stdio.h>

unsigned
walls(unsigned n, unsigned w, unsigned h)
{
	return n / (w * h);
}

int
main(void)
{
	assert(walls(100, 4, 5) == 5);
	assert(walls(10, 15, 12) == 0);
	assert(walls(41, 3, 6) == 2);
	assert(walls(50, 11, 5) == 0);
	assert(walls(1, 1, 1) == 1);

	return 0;
}
