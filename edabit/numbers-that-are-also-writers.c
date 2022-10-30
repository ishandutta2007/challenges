/*

If a number is autobiographical, then the number's digits describe itself.
The first digit is the amount of times the digit 0 appears, the second digit is the amount of times the digit 1 appears, the third digit is the amount of times the digit 2 appears, etc.
This repeats for all digits of the number. The number 6210001000 is autobiographical, because it has six 0's, two 1's, one 2, zero 3's, zero 4's, zero 5's, one 6, zero 7's, zero 8's, and zero 9's.

Create a function that takes an integer n and returns whether or not n is an autobiographical number.
Examples

is_autobiographical(6210001000) ➞ True

is_autobiographical(12345) ➞ False

is_autobiographical(1210) ➞ True
# one 0, two 1's, one 2, zero 3's

is_autobiographical(638) ➞ False

is_autobiographical(0) ➞ False
# claims no zeroes, however zero is the first digit

Notes

    Numbers with more than 10 digits should always return False (9 is the highest digit in base 10, so you can't go higher than 9,999,999,999).
    n is always >= 0 and is always an integer.

*/

#include <assert.h>
#include <stdbool.h>
#include <stdio.h>
#include <string.h>
#include <limits.h>

typedef unsigned long long uvlong;

size_t
digits(uvlong n, uvlong *d)
{
	size_t i;

	i = 0;
	do {
		d[i++] = n % 10;
	} while (n /= 10);
	return i;
}

void
count(uvlong n, uvlong h[10])
{
	memset(h, 0, sizeof(*h) * 10);
	do {
		h[n % 10]++;
	} while (n /= 10);
}

bool
autobiographical(uvlong n)
{
	uvlong d[sizeof(n) * CHAR_BIT];
	uvlong h[10];
	size_t i, l;

	l = digits(n, d);
	if (l > 10)
		return false;
	count(n, h);

	i = 0;
	while (l > 0) {
		if (d[--l] != h[i++])
			return false;
	}

	return true;
}

int
main(void)
{
	assert(autobiographical(6210001000ull) == true);
	assert(autobiographical(12345ull) == false);
	assert(autobiographical(1210ull) == true);
	assert(autobiographical(638ull) == false);
	assert(autobiographical(0ull) == false);
	assert(autobiographical(10000000000ull) == false);
	assert(autobiographical(2020ull) == true);
	assert(autobiographical(3211000ull) == true);
	assert(autobiographical(3434343ull) == false);
	assert(autobiographical(2100ull) == false);

	return 0;
}
