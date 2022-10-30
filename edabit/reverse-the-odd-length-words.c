/*

Given a string, reverse all the words which have odd length. The even length words are not changed.

Notes

There is exactly one space between each word and no punctuation is used.

*/

#include <stdio.h>
#include <ctype.h>

void
rev(char *s, size_t i, size_t j)
{
	char c;

	for (; i < j; i++, j--) {
		c = s[i];
		s[i] = s[j];
		s[j] = c;
	}
}

char *
rolw(char *s)
{
	size_t i, j;

	for (i = 0; s[i]; i = j) {
		while (isspace(s[i]))
			i++;

		j = i + 1;
		while (!isspace(s[j]) && s[j] != '\0')
			j++;

		if ((j - i) & 1)
			rev(s, i, j - 1);
	}

	return s;
}

int
main(void)
{
	char s1[] = "One two three four";
	char s2[] = "Make sure uoy only esrever sdrow of ddo length";
	char s3[] = "";
	char s4[] = "Bananas";
	char s5[] = "Even even even even even even even even even";
	char s6[] = "Odd odd odd odd odd odd odd odd odd odd odd";

	printf("%s\n", rolw(s1));
	printf("%s\n", rolw(s2));
	printf("%s\n", rolw(s3));
	printf("%s\n", rolw(s4));
	printf("%s\n", rolw(s5));
	printf("%s\n", rolw(s6));

	return 0;
}
