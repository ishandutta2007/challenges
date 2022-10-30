/*

Implement strStr().

Return the index of the first occurrence of needle in haystack, or -1 if needle is not part of haystack.

Clarification:

What should we return when needle is an empty string? This is a great question to ask during an interview.

For the purpose of this problem, we will return 0 when needle is an empty string. This is consistent to C's strstr() and Java's indexOf().

*/

#define _GNU_SOURCE
#include <stdio.h>

ssize_t
strstri(const char *haystack, const char *needle)
{
	size_t i, j;
	int f;

	if (haystack == NULL || needle == NULL)
		return -1;

	for (i = 0; haystack[i]; i++) {
		f = 1;
		for (j = 0; needle[j]; j++) {
			if (haystack[i + j] != needle[j]) {
				f = 0;
				break;
			}
		}
		if (f)
			return i;
	}
	return -1;
}

int
main(void)
{
	printf("%zd\n", strstri("hello", "ll"));
	printf("%zd\n", strstri("aaaaa", "bba"));
	printf("%zd\n", strstri("a", "tau"));
	printf("%zd\n", strstri("tau", "au"));
	printf("%zd\n", strstri("xyz", ""));
	printf("%zd\n", strstri("For the purpose of this problem, we will return 0 when needle is an empty string. This is consistent to C's strstr() and Java's indexOf().", "indexOf()"));
	return 0;
}
