/*

Create a function that takes both a string and an array of numbers as arguments.
Rearrange the letters in the string to be in the order specified by the index numbers. Return the "remixed" string.

Notes

Be sure not to change the original case; otherwise no gotchas. Assume you'll be given a string and array of equal length,
both containing valid characters (A-Z, a-z, or 0-9).

*/

#include <assert.h>
#include <stdio.h>
#include <string.h>

#define nelem(x) (sizeof(x) / sizeof(x[0]))

int
remix(const char *s, size_t *p, char *b, size_t n)
{
	size_t i;

	if (n == 0)
		return 0;
	if (s[n] != '\0')
		return -1;

	for (i = 0; i < n; i++) {
		if (p[i] >= n)
			return -1;
		b[p[i]] = s[i];
	}
	b[n] = '\0';

	return 0;
}

void
test(const char *s, size_t *p, size_t n)
{
	char b[80];

	assert(remix(s, p, b, n) == 0);
	printf("%s\n", b);
}

int
main(void)
{
	const char *s1 = "abcd";
	const char *s2 = "PlOt";
	const char *s3 = "computer";
	const char *s4 = "twist";
	const char *s5 = "responsibility";
	const char *s6 = "Interference";
	const char *s7 = "sequence";

	size_t p1[] = {0, 3, 1, 2};
	size_t p2[] = {1, 3, 0, 2};
	size_t p3[] = {0, 2, 1, 5, 3, 6, 7, 4};
	size_t p4[] = {4, 0, 1, 2, 3};
	size_t p5[] = {0, 6, 8, 11, 10, 7, 13, 5, 3, 2, 4, 12, 1, 9};
	size_t p6[] = {6, 9, 10, 11, 7, 3, 0, 2, 5, 1, 8, 4};
	size_t p7[] = {5, 7, 3, 4, 0, 1, 2, 6};

	test(s1, p1, nelem(p1));
	test(s2, p2, nelem(p2));
	test(s3, p3, nelem(p3));
	test(s4, p4, nelem(p4));
	test(s5, p5, nelem(p5));
	test(s6, p6, nelem(p6));
	test(s7, p7, nelem(p7));

	return 0;
}
