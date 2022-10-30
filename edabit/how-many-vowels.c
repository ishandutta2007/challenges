/*

Create a function that takes a string and returns the number (count) of vowels contained within it.

Notes

    a, e, i, o, u are considered vowles (not y).
    All test cases are one word and only contain letters.

*/
#include <stdio.h>
#include <string.h>
#include <ctype.h>

int
isvowel(int c)
{
	return strchr("aeiou", tolower(c)) != NULL;
}

size_t
count(const char *s)
{
	size_t i, v;

	v = 0;
	for (i = 0; s[i]; i++) {
		if (isvowel(s[i]))
			v++;
	}
	return v;
}

int
main(void)
{
	printf("%zu\n", count("Celebration"));
	printf("%zu\n", count("Palm"));
	printf("%zu\n", count("Prediction"));
	printf("%zu\n", count("Suite"));
	printf("%zu\n", count("Quote"));
	printf("%zu\n", count("Portrait"));
	printf("%zu\n", count("Steam"));
	printf("%zu\n", count("Tape"));
	printf("%zu\n", count("Nightmare"));
	printf("%zu\n", count("Convention"));
	return 0;
}
