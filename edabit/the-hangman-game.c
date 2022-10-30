/*

Create a function that, given a phrase and a number of letters guessed, returns a string with hyphens - for every letter of the phrase not guessed, and each letter guessed in place.

Examples

hangman("helicopter", ["o", "e", "s"]) ➞ "-e---o--e-"

hangman("tree", ["r", "t", "e"]) ➞ "tree"

hangman("Python rules", ["a", "n", "p", "r", "z"]) ➞ "P----n r----"

hangman("He"s a very naughty boy!", ["e", "a", "y"]) ➞ "-e"- a -e-y -a----y --y!"

Notes

    The letters are always given in lowercase, but they should be returned in the same case as in the original phrase (see example #3).
    All characters other than letters should always be returned (see example #4).

*/

#include <assert.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>

char *
hangman(const char *s, const char *t, char *b)
{
	size_t i;
	char h[256];

	memset(h, 0, sizeof(h));
	for (i = 0; t[i]; i++) {
		h[tolower(t[i]) & 0xff] = 1;
		h[toupper(t[i]) & 0xff] = 1;
	}
	for (i = 0; s[i]; i++)
		b[i] = (isspace(s[i]) || !isalpha(s[i]) || h[s[i] & 0xff]) ? s[i] : '-';
	b[i] = '\0';
	return b;
}

void
test(const char *s, const char *t, const char *r)
{
	char b[128];

	hangman(s, t, b);
	assert(!strcmp(b, r));
}

int
main(void)
{
	test("helicopter", "oes", "-e---o--e-");
	test("tree", "rte", "tree");
	test("Python rules", "anprz", "P----n r----");
	test("He\"s a very naughty boy!", "eay", "-e\"- a -e-y -a----y --y!");
	test("Looney Tunes", "aeiou", "-oo-e- -u-e-");
	test("summer", "fli", "------");
	test("Connect-4", "cee", "C---ec--4");
	test("thE elePhaNt IN the rOom.", "oggmhnp", "-h- ---Ph-N- -N -h- -Oom.");
	test("deoxyribonucleic acid", "", "---------------- ----");
	test("IM YELLING!", "myilg", "IM Y-LLI-G!");
	test("Show me the money", "afurq", "---- -- --- -----");
	test("peter pan", "erpnnat", "peter pan");

	return 0;
}
