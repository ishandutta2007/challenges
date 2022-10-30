/*

Alliteration refers to a sequence of words that begin with the same letter.
For this exercise, a sentence is correctly alliterated if all words strictly greater
than 3 characters begin with the same letter.

Notes

This is to allow for filler words such as "the", "to", "a", etc. - so words with three
or fewer characters are not counted.

Punctuation does not count as part of a word's length.

*/

#include <stdio.h>
#include <ctype.h>

int
isalliteration(const char *s)
{
	size_t i, l;
	char c, nc;

	c = -1;
	i = 0;
	for (;;) {
		while (isspace(s[i]) && !isalpha(s[i]))
			i++;

		if (s[i] == '\0')
			break;

		nc = tolower(s[i]);
		l = 0;
		while (!isspace(s[i]) && s[i] != '\0') {
			if (isalpha(s[i]))
				l++;
			i++;
		}

		if (l > 3) {
			if (c == -1)
				c = nc;
			else if (c != nc)
				return 0;
		}
	}

	return 1;
}

int
main(void)
{
	printf("%d\n", isalliteration("She swam to the shore."));
	printf("%d\n", isalliteration("Maybel manages money well."));
	printf("%d\n", isalliteration("He helps harness happiness."));
	printf("%d\n", isalliteration("There are many animals in the zoo."));
	printf("%d\n", isalliteration("Tanya took the tomatoes. Two times two is not twenty."));
	printf("%d\n", isalliteration("Two times two is four."));
	printf("%d\n", isalliteration("Nancy nimbly ran for the newts."));
	return 0;
}
