/*

A tetrahedron is a pyramid with a triangular base and three sides. A tetrahedral number is a number of items within a tetrahedron.

Create a function that takes an integer n and returns the nth tetrahedral number.

Alternative Text
Examples

tetra(2) ➞ 4

tetra(5) ➞ 35

tetra(6) ➞ 56

Notes

There is a formula for the nth tetrahedral number.

*/

#include <assert.h>

unsigned
tetra(unsigned n)
{
	return n * (n + 1) * (n + 2) / 6;
}

int
main(void)
{
	assert(tetra(1) == 1);
	assert(tetra(2) == 4);
	assert(tetra(3) == 10);
	assert(tetra(4) == 20);
	assert(tetra(5) == 35);
	assert(tetra(9) == 165);

	return 0;
}
