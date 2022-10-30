/*

Create a function that returns the number of times a character appears in each word in a sentence.
Treat upper and lower case characters of the same letter as being identical (e.g. a exists in Anna twice, not once).

Examples

char_appears("She sells sea shells by the seashore.", "s")
➞ [1, 2, 1, 2, 0, 0, 2]
# "s" shows up once in "She", twice in "sells", once in "sea", twice in "shells", etc.

char_appears("Peter Piper picked a peck of pickled peppers.", "P")
➞ [1, 2, 1, 0, 1, 0, 1, 3]
# "p" shows up once in "Peter", ... 3 times in "peppers".

char_appears("She hiked in the morning, then swam in the river.", "t")
➞ [0, 0, 0, 1, 0, 1, 0, 0, 1, 0]

Notes

Ignore case (note that capitalization, in both the sentence and character itself, in examples #1 & #2).

*/

#include <assert.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

#define nelem(x) (sizeof(x) / sizeof(x[0]))

size_t *
chars(const char *s, char c, size_t *l)
{
	size_t i, n, *p;

	*l = 0;
	n = strlen(s);
	p = calloc(n + 1, sizeof(*p));
	if (!p)
		return NULL;

	c = tolower(c);
	for (i = 0; s[i];) {
		while (isspace(s[i]))
			i++;

		while (s[i] && !isspace(s[i])) {
			p[*l] += (tolower(s[i]) == c);
			i++;
		}
		(*l)++;
	}

	return p;
}

void
test(const char *s, char c, size_t *r, size_t nr)
{
	size_t i, *p, np;

	p = chars(s, c, &np);
	for (i = 0; i < np; i++)
		printf("%zu ", p[i]);
	printf("\n");
	assert(np == nr);
	assert(!memcmp(p, r, sizeof(*r) * nr));
	free(p);
}

int
main(void)
{
	size_t r1[] = {1, 2, 1, 2, 0, 0, 2};
	size_t r2[] = {1, 2, 1, 0, 1, 0, 1, 3};
	size_t r3[] = {0, 0, 0, 1, 0, 1, 0, 0, 1, 0};
	size_t r4[] = {0, 0, 0, 0, 0, 0, 0, 1, 0, 0};
	size_t r5[] = {1, 0, 2};
	size_t r6[] = {1, 0, 1, 1};

	test("She sells sea shells by the seashore.", 's', r1, nelem(r1));
	test("Peter Piper picked a peck of pickled peppers.", 'p', r2, nelem(r2));
	test("She hiked in the morning, then swam in the river.", 't', r3, nelem(r3));
	test("I scream, you scream, we all scream for ice cream.", 'f', r4, nelem(r4));
	test("Snap, crackle, pop!", 'p', r5, nelem(r5));
	test("What a wonderful world.", 'w', r6, nelem(r6));

	return 0;
}
