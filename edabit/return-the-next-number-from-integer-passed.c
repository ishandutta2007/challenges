/*

Create a function that takes a number as an argument, increments the number by +1 and returns the result.
Examples

addition(0) ➞ 1

addition(9) ➞ 10

addition(-3) ➞ -2

*/

#include <assert.h>

int
addition(int x)
{
	return x + 1;
}

int
main(void)
{
	assert(addition(2) == 3);
	assert(addition(-9) == -8);
	assert(addition(0) == 1);
	assert(addition(999) == 1000);
	assert(addition(73) == 74);

	return 0;
}
