/*

Challenge

Your goal is, given two positive integer numbers a and b, to calculate (and output) a ^ b without using either multiplication, division and the power itself (not directly, at least). And, of course, built-in exponentiation functions.
Scoring

This is code-golf, so the shorter, the better.
Test cases

Input => Output
2, 3 => 8
5, 5 => 3125
100, 4 => 100000000
17, 9 => 118587876497
0, 1 => 0
3921, 0 => 1

*/

#include <assert.h>
#include <stdio.h>

typedef unsigned long long uvlong;

uvlong
mul(uvlong a, uvlong b)
{
	uvlong i, r;

	r = 0;
	for (i = 0; i < b; i++)
		r += a;
	return r;
}

uvlong
powi(uvlong a, uvlong b)
{
	uvlong i, r;

	r = 1;
	for (i = 0; i < b; i++)
		r = mul(r, a);
	return r;
}

int
main(void)
{
	assert(powi(2, 3) == 8);
	assert(powi(5, 5) == 3125);
	assert(powi(100, 4) == 100000000ull);
	assert(powi(17, 9) == 118587876497ull);
	assert(powi(0, 1) == 0);
	assert(powi(3921, 0) == 1);
	assert(powi(245, 0) == 1);
	assert(powi(0, 5465) == 0);
	assert(powi(0, 0) == 1);

	return 0;
}
