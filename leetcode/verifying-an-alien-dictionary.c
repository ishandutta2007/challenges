/*

In an alien language, surprisingly they also use english lowercase letters, but possibly in a different order. The order of the alphabet is some permutation of lowercase letters.

Given a sequence of words written in the alien language, and the order of the alphabet, return true if and only if the given words are sorted lexicographicaly in this alien language.

Note:

    1 <= words.length <= 100
    1 <= words[i].length <= 20
    order.length == 26
    All characters in words[i] and order are english lowercase letters.

*/

#include <stdio.h>

#define nelem(x) (sizeof(x) / sizeof(x[0]))

int
dstrcmp(const char *a, const char *b, int *d)
{
	size_t i;
	int x, y;

	for (i = 0;; i++) {
		if (!a[i] && b[i])
			return -1;
		if (a[i] && !b[i])
			return 1;

		x = a[i] - 'a';
		y = b[i] - 'a';
		if (!(0 <= x && x < 26))
			return -1;
		if (!(0 <= y && y < 26))
			return 1;

		if (d[x] < d[y])
			return -1;
		if (d[x] > d[y])
			return 1;
	}
	return 0;
}

int
sorted(const char **w, size_t n, const char *o)
{
	size_t i;
	int d[26];

	for (i = 0; i < 26; i++)
		d[(o[i] - 'a') & 0xff] = i;
	for (i = 0; i < n - 1; i++) {
		if (dstrcmp(w[i], w[i + 1], d) > 0)
			return 0;
	}
	return 1;
}

int
main(void)
{
	const char *w1[] = {
	    "hello",
	    "leetcode",
	};
	const char *o1 = "hlabcdefgijkmnopqrstuvwxyz";
	printf("%d\n", sorted(w1, nelem(w1), o1));

	const char *w2[] = {
		"word", "world", "row",
	};
	const char *o2 = "worldabcefghijkmnpqstuvxyz";
	printf("%d\n", sorted(w2, nelem(w2), o2));

	const char *w3[] = {
		"apple", "app",
	};
	const char *o3 = "abcdefghijklmnopqrstuvwxyz";
	printf("%d\n", sorted(w3, nelem(w3), o3));

	return 0;
}
