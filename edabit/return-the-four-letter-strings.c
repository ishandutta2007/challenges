/*

Create a function that takes an array of strings. Return all words in the array that are exactly four letters.

Notes
You can expect valid strings for all test cases.

*/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define nelem(x) (sizeof(x) / sizeof(x[0]))

void
freestr(char **p, size_t n)
{
	size_t i;

	if (!p)
		return;

	for (i = 0; i < n; i++)
		free(p[i]);
	free(p[i]);
}

char **
fours(const char **s, size_t n, size_t *l)
{
	char **p;
	size_t i, j;

	*l = 0;
	if (!(p = calloc(n, sizeof(*p))))
		return NULL;

	for (i = j = 0; i < n; i++) {
		if (strlen(s[i]) != 4)
			continue;

		if (!(p[j++] = strdup(s[i]))) {
			freestr(p, n);
			return NULL;
		}
	}

	*l = j;
	return p;
}

void
test(const char **s, size_t n)
{
	char **p;
	size_t i, l;

	p = fours(s, n, &l);
	for (i = 0; i < l; i++)
		printf("%s ", p[i]);
	printf("\n");
	freestr(p, l);
}

int
main(void)
{
	const char *s1[] = {"Ryan", "Kieran", "Jason", "Matt"};
	test(s1, nelem(s1));

	const char *s2[] = {"Tomato", "Potato", "Pair"};
	test(s2, nelem(s2));

	const char *s3[] = {"Kangaroo", "Bear", "Fox"};
	test(s3, nelem(s3));

	return 0;
}
