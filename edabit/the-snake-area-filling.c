/*

Assuming that you know the popular game "Snake", you have an area of x*x, the snake length is 1 (only the head) and is
positioned in the top left corner of the area at the beginning which means if your area is 7*7 it will look something like this:

Knowing that each time the snake eats the food his length will be 2 times longer (so if the length of the snake is 4, after eating it will be 8),
you have to create a function that takes a number as an argument and returns how many times the snake needs to eat to fill the entire area.

Notes

    The argument is the length of a side of the area which mean that if the given number is 6 your area will be of 6*6.
    The snake can exceed the borders
    The given number can't be a float.
    The given number is always positive.

*/

#include <stdio.h>

unsigned
snakefill(unsigned n)
{
	unsigned v, c;

	c = 0;
	for (v = 1; v <= n * n; v <<= 1)
		c++;
	return (c == 0) ? 1 : c - 1;
}

int
main(void)
{
	printf("%u\n", snakefill(3));
	printf("%u\n", snakefill(6));
	printf("%u\n", snakefill(24));
	printf("%u\n", snakefill(18));
	printf("%u\n", snakefill(555));
	printf("%u\n", snakefill(2));
	printf("%u\n", snakefill(1));
	printf("%u\n", snakefill(900));

	return 0;
}
