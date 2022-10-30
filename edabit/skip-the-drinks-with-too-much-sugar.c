/*

The function skipTooMuchSugarDrinks() takes in an array of drinks. Make sure the function only returns an array of drinks with no sugar in it or a little bit of sugar.

Drinks that contain too much sugar (in this challenge) are:

    Cola
    Fanta

Examples

skipTooMuchSugarDrinks(["fanta", "cola", "water"]) ➞ [water]

skipTooMuchSugarDrinks(["fanta", "cola"]) ➞ []

skipTooMuchSugarDrinks(["lemonade", "beer", "water"]) ➞ ["lemonade", "beer", "water"]

Notes

The skipTooMuchSugarDrinks() function returns an array of strings. All drink names are in lowercase.

*/

#define _GNU_SOURCE
#include <assert.h>
#include <stdio.h>
#include <string.h>

#define nelem(x) (sizeof(x) / sizeof(x[0]))

size_t
skipsugardrinks(const char **s, size_t n)
{
	size_t i, j;

	for (i = j = 0; i < n; i++) {
		if (!strcasecmp(s[i], "cola") || !strcasecmp(s[i], "fanta"))
			continue;
		s[j++] = s[i];
	}
	return j;
}

void
test(const char **a, size_t n, const char **b, size_t m)
{
	size_t i;

	assert(skipsugardrinks(a, n) == m);
	for (i = 0; i < m; i++)
		assert(!strcmp(a[i], b[i]));
}

int
main(void)
{
	const char *s1[] = { "cola", "fanta" };
	const char *s2[] = { "cola", "fanta", "water" };
	const char *s3[] = { "cola" };
	const char *s4[] = { "" };
	const char *s5[] = { "lemonade", "beer", "fanta" };
	const char *s6[] = { "water", "cola" };
	const char *s7[] = { "water", "tea" };

	const char *t2[] = { "water" };
	const char *t4[] = { "" };
	const char *t5[] = { "lemonade", "beer" };
	const char *t6[] = { "water" };
	const char *t7[] = { "water", "tea" };

	test(s1, nelem(s1), NULL, 0);
	test(s2, nelem(s2), t2, nelem(t2));
	test(s3, nelem(s3), NULL, 0);
	test(s4, nelem(s4), t4, nelem(t4));
	test(s5, nelem(s5), t5, nelem(t5));
	test(s6, nelem(s6), t6, nelem(t6));
	test(s7, nelem(s7), t7, nelem(t7));

	return 0;
}
