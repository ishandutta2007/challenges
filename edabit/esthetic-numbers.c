/*

A number is Esthetic if, in any base from base2 up to base10, the absolute difference between every pair of its adjacent digits is constantly equal to 1.

num = 441 (base10)
// Adjacent pairs of digits:
// |4, 4|, |4, 1|
// The absolute difference is not constant
// 441 is not Esthetic in base10

441 in base4 = 12321
// Adjacent pairs of digits:
// |1, 2|, |2, 3|, |3, 2|, |2, 1|
// The absolute difference is constant and is equal to 1
// 441 is Esthetic in base4

Given a positive integer num, implement a function that returns an array containing the bases (as integers from 2 up to 10) in which num results to be Esthetic, or a string "Anti-Esthetic" if no base makes num Esthetic.

Examples

esthetic(10) ➞ [2, 3, 8, 10]
// 10 in base2 = 1010
// 10 in base3 = 101
// 10 in base8 = 12
// 10 in base10 = 10

esthetic(23) ➞ [3, 5, 7, 10]
// 23 in base3 = 212
// 23 in base5 = 43
// 23 in base7 = 32
// 23 in base10 = 23

esthetic(666) ➞ [8]
// 666 in base8 = 1232

Notes

N/A

*/

#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>

#define nelem(x) (sizeof(x) / sizeof(x[0]))

typedef unsigned long long uvlong;

uvlong
base10x(uvlong n, uvlong b)
{
	uvlong d[sizeof(n) * CHAR_BIT];
	uvlong i, r;

	if (b == 0)
		return 0;
	for (i = 0; n; n /= b)
		d[i++] = n % b;
	for (r = 0; i; i--)
		r = (r * 10) + d[i - 1];
	return r;
}

int
constant(uvlong n)
{
	int x, y;

	y = n % 10;
	while (n /= 10) {
		x = y;
		y = n % 10;
		if (abs(x - y) != 1)
			return 0;
	}
	return 1;
}

size_t
esthetic(uvlong n, uvlong *b)
{
	size_t i, j;

	j = 0;
	for (i = 2; i <= 10; i++) {
		if (constant(base10x(n, i)))
			b[j++] = i;
	}
	return j;
}

void
test(uvlong n, uvlong *r, size_t nr)
{
	uvlong b[10];
	size_t nb;

	nb = esthetic(n, b);
	assert(nb == nr);
	if (nb)
		assert(!memcmp(b, r, sizeof(*r) * nr));
}

int
main(void)
{
	uvlong r1[] = {2, 3, 8, 10};
	uvlong r2[] = {3, 5, 7, 10};
	uvlong r3[] = {8};
	uvlong r4[] = {5, 6};
	uvlong r5[] = {2, 3, 4, 5, 6, 7, 8, 9, 10};
	uvlong r6[] = {4, 7, 9, 10};
	uvlong r7[] = {4, 6, 9};
	uvlong r8[] = {9};
	uvlong r9[] = {7};

	test(10, r1, nelem(r1));
	test(23, r2, nelem(r2));
	test(666, r3, nelem(r3));
	test(13, r4, nelem(r4));
	test(1, r5, nelem(r5));
	test(9, r6, nelem(r6));
	test(74, NULL, 0);
	test(740, r7, nelem(r7));
	test(928, NULL, 0);
	test(259259ull, r8, nelem(r8));
	test(883271ull, NULL, 0);
	test(1080898ull, r9, nelem(r9));
	test(1080899ull, NULL, 0);

	return 0;
}
