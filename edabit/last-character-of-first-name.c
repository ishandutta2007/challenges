/*

Create a function that takes a string as an argument. The string is a random name.

    If the last character of the name is an "n", return true.
    If the last character of the name is not an "n", return false.

Notes

	The function must return a boolean value ( i.e. true or false).

*/

#include <stdio.h>
#include <stdbool.h>
#include <ctype.h>

bool
islastcharn(const char *s)
{
	size_t i;

	for (i = 0; s[i]; i++) {
		if (isspace(s[i + 1]) || s[i + 1] == '\0')
			return s[i] == 'n';
	}
	return false;
}

int
main(void)
{
	printf("%d\n", islastcharn("Aiden"));
	printf("%d\n", islastcharn("Roxy"));
	printf("%d\n", islastcharn("Bert"));
	printf("%d\n", islastcharn("Dean"));
	printf("%d\n", islastcharn("Ian"));
	printf("%d\n", islastcharn("Brian"));
	printf("%d\n", islastcharn("Daniel"));
	printf("%d\n", islastcharn("Piet"));
	return 0;
}
