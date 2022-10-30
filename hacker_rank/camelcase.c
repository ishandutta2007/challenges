/*
Alice wrote a sequence of words in CamelCase as a string of letters having the following properties:

It is a concatenation of one or more words consisting of English letters.
All letters in the first word are lowercase.
For each of the subsequent words, the first letter is uppercase and rest of the letters are lowercase.
Given s, print the number of words in s on a new line.

For example, s=oneTwoThree. There are 3 words in the string.
*/

#include <stdio.h>
#include <ctype.h>

size_t
camelcase(const char *s)
{
	size_t i, c;

	if (s[0] == '\0')
		return 0;

	c = 1;
	for (i = 1; s[i]; i++) {
		if (isupper(s[i]))
			c++;
	}
	return c;
}

int
main(int argc, char *argv[])
{
	printf("%zu\n", camelcase("oneTwoThree"));
	printf("%zu\n", camelcase("saveChangesInTheEditor"));
	printf("%zu\n", camelcase("blahblahblah"));
	printf("%zu\n", camelcase("fooBarBazGos"));

	for (int i = 1; i < argc; i++)
		printf("%s: %zu\n", argv[i], camelcase(argv[i]));
	return 0;
}
