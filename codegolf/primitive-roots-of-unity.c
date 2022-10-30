/*

Let z be a complex number. z is an nth primitive root of unity if for a certain positive integer n and for any positive integer k < n .

Challenge

Write a full program or function that, given a positive integer n as input, outputs all of the nth primitive roots of unity.
You may output them in polar form (e^θi or e^iθ, argument should be a decimal with at least 2 decimal places) or rectangular form (a + bi or a similar form, real and imaginary parts should also be decimals),
and they may be outputted in your language's list/array format or as a string with the numbers separated by spaces or newlines.
Built-ins that calculate the nth roots of unity or the nth primitive roots of unity are not allowed.

This is code-golf, so shortest code in bytes wins.
Sample Inputs and Outputs

6 -> e^1.05i, e^-1.05i # polar form
3 -> e^2.094395i, e^-2.094395i # any number of decimal places is OK as long as there are more than 2
8 -> 0.707 + 0.707i, 0.707 - 0.707i, -0.707 + 0.707i, -0.707 - 0.707i # rectangular form
1 -> 1 + 0i # this is OK
1 -> 1 # this is also OK
4 -> 0 + i, 0 - i # this is OK
4 -> i, -i # this is also OK

*/

#include <stdio.h>
#include <math.h>
#include <complex.h>

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

/*

z = e^2tπi is an nth root of 1 if and only if t = k / n for some integer k.
z is primitive if and only if k and n are coprime so gcd(k, n) = 1

*/

size_t
roots(int n, double complex *r)
{
	size_t i;
	int k;

	i = 0;
	for (k = 1; k <= n; k++) {
		if (gcd(k, n) == 1)
			r[i++] = cpow(I, 4.0 * k / n);
	}
	return i;
}

void
test(int n)
{
	double complex r[128];
	size_t i, l;

	l = roots(n, r);
	printf("%d\n", n);
	for (i = 0; i < l; i++)
		printf("%f%+fi\n", creal(r[i]), cimag(r[i]));
	printf("\n");
}

int
main(void)
{
	test(6);
	test(3);
	test(8);
	test(1);
	test(4);

	return 0;
}
