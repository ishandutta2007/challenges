/*

Integers in cosine

From trigonometry we know that

sin(a)=−cos(a+(4∗m+1)π2)

where a
is an angle and m∈Z

(integer).
The task

For an input of a positive integer n calculate the value of the integer k with n digits that minimizes the difference between sin(a) and −cos(a+k). Or in a simpler way, generate the sequence A308879.
First few values

1 digit : 8
2 digits: 33
3 digits: 699
4 digits: 9929
5 digits: 51819
6 digits: 573204
Output

You can create a function or print the result on the standard output. Your program needs to be able to calculate at least the 6 cases in the section above.
Scoring

This is code-golf, shortest code in bytes wins.

*/

#define _GNU_SOURCE
#include <stdio.h>
#include <math.h>

typedef unsigned long long uvlong;

// http://oeis.org/A308879
uvlong
seq(uvlong n)
{
	uvlong b, c, d, i, w, r;
	double e, f, y, z;

	b = 0;
	d = 1;
	c = 10;
	e = 1.0;
	r = b;
	for (i = 0; d < n; i++) {
		y = (i * 4 + 1) * M_PI / 2.0;
		z = round(y);
		f = fabs(z - y);
		w = z;
		if (w >= c) {
			r = b;
			c *= 10;
			e = 1.0;
			b = 0;
			d++;
		}
		if (f < e) {
			e = f;
			b = w;
		}
	}

	return r;
}

int
main(void)
{
	uvlong i;

	for (i = 1; i <= 10; i++)
		printf("%llu\n", seq(i));

	return 0;
}
