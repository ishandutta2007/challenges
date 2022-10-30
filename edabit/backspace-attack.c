/*

Suppose a hash # represents the backspace key being pressed. Write a function that transforms a string containing # into a string without any #.

Notes

    In addition to characters, backspaces can also remove whitespaces.
    If the number of hashes exceeds the previous characters, remove those previous characters entirely (see example #3).
    If there only exist backspaces, return an empty string (see example #4).

*/

#include <stdio.h>

char *
erase(char *s)
{
	size_t i, j;

	for (i = j = 0; s[i];) {
		if (s[i] != '#')
			s[j++] = s[i++];
		else {
			for (; s[i] == '#'; i++)
				j = (j > 0) ? j - 1 : j;
		}
	}
	s[j] = '\0';

	return s;
}

int
main(void)
{
	char s1[] = "he##l#hel#llo";
	char s2[] = "major# spar##ks";
	char s3[] = "si###t boy";
	char s4[] = "####";
	char s5[] = "motion #sick";
	char s6[] = "m#oti#o#n sick##ne#ss##";
	char s7[] = "courz#i#age";
	char s8[] = "aris##### c#r#ti#c";
	char s9[] = "beauty##";
	char s10[] = "beauty#";
	char s11[] = "b#";

	printf("\"%s\"\n", erase(s1));
	printf("\"%s\"\n", erase(s2));
	printf("\"%s\"\n", erase(s3));
	printf("\"%s\"\n", erase(s4));
	printf("\"%s\"\n", erase(s5));
	printf("\"%s\"\n", erase(s6));
	printf("\"%s\"\n", erase(s7));
	printf("\"%s\"\n", erase(s8));
	printf("\"%s\"\n", erase(s9));
	printf("\"%s\"\n", erase(s10));
	printf("\"%s\"\n", erase(s11));

	return 0;
}
