/*

Create a function that returns true when num1 is equal to num2; otherwise return false.
Examples

isSameNum(4, 8) ➞ false

isSameNum(2, 2) ➞  true

isSameNum(2, "2") ➞ false

Notes

Don't forget to return the result.

*/

#include <assert.h>

int
same(int x, int y)
{
	return x == y;
}

int
main(void)
{
	assert(same(4, 8) == 0);
	assert(same(2, 2) == 1);
	assert(same(0, 6) == 0);
	assert(same(2, '2') == 0);

	return 0;
}
