/*

Chef has a string S with length N. He needs to find the number of indices i (1≤i≤N−1) such that the i-th character of this string is a consonant and the i+1-th character is a vowel.
However, he is busy, so he asks for your help.

Note: The letters 'a', 'e', 'i', 'o', 'u' are vowels; all other lowercase English letters are consonants.

Input

The first line of the input contains a single integer T denoting the number of test cases. The description of T test cases follows.
The first line of each test case contains a single integer N.
The second line contains a single string S with length N.

Output

For each test case, print a single line containing one integer ― the number of occurrences of a vowel immediately after a consonant.

Constraints
1≤T≤100
1≤N≤100
S contains only lowercase English letters

*/

#include <assert.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>

int
isvowel(int c)
{
	return strchr("aeiou", tolower(c)) != NULL;
}

size_t
occurences(const char *s)
{
	size_t c, i;

	c = 0;
	for (i = 0; s[i] && s[i + 1]; i++) {
		if (!isvowel(s[i]) && isvowel(s[i + 1]))
			c++;
	}
	return c;
}

int
main(void)
{
	assert(occurences("bazeci") == 3);
	assert(occurences("abu") == 1);
	assert(occurences("o") == 0);

	return 0;
}
