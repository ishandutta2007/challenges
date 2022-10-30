/*

Given an integer, output five perfect cubes whose sum is that integer. Note that cubes can be positive, negative, or zero. For example,

-10 == -64 - 64 + 64 + 27 + 27
so for input -10 you could output [-64, -64, 64, 27, 27], though other solutions are possible. Note that you should output the cubes, not the numbers being cubed.

A solution always exists -- you might enjoy puzzling this out for yourself. It's further conjectured that four cubes suffice.

*/

#include <assert.h>
#include <stdio.h>

typedef long long vlong;

vlong
sum(vlong *a, size_t n)
{
	vlong r;
	size_t i;

	r = 0;
	for (i = 0; i < n; i++)
		r += a[i];
	return r;
}

vlong
cube(vlong n)
{
	return n * n * n;
}

/*

https://math.stackexchange.com/questions/207366/can-any-integer-can-be-written-as-the-sum-of-8-integer-cubes
https://proofwiki.org/wiki/Number_is_Sum_of_Five_Cubes
Richard K. Guy, Unsolved Problems in Number Theory

Let n be the number we want to express as a sum of 5 cubes

m is arbitrary
n = (6m+n)^3 + k^3 + k^3 - (k+1)^3 - (k-1)^3
k = ((6m+n)^3 - n)/6

*/

void
so5c(vlong n, vlong r[5])
{
	vlong k, m, p;

	m = 1;
	p = cube((6 * m) + n);
	k = (p - n) / 6;
	r[0] = p;
	r[1] = cube(k);
	r[2] = r[1];
	r[3] = -cube(k + 1);
	r[4] = -cube(k - 1);
}

void
test(vlong n)
{
	vlong c[5];

	so5c(n, c);
	assert(sum(c, 5) == n);
}

int
main(void)
{
	vlong i;

	for (i = -50000LL; i <= 50000LL; i++)
		test(i);

	return 0;
}
