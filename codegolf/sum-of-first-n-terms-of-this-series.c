/*

Given a digit x (between 0 to 9, inclusive) and a number n, calculate the sum of the first n terms of the following sequence:

x,10x+x,100x+10x+x,…

For example, if x is 6 and n is 2, then the result will be 6+66 meaning 72.

There can be trailing whitespace in the output but not leading whitespace.

*/

#include <assert.h>
#include <stdio.h>

typedef unsigned long long uvlong;

uvlong
sum(uvlong x, uvlong n)
{
	uvlong i, p, r;

	p = x;
	r = 0;
	for (i = 0; i < n; i++) {
		r += x;
		x = (x * 10) + p;
	}
	return r;
}

int
main(void)
{
	assert(sum(6, 2) == 72);
	assert(sum(6, 3) == 738);

	return 0;
}
