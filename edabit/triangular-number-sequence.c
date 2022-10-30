/*

This Triangular Number Sequence is generated from a pattern of dots that form a triangle. The first 5 numbers of the sequence, or dots, are: 1, 3, 6, 10, 15. Write a function that converts n number of places with its corresponding number.
Examples

triangle(1) ➞ 1

triangle(6) ➞ 21

triangle(215) ➞ 23220

Notes

N/A

*/

#include <assert.h>

unsigned
triangle(unsigned n)
{
	return n * (n + 1) / 2;
}

int
main(void)
{
	assert(triangle(0) == 0);
	assert(triangle(1) == 1);
	assert(triangle(2) == 3);
	assert(triangle(3) == 6);
	assert(triangle(6) == 21);
	assert(triangle(8) == 36);
	assert(triangle(215) == 23220);
	assert(triangle(2153) == 2318781);
	return 0;
}
