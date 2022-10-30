/*

Create a function that takes in two words as input and returns a list of three elements, in the following order:

    Shared letters between two words.
    Letters unique to word 1.
    Letters unique to word 2.

Each element should have unique letters, and have each letter be alphabetically sorted.

Examples

letters("sharp", "soap") ➞ ["aps", "hr", "o"]

letters("board", "bored") ➞ ["bdor", "a", "e"]

letters("happiness", "envelope") ➞ ["enp", "ahis", "lov"]

letters("kerfuffle", "fluffy") ➞ ["flu", "ekr", "y"]
# Even with multiple matching letters (e.g. 3 f's), there should 
# only exist a single "f" in your first element.

letters("match", "ham") ➞ ["ahm", "ct", ""]
# "ham" does not contain any letters that are not found already 
# in "match".

Notes

    Both words will be in lower case.
    You do not have to worry about punctuation, all words only have letters from [a-z].
    If an element contains no letters, return an empty string (see last example).

*/

#include <assert.h>
#include <stdio.h>
#include <string.h>

#define nelem(x) (sizeof(x) / sizeof(x[0]))

void
letters(const char *s, const char *t, char *b[3])
{
	size_t h[2][256], l[3];
	size_t i;

	memset(l, 0, sizeof(l));
	memset(h, 0, sizeof(h));
	for (i = 0; s[i]; i++)
		h[0][s[i] & 0xff]++;
	for (i = 0; t[i]; i++)
		h[1][t[i] & 0xff]++;

	for (i = 0; i < nelem(h[0]); i++) {
		if (h[0][i] && h[1][i])
			b[0][l[0]++] = i;
		else if (h[0][i] && !h[1][i])
			b[1][l[1]++] = i;
		else if (!h[0][i] && h[1][i])
			b[2][l[2]++] = i;
	}
	for (i = 0; i < nelem(l); i++)
		b[i][l[i]] = '\0';
}

void
test(const char *s, const char *t, const char *r[3])
{
	char b[3][128];
	size_t i;

	letters(s, t, (char *[]){b[0], b[1], b[2]});
	printf("%s %s %s\n", b[0], b[1], b[2]);
	for (i = 0; i < 3; i++)
		assert(!strcmp(b[i], r[i]));
}

int
main(void)
{
	test("sharp", "soap", (const char *[]){"aps", "hr", "o"});
	test("board", "bored", (const char *[]){"bdor", "a", "e"});
	test("happiness", "envelope", (const char *[]){"enp", "ahis", "lov"});
	test("match", "ham", (const char *[]){"ahm", "ct", ""});
	test("kerfuffle", "fluffy", (const char *[]){"flu", "ekr", "y"});

	return 0;
}
