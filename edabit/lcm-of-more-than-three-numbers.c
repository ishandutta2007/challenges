/*

Create a function that takes an array of more than three numbers as an argument and returns the Least Common Multiple (LCM).

Notes

In math, the LCM is the smallest positive number that is a multiple of two or more numbers.

*/

#include <stdio.h>
#include <stdlib.h>

#define nelem(x) (sizeof(x) / sizeof(x[0]))

long
gcd(long a, long b)
{
	long t;

	while (b) {
		t = b;
		b = a % b;
		a = t;
	}
	return a;
}

long
lcm(long a, long b)
{
	return labs(a * b) / gcd(a, b);
}

long
lcmv(long *a, size_t n)
{
	long l;
	size_t i;

	if (n == 0)
		return 0;

	l = a[0];
	for (i = 1; i < n; i++)
		l = lcm(l, a[i]);
	return l;
}

int
main(void)
{
	long a1[] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
	long a2[] = { 13, 6, 17, 18, 19, 20, 37 };
	long a3[] = { 44, 64, 12, 17, 65 };
	long a4[] = { 200, 30, 18, 11, 8, 64, 34 };

	printf("%ld\n", lcmv(a1, nelem(a1)));
	printf("%ld\n", lcmv(a2, nelem(a2)));
	printf("%ld\n", lcmv(a3, nelem(a3)));
	printf("%ld\n", lcmv(a4, nelem(a4)));

	return 0;
}
