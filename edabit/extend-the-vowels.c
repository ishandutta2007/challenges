/*

Create a function that takes a word and extends all vowels by a number num.
Examples

extendVowels("Hello", 5) ➞ "Heeeeeelloooooo"

extendVowels("Edabit", 3) ➞ "EEEEdaaaabiiiit"

extendVowels("Extend", 0) ➞ "Extend"

Notes

Return "invalid" if num isn't 0 or a positive integer.

*/

#include <assert.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>

char *
extendvowels(const char *s, int n, char *b)
{
	size_t i, j, k;

	if (n < 0) {
		sprintf(b, "invalid");
		return b;
	}

	for (i = j = 0; s[i]; i++) {
		k = 1;
		if (strchr("aeiou", tolower(s[i])))
			k = n + 1;

		for (; k; k--)
			b[j++] = s[i];
	}
	b[j] = '\0';
	return b;
}

void
test(const char *s, int n, const char *r)
{
	char b[128];

	extendvowels(s, n, b);
	printf("%s\n", b);
	assert(!strcmp(b, r));
}

int
main(void)
{
	test("Hello", 5, "Heeeeeelloooooo");
	test("Edabit", 3, "EEEEdaaaabiiiit");
	test("Extend", 0, "Extend");
	test("A", 10, "AAAAAAAAAAA");
	test("Z", 93, "Z");
	test("Vowel", -5, "invalid");
	test("Nice", -8, "invalid");

	return 0;
}
