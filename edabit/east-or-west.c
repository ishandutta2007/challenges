/*

You will be given an array of string "east" formatted differently every time. Create a function that returns "west" wherever there is "east". Format the string according to the input. Check the examples below to better understabd the question.
Examples

direction(["east", "EAST", "eastEAST"]) ➞ ["west", "WEST", "westWEST"]

direction(["eAsT EaSt", "EaSt eAsT"]) ➞ ["wEsT WeSt", "WeSt wEsT"]

direction(["east EAST", "e a s t", "E A S T"]) ➞ ["west WEST", "w e s t", "W E S T"]

Notes

The input will only be "east" in different formats.

*/

#define _GNU_SOURCE
#include <assert.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

#define nelem(x) (sizeof(x) / sizeof(x[0]))

void
frees(char **s, size_t n)
{
	size_t i;

	if (!s)
		return;

	for (i = 0; i < n; i++)
		free(s[i]);
	free(s);
}

char **
direction(const char **s, size_t n)
{
	static const char word[] = "west";

	size_t i, j, k;
	char **p, c;

	p = calloc(n, sizeof(*p));
	if (!p)
		goto error;

	for (i = 0; i < n; i++) {
		p[i] = strdup(s[i]);
		if (!p[i])
			goto error;
	}

	for (i = 0; i < n; i++) {
		k = 0;
		for (j = 0; p[i][j]; j++) {
			if (isspace(p[i][j]))
				continue;

			c = word[k++ % (nelem(word) - 1)];
			if (isupper(p[i][j]))
				c = toupper(c);
			p[i][j] = c;
		}
	}

	return p;

error:
	frees(p, n);
	return NULL;
}

void
test(const char **s, const char **r, size_t n)
{
	char **p;
	size_t i;

	p = direction(s, n);
	assert(p);
	for (i = 0; i < n; i++)
		assert(!strcmp(p[i], r[i]));
	frees(p, n);
}

int
main(void)
{
	const char *s1[] = { "east", "EAST", "eastEAST" };
	const char *r1[] = { "west", "WEST", "westWEST" };

	const char *s2[] = { "eAsT EaSt", "EaSt eAsT" };
	const char *r2[] = { "wEsT WeSt", "WeSt wEsT" };

	const char *s3[] = { "east EAST", "e a s t", "E A S T" };
	const char *r3[] = { "west WEST", "w e s t", "W E S T" };

	test(s1, r1, nelem(s1));
	test(s2, r2, nelem(s2));
	test(s3, r3, nelem(s3));

	return 0;
}
