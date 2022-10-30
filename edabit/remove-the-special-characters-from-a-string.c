/*

Create a function that takes a string, removes all "special" characters (e.g. !, @, #, $, %, ^, &, \, *, (, )) and returns the new string. The only non-alphanumeric characters allowed are dashes -, underscores _ and spaces.
Examples

removeSpecialCharacters("The quick brown fox!") ➞ "The quick brown fox"

removeSpecialCharacters("%fd76$fd(-)6GvKlO.") ➞ "fd76fd-6GvKlO"

removeSpecialCharacters("D0n$c sed 0di0 du1") ➞ "D0nc sed 0di0 du1"

*/

#include <assert.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>

char *
rmsch(char *s)
{
	size_t i, j;

	for (i = j = 0; s[i]; i++) {
		if (isalnum(s[i]) || strchr("-_ ", s[i]))
			s[j++] = s[i];
	}
	s[j] = '\0';
	return s;
}

int
main(void)
{
	char s1[] = "The quick brown fox!";
	char s2[] = "%fd76$fd(-)6GvKlO.";
	char s3[] = "D0n$c sed 0di0 du1";
	char s4[] = "cat_pic.jpeg";
	char s5[] = "519-555-8093";
	char s6[] = "h-d+=rf[]_{}<>.,`~!@#$%^&*(|)";
	char s7[] = "Etiam#!!!!!,,, [`po%rta ~sem!] {male*su-ada} (ma*gna) mo^llis... euismod???";

	char t1[] = "The quick brown fox";
	char t2[] = "fd76fd-6GvKlO";
	char t3[] = "D0nc sed 0di0 du1";
	char t4[] = "cat_picjpeg";
	char t5[] = "519-555-8093";
	char t6[] = "h-drf_";
	char t7[] = "Etiam porta sem malesu-ada magna mollis euismod";

	assert(strcmp(rmsch(s1), t1) == 0);
	assert(strcmp(rmsch(s2), t2) == 0);
	assert(strcmp(rmsch(s3), t3) == 0);
	assert(strcmp(rmsch(s4), t4) == 0);
	assert(strcmp(rmsch(s5), t5) == 0);
	assert(strcmp(rmsch(s6), t6) == 0);
	assert(strcmp(rmsch(s7), t7) == 0);

	return 0;
}
