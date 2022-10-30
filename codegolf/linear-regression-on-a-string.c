/*

This challenge is a little tricky, but rather simple, given a string s:

meta.codegolf.stackexchange.com

Use the position of the character in the string as an x coordinate and the ascii value as a y coordinate. For the above string, the resultant set of coordinates would be:

0, 109
1, 101
2, 116
3, 97
4, 46
5, 99
6, 111
7, 100
8, 101
9, 103
10,111
11,108
12,102
13,46
14,115
15,116
16,97
17,99
18,107
19,101
20,120
21,99
22,104
23,97
24,110
25,103
26,101
27,46
28,99
29,111
30,109

Next, you must calculate both the slope and the y-intercept of the set you've garnered using Linear Regression, here's the set above plotted:

Plot

Which results in a best fit line of (0-indexed):

y = 0.014516129032258x + 99.266129032258

Here's the 1-indexed best-fit line:

y = 0.014516129032258x + 99.251612903226

So your program would return:

f("meta.codegolf.stackexchange.com") = [0.014516129032258, 99.266129032258]

Or (Any other sensible format):

f("meta.codegolf.stackexchange.com") = "0.014516129032258x + 99.266129032258"

Or (Any other sensible format):

f("meta.codegolf.stackexchange.com") = "0.014516129032258\n99.266129032258"

Or (Any other sensible format):

f("meta.codegolf.stackexchange.com") = "0.014516129032258 99.266129032258"

Just explain why it is returning in that format if it isn't obvious.

Some clarifying rules:

- Strings are 0-indexed or 1 indexed both are acceptable.
- Output may be on new lines, as a tuple, as an array or any other format.
- Precision of the output is arbitrary but should be enough to verify validity (min 5).

This is code-golf lowest byte-count wins.

*/

#include <assert.h>
#include <stdio.h>
#include <math.h>

size_t
slmean(const char *s, double *xm, double *ym)
{
	size_t i;

	*xm = *ym = 0;
	for (i = 0; s[i]; i++) {
		*xm += i;
		*ym += s[i];
	}

	if (i) {
		*xm /= i;
		*ym /= i;
	}

	return i;
}

void
slcoeff(const char *s, double xm, double ym, double r[2])
{
	double a, b;
	double x, y;
	size_t i;

	a = b = 0;
	for (i = 0; s[i]; i++) {
		x = i;
		y = s[i];

		a += (x - xm) * (y - ym);
		b += (x - xm) * (x - xm);
	}

	r[1] = a / b;
	r[0] = ym - (r[1] * xm);
}

void
linreg(const char *s, double r[2])
{
	double xm, ym;

	r[0] = r[1] = 0;
	if (!slmean(s, &xm, &ym))
		return;

	slcoeff(s, xm, ym, r);
}

void
test(const char *s, double r[2])
{
	double p[2];
	int i;

	linreg(s, p);
	printf("%fx + %f\n", p[1], p[0]);
	for (i = 0; i < 2; i++)
		assert(fabs(p[i] - r[i]) < 1e-12);
}

int
main(void)
{
	test("meta.codegolf.stackexchange.com", (double[2]){99.266129032258, 0.014516129032258});

	return 0;
}
