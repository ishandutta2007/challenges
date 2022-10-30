/*

You are given a polynomial of degree N with integer coefficients. Your task is to find the value of this polynomial at some K different integers, modulo 786433.

*/

#include <stdio.h>

#define nelem(x) (sizeof(x) / sizeof(x[0]))

int
modadd(int a, int b, int m)
{
	return ((a % m) + (b % m)) % m;
}

int
modmul(int a, int b, int m)
{
	return ((a % m) * (b % m)) % m;
}

int
eval(int *a, size_t n, int x)
{
	size_t i;
	int r, s, p, m;

	m = 786433;
	r = 0;
	p = 1;
	for (i = 0; i < n; i++) {
		s = modmul(a[i], p, m);
		r = modadd(r, s, m);
		p = modmul(p, x, m);
	}
	return r;
}

int
main(void)
{
	int a[] = {1, 2, 3};
	printf("%d\n", eval(a, nelem(a), 7));
	printf("%d\n", eval(a, nelem(a), 8));
	printf("%d\n", eval(a, nelem(a), 9));
	return 0;
}
