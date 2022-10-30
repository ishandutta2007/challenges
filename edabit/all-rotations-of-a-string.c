/*

Create a left rotation and a right rotation function that returns all the left rotations and right rotations of a string.
Examples

leftRotations("abc") ➞ ["abc", "bca", "cab"]

rightRotations("abc") ➞ ["abc", "cab", "bca"]

leftRotations("abcdef")
➞ ["abcdef", "bcdefa", "cdefab", "defabc", "efabcd", "fabcde"]

rightRotations("abcdef")
➞ ["abcdef", "fabcde", "efabcd", "defabc", "cdefab", "bcdefa"]

*/

#define _GNU_SOURCE
#include <assert.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define nelem(x) (sizeof(x) / sizeof(x[0]))

void
frees(char **p, size_t n)
{
	size_t i;

	if (!p)
		return;

	for (i = 0; i < n; i++)
		free(p[i]);
	free(p);
}

char **
rot(const char *s, ssize_t d)
{
	ssize_t i, j, k, l, n;
	char **p;

	n = strlen(s);
	p = calloc(n, sizeof(*p));
	if (!p)
		goto error;

	for (i = k = 0; i < n; i++) {
		p[i] = calloc(n + 1, sizeof(**p));
		if (!p[i])
			goto error;

		for (j = 0; j < n; j++) {
			l = (k + j) % n;
			if (l < 0)
				l += n;
			p[i][j] = s[l];
		}
		k += d;
	}

	if (0) {
	error:
		frees(p, n);
		p = NULL;
	}

	return p;
}

char **
lrot(const char *s)
{
	return rot(s, 1);
}

char **
rrot(const char *s)
{
	return rot(s, -1);
}

void
test(const char *s, char **(*f)(const char *), const char **r, size_t n)
{
	char **p;
	size_t i;

	p = f(s);
	for (i = 0; i < n; i++)
		assert(!strcmp(p[i], r[i]));
	frees(p, n);
}

int
main(void)
{
	const char *s1 = "abc";
	const char *s2 = "abcdef";
	const char *s3 = "himalaya";
	const char *s4 = "aab";

	const char *l1[] = {
		"abc",
		"bca",
		"cab",
	};
	const char *l2[] = {
		"abcdef",
		"bcdefa",
		"cdefab",
		"defabc",
		"efabcd",
		"fabcde",
	};
	const char *l3[] = {
		"himalaya",
		"imalayah",
		"malayahi",
		"alayahim",
		"layahima",
		"ayahimal",
		"yahimala",
		"ahimalay",
	};
	const char *l4[] = {
		"aab",
		"aba",
		"baa",
	};

	const char *r1[] = {
		"abc",
		"cab",
		"bca",
	};
	const char *r2[] = {
		"abcdef",
		"fabcde",
		"efabcd",
		"defabc",
		"cdefab",
		"bcdefa",
	};
	const char *r3[] = {
		"himalaya",
		"ahimalay",
		"yahimala",
		"ayahimal",
		"layahima",
		"alayahim",
		"malayahi",
		"imalayah",
	};
	const char *r4[] = {
		"aab",
		"baa",
		"aba",
	};

	test(s1, lrot, l1, nelem(l1));
	test(s2, lrot, l2, nelem(l2));
	test(s3, lrot, l3, nelem(l3));
	test(s4, lrot, l4, nelem(l4));

	test(s1, rrot, r1, nelem(r1));
	test(s2, rrot, r2, nelem(r2));
	test(s3, rrot, r3, nelem(r3));
	test(s4, rrot, r4, nelem(r4));

	return 0;
}
