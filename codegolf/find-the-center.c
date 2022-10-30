/*

Given a string of ASCII characters, output the character that is in the middle.
If there is no middle character (when the string has an even length), output the ASCII character whose ordinal is the floored average of the two center characters.
If the string is empty, an empty string should be output.

Test cases:

12345 => 3

Hello => l

Hiya => q

(empty input) => (empty output)

Shortest program in characters wins. (Not bytes.)

*/

#include <assert.h>
#include <stdio.h>
#include <string.h>

int
center(const char *s)
{
	size_t n;

	n = strlen(s);
	if (n == 0)
		return 0;
	if (n & 1)
		return s[n / 2];
	return (s[n / 2] + s[(n / 2) - 1]) / 2;
}

int
main(void)
{
	assert(center("12345") == '3');
	assert(center("Hello") == 'l');
	assert(center("Hiya") == 'q');
	assert(center("") == 0);

	return 0;
}
