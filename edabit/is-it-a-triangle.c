/*

Create a function that takes three numbers as arguments and returns true if it's a triangle and false if not.
Examples

isTriangle(2, 3, 4) ➞ true

isTriangle(3, 4, 5) ➞ true

isTriangle(4, 3, 8) ➞ false

Notes

    a, b and, c are the side lengths of the triangles.
    Test input will always be three positive numbers.

*/

#include <assert.h>

void
swapu(unsigned *a, unsigned *b)
{
	unsigned t;

	t = *a;
	*a = *b;
	*b = t;
}

int
istriangle(unsigned a, unsigned b, unsigned c)
{
	if (a > b)
		swapu(&a, &b);
	if (a > c)
		swapu(&a, &c);
	if (b > c)
		swapu(&b, &c);
	return c < a + b;
}

int
main(void)
{
	assert(istriangle(2, 3, 4) == 1);
	assert(istriangle(3, 4, 5) == 1);
	assert(istriangle(4, 3, 8) == 0);
	assert(istriangle(4, 5, 6) == 1);
	assert(istriangle(3, 4, 6) == 1);
	assert(istriangle(2, 5, 7) == 0);
	assert(istriangle(2, 5, 9) == 0);
	assert(istriangle(2, 9, 5) == 0);
	assert(istriangle(9, 2, 5) == 0);
	assert(istriangle(11, 12, 20) == 1);
	assert(istriangle(14, 3, 12) == 1);
	assert(istriangle(23, 4, 28) == 0);
	assert(istriangle(21, 4, 25) == 0);

	return 0;
}
