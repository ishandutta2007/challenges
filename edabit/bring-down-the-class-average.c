/*

What is the percentage you can score on a test, which singlehandedly brings down the class average by 5%?
Given an array of your classmates scores, create a function that returns the answer.
Round to the nearest percent.

Examples

takeDownAverage(["95%", "83%", "90%", "87%", "88%", "93%"]) ➞ "54%"

takeDownAverage(["10%"]) ➞ "0%"

takeDownAverage(["53%", "79%"]) ➞ "51%"

Notes

No tests will include empty arrays or require negative percentages.
Note that you need to return a string.

*/

#include <assert.h>
#include <stdio.h>
#include <string.h>

#define nelem(x) (sizeof(x) / sizeof(x[0]))

char *
takedown(const char **s, size_t n, char *b, size_t m)
{
	unsigned v, x, y, z;
	size_t i;

	if (n == 0)
		return NULL;

	y = 0;
	for (i = 0; i < n; i++) {
		if (sscanf(s[i], "%u%%", &v) != 1)
			continue;
		y += v;
	}

	// y/n - x/(n+1) = 5
	// y + y/n - 5(n+1) = x
	// need to round y/n in integer land
	// and handle the case where we can't bring down 5%
	x = y + ((y + (n >> 1)) / n);
	z = 5 * (n + 1);
	if (x < z)
		return NULL;
	snprintf(b, m, "%u%%", x - z - y);
	return b;
}

void
test(const char **s, size_t n, const char *r)
{
	char b[80], *p;

	p = takedown(s, n, b, sizeof(b));
	if (p == NULL)
		assert(p == r);
	else
		assert(!strcmp(b, r));
}

int
main(void)
{
	const char *s1[] = {
	    "95%",
	    "83%",
	    "90%",
	    "87%",
	    "88%",
	    "93%",
	};
	const char *s2[] = {
	    "10%",
	};
	const char *s3[] = {
	    "53%",
	    "79%",
	};
	const char *s4[] = {
	    "74%",
	    "76%",
	    "58%",
	    "50%",
	    "99%",
	    "70%",
	};
	const char *s5[] = {
	    "64%",
	    "95%",
	    "89%",
	    "69%",
	    "96%",
	    "59%",
	    "84%",
	    "93%",
	};
	const char *s6[] = {
	    "77%",
	    "77%",
	};
	const char *s7[] = {
	    "73%",
	    "98%",
	};
	const char *s8[] = {
	    "96%",
	    "87%",
	    "66%",
	};
	const char *s9[] = {
	    "94%",
	    "79%",
	    "54%",
	    "62%",
	};
	const char *s10[] = {
	    "56%",
	    "50%",
	};
	const char *s11[] = {
	    "100%",
	    "51%",
	    "98%",
	};
	const char *s12[] = {
	    "85%",
	    "74%",
	    "61%",
	    "70%",
	    "56%",
	    "67%",
	    "53%",
	    "53%",
	};
	const char *s13[] = {
	    "67%",
	    "91%",
	    "93%",
	    "87%",
	    "81%",
	    "79%",
	    "88%",
	    "69%",
	    "92%",
	    "69%",
	};
	const char *s14[] = {
	    "75%",
	    "100%",
	};
	const char *s15[] = {
	    "1%",
	};

	test(s1, nelem(s1), "54%");
	test(s2, nelem(s2), "0%");
	test(s3, nelem(s3), "51%");
	test(s4, nelem(s4), "36%");
	test(s5, nelem(s5), "36%");
	test(s6, nelem(s6), "62%");
	test(s7, nelem(s7), "71%");
	test(s8, nelem(s8), "63%");
	test(s9, nelem(s9), "47%");
	test(s10, nelem(s10), "38%");
	test(s11, nelem(s11), "63%");
	test(s12, nelem(s12), "20%");
	test(s13, nelem(s13), "27%");
	test(s14, nelem(s14), "73%");
	test(s15, nelem(s15), NULL);

	return 0;
}
