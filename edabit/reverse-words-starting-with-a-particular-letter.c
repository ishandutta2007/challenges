/*

Write a function that reverses all the words in a sentence that start with a particular letter.

Examples

specialReverse("word searches are super fun", "s")
➞ "word sehcraes are repus fun"

specialReverse("first man to walk on the moon", "m")
➞ "first nam to walk on the noom"

specialReverse("peter piper picked pickled peppers", "p")
➞ "retep repip dekcip delkcip sreppep"

Notes

    Reverse the words themselves, not the entire sentence.
    All characters in the sentence will be in lower case.

*/

#include <assert.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>

void
swapc(char *x, char *y)
{
	char t;

	t = *y;
	*y = *x;
	*x = t;
}

void
rev(char *b, size_t i, size_t j)
{
	while (i < j)
		swapc(&b[i++], &b[--j]);
}

char *
spcrev(const char *s, char c, char *b)
{
	size_t i, j, k;
	int f;

	i = j = 0;
	while (s[i]) {
		while (isspace(s[i]))
			b[j++] = s[i++];

		k = j;
		f = 0;
		while (s[i] && !isspace(s[i])) {
			f |= (s[i] == c);
			b[j++] = s[i++];
		}
		if (f)
			rev(b, k, j);
	}
	b[j] = '\0';
	return b;
}

void
test(const char *s, char c, const char *r)
{
	char b[128];

	spcrev(s, c, b);
	printf("%s\n", b);
	assert(!strcmp(b, r));
}

int
main(void)
{
	test("word searches are super fun", 's', "word sehcraes are repus fun");
	test("first man to walk on the moon", 'm', "first nam to walk on the noom");
	test("peter piper picked pickled peppers", 'p', "retep repip dekcip delkcip sreppep");
	test("he went to climb mount everest", 'p', "he went to climb mount everest");
	test("abc", 'c', "cba");

	return 0;
}
