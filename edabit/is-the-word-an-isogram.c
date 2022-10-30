/*

An isogram is a word that has no repeating letters, consecutive or nonconsecutive. Create a function that takes a string and returns either true or false depending on whether or not it's an "isogram".

Notes

    Ignore letter case (should not be case sensitive).
    All test cases contain valid one word strings.

*/

#include <stdio.h>
#include <string.h>
#include <ctype.h>

int
isogram(const char *s)
{
	size_t f[256], i;

	memset(f, 0, sizeof(f));
	for (i = 0; s[i]; i++) {
		if (++f[tolower(s[i]) & 0xff] >= 2)
			return 0;
	}
	return 1;
}

int
main(void)
{
	printf("%d\n", isogram("Algorism"));
	printf("%d\n", isogram("PasSword"));
	printf("%d\n", isogram("Dermatoglyphics"));
	printf("%d\n", isogram("Cat"));
	printf("%d\n", isogram("Filmography"));
	printf("%d\n", isogram("Consecutive"));
	printf("%d\n", isogram("Bankruptcies"));
	printf("%d\n", isogram("Unforgivable"));
	printf("%d\n", isogram("Unpredictably"));
	printf("%d\n", isogram("Moose"));
	return 0;
}
