/*

Create a function that takes a string and returns a string in which each character is repeated once.

Notes

All test cases contain valid strings. Don't worry about spaces, special characters or numbers. They're all considered valid characters.

*/

#include <stdio.h>

char *
doublechar(const char *s, char *b, size_t n)
{
	size_t i, j, k;

	if (n == 0)
		return b;

	k = 0;
	for (i = 0; s[i]; i++) {
		for (j = 0; j < 2; j++) {
			if (k >= n) {
				b[--k] = '\0';
				return b;
			}
			b[k++] = s[i];
		}
	}
	b[k] = '\0';
	return b;
}

int
main(void)
{
	char b[80];
	printf("%s\n", doublechar("String", b, sizeof(b)));
	printf("%s\n", doublechar("Hello World!", b, sizeof(b)));
	printf("%s\n", doublechar("1234!_ ", b, sizeof(b)));
	printf("%s\n", doublechar("##^&%%*&%%$#@@! ", b, sizeof(b)));
	printf("%s\n", doublechar("scandal", b, sizeof(b)));
	printf("%s\n", doublechar("economics", b, sizeof(b)));
	printf("%s\n", doublechar(" ", b, sizeof(b)));
	printf("%s\n", doublechar("_______", b, sizeof(b)));
	printf("%s\n", doublechar("equip gallon read", b, sizeof(b)));
	printf("%s\n", doublechar("baby increase", b, sizeof(b)));
	return 0;
}
