/*

The Simpson index is a measure of diversity of a collection of items with duplicates. It is simply the probability of drawing two different items when picking without replacement uniformly at random.

With n items in groups of n_1, ..., n_k identical items, the probability of two different items is

$$1-\sum_{i=1}^k \frac{n_i(n_i-1)}{n(n -1)}$$

For example, if you have 3 apples, 2 bananas, and 1 carrot, the diversity index is

D = 1 - (6 + 2 + 0)/30 = 0.7333

Alternatively, the number of unordered pairs of different items is 3*2 + 3*1 + 2*1 = 11 out of 15 pairs overall, and 11/15 = 0.7333.

Input:

A string of characters A to Z. Or, a list of such characters. Its length will be at least 2. You may not assume it to be sorted.

Output:

The Simpson diversity index of characters in that string, i.e., the probability that two characters taken randomly with replacement are different. This is a number between 0 and 1 inclusive.

When outputting a float, display at least 4 digits, though terminating exact outputs like 1 or 1.0 or 0.375 are OK.

You may not use built-ins that specifically compute diversity indices or entropy measures. Actual random sampling is fine, as long as you get sufficient accuracy on the test cases.

Test cases

AAABBC 0.73333
ACBABA 0.73333
WWW 0.0
CODE 1.0
PROGRAMMING 0.94545

*/

#include <assert.h>
#include <stdio.h>
#include <string.h>
#include <math.h>

double
simpsonindex(const char *s)
{
	size_t h[256];
	size_t i, n;
	double v;

	memset(h, 0, sizeof(h));
	for (n = 0; s[n]; n++)
		h[s[n] & 0xff]++;

	if (n == 0)
		return 0;

	v = 0;
	for (i = 0; i < 256; i++)
		v += (h[i] * (h[i] - 1));
	return 1 - (v / (n * (n - 1)));
}

void
test(const char *s, double r)
{
	double p;

	p = simpsonindex(s);
	printf("%f\n", p);
	assert(fabs(p - r) < 1e-5);
}

int
main(void)
{
	test("AAABBC", 0.73333);
	test("ACBABA", 0.73333);
	test("WWW", 0.0);
	test("CODE", 1.0);
	test("PROGRAMMING", 0.94545);

	return 0;
}
