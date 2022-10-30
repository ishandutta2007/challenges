/*

You are counting points for a basketball game, given the amount of 2-pointers scored and 3-pointers scored,
find the final points for the team and return that value.

Examples

points(1, 1) ➞ 5

points(7, 5) ➞ 29

points(38, 8) ➞ 100

Notes

N/A

*/

#include <assert.h>
#include <stdio.h>

unsigned
points(unsigned p2, unsigned p3)
{
	return p2 * 2 + p3 * 3;
}

int
main(void)
{
	assert(points(1, 1) == 5);
	assert(points(1, 2) == 8);
	assert(points(2, 1) == 7);
	assert(points(2, 2) == 10);
	assert(points(69, 420) == 1398);
	assert(points(7, 5) == 29);
	assert(points(38, 8) == 100);

	return 0;
}
