/*

A number may not be a palindrome, but its descendant can be.
A number's direct child is created by summing each pair of adjacent digits to create the digits of the next number.

For instance, 123312 is not a palindrome, but its next child 363 is, where: 3 = 1 + 2; 6 = 3 + 3; 3 = 1 + 2.

Create a function that returns true if the number itself is a palindrome or any of its descendants down to the first 2 digit number (a 1-digit number is trivially a palindrome).
Examples

PalindromeDescendant(11211230) ➞ false
// 11211230 ➞ 2333 ➞ 56

palindromeDescendant(13001120) ➞ true
// 13001120 ➞ 4022 ➞ 44

PalindromeDescendant(23336014) ➞ true
// 23336014 ➞ 5665

PalindromeDescendant(11) ➞ true
// Number itself is a palindrome.

Notes

Numbers will always have an even number of digits.

*/

#include <assert.h>
#include <stdbool.h>
#include <stdio.h>
#include <limits.h>

typedef unsigned long long uvlong;

uvlong
adjsum(uvlong x)
{
	uvlong d[sizeof(x) * CHAR_BIT];
	uvlong n, r;

	for (n = 0; x; x /= 100)
		d[n++] = (x % 10) + ((x / 10) % 10);

	for (r = 0; n; n--) {
		r *= 10;
		if (d[n - 1] >= 10)
			r *= 10;
		r += d[n - 1];
	}
	return r;
}

bool
palidesc(uvlong x)
{
	char b[sizeof(x) * CHAR_BIT];
	int i, n;

	n = snprintf(b, sizeof(b), "%llu", x);
	if (n < 2)
		return true;
	if (n & 1)
		return false;

	for (i = 0; i < n / 2; i++) {
		if (b[i] != b[n - i - 1])
			return false;
	}
	return true;
}

bool
descendant(uvlong x)
{
	while (!palidesc(x)) {
		if (x < 100)
			return false;
		x = adjsum(x);
	}
	return true;
}

int
main(void)
{
	assert(descendant(11211230ull) == false);
	assert(descendant(13001120ull) == true);
	assert(descendant(23336014ull) == true);
	assert(descendant(11ull) == true);
	assert(descendant(1122ull) == false);
	assert(descendant(332233ull) == true);
	assert(descendant(10210112ull) == true);
	assert(descendant(9735ull) == false);
	assert(descendant(97358817ull) == false);
	assert(descendant(7ull) == true);

	return 0;
}
