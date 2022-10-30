/*

A repdigit is a positive number composed out of the same digit. Create a function that takes an integer and returns whether it's a repdigit or not.
Examples

isRepdigit(66) ➞ true

isRepdigit(0) ➞ true

isRepdigit(-11) ➞ false

Notes

    The number 0 should return true (even though it's not a positive number).
    Check the Resources tab for more info on repdigits.

*/

#include <assert.h>
#include <stdbool.h>
#include <stdio.h>

bool
isrepdigit(int n)
{
	int v;

	if (n < 0)
		return false;

	v = n % 10;
	while (n /= 10) {
		if (v != (n % 10))
			return false;
	}

	return true;
}

int
main(void)
{
	assert(isrepdigit(6) == true);
	assert(isrepdigit(66) == true);
	assert(isrepdigit(666) == true);
	assert(isrepdigit(6666) == true);
	assert(isrepdigit(1001) == false);
	assert(isrepdigit(-11) == false);
	assert(isrepdigit(554) == false);
	assert(isrepdigit(45555) == false);
	assert(isrepdigit(0) == true);
	assert(isrepdigit(55155) == false);

	return 0;
}
