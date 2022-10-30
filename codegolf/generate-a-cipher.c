/*

Generate a cipher given a number and string

Your task is simple. Given a string s and a number 0 <= n <= 9 as inputs, insert a pseudo-random printable ASCII character between each character of the string n times.
Such that for each character of s there are n random characters between them. Spaces should be trimmed.

Input:

    string s phrase to encrypt in the cipher
    integer n in the range of 0 <= n <= 9

Example:

Input:

The treasure is here
2

Output:

    T!0h32eF4t0irlkehma7ys#0u*&r*he!2iH^sB,h!@e0)r$he

This is code-golf so the shortest code wins! Good Luck and have fun!

*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

char *
cipher(const char *s, unsigned n, char *b)
{
	size_t i, j;
	unsigned k;

	for (i = j = 0; s[i]; i++) {
		b[j++] = s[i];
		if (s[i + 1] == '\0')
			break;

		for (k = 0; k < n; k++)
			b[j++] = 32 + (rand() % 95);
	}
	b[j] = '\0';

	return b;
}

void
test(const char *s, unsigned n)
{
	char b[128];

	cipher(s, n, b);
	printf("%s\n", b);
}

int
main(void)
{
	srand(time(NULL));

	test("The treasure is here", 2);
	return 0;
}
