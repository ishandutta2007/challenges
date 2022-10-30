/*

Create a function that is a Hashtag Generator by using the following rules:

    The output must start with a hashtag (#).
    Each word in the output must have its first letter capitalized.
    If the final result, a single string, is longer than 140 characters, the function should return false.
    If either the input (str) or the result is an empty string, the function should return false.

Examples

generate_hashtag("    Hello     World   " ) ➞ "#HelloWorld"

generate_hashtag("") ➞ false, "Expected an empty string to return false"

generate_hashtag("Edabit Is Great") ➞ "#EdabitIsGreat", "Should remove spaces."

Notes

N/A

*/

#include <assert.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define nelem(x) (sizeof(x) / sizeof(x[0]))

char *
hashtag(const char *s, char *b)
{
	size_t i, j;
	int c, f;

	b[0] = '#';
	j = 1;
	for (i = 0; s[i];) {
		while (isspace(s[i]))
			i++;

		f = 0;
		while (s[i] && !isspace(s[i])) {
			c = s[i++];
			if (isalpha(c) && !f) {
				c = toupper(c);
				f = 1;
			}
			b[j++] = c;
		}
	}
	b[j] = '\0';

	if (j == 1 || j > 140)
		return NULL;
	return b;
}

char *
repeat(const char *s, size_t n)
{
	static char b[256];
	size_t i, j, k;

	for (i = j = k = 0; j + 1 < nelem(b) && k < n; k++) {
		b[j++] = s[i];
		i = (!s[i] || !s[i + 1]) ? 0 : i + 1;
	}
	b[j] = '\0';
	return b;
}

void
test(const char *s, const char *r)
{
	char b[256];

	if (!hashtag(s, b))
		assert(r == NULL);
	else {
		printf("'%s'\n'%s'\n\n", b, r);
		assert(!strcmp(b, r));
	}
}

int
main(void)
{
	test("", NULL);
	test(repeat(" ", 100), NULL);
	test("Do We have A Hashtag", "#DoWeHaveAHashtag");
	test("Edabit", "#Edabit");
	test("Edabit Is Great", "#EdabitIsGreat");
	test("Edabit is great", "#EdabitIsGreat");
	test("Smmmmmmmmmmmmmmmmmmmmmmmmmmmmaaaaaaaaaaaaaaaaaaaaaaaaaaaaalllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllll Dog", NULL);
	test(repeat("e", 10), "#Eeeeeeeeee");
	test(repeat("e", 140), NULL);
	test("    Hello     World   ", "#HelloWorld");

	return 0;
}
