/*

A simple pseudo-random number generator looks like this:

s(0) = 123456789
s(n) = (22695477 * s(n-1) + 12345) mod 1073741824

So each number is generated from the previous one.

Using this generator, generate 10 million numbers (i.e. s(0) through s(9,999,999)) and find the 1000 largest numbers in that list. What is the sum of those numbers?

Try to make your solution as efficient as possible.

    Thanks to sim642 for submitting this problem in /r/dailyprogrammer_ideas! If you have a problem that you think would be good, head on over there and help us out!

*/

#include <stdio.h>
#include <stdlib.h>
#include <errno.h>

typedef unsigned long ulong;
typedef long long vlong;

typedef struct {
	ulong a, b, m;
	ulong x;
} LCG;

void
lcginit(LCG *l, ulong s)
{
	l->a = 22695477ul;
	l->b = 12345ul;
	l->m = 1073741824ul;
	l->x = s;
}

ulong
lcgnext(LCG *l)
{
	ulong r;

	r = l->x;
	l->x = (l->a * l->x + l->b) % l->m;
	return r;
}

int
cmp(const void *a, const void *b)
{
	ulong x, y;

	x = *(ulong *)a;
	y = *(ulong *)b;
	if (x > y)
		return -1;
	if (x == y)
		return 0;
	return 1;
}

vlong
solve(ulong n, ulong m, ulong s)
{
	LCG l;
	ulong *v;
	ulong i;
	vlong r;

	v = calloc(n, sizeof(*v));
	if (!v)
		return -errno;

	lcginit(&l, s);
	for (i = 0; i < n; i++)
		v[i] = lcgnext(&l);

	qsort(v, n, sizeof(*v), cmp);

	r = 0;
	for (i = 0; i < m; i++)
		r += v[i];

	free(v);
	return r;
}

int
main(void)
{
	printf("%lld\n", solve(10000000ul, 1000ul, 123456789ul));
	return 0;
}
