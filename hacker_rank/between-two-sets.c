/*

You will be given two arrays of integers and asked to determine all integers that satisfy the following two conditions:

The elements of the first array are all factors of the integer being considered
The integer being considered is a factor of all elements of the second array
These numbers are referred to as being between the two arrays. You must determine how many such numbers exist.

For example, given the arrays a=[2 6] and b=[24 36], 
there are two numbers between them: 6 and 12. 
6%2=0, 6%6=0, 24%6=0 and 36%6=0 for the first value.

Similarly, 12%2=0, 12%6=0 and 24%12=0, 36%12=0.

*/

#include <stdio.h>
#include <math.h>
#include <limits.h>

#define nelem(x) (sizeof(x) / sizeof(x[0]))
#define max(a, b) (((a) > (b)) ? (a) : (b))

int
gcd(int a, int b)
{
	int t;
	while (b) {
		t = b;
		b = a % b;
		a = t;
	}
	return a;
}

int
lcm(int a, int b)
{
	return (a * b) / gcd(a, b);
}

int
gcdv(int *a, size_t n)
{
	int i, v;

	if (n == 0)
		return 0;

	v = a[0];
	for (i = 1; i < n; i++)
		v = gcd(v, a[i]);
	return v;
}

int
lcmv(int *a, size_t n)
{
	int i, v;

	if (n == 0)
		return 0;

	v = a[0];
	for (i = 1; i < n; i++)
		v = lcm(v, a[i]);
	return v;
}

int
divisors(int n)
{
	int i, c, l;

	c = 0;
	l = sqrt(n);
	for (i = 1; i <= l; i++) {
		if ((n % i) == 0)
			c += 2;
	}
	if (l * l == n)
		c--;
	return c;
}

int
between(int *a, size_t na, int *b, size_t nb)
{
	int l, g;

	if (na == 0 || nb == 0)
		return 0;

	l = lcmv(a, na);
	g = gcdv(b, nb);
	if (l == 0 || g % l != 0)
		return 0;
	return divisors(g / l);
}

int
between_slow(int *a, size_t na, int *b, size_t nb)
{
	int i, c, f, n;
	size_t j;

	n = INT_MIN;
	for (j = 0; j < na; j++)
		n = max(a[j], n);
	for (j = 0; j < nb; j++)
		n = max(b[j], n);

	c = 0;
	for (i = 1; i <= n; i++) {
		f = 1;
		for (j = 0; j < na; j++) {
			if (a[j] == 0 || i % a[j] != 0) {
				f = 0;
				goto next;
			}
		}

		for (j = 0; j < nb; j++) {
			if (b[j] % i != 0) {
				f = 0;
				goto next;
			}
		}

	next:
		c += f;
	}

	return c;
}

int
main(void)
{
	int a[] = {2, 4};
	int b[] = {16, 32, 96};
	printf("%d %d\n", between_slow(a, nelem(a), b, nelem(b)),
	       between(a, nelem(a), b, nelem(b)));

	int c[] = {2, 6};
	int d[] = {24, 36};
	printf("%d %d\n", between_slow(c, nelem(c), d, nelem(d)),
	       between(c, nelem(c), d, nelem(d)));

	return 0;
}
