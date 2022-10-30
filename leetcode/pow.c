/*

Implement pow(x, n), which calculates x raised to the power n (xn).

Note:

    -100.0 < x < 100.0
    n is a 32-bit signed integer, within the range [−231, 231 − 1]
*/

#include <stdio.h>
#include <stdlib.h>

double
xpow(double x, int n)
{
	double r;
	unsigned s;

	if (x == 1 || n == 0)
		return 1;
	if (n == 1)
		return x;

	r = 1;
	s = abs(n);
	if (n < 0)
		x = 1 / x;

	while (s) {
		if (s & 1)
			r *= x;
		x *= x;
		s >>= 1;
	}

	return r;
}

int
main(void)
{
	printf("%lf\n", xpow(2, 10));
	printf("%lf\n", xpow(2.1, 3));
	printf("%lf\n", xpow(2, -2));
	printf("%lf\n", xpow(2, 0));
	printf("%lf\n", xpow(30.5234, 5));

	return 0;
}
