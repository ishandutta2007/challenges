/*

Create a function which takes a sentence and returns its abbreviation.
Get all of the words over or equal to n characters in length and return the first letter of each, capitalised and overall returned as a single string.

Examples

abbreviate("do it yourself") ➞ "Y"

abbreviate("do it yourself", 2) ➞ "DIY"
# "do" and "it" are included because the second parameter specified that word lengths 2 are allowed.

abbreviate("attention AND deficit OR hyperactivity THE disorder") ➞ "ADHD"
# Words below the default 4 characters are not included in the abbreviation.

abbreviate("the acronym of long word lengths", 5) ➞ "AL"
# "acronym" and "lengths" have 5 or more characters.

Notes

There may not be an argument given for n so set the default to 4.

*/

#include <assert.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>

char *
abbreviate(const char *s, size_t n, char *b)
{
	size_t i, j, k;

	for (i = k = 0; s[i];) {
		while (isspace(s[i]))
			i++;

		j = i;
		while (s[i] && !isspace(s[i]))
			i++;

		if (i - j >= n)
			b[k++] = toupper(s[j]);
	}
	b[k] = '\0';

	return b;
}

void
test(const char *s, size_t n, const char *r)
{
	char b[128];

	abbreviate(s, n, b);
	printf("%s\n", b);
	assert(!strcmp(b, r));
}

int
main(void)
{
	test("do it yourself", 4, "Y");
	test("do it yourself", 2, "DIY");
	test("attention AND deficit OR hyperactivity THE disorder", 4, "ADHD");
	test("the acronym of long word lengths", 5, "AL");
	test("laugh out loud", 4, "LL");
	test("Keep It Simple Stupid", 4, "KSS");
	test("laugh out loud", 3, "LOL");
	test("Keep It Simple Stupid", 2, "KISS");
	test("A B C", 1, "ABC");

	return 0;
}
