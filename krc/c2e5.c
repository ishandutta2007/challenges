/*

Write the function any(s1, s2), which returns the first location in the string
s1 where any character from the string s2 occurs, or -1 if s1 contains no
characters from s2. (The standard library function strpbrk does the same
job but returns a pointer to the location .)

*/

#define _GNU_SOURCE
#include <stdio.h>
#include <stdlib.h>

ssize_t
any(const char *s, const char *t)
{
	ssize_t i, j;

	for (i = 0; s[i]; i++) {
		for (j = 0; t[j]; j++) {
			if (s[i] == t[j])
				return i;
		}
	}
	return -1;
}

int
main(int argc, char *argv[])
{
	if (argc != 3) {
		fprintf(stderr, "usage: string accept\n");
		exit(2);
	}
	printf("%zd\n", any(argv[1], argv[2]));
	return 0;
}
