/*

Given two strings, first_name and last_name, return a single string in the format "last, first".

*/

#include <stdio.h>
#include <string.h>

char *
concat(const char *f, const char *l, char *b, size_t n)
{
	snprintf(b, n, "%s, %s", l, f);
	return b;
}

int
main(void)
{
	char b[128];

	printf("%s\n", concat("John", "Doe", b, sizeof(b)));
	printf("%s\n", concat("First", "Last", b, sizeof(b)));
	printf("%s\n", concat("A", "B", b, sizeof(b)));
	printf("%s\n", concat(",", ",", b, sizeof(b)));
	return 0;
}
