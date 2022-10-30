/*

Steve has a string of lowercase characters in range ascii[‘a’..’z’]. He wants to reduce the string to its shortest length by doing a series of operations.
In each operation he selects a pair of adjacent lowercase letters that match, and he deletes them. For instance, the string aab could be shortened to b in one operation.

Steve’s task is to delete as many characters as possible using this method and print the resulting string. If the final string is empty, print Empty String

*/

#include <stdio.h>
#include <string.h>

#define nelem(x) (sizeof(x) / sizeof(x[0]))

char *
reduce(char *b, size_t n, const char *s)
{
	size_t i, j;

	if (n == 0)
		return b;

	for (i = j = 0; s[i] && j < n - 1; i++) {
		if (j > 0 && b[j - 1] == s[i])
			j--;
		else
			b[j++] = s[i];
	}
	b[j] = '\0';

	if (j == 0)
		snprintf(b, n, "Empty String");
	return b;
}

int
main(void)
{
	char b[80];
	printf("%s\n", reduce(b, nelem(b), "aab"));
	printf("%s\n", reduce(b, nelem(b), "aaabccddd"));
	printf("%s\n", reduce(b, nelem(b), "aa"));
	printf("%s\n", reduce(b, nelem(b), "baab"));
	printf("%s\n", reduce(b, nelem(b), "Z"));
	printf("%s\n", reduce(b, nelem(b), "kekekk"));
	printf("%s\n", reduce(b, nelem(b), "aaaaaazp"));
	return 0;
}
