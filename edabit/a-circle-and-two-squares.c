/*

Imagine a circle and two squares: a smaller and a bigger one. For the smaller one, the circle is a circumcircle and for the bigger one, an incircle.

https://edabit-challenges.s3.amazonaws.com/scale.png

Create a function, that takes an integer (radius of the circle) and returns the difference of the areas of the two squares.
Examples

square_areas_difference(5) ➞ 50

square_areas_difference(6) ➞ 72

square_areas_difference(7) ➞ 98

Notes

Use only positive integer parameters.

*/

#include <assert.h>
#include <stdio.h>

unsigned
sqadiff(unsigned r)
{
	return 2 * r * r;
}

int
main(void)
{
	assert(sqadiff(5) == 50);
	assert(sqadiff(6) == 72);
	assert(sqadiff(7) == 98);
	assert(sqadiff(17) == 578);

	return 0;
}
