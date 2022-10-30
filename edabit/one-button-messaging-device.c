/*

Imagine a messaging device with only one button. For the letter A, you press the button one time, for E, you press it five times, for G, it's pressed seven times, etc, etc.

Write a function that takes a string (the message) and returns the total number of times the button is pressed.

Notes

Ignore spaces.

*/

#include <stdio.h>

size_t
presses(const char *s)
{
	size_t i, c;

	for (i = c = 0; s[i]; i++) {
		if ('a' <= s[i] && s[i] <= 'z')
			c += s[i] - 'a' + 1;
		else if ('A' <= s[i] && s[i] <= 'Z')
			c += s[i] - 'A' + 1;
	}
	return c;
}

int
main(void)
{
	printf("%zu\n", presses("qudusayo"));
	printf("%zu\n", presses("que"));
	printf("%zu\n", presses("abd"));
	printf("%zu\n", presses("abde"));
	printf("%zu\n", presses("azy"));
	printf("%zu\n", presses("AAA"));
	return 0;
}
