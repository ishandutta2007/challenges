/*

You are given two numbers a and b.
Create a function that returns the next number greater than a and b and divisible by b.

Examples

divisible_by_b(17, 8) ➞ 24

divisible_by_b(98, 3) ➞ 99

divisible_by_b(14, 11) ➞ 22

Notes

a will always be greater than b.

*/

#include <assert.h>
#include <stdio.h>

unsigned
divb(unsigned a, unsigned b)
{
	return (a + b) / b * b;
}

int
main(void)
{
	assert(divb(17, 8) == 24);
	assert(divb(98, 3) == 99);
	assert(divb(14, 11) == 22);
	assert(divb(11, 8) == 16);
	assert(divb(450, 36) == 468);
	assert(divb(1019, 13) == 1027);

	return 0;
}
