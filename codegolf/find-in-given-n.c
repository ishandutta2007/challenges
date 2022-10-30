/*

The Challenge

In as few characters as possible, find the value of i^n, given n is a positive integer greater than 0. This should be outputted as a String.

For those that don't know, i is defined such that i^2=−1.

So:

i^1=i
i^2=−1
i^3=−i
i^4=1

This then repeats..

Rules

    If your language supports complex numbers, don't use any functions or arithmetic that could work this out.
    Floating point inaccuracies are fine for answers that would return decimals anyway, but integer inputs should give exact results

Bonus Points

-5 if you can work the value out where n is also negative

-15 if you can work out the value for any real number (this bonus includes the -5 from the above bonus)

Good luck!

*/

#include <stdio.h>
#include <complex.h>

int
mod(int x, int m)
{
	x %= m;
	if (x < 0)
		x += m;
	return x;
}

complex double
in(int n)
{
	static const double complex tab[] = {
	    1,
	    I,
	    -1,
	    -I,
	};
	return tab[mod(n, 4)];
}

int
main(void)
{
	complex double r;
	int i;

	for (i = -12; i <= 12; i++) {
		r = in(i);
		printf("%- 2d %.0f%+.0fi\n", i, creal(r), cimag(r));
	}
	return 0;
}
