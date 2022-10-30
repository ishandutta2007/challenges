/*

Create a function that takes a string and censors words over four characters with *.

Examples

censor("The code is fourty") ➞ "The code is ******"

censor("Two plus three is five") ➞ "Two plus ***** is five"

censor("aaaa aaaaa 1234 12345") ➞ "aaaa ***** 1234 *****"

Notes

    Don't censor words with exactly four characters.
    If all words have four characters or less, return the original string.
    The amount of * is the same as the length of the word.

*/

#include <assert.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>

char *
censor(const char *s, char *b)
{
	size_t i, j, k, n;

	for (i = n = 0; s[i];) {
		while (isspace(s[i]))
			b[n++] = s[i++];

		j = 0;
		while (!isspace(s[i]) && s[i]) {
			i++;
			j++;
		}

		for (k = 0; k < j; k++)
			b[n++] = (j > 4) ? '*' : s[i - j + k];
	}
	b[n] = '\0';
	return b;
}

void
test(const char *s, const char *r)
{
	char b[128];

	censor(s, b);
	printf("%s\n", b);
	assert(!strcmp(b, r));
}

int
main(void)
{
	test("The code is fourty", "The code is ******");
	test("Two plus three is five", "Two plus ***** is five");
	test("aaaa aaaaa 1234 12345", "aaaa ***** 1234 *****");
	test("abcdefghijklmnop", "****************");
	test("a", "a");
	test("abcd", "abcd");
	test("yours", "*****");

	return 0;
}
