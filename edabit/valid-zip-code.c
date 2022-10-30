/*

Zip codes consist of 5 consecutive digits. Given a string, write a function to determine whether the input is a valid zip code. A valid zip code is as follows:

    Must only contain numbers (no non-digits allowed).
    Must not contain any spaces.
    Must not be greater than 5 digits in length.

*/

#include <stdio.h>
#include <ctype.h>

int
validzip(const char *s)
{
	size_t i;

	for (i = 0; i < 6 && s[i]; i++) {
		if (!isdigit(s[i]))
			return 0;
	}
	return i == 5;
}

int
main(void)
{
	printf("%d\n", validzip("59001"));
	printf("%d\n", validzip("853a7"));
	printf("%d\n", validzip("732 32"));
	printf("%d\n", validzip("788876"));
	printf("%d\n", validzip("a923b"));
	printf("%d\n", validzip("5923!"));
	printf("%d\n", validzip("59238aa"));
	printf("%d\n", validzip("88231"));
	return 0;
}
