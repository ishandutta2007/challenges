/*

Write a function that takes a string name and a number num (either 0 or 1) and return "Hello" + name if num is 1, otherwise return "Bye" + name.

Notes

The name you return must be capitalized.

*/

#include <stdio.h>
#include <ctype.h>

char *
sayhellobye(const char *s, int m, char *b, size_t n)
{
	if (*s == '\0')
		snprintf(b, n, "%s", (m == 1) ? "Hello" : "Bye");
	else
		snprintf(b, n, "%s %c%s", (m == 1) ? "Hello" : "Bye", toupper(*s), s + 1);
	return b;
}

int
main(void)
{
	char b[80];

	printf("%s\n", sayhellobye("jose", 1, b, sizeof(b)));
	printf("%s\n", sayhellobye("barry", 1, b, sizeof(b)));
	printf("%s\n", sayhellobye("jon", 0, b, sizeof(b)));
	printf("%s\n", sayhellobye("khloy", 1, b, sizeof(b)));
	printf("%s\n", sayhellobye("sara", 0, b, sizeof(b)));
	printf("%s\n", sayhellobye("Jon", 0, b, sizeof(b)));
	printf("%s\n", sayhellobye("Matt", 1, b, sizeof(b)));
	return 0;
}
