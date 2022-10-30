/*

Create a function that takes two inputs: idx (an array of integers) and str (a string).
The function should return another string with the letters of str at each index in idx in order.

Examples

index_filter([2, 3, 8, 11], "Autumn in New York") ➞ "tune"

index_filter([0, 1, 5, 7, 4, 2], "Cry me a river") ➞ "creamy"

index_filter([9, -9, 2, 27, 36, 6, 5, 13, -1, 2, 0, 30, 2], 
  "That's life, I've got you under my skin") ➞ "frank sinatra"

Notes

    Indexes may not be in order or may be negative (see example #2 and #3).
    The output string must always be lowercase, but the input str may not be (see examples).

*/

#define _GNU_SOURCE
#include <assert.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define nelem(x) (sizeof(x) / sizeof(x[0]))

ssize_t
mod(ssize_t x, ssize_t m)
{
	x %= m;
	if (x < 0)
		x += m;
	return x;
}

char *
indexfilter(ssize_t *a, size_t n, const char *s, char *b)
{
	size_t i, j;
	ssize_t m;

	m = strlen(s);
	if (m == 0) {
		b[0] = '\0';
		return b;
	}

	for (i = j = 0; i < n; i++)
		b[j++] = tolower(s[mod(a[i], m)]);
	b[j] = '\0';
	return b;
}

void
test(ssize_t *a, size_t n, const char *s, const char *r)
{
	char b[128];

	indexfilter(a, n, s, b);
	printf("%s\n", b);
	assert(!strcmp(b, r));
}

int
main(void)
{
	ssize_t a1[] = {2, 3, 8, 11};
	ssize_t a2[] = {0, 1, 5, 7, 4, 2};
	ssize_t a3[] = {9, -9, 2, 27, 36, 6, 5, 13, -1, 2, 0, 30, 2};
	ssize_t a4[] = {-1, 8, 8, 3};

	test(a1, nelem(a1), "Autumn in New York", "tune");
	test(a2, nelem(a2), "Cry me a river", "creamy");
	test(a3, nelem(a3), "That's life, I've got you under my skin", "frank sinatra");
	test(a4, nelem(a4), "Dream a Little Dream of Me", "ella");

	return 0;
}
