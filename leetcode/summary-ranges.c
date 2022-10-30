/*

Given a sorted integer array without duplicates, return the summary of its ranges.

*/

#include <stdio.h>
#include <stdlib.h>

#define nelem(x) (sizeof(x) / sizeof(x[0]))

char **
sumranges(int *a, size_t n, size_t *m)
{
	char **s, *t;
	size_t i, j, l;

	*m = 0;
	if (n == 0)
		return NULL;

	l = 128;
	s = calloc(n, sizeof(*s));
	t = calloc(n * l, sizeof(*t));
	if (!s || !t)
		goto error;
	for (i = 0; i < n; i++)
		s[i] = &t[l * i];

	for (i = 0; i < n; i = j + 1) {
		j = i;
		while (j + 1 < n && a[j] + 1 == a[j + 1])
			j++;
		if (i != j)
			snprintf(s[(*m)++], l, "%d->%d", a[i], a[j]);
		else
			snprintf(s[(*m)++], l, "%d", a[i]);
	}

	return s;

error:
	free(s);
	free(t);
	return NULL;
}

void
test(int *a, size_t n)
{
	char **s;
	size_t i, l;

	s = sumranges(a, n, &l);
	if (!s) {
		printf("oom\n");
		return;
	}
	printf("[");
	for (i = 0; i < l; i++) {
		printf("\"%s\"", s[i]);
		if (i + 1 < l)
			printf(",");
	}
	printf("]\n");
	free(s[0]);
	free(s);
}

int
main(void)
{
	int a1[] = {0, 1, 2, 4, 5, 7};
	int a2[] = {0, 2, 3, 4, 6, 8, 9};
	int a3[] = {1};
	int a4[] = {2, 4, 6, 8, 10, 11, 12, 13, 14, 15};
	test(a1, nelem(a1));
	test(a2, nelem(a2));
	test(a3, nelem(a3));
	test(a4, nelem(a4));
	return 0;
}
