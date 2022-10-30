/*

Create a function that takes a number as an argument and returns the highest digit in that number.

Examples

highestDigit(4666) ➞ 6

highestDigit(544) ➞ 5

highestDigit(379) ➞ 9

highestDigit(2) ➞ 2

highestDigit(377401) ➞ 7

Notes

    Don't forget to return the result.
    If you get stuck on a challenge, find help in the Resources tab.
    If you're really stuck, unlock solutions in the Solutions tab.

*/

#include <assert.h>
#include <stdio.h>

#define max(a, b) (((a) > (b)) ? (a) : (b))

typedef unsigned long long uvlong;

uvlong
highestdigit(uvlong n)
{
	uvlong r;

	r = 0;
	while (n) {
		r = max(r, n % 10);
		n /= 10;
	}
	return r;
}

int
main(void)
{
	assert(highestdigit(4666ull) == 6);
	assert(highestdigit(544ull) == 5);
	assert(highestdigit(51ull) == 5);
	assert(highestdigit(0ull) == 0);
	assert(highestdigit(7495037ull) == 9);
	assert(highestdigit(222222ull) == 2);
	assert(highestdigit(379ull) == 9);
	assert(highestdigit(2ull) == 2);
	assert(highestdigit(377401ull) == 7);

	return 0;
}
