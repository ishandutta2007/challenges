/*

Strings are usually ordered in lexicographical order.
That means they are ordered by comparing their leftmost different characters.
For example, abc < abd because c < d. Also z > yyy because z > y.
If one string is an exact prefix of the other it is lexicographically smaller, e.g., gh < ghij.


Given an array of strings sorted in lexicographical order, print all of its permutations in strict lexicographical order.
If two permutations look the same, only print one of them. See the 'note' below for an example.

Complete the function next_permutation which generates the permutations in the described order.

For example, s=[ab bc cd]. The six permutations in correct order are:

ab bc cd
ab cd bc
bc ab cd
bc cd ab
cd ab bc
cd bc ab

*/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define nelem(x) (sizeof(x) / sizeof(x[0]))

int
cmp(const void *a, const void *b)
{
	const char **x, **y;

	x = (const char **)a;
	y = (const char **)b;
	return strcmp(*x, *y);
}

void
prints(const char **s, size_t n)
{
	size_t i;

	for (i = 0; i < n; i++)
		printf("%s ", s[i]);
	printf("\n");
}

size_t
findceil(const char **s, const char *f, size_t l, size_t h)
{
	size_t i, n;

	n = l;
	for (i = l + 1; i <= h; i++) {
		if (strcmp(s[i], f) > 0 && strcmp(s[i], s[n]) < 0)
			n = i;
	}
	return n;
}

void
perm(const char **s, size_t n)
{
	ssize_t i, j;
	const char *t;

	qsort(s, n, sizeof(*s), cmp);
	for (;;) {
		prints(s, n);

		for (i = n - 2; i >= 0; i--) {
			if (strcmp(s[i], s[i + 1]) < 0)
				break;
		}
		if (i < 0)
			break;

		j = findceil(s, s[i], i + 1, n - 1);
		t = s[j];
		s[j] = s[i];
		s[i] = t;

		qsort(&s[i + 1], n - i - 1, sizeof(*s), cmp);
	}
	printf("\n");
}

int
main(void)
{
	const char *a[] = {"bc", "cd", "ab"};
	perm(a, nelem(a));

	const char *b[] = {"ab", "ab", "bc"};
	perm(b, nelem(b));

	const char *c[] = {"ab", "cd"};
	perm(c, nelem(c));

	const char *d[] = {"a", "bc", "bc"};
	perm(d, nelem(d));

	const char *e[] = { "cjeihg" };
	perm(e, nelem(e));

	return 0;
}
