/*

A number is narcissistic when the sum of its digits, with each digit raised to the power of digits quantity, is equal to the number itself.

153 ➞ 3 digits ➞ 1³ + 5³ + 3³ = 1 + 125 + 27 = 153 ➞ Narcissistic
84 ➞ 2 digits ➞ 8² + 4² = 64 + 16 = 80 ➞ Not narcissistic

Given a positive integer n, implement a function that returns true if the number is narcissistic, and false if it's not.
Examples

isNarcissistic(8208) ➞ true
// 8⁴ + 2⁴ + 0⁴ + 8⁴ = 8208

isNarcissistic(22) ➞ false
// 2² + 2² = 8

isNarcissistic(9) ➞ true
// 9¹ = 9

Notes

    Trivially, any number in the 1-9 range is narcissistic and any two-digit number is not.
    Curious fact: Only 88 numbers are narcissistic.

*/

#include <assert.h>
#include <stdbool.h>
#include <limits.h>

typedef unsigned long long uvlong;

uvlong
ipow(uvlong x, uvlong y)
{
	uvlong i, p;

	p = 1;
	for (i = 0; i < y; i++)
		p *= x;
	return p;
}

bool
narcissistic(uvlong x)
{
	uvlong d[sizeof(x) * CHAR_BIT];
	uvlong i, n, v;

	v = x;
	for (n = 0; v; v /= 10)
		d[n++] = v % 10;

	v = 0;
	for (i = 0; i < n; i++) {
		v += ipow(d[i], n);
		if (v > x)
			return false;
	}
	return v == x;
}

int
main(void)
{
	assert(narcissistic(153) == true);
	assert(narcissistic(84) == false);
	assert(narcissistic(8208) == true);
	assert(narcissistic(22) == false);
	assert(narcissistic(9) == true);
	assert(narcissistic(6) == true);
	assert(narcissistic(1741725ull) == true);
	assert(narcissistic(66) == false);
	assert(narcissistic(65239ull) == false);
	assert(narcissistic(886243ull) == false);
	assert(narcissistic(92727ull) == true);
	assert(narcissistic(472335975ull) == true);
	assert(narcissistic(42300981ull) == false);
	assert(narcissistic(548834ull) == true);

	return 0;
}
