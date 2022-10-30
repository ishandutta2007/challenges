/*

Create a function that returns true if an integer is evenly divisible by 5, and false otherwise.
Examples

divisibleByFive(5) ➞ true

divisibleByFive(-55) ➞ true

divisibleByFive(37) ➞ false

Notes

    Don't forget to return the result.
    If you get stuck on a challenge, find help in the Resources tab.
    If you're really stuck, unlock solutions in the Solutions tab.

*/

#include <assert.h>
#include <stdlib.h>

int
div5(int x)
{
	return abs(x) % 5 == 0;
}

int
main(void)
{
	assert(div5(7) == 0);
	assert(div5(5) == 1);
	assert(div5(15) == 1);
	assert(div5(33) == 0);
	assert(div5(-18) == 0);
	assert(div5(999) == 0);
	assert(div5(2) == 0);
	assert(div5(37) == 0);
	assert(div5(-55) == 1);

	return 0;
}
