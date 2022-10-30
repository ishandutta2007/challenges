/*
Given an alphanumeric string made up of digits and lower case Latin characters only, find the sum of all the digit characters in the string.
*/

#include <stdio.h>
#include <ctype.h>

int
process(const char *s)
{
	size_t i;
	int r;

	r = 0;
	for (i = 0; s[i]; i++) {
		if (isdigit(s[i]))
			r += s[i] - '0';
	}
	return r;
}

int
main(void)
{
	printf("%d\n", process("ab1231da"));
	return 0;
}
