/*

Create a function double UniqueFract(), which should sum all irreducible regular fractions between 0 and 1,
in the numerator and denominator of which there are only single-digit numbers: 1/2, 1/3, 1/4, ... 2/3, 2/4, ... 8/9.

Task

UniqueFract() ➞ sum

Notes

    Of the fractions 1/2 2/4 3/6 4/8, only 1/2 is included in the sum.
    Don't include any values >= 1.
    Both the numerator and denominator are single digit.

*/

#include <assert.h>
#include <stdio.h>

unsigned
gcd(unsigned a, unsigned b)
{
	unsigned t;

	while (b) {
		t = b;
		b = a % b;
		a = t;
	}
	return a;
}

double
uniqfract(void)
{
	unsigned n, d;
	double r;

	r = 0;
	for (n = 1; n <= 9; n++) {
		for (d = n + 1; d <= 9; d++) {
			if (gcd(n, d) == 1)
				r += n * 1.0 / d;
		}
	}
	return r;
}

int
main(void)
{
	assert(uniqfract() == 13.5);

	return 0;
}
