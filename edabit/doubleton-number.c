/*

Mubashir was reading about Doubleton Numbers on Wikipedia.

A natural number is a "Doubleton Number", if it contains exactly two distinct digits. For example, 23, 35, 100, 12121 are doubleton numbers, and 123 and 114455 are not.

Create a function which takes a number n and finds the next doubleton number.
Examples

doubleton(10) ➞ 12
// 12 has only two distinct numbers 1 and 2

doubleton(120) ➞ 121
// 121 has only two distinct numbers 1 and 2

doubleton(1234) ➞ 1311
// 1311 has only two distinct numbers 1 and 3

Notes

N/A

*/

#include <assert.h>
#include <stdio.h>
#include <string.h>
#include <limits.h>

typedef unsigned long long uvlong;

int
isdoubleton(uvlong n)
{
	uvlong h[10];
	uvlong c;

	memset(h, 0, sizeof(h));

	c = 0;
	do {
		c += (++h[n % 10] == 1);
	} while (n /= 10);

	return c == 2;
}

uvlong
doubleton(uvlong n)
{
	uvlong i;

	for (i = n + 1; i < ULLONG_MAX; i++) {
		if (isdoubleton(i))
			return i;
	}
	return 0;
}

int
main(void)
{
	assert(doubleton(10) == 12);
	assert(doubleton(120) == 121);
	assert(doubleton(1234) == 1311);
	assert(doubleton(130) == 131);
	assert(doubleton(1434) == 1441);
	assert(doubleton(20) == 21);
	assert(doubleton(5) == 10);
	assert(doubleton(131) == 133);
	assert(doubleton(1000000ull) == 1000001ull);

	return 0;
}
