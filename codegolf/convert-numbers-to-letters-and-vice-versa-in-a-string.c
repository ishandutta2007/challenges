/*

Based on a list of numbers and their equivalent letters, take a string input, replace the characters of that string with the equivalent number/letter and output the result.

List
1 = a
2 = b
3 = c
4 = d
5 = e
6 = f
7 = g
8 = h
9 = i
0 = j
Input
thisisastring1124

Output
t89s9s1str9n7aabd

Rules
Numbers are equivalent to lowercase letters only.
Any character outside the list will be left as is.
Input string must not contain spaces.
Either full program or function is permitted.
Since it's code-golf, fewest bytes wins.

*/

#include <assert.h>
#include <stdio.h>
#include <string.h>

char *
conv(const char *s, char *b)
{
	size_t i, j;

	for (i = j = 0; s[i]; i++) {
		if ('a' <= s[i] && s[i] <= 'j')
			b[j++] = '0' + ((s[i] - 'a' + 1) % 10);
		else if ('1' <= s[i] && s[i] <= '9')
			b[j++] = 'a' + (s[i] - '1');
		else if (s[i] == '0')
			b[j++] = 'j';
		else
			b[j++] = s[i];
	}
	b[j] = '\0';

	return b;
}

void
test(const char *s, const char *r)
{
	char b[128];

	conv(s, b);
	printf("%s\n", b);
	assert(!strcmp(b, r));
}

int
main(void)
{
	test("thisisastring1124", "t89s9s1str9n7aabd");
	test("1234567890", "abcdefghij");
	test("abcdefghij", "1234567890");

	return 0;
}
