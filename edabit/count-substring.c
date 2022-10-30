/*

Implement a function count_substring that counts the number of substrings that begin with character "A" and ends with character "X".

For example, given the input string "CAXAAYXZA", there are four substrings that begin with "A" and ends with "X", namely: "AX", "AXAAYX", "AAYX", and "AYX".

Examples

countSubstring("CAXAAYXZA") ➞  4

countSubstring("AAXOXXA") ➞ 6

countSubstring("AXAXAXAXAX") ➞ 15

Notes

    You should aim to avoid using nested loops to complete the task.
    You can assume that the input string is composed of English upper case letters only.

*/

#include <assert.h>
#include <stdio.h>

size_t
count(const char *s)
{
	size_t a, c, i;

	for (a = c = i = 0; s[i]; i++) {
		a += (s[i] == 'A');
		c += (s[i] == 'X') ? a : 0;
	}
	return c;
}

int
main(void)
{
	assert(count("CAXAAYXZA") == 4);
	assert(count("AAXOXXA") == 6);
	assert(count("AXAXAXAXAX") == 15);

	return 0;
}
