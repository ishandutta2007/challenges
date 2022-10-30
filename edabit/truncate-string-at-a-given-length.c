/*

Create a function that takes a string (the string to truncate) and a number
(the maximum length of the truncated string) as arguments and returns the truncated string at the given length.

Notes

    To "truncate" means "to shorten by cutting off the top or end".
    If a word is trucated in the middle, discard it in the output (see 2nd example above).

*/

#include <stdio.h>
#include <ctype.h>

char *
truncate(char *s, size_t t)
{
	size_t i, j;

	for (i = j = 0; s[i]; i++) {
		if (isspace(s[i]))
			j = i;
		if (i == t) {
			s[j] = '\0';
			break;
		}
	}
	return s;
}

int
main(void)
{
	char s1[] = "Lorem ipsum dolor sit amet.";
	char s2[] = "Lorem ipsum dolor sit amet.";
	char s3[] = "Lorem ipsum dolor sit amet.";
	char s4[] = "Lorem ipsum";
	char s5[] = "Lorem ipsum";
	char s6[] = "Lorem ipsum";
	char s7[] = "";

	printf("%s\n", truncate(s1, 11));
	printf("%s\n", truncate(s2, 16));
	printf("%s\n", truncate(s3, 17));
	printf("%s\n", truncate(s4, 20));
	printf("%s\n", truncate(s5, 4));
	printf("%s\n", truncate(s6, 0));
	printf("%s\n", truncate(s7, 30));

	return 0;
}
