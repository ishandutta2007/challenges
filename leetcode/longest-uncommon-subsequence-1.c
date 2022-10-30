/*

Given a group of two strings, you need to find the longest uncommon subsequence of this group of two strings. The longest uncommon subsequence is defined as the longest subsequence of one of these strings and this subsequence should not be any subsequence of the other strings.

A subsequence is a sequence that can be derived from one sequence by deleting some characters without changing the order of the remaining elements. Trivially, any string is a subsequence of itself and an empty string is a subsequence of any string.

The input will be two strings, and the output needs to be the length of the longest uncommon subsequence. If the longest uncommon subsequence doesn't exist, return -1.

Note:

    Both strings' lengths will not exceed 100.
    Only letters from a ~ z will appear in input strings.

*/

#include <stdio.h>

#define max(a, b) (((a) > (b)) ? (a) : (b))

size_t
lus(const char *s, const char *t)
{
	size_t i, m, n;

	m = 0;
	n = 0;
	for (i = 0; s[i] && t[i]; i++) {
		if (s[i] == t[i])
			n = 0;
		else {
			n++;
			m = max(m, n);
		}
	}
	return m;
}

int
main(void)
{
	printf("%zu\n", lus("aba", "cdc"));
	printf("%zu\n", lus("aba", "abaword"));
	printf("%zu\n", lus("abaduft", "abaword"));
	return 0;
}
