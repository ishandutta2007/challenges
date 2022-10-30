/*

Write a function that sorts a list of characters alphabetically in ascending order (a-z) by the character at the n-th character.

Notes

All inputs will be of same length.

*/

#define _GNU_SOURCE
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

#define nelem(x) (sizeof(x) / sizeof(x[0]))

int
cmp(const void *a, const void *b, void *arg)
{
	const char **s, **t;
	size_t i;

	i = (uintptr_t)arg;
	s = (const char **)a;
	t = (const char **)b;

	if ((*s)[i] < (*t)[i])
		return -1;
	if ((*s)[i] == (*t)[i])
		return 0;
	return 1;
}

void
test(char *s[], size_t n, size_t m)
{
	size_t i;

	qsort_r(s, n, sizeof(*s), cmp, (void *)(uintptr_t)(m - 1));
	printf("[");
	for (i = 0; i < n; i++) {
		printf("\"%s\"", s[i]);
		if (i + 1 < n)
			printf(", ");
	}
	printf("]\n");
}

int
main(void)
{
	char *s1[] = {"az16", "by35", "cx24"};
	char *s2[] = {"apple", "mayor", "bendy", "petal"};
	char *s3[] = {"team", "mate", "bade"};
	for (size_t i = 1; i < 4; i++)
		test(s1, nelem(s1), i);
	test(s2, nelem(s2), 5);
	test(s3, nelem(s3), 3);
	return 0;
}
