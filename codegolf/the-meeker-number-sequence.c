/*

The Meeker numbers are a 7 digit number in form of abcdefg, where a×b=10c+d and d×e=10f+g. As an example 6742612 is a meeker number, here 6×7=10×4+2 and 2×6=10×1+2, so it is a meeker number.

Additionally, a Meeker number does not have any leading zeros (so a≠0)

The Challenge
Your program can do one of the following tasks:

Take a positive integer n and output the nth Meeker number (0 or 1 indexed, your choice. If 0 indexed, n will be a non-negative integer)
Take a positive integer n and output the first n Meeker numbers
Output all 900 Meeker numbers
Rules
You may take an empty input if you output all Meeker numbers
Standard loopholes are forbidden.
Trailing whitespace is allowed.
If possible, please link to an online interpreter (e.g. TIO) to run your program on.
Please explain your answer. This is not necessary, but it makes it easier for others to understand.
Languages newer than the question are allowed. This means you could create your own language where the empty program calculates this number, but don't expect any upvotes.
This is code-golf, so shortest code in bytes wins!
The first few Meeker numbers are

1000000
1000100
1000200
1000300
1000400
1000500
1000600
1000700
1000800
1000900
1101000
1101101
1101202
1101303
1101404
1101505
1101606
1101707
1101808
1101909
...
Thanks to @Adám for the detailed analysis and @cairdcoinheringaahing for the editing rework

*/

#include <assert.h>
#include <stdio.h>

typedef unsigned long long uvlong;

int
meeker(uvlong n)
{
	uvlong a, b, c, d, e, f, g;

	if (n < 1000000ULL || n >= 10000000ULL)
		return 0;

	a = (n / 1000000ULL) % 10;
	b = (n / 100000ULL) % 10;
	c = (n / 10000ULL) % 10;
	d = (n / 1000ULL) % 10;
	e = (n / 100ULL) % 10;
	f = (n / 10ULL) % 10;
	g = (n / 1ULL) % 10;

	if ((a * b) != (10 * c + d))
		return 0;
	if ((d * e) != (10 * f + g))
		return 0;
	return 1;
}

uvlong
seq(uvlong n)
{
	uvlong c, i, v;

	c = 0;
	v = 1000000ULL;
	for (i = 0; i < n; i++) {
		for (; v < 10000000ULL; v++) {
			if (meeker(v)) {
				printf("%llu\n", v++);
				c++;
				break;
			}
		}
	}
	return c;
}

int
main(void)
{
	assert(seq(1000) == 900);

	return 0;
}
