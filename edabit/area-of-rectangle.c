/*

Create a function that calculates the area of a rectangle. If the arguments are invalid, your function must return -1.
Examples

area(3, 4) ➞ 12

area(10, 11) ➞ 110

area(-1, 5) ➞ -1

area(0, 2) ➞ -1

Notes

N/A

*/

#include <assert.h>

long
area(long w, long h)
{
	if (w <= 0 || h <= 0)
		return -1;
	return w * h;
}

int
main(void)
{
	assert(area(3, 4) == 12);
	assert(area(10, 11) == 110);
	assert(area(-1, 5) == -1);
	assert(area(0, 2) == -1);
	assert(area(5, 3) == 15);
	assert(area(8, 5) == 40);
	assert(area(5, 4) == 20);
	assert(area(2, 3) == 6);
	assert(area(10000, 10000) == 100000000l);
	assert(area(-2, -5) == -1);
	assert(area(0, 3) == -1);
	assert(area(5, -3) == -1);
	assert(area(0, 1) == -1);
	assert(area(-1, 0) == -1);

	return 0;
}
