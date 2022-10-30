/*

Write the function that takes three dimensions of a brick: height(a), width(b) and depth(c) and returns true if this brick can fit into a hole with the width(w) and height(h).
Examples

doesBrickFit(1, 1, 1, 1, 1) ➞ true

doesBrickFit(1, 2, 1, 1, 1) ➞ true

doesBrickFit(1, 2, 2, 1, 1) ➞ false

Notes

    You can turn the brick with any side towards the hole.
    We assume that the brick fits if its sizes equal the ones of the hole (i.e. brick size should be less than or equal to the size of the hole, not strickly less).
    You can't put a brick in at a non-orthogonal angle.

*/

#include <assert.h>
#include <stdbool.h>

void
swapu(unsigned *a, unsigned *b)
{
	unsigned t;

	t = *a;
	*a = *b;
	*b = t;
}

bool
brickfit(unsigned a, unsigned b, unsigned c, unsigned w, unsigned h)
{
	if (a > b)
		swapu(&a, &b);
	if (b > c)
		swapu(&b, &c);
	if (a > c)
		swapu(&a, &c);
	if (w > h)
		swapu(&w, &h);
	return (a <= w && b <= h);
}

int
main(void)
{
	assert(brickfit(1, 1, 1, 1, 1) == true);
	assert(brickfit(1, 2, 1, 1, 1) == true);
	assert(brickfit(1, 2, 2, 1, 1) == false);
	assert(brickfit(1, 2, 2, 1, 2) == true);
	assert(brickfit(1, 2, 2, 2, 1) == true);
	assert(brickfit(2, 2, 2, 1, 2) == false);

	return 0;
}
