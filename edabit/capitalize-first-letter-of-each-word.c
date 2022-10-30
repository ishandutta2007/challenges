/*

Create a function that takes a string as an argument and converts the first character of each word to uppercase. Return the newly formatted string.

Notes

You can expect a valid string for each test case.

*/

#include <stdio.h>
#include <ctype.h>

char *
capwords(char *s)
{
	size_t i, j;
	int f;

	f = 1;
	for (i = j = 0; s[i]; i++, j++) {
		s[j] = s[i];
		if (isspace(s[i])) {
			f = 1;
			continue;
		}
		if (f) {
			s[j] = toupper(s[j]);
			f = 0;
		}
	}
	s[j] = '\0';
	return s;
}

int
main(void)
{
	char s1[] = "This is a title";
	printf("%s\n", capwords(s1));

	char s2[] = "capitalize every word";
	printf("%s\n", capwords(s2));

	char s3[] = "I Like Pizza";
	printf("%s\n", capwords(s3));

	char s4[] = "PIZZA PIZZA PIZZA";
	printf("%s\n", capwords(s4));

	char s5[] = "I am a title";
	printf("%s\n", capwords(s5));

	char s6[] = "I AM A TITLE";
	printf("%s\n", capwords(s6));

	char s7[] = "the first letter of every word is capitalized";
	printf("%s\n", capwords(s7));

	char s8[] = "Don't count your ChiCKens BeFore They HatCh";
	printf("%s\n", capwords(s8));

	char s9[] = "All generalizations are false, including this one";
	printf("%s\n", capwords(s9));

	char s10[] = "Me and my wife lived happily for twenty years and then we met.";
	printf("%s\n", capwords(s10));

	char s11[] = "There are no stupid questions, just stupid people.";
	printf("%s\n", capwords(s11));

	char s12[] = "1f you c4n r34d 7h15, you r34lly n33d 2 g37 l41d";
	printf("%s\n", capwords(s12));

	return 0;
}
