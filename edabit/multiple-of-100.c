/*

Create a function that takes an integer and returns true if it's divisible by 100, otherwise return false.
Examples

divisible(1) ➞ false

divisible(1000) ➞ true

divisible(100) ➞ true

Notes

    Don't forget to return the result.
    If you get stuck on a challenge, find help in the Resources tab.
    If you're really stuck, unlock solutions in the Solutions tab.

*/

#include <assert.h>
#include <stdlib.h>

int
divisible(int n)
{
	return abs(n) % 10 == 0;
}

int
main(void)
{
	assert(divisible(1) == 0);
	assert(divisible(100) == 1);
	assert(divisible(1000) == 1);
	assert(divisible(111000) == 1);
	assert(divisible(-1) == 0);
	assert(divisible(0) == 1);
	assert(divisible(-100) == 1);

	return 0;
}
