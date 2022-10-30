/*

Given a string S and a character C, return an array of integers representing the shortest distance from the character C in the string.

Example 1:

Input: S = "loveleetcode", C = 'e'
Output: [3, 2, 1, 0, 1, 0, 0, 1, 2, 2, 1, 0]

 

Note:

    S string length is in [1, 10000].
    C is a single character, and guaranteed to be in string S.
    All letters in S and C are lowercase.


*/
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int
mingtz(int a, int b)
{
	if (a < 0)
		return b;
	if (b < 0)
		return a;
	return (a < b) ? a : b;
}

int *
distch(const char *s, int c, size_t *l)
{
	size_t i, j, k, n;
	int *p;

	n = *l = strlen(s);
	p = calloc(n, sizeof(*p));
	if (!p)
		return NULL;

	for (i = 0; i < n; i++)
		p[i] = -1;
	for (i = j = k = 0; i < n; i++) {
		if (s[i] != c)
			continue;
		for (; j <= i; j++) {
			if (s[k] == c)
				p[j] = mingtz(p[j], j - k);
			p[j] = mingtz(p[j], i - j);
		}
		k = i;
	}
	if (s[k] == c) {
		for (; j < n; j++)
			p[j] = mingtz(p[j], j - k);
	}

	return p;
}

void
print(int *a, size_t n)
{
	size_t i;

	for (i = 0; i < n; i++)
		printf("%d ", a[i]);
	printf("\n");
}

void
test(const char *s, int c)
{
	int *p;
	size_t n;

	p = distch(s, c, &n);
	print(p, n);
	free(p);
}

int
main(void)
{
	test("loveleetcode", 'e');
	test("loveleetcode", 'c');
	test("loveleetcode", 'o');
	test("", 'z');
	test("aa", 'b');
	return 0;
}
