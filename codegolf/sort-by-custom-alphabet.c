/*

The challenge is to make a program that sorts a list of words, only that the words need to be in the order of a random given alphabet.

Your program will accept a string of comma-separated words and a new alphabet.
Your program will output every word in the same way in the new sorted order.
Example:

Input:

home,oval,cat,egg,network,green bcdfghjklmnpqrstvwxzaeiouy

Output:

cat,green,home,network,egg,oval

This is a code-golf, so the winner is the person with the shortest program.

This is my first challenge so any improvements to the question/challenge are appreciated.

*/

#include <assert.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <threads.h>

#define nelem(x) (sizeof(x) / sizeof(x[0]))

int
alphacmp(const char *s, const char *t, const char *a)
{
	const char *p, *q;
	size_t i;
	int x, y;

	for (i = 0; s[i] && t[i]; i++) {
		p = strchr(a, s[i]);
		q = strchr(a, t[i]);
		x = (p) ? (p - a) : s[i];
		y = (q) ? (q - a) : t[i];

		if (x < y)
			return -1;
		if (x > y)
			return 1;
	}

	if (!s[i] && t[i])
		return -1;
	if (s[i] && !t[i])
		return 1;
	return 0;
}

thread_local const char *alphabet;

int
cmp(const void *a, const void *b)
{
	const char *s, *t;

	s = *(const char **)a;
	t = *(const char **)b;
	return alphacmp(s, t, alphabet);
}

void
alphasort(const char **s, size_t n, const char *a)
{
	alphabet = a;
	qsort(s, n, sizeof(*s), cmp);
}

void
test(const char **s, size_t n, const char *a, const char **r)
{
	size_t i;

	alphasort(s, n, a);
	for (i = 0; i < n; i++)
		assert(!strcmp(s[i], r[i]));
}

int
main(void)
{
	const char *s1[] = {
	    "home",
	    "oval",
	    "cat",
	    "egg",
	    "network",
	    "green",
	};
	const char *r1[] = {
	    "cat",
	    "green",
	    "home",
	    "network",
	    "egg",
	    "oval",
	};

	test(s1, nelem(s1), "bcdfghjklmnpqrstvwxzaeiouy", r1);

	return 0;
}
