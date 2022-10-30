/*

James found a love letter that his friend Harry has written to his girlfriend. James is a prankster, so he decides to meddle with the letter. He changes all the words in the letter into palindromes.

To do this, he follows two rules:

    He can only reduce the value of a letter by 1, i.e. he can change d to c, but he cannot change c to d or d to b.
    The letter a may not be reduced any further.

Each reduction in the value of any letter is counted as a single operation. Find the minimum number of operations required to convert a given string into a palindrome.

For example, given the string s=cde, the following two operations are performed: cde → cdd → cdc.


*/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdint.h>

int
ischar(char c)
{
	return 'a' <= c && c <= 'z';
}

size_t
conv(const char *s)
{
	size_t i, n, c;

	c = 0;
	n = strlen(s);
	for (i = 0; i < n / 2; i++) {
		if (!ischar(s[i]) || !ischar(s[n - i - 1]))
			return SIZE_MAX;
		c += abs(s[i] - s[n - i - 1]);
	}
	return c;
}

int
main(void)
{
	printf("%zu\n", conv("abc"));
	printf("%zu\n", conv("abcba"));
	printf("%zu\n", conv("abcd"));
	printf("%zu\n", conv("cba"));
	printf("%zu\n", conv("cde"));
	return 0;
}
