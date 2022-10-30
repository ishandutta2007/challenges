/*

Great scientific discoveries are often named by the last names of scientists that made them.
For example, the most popular asymmetric cryptography system, RSA was discovered by Rivest, Shamir and Adleman.
Another notable example is the Knuth-Morris-Pratt algorithm, named by Knuth, Morris and Pratt.

Scientific papers reference earlier works a lot and it’s not uncommon for one document to use two different naming conventions:
the short variation (e.g. KMP) using only the first letters of authors last names and the long variation (e.g. Knuth-Morris-Pratt) using complete last names separated by hyphens.

We find mixing two conventions in one paper to be aesthetically unpleasing and would like you to write a program that will transform long variations into short.

Input

The first and only line of input will contain at most 100 characters, uppercase and lowercase letters of the English alphabet and hyphen (‘-’ ASCII 45).
The first character will always be an uppercase letter.
Hyphens will always be followed by an uppercase letter.
All other characters will be lowercase letters.

Output

The first and only line of output should contain the appropriate short variation.

*/

#include <assert.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>

char *
abbreviate(const char *s, char *b)
{
	size_t i, j;

	for (i = j = 0; s[i]; i++) {
		if (!isupper(s[i]))
			continue;
		if (i == 0 || s[i - 1] == '-')
			b[j++] = s[i];
	}
	b[j] = '\0';
	return b;
}

void
test(const char *s, const char *r)
{
	char b[128];

	abbreviate(s, b);
	printf("%s\n", b);
	assert(!strcmp(b, r));
}

int
main(void)
{
	test("Knuth-Morris-Pratt", "KMP");
	test("Mirko-Slavko", "MS");
	test("Pasko-Patak", "PP");
	test("Rivest-Shamir-Adleman", "RSA");

	return 0;
}
