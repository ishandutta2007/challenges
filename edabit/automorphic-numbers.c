/*

A number n is automorphic if n^2 ends in n.

For example: n=5, n^2=25

Create a function that takes a number and returns true if the number is automorphic, false if it isn't.
Examples

isAutomorphic(5) ➞ true

isAutomorphic(8) ➞ false

isAutomorphic(76) ➞ true

Notes

Squaring numbers can make them get quite large.

*/

#include <assert.h>
#include <stdbool.h>
#include <stdio.h>
#include <inttypes.h>

bool
isautomorphic(uintmax_t n)
{
	uintmax_t m;

	m = n * n;
	while (n) {
		if (n % 10 != m % 10)
			return false;
		n /= 10;
		m /= 10;
	}
	return true;
}

int
main(void)
{
	assert(isautomorphic(0) == true);
	assert(isautomorphic(1) == true);
	assert(isautomorphic(5) == true);
	assert(isautomorphic(6) == true);
	assert(isautomorphic(25) == true);
	assert(isautomorphic(76) == true);
	assert(isautomorphic(7109376) == true);
	assert(isautomorphic(36) == false);
	assert(isautomorphic(100) == false);
	assert(isautomorphic(11) == false);
	assert(isautomorphic(6025) == false);
	assert(isautomorphic(3) == false);
	assert(isautomorphic(1376) == false);
	assert(isautomorphic(8) == false);

	return 0;
}
