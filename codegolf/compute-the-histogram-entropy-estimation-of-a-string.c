/*

Write a program or function that estimates the Shannon entropy of a given string.

If a string has n characters, d distinct characters, xi is the i th distinct character, and P(xi) is the probability of that character occuring in the string, then our Shannon entropy estimate for that string is given by:

H = -n\sum\limits_{i=1}^d P(x_i) \log_2 P(x_i)

For the estimation in this challenge we assume that the probability of a character occurring in a string is simply the number of times it occurs divided by the total number of characters.

Your answer must be accurate to at least 3 digits after the period.

Test cases:

"This is a test.", 45.094
"00001111", 8.000
"cwmfjordbankglyphsvextquiz", 122.211
"             ", 0.0

*/

#include <assert.h>
#include <stdio.h>
#include <string.h>
#include <math.h>

size_t
stats(const char *s, size_t h[256])
{
	size_t i;

	memset(h, 0, sizeof(*h) * 256);
	for (i = 0; s[i]; i++)
		h[s[i] & 0xff]++;
	return i;
}

double
shannon(const char *s, size_t h[256], size_t n)
{
	double p, r;
	size_t i;
	int c;

	r = 0;
	for (i = 0; s[i]; i++) {
		c = s[i] & 0xff;
		if (!h[c])
			continue;
		p = (h[c] * 1.0) / n;
		r += p * log2(p);
		h[c] = 0;
	}
	return -r * n;
}

double
entropy(const char *s)
{
	size_t h[256], n;

	n = stats(s, h);
	return shannon(s, h, n);
}

void
test(const char *s, double r)
{
	double p;

	p = entropy(s);
	printf("%.3f\n", p);
	assert(fabs(p - r) < 1e-3);
}

int
main(void)
{
	test("This is a test.", 45.094);
	test("00001111", 8.000);
	test("cwmfjordbankglyphsvextquiz", 122.211);
	test("             ", 0.0);

	return 0;
}
