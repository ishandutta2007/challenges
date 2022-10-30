/*

Create a function that takes a string; we'll say that the front is the first three characters of the string.
If the string length is less than three characters, the front is whatever is there. Return a new string, which is three copies of the front.

Examples

frontThree("Python") ➞ "PytPytPyt"

frontThree("Cucumber") ➞ "CucCucCuc"

frontThree("bioshock") ➞ "biobiobio"

Notes

Don't forget to return the result.

*/

#include <assert.h>
#include <stdio.h>
#include <string.h>

char *
frontthree(const char *s, char *b)
{
	size_t i, j, k, l;

	i = 0;
	while (s[i] && i < 3)
		i++;

	for (j = 0; j < 3; j++) {
		for (k = 0; k < i; k++)
			b[l++] = s[k];
	}
	b[l] = '\0';

	return b;
}

void
test(const char *s, const char *r)
{
	char b[128];

	frontthree(s, b);
	printf("%s\n", b);
	assert(!strcmp(b, r));
}

int
main(void)
{
	test("Python", "PytPytPyt");
	test("Chocolate", "ChoChoCho");
	test("duh", "duhduhduh");
	test("Sportsmanship", "SpoSpoSpo");
	test("ab", "ababab");
	test("a", "aaa");
	test("", "");

	return 0;
}
