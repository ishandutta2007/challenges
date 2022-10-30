/*

Imagine a school that kids attend for 6 years. In each year, there are five groups started, marked with the letters a, b, c, d, e.
For the first year, the groups are 1a, 1b, 1c, 1d, 1e and for the last year, the groups are 6a, 6b, 6c, 6d, 6e.

Write a function that returns the groups in the school by year (as a string),
separated with a comma and a space in the form of "1a, 1b, 1c, 1d, 1e, 2a, 2b (....) 5d, 5e, 6a, 6b, 6c, 6d, 6e".

Examples

printAllGroups() ➞ "1a, 1b, 1c, 1d, 1e, 2a, 2b, 2c, 2d, 2e, 3a, 3b, 3c, 3d, 3e, 4a, 4b, 4c, 4d, 4e, 5a, 5b, 5c, 5d, 5e, 6a, 6b, 6c, 6d, 6e "

Notes

Use nested "for" loops to achieve this, as well as the array of ["a", "b", "c", "d", "e"] groups.


*/

#include <assert.h>
#include <stdio.h>
#include <string.h>

char *
groups(char *b)
{
	int i, j, l;

	l = 0;
	for (i = '1'; i <= '6'; i++) {
		for (j = 'a'; j <= 'e'; j++)
			l += sprintf(b + l, "%c%c, ", i, j);
	}
	b[l - 2] = ' ';
	b[l - 1] = '\0';
	return b;
}

int
main(void)
{
	char b[128];

	assert(!strcmp(groups(b), "1a, 1b, 1c, 1d, 1e, 2a, 2b, 2c, 2d, 2e, 3a, 3b, 3c, 3d, 3e, 4a, 4b, 4c, 4d, 4e, 5a, 5b, 5c, 5d, 5e, 6a, 6b, 6c, 6d, 6e "));
	return 0;
}
