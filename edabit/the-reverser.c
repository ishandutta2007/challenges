/*

The "Reverser" takes a string as input and returns that string in reverse order, with the opposite case.
Examples

reverse("Hello World") ➞ "DLROw OLLEh"

reverse("ReVeRsE") ➞ "eSrEvEr"

reverse("Radar") ➞ "RADAr"

Notes

There will be no punctuation in any of the test cases.

*/

#include <assert.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>

void
swapc(char *x, char *y)
{
	char t;

	t = *x;
	*x = *y;
	*y = t;
}

int
flipcase(char c)
{
	return isupper(c) ? tolower(c) : toupper(c);
}

char *
reverse(char *s)
{
	size_t i, j, l;

	l = strlen(s);
	for (i = 0; i < l / 2; i++) {
		j = l - i - 1;
		swapc(&s[i], &s[j]);
		s[i] = flipcase(s[i]);
		s[j] = flipcase(s[j]);
	}
	if (l & 1)
		s[l / 2] = flipcase(s[l / 2]);
	return s;
}

int
main(void)
{
	char s1[] = "Hello World";
	char s2[] = "ReVeRsE";
	char s3[] = "";
	char s4[] = "Radar";
	char s5[] = "aBcE";

	assert(strcmp(reverse(s1), "DLROw OLLEh") == 0);
	assert(strcmp(reverse(s2), "eSrEvEr") == 0);
	assert(strcmp(reverse(s3), "") == 0);
	assert(strcmp(reverse(s4), "RADAr") == 0);
	assert(strcmp(reverse(s5), "eCbA") == 0);

	return 0;
}
