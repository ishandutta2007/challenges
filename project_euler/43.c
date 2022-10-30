/*

The number, 1406357289, is a 0 to 9 pandigital number because it is made up of each of the digits 0 to 9 in some order, but it also has a rather interesting sub-string divisibility property.

Let d1 be the 1st digit, d2 be the 2nd digit, and so on. In this way, we note the following:

    d2d3d4=406 is divisible by 2
    d3d4d5=063 is divisible by 3
    d4d5d6=635 is divisible by 5
    d5d6d7=357 is divisible by 7
    d6d7d8=572 is divisible by 11
    d7d8d9=728 is divisible by 13
    d8d9d10=289 is divisible by 17

Find the sum of all 0 to 9 pandigital numbers with this property.

*/

#include <stdio.h>

#define nelem(x) (sizeof(x) / sizeof(x[0]))

typedef unsigned long long uvlong;

uvlong
mknum(uvlong *p, uvlong n)
{
	uvlong i, r;

	r = 0;
	for (i = 0; i < n; i++)
		r = (r * 10) + p[i];
	return r;
}

void
swap(uvlong *x, uvlong *y)
{
	uvlong t;

	t = *y;
	*y = *x;
	*x = t;
}

void
perm(uvlong p[10], uvlong n, void (*f)(uvlong[10], void *), void *ud)
{
	uvlong i, j;

	f(p, ud);
	for (i = n; i < 10; i++) {
		for (j = i + 1; j < 10; j++) {
			swap(&p[i], &p[j]);
			perm(p, i + 1, f, ud);
			swap(&p[i], &p[j]);
		}
	}
}

void
pansum(uvlong p[10], void *ud)
{
	static const uvlong tab[] = {
	    2,
	    3,
	    5,
	    7,
	    11,
	    13,
	    17,
	};

	uvlong i, n, *r;

	for (i = 0; i < nelem(tab); i++) {
		n = mknum(p + i + 1, 3);
		if ((n % tab[i]) != 0)
			return;
	}

	r = ud;
	n = mknum(p, 10);
	*r += n;

	printf("num: %llu\n", n);
}

uvlong
solve(void)
{
	uvlong i, r, p[10];

	r = 0;
	for (i = 0; i < 10; i++)
		p[i] = i;
	perm(p, 0, pansum, &r);
	return r;
}

int
main(void)
{
	printf("sum: %llu\n", solve());
	return 0;
}
