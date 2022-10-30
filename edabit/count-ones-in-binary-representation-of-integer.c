/*

Count the amount of ones in the binary representation of an integer. So for example, since 12 is '1100' in binary, the return value should be 2.
Examples

countOnes(0) ➞ 0

countOnes(100) ➞ 3

countOnes(999) ➞ 8

Notes

The input will always be a valid integer (number).

*/

#include <assert.h>
#include <stdint.h>
#include <limits.h>

#define T uintmax_t

// https://graphics.stanford.edu/~seander/bithacks.html
int
popcnt(T v)
{
	T c;

	v = v - ((v >> 1) & (T) ~(T)0 / 3);
	v = (v & (T) ~(T)0 / 15 * 3) + ((v >> 2) & (T) ~(T)0 / 15 * 3);
	v = (v + (v >> 4)) & (T) ~(T)0 / 255 * 15;
	c = (T)(v * ((T) ~(T)0 / 255)) >> (sizeof(T) - 1) * CHAR_BIT;
	return c;
}

int
main(void)
{
	assert(popcnt(12) == 2);
	assert(popcnt(0) == 0);
	assert(popcnt(100) == 3);
	assert(popcnt(101) == 4);
	assert(popcnt(999) == 8);
	assert(popcnt(1000000000ull) == 13);
	assert(popcnt(123456789) == 16);
	assert(popcnt(1234567890) == 12);
	return 0;
}
