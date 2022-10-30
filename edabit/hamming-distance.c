/*

Hamming distance is the number of characters that differ between two strings.

To illustrate:

String1: "abcbba"
String2: "abcbda"

Hamming Distance: 1 - "b" vs. "d" is the only difference.

Create a function that computes the hamming distance between two strings.
Examples

hammingDistance("abcde", "bcdef") ➞ 5

hammingDistance("abcde", "abcde") ➞ 0

hammingDistance("strong", "strung") ➞ 1

Notes

Both strings will have the same length.

*/

#include <assert.h>
#include <stdio.h>

size_t
hamming(const char *s, const char *t)
{
	size_t i, j, r;

	r = 0;
	for (i = 0; s[i] && t[i]; i++)
		r += (s[i] != t[i]);
	for (j = i; s[j]; j++)
		r++;
	for (j = i; t[j]; j++)
		r++;

	return r;
}

int
main(void)
{
	assert(hamming("abcbba", "abcbda") == 1);
	assert(hamming("abcde", "bcdef") == 5);
	assert(hamming("abcde", "abcde") == 0);
	assert(hamming("strong", "strung") == 1);

	return 0;
}
