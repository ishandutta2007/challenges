/*

You will be given 3 integers as input.
The inputs may or may not be different from each other.
You have to output 1 if all three inputs are different from each other, and 0 if any input is repeated more than once.

This is code-golf, so make your code as short as possible!

*/

#include <assert.h>

int
distinct(int a, int b, int c)
{
	return !(a == b || a == c || b == c);
}

int
main(void)
{
	assert(distinct(3, 2, 1) == 1);
	assert(distinct(1, 2, 3) == 1);
	assert(distinct(-5, 2, 5) == 1);

	assert(distinct(3, 3, 2) == 0);
	assert(distinct(3, 3, 3) == 0);
	assert(distinct(-33, -3, -3) == 0);

	return 0;
}
