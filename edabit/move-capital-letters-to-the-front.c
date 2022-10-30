/*

Create a function that moves all capital letters to the front of a word.
Examples

capToFront("hApPy") ➞ "APhpy"

capToFront("moveMENT") ➞ "MENTmove"

capToFront("shOrtCAKE") ➞ "OCAKEshrt"

Notes

Keep the original relative order of the upper and lower case letters the same.

*/

#include <assert.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

int
cmp(const void *a, const void *b)
{
	char x, y;

	x = *(char *)a;
	y = *(char *)b;
	if (isupper(x) && !isupper(y))
		return -1;
	if (!isupper(x) && isupper(y))
		return 1;

	if (a < b)
		return -1;
	if (a > b)
		return 1;
	return 0;
}

char *
captofront(char *s)
{
	qsort(s, strlen(s), sizeof(*s), cmp);
	return s;
}

int
main(void)
{
	char s1[] = "hApPy";
	char s2[] = "moveMENT";
	char s3[] = "shOrtCAKE";
	char s4[] = "aPPlE";

	assert(strcmp(captofront(s1), "APhpy") == 0);
	assert(strcmp(captofront(s2), "MENTmove") == 0);
	assert(strcmp(captofront(s3), "OCAKEshrt") == 0);
	assert(strcmp(captofront(s4), "PPEal") == 0);

	return 0;
}
