/*

Create a function that alternates the case of the characters in a string.

Notes

The first character should always be UPPERCASE.

*/

#include <stdio.h>
#include <ctype.h>

char *
altcaps(char *s)
{
	size_t i;

	for (i = 0; s[i]; i++) {
		if ((i & 1) == 0)
			s[i] = toupper(s[i]);
		else
			s[i] = tolower(s[i]);
	}
	return s;
}

int
main(void)
{
	char s1[] = "Hello";
	printf("%s\n", altcaps(s1));

	char s2[] = "Hey, how are you?";
	printf("%s\n", altcaps(s2));

	char s3[] = "OMG!!! This website is awesome!!";
	printf("%s\n", altcaps(s3));

	char s4[] = "alternating caps";
	printf("%s\n", altcaps(s4));

	char s5[] = "Hello, what's your name?";
	printf("%s\n", altcaps(s5));

	char s6[] = "Lorem ipsum dolor sit amet, consectetur adipisicing elit.";
	printf("%s\n", altcaps(s6));

	char s7[] = "The quick brown fox jumps over the lazy dog";
	printf("%s\n", altcaps(s7));

	char s8[] = "The intent is to provide players with a sense of pride and accomplishment for unlocking different heroes.";
	printf("%s\n", altcaps(s8));

	return 0;
}
