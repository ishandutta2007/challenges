/*

Amanda has a string of lowercase letters that she wants to copy to a new string. 
She can perform the following operations with the given costs. 
She can perform them any number of times to construct a new string p:

Append a character to the end of string p at a cost of 1 dollar.
Choose any substring of p and append it to the end of p at no charge.

Given n strings s[i], find and print the minimum cost of copying each s[i] to p[i] on a new line.

For example, given a string s=abcabc, it can be copied for 3 dollars.
Start by copying a, b and c individually at a cost of 1 dollar per character. String p=abc at this time.
Copy p[0:2] to the end of at no cost to complete the copy.

*/

#include <stdio.h>
#include <string.h>

size_t
construct(const char *s)
{
	size_t f[256], i, n;
	int c;

	memset(f, 0, sizeof(f));
	n = 0;
	for (i = 0; s[i]; i++) {
		c = s[i] & 0xff;
		if (f[c] == 0) {
			f[c]++;
			n++;
		}
	}
	return n;
}

int
main(void)
{
	printf("%zu\n", construct("abcabc"));
	printf("%zu\n", construct("abcd"));
	printf("%zu\n", construct("abab"));
	return 0;
}
