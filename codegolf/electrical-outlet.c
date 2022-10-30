/*

This is a problem from NCPC 2005. Roy has an apartment with only one single electrical outlet, but he has a bunch of power strips.
Compute the maximum number of outlets he can have using the power strips he has.
The number of outlets per power strip is given as input.

It turns out that if the number of outlets of the strips respectively are

p1,p2,…,pn

then the number of outlets is
1−n+∑ipi,

or

1+p1−1+p2−1+⋯+pn−1.

The input to the program or function is a non-empty series of positive integers.
Examples

2 3 4
> 7
2 4 6
> 10
1 1 1 1 1 1 1 1
> 1
100 1000 10000
> 11098

*/

#include <assert.h>
#include <stdio.h>

#define nelem(x) (sizeof(x) / sizeof(x[0]))

typedef unsigned long long uvlong;

uvlong
outlets(uvlong *a, size_t n)
{
	uvlong r;
	size_t i;

	r = 0;
	for (i = 0; i < n; i++)
		r += a[i];
	return (r >= n) ? r - n + 1 : 0;
}

int
main(void)
{
	uvlong a1[] = {2, 3, 4};
	uvlong a2[] = {2, 4, 6};
	uvlong a3[] = {1, 1, 1, 1, 1, 1, 1, 1};
	uvlong a4[] = {100, 1000, 10000};

	assert(outlets(a1, nelem(a1)) == 7);
	assert(outlets(a2, nelem(a2)) == 10);
	assert(outlets(a3, nelem(a3)) == 1);
	assert(outlets(a4, nelem(a4)) == 11098);

	return 0;
}
