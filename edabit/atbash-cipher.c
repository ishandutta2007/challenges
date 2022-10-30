/*

The Atbash cipher is an encryption method in which each letter of a word is replaced with its "mirror" letter in the alphabet: A <=> Z; B <=> Y; C <=> X; etc.

Create a function that takes a string and applies the Atbash cipher to it.

Notes

    Capitalisation should be retained.
    Non-alphabetic characters should not be altered.

*/

#include <stdio.h>

char *
atbash(const char *s, char *b, size_t n)
{
	size_t i;

	if (n == 0)
		return NULL;

	for (i = 0; i + 1 < n && s[i]; i++) {
		if ('A' <= s[i] && s[i] <= 'Z')
			b[i] = 'A' + ('Z' - s[i]);
		else if ('a' <= s[i] && s[i] <= 'z')
			b[i] = 'a' + ('z' - s[i]);
		else
			b[i] = s[i];
	}
	b[i] = '\0';
	return b;
}

int
main(void)
{
	char b[256];

	printf("%s\n", atbash("abcdefghijklmnopqrstuvwxyz", b, sizeof(b)));
	printf("%s\n", atbash("ABCDEFGHIJKLMNOPQRSTUVWXYZ", b, sizeof(b)));
	printf("%s\n", atbash("The word 'atbash' derives from the the first and last 2 letters of the Hebrew alphabet.", b, sizeof(b)));
	printf("%s\n", atbash("Vmxibkgrlm zmw wvxibkgrlm ziv rwvmgrxzo uli gsv Zgyzhs xrksvi.", b, sizeof(b)));
	printf("%s\n", atbash("apple", b, sizeof(b)));
	printf("%s\n", atbash("Hello world!", b, sizeof(b)));
	printf("%s\n", atbash("Christmas is the 25th of December", b, sizeof(b)));
	return 0;
}
