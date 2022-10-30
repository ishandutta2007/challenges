/*

Given a list of strings, output a single string formed by taking a character from each string at each position, sorting them by ASCII ordinal, and appending them in order to the output string.
In other words, for n input strings, the first n characters of the output will be the first characters of each of the inputs sorted by ordinal, the second n characters of the output will be the second characters of each of the inputs sorted by ordinal, and so on.
You may assume that the strings are all of equal length, and that there will be at least one string.
All strings will be composed of only ASCII printable characters (ordinals 32-127).

Reference implementation in Python (try it online):

def stringshuffle(strings):
  res = ''
  for i in range(len(strings[0])):
    res += ''.join(sorted([s[i] for s in strings],key=ord))
  return res
Examples:

"abc","cba" -> "acbbac"
"HELLO","world","!!!!!" -> "!Hw!Eo!Lr!Ll!Od"
Rules
Standard loopholes are forbidden
This is code-golf, so shortest answer in bytes wins

*/

#include <assert.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define nelem(x) (sizeof(x) / sizeof(x[0]))

int
cmp(const void *a, const void *b)
{
	char x, y;

	x = *(char *)a;
	y = *(char *)b;
	if (x < y)
		return -1;
	if (x == y)
		return 0;
	return 1;
}

int
copy(const char **s, size_t n, size_t i, char *b)
{
	size_t m;

	for (m = 0; m < n; m++) {
		if (!s[m][i])
			return 0;
		b[m] = s[m][i];
	}
	return 1;
}

char *
zipnsort(const char **s, size_t n, char *b)
{
	size_t i, j;

	i = j = 0;
	for (;;) {
		if (!copy(s, n, i, b + j))
			break;

		qsort(b + j, n, sizeof(*b), cmp);

		i += 1;
		j += n;
	}
	b[j] = '\0';

	return b;
}

void
test(const char **s, size_t n, const char *r)
{
	char b[128];

	zipnsort(s, n, b);
	printf("%s\n", b);
	assert(!strcmp(b, r));
}

int
main(void)
{
	const char *s1[] = {
	    "abc",
	    "cba",
	};
	const char *s2[] = {
	    "HELLO",
	    "world",
	    "!!!!!",
	};

	test(s1, nelem(s1), "acbbac");
	test(s2, nelem(s2), "!Hw!Eo!Lr!Ll!Od");

	return 0;
}
