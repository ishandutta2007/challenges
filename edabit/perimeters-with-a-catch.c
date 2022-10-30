/*

Write a function that takes a number and returns the perimeter of either a circle or a square.
The input will be in the form (letter l, number num) where the letter will be either "s" for square, or "c" for circle,
and the number will be the side of the square or the radius of the circle.

Use the following formulas:

Perimeter of a square: 4 * side.
Perimeter of a circle: 6.28 * radius.

The catch is you can only use arithmetic or comparison operators, which means:

    No if... else statements.
    No objects.
    No arrays.
    No formatting methods, etc.

The goal is to write a short, branch-free piece of code.
Examples

perimeter("s", 7) ➞ 28

perimeter("c", 4) ➞ 25.12

perimeter("c", 9) ➞ 56.52

Notes

No rounding is needed.

*/

#include <assert.h>
#include <stdio.h>

double
perimeter(char t, double v)
{
	static const double tab[256] = {
	    ['c'] = 6.28,
	    ['s'] = 4,
	};
	return tab[t & 0xff] * v;
}

int
main(void)
{
	assert(perimeter('s', 1) == 4);
	assert(perimeter('s', 4) == 16);
	assert(perimeter('s', 9) == 36);
	assert(perimeter('s', 13) == 52);
	assert(perimeter('s', 30) == 120);
	assert(perimeter('c', 1) == 6.28);
	assert(perimeter('c', 4) == 25.12);
	assert(perimeter('c', 9) == 56.52);
	assert(perimeter('c', 13) == 81.64);
	assert(perimeter('c', 30) == 188.4);

	return 0;
}
