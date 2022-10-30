/*
The Sine, Cosine of x can be computed as follows.

sin(x) = x - x3/3! + x5/5! - x7/7! + x9/9! ....

cos(x) = 1 - x2/2! + x4/4! - x6/6! + x8/8! ....

Your task is to compute the Sine and Cosine for given values of x (where x is in radians) using the above series upto 5 terms.
*/
#include <stdio.h>

int
tfact(int n)
{
	int tab[] = {1, 1, 2, 6, 24, 120, 720, 5040, 40320, 362880};
	return tab[n];
}

double
tpow(double x, int n)
{
	double r;
	int i;

	r = x;
	for (i = 1; i < n; i++)
		r *= x;
	return r;
}

double
tsin(double x)
{
	return x - tpow(x, 3)/tfact(3) + tpow(x, 5)/tfact(5) - tpow(x, 7)/tfact(7) + tpow(x, 9)/tfact(9);
}

double
tcos(double x)
{
	return 1 - tpow(x, 2)/tfact(2) + tpow(x, 4)/tfact(4) - tpow(x, 6)/tfact(6) + tpow(x, 8)/tfact(8);
}

void
calc(double x)
{
	printf("%.3lf\n%.3lf\n", tsin(x), tcos(x));
}

int
main(void)
{
	calc(2.83);
	calc(3.24);
	calc(0.99);
	calc(2.74);
	calc(5.04);
	return 0;
}
