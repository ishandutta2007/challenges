/*

Hi folks! We are in the midst of discussing how this subreddit will go about but for now how about we just concentrate on challenges!

Write a function that takes two strings and removes from the first string any character that appears in the second string. For instance, if the first string is “Daily Programmer” and the second string is “aeiou ” the result is “DlyPrgrmmr”.
note: the second string has [space] so the space between "Daily Programmer" is removed

edit: if anyone has any suggestions for the subreddit, kindly post it in the feedback thread posted a day before. It will be easier to assess. Thank you.

*/

#include <assert.h>
#include <stdio.h>
#include <string.h>

char *
rmchars(char *s, const char *t)
{
	size_t i, j;
	char h[256];
	int c;

	memset(h, 0, sizeof(h));
	for (i = 0; t[i]; i++) {
		c = t[i] & 0xff;
		h[c] = 1;
	}

	for (i = j = 0; s[i]; i++) {
		c = s[i] & 0xff;
		if (!h[c])
			s[j++] = s[i];
	}
	s[j] = '\0';

	return s;
}

void
test(const char *s, const char *t, const char *r)
{
	char b[128];

	strcpy(b, s);
	rmchars(b, t);
	printf("%s\n", b);
	assert(!strcmp(b, r));
}

int
main(void)
{
	test("Daily Programmer", "aeiou ", "DlyPrgrmmr");

	return 0;
}
