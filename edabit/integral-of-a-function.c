/*

Create a function that takes numbers b, m, and n as arguments and returns the definite integral of the function f(x)=(b+1)*x^b with respect to x from x=m to x=n, where b, m, and n are constants.

Examples

integral(0, 2, 5) ➞ 3

integral(2, 4, 7) ➞ 279

integral(5, 9, 3) ➞ -530712

Notes

    ^ in the context of this challenge means "to the power of", also known as the "exponent" operator.
    Assume that b will be an integer greater than or equal to 0.
    m and n can be any integer, both positive and negative.

*/

#include <assert.h>
#include <stdio.h>

typedef long long vlong;

vlong
ipow(vlong x, vlong y)
{
	vlong i, p;

	if (y < 0)
		return 0;

	p = 1;
	for (i = 0; i < y; i++)
		p *= x;
	return p;
}

vlong
integral(vlong b, vlong m, vlong n)
{
	return ipow(n, b + 1) - ipow(m, b + 1);
}

int
main(void)
{
	assert(integral(0, 2, 5) == 3);
	assert(integral(2, 4, 7) == 279);
	assert(integral(5, 9, 3) == -530712ll);
	assert(integral(10, 2, -4) == -4196352ll);
	assert(integral(7, 2, 2) == 0);

	return 0;
}
