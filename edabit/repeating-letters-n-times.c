/*

Create a function that repeats each character in a string n times.
Examples

Repeat("mice", 5) ➞ "mmmmmiiiiiccccceeeee"

Repeat("hello", 3) ➞ "hhheeellllllooo"

Repeat("stop", 1) ➞ "stop"

*/

#include <assert.h>
#include <stdio.h>
#include <string.h>

char *
repeat(const char *s, unsigned n, char *b)
{
	size_t i, j, k;

	k = 0;
	for (i = 0; s[i]; i++) {
		for (j = 0; j < n; j++)
			b[k++] = s[i];
	}
	b[k] = '\0';
	return b;
}

int
main(void)
{
	char b[128];

	assert(!strcmp(repeat("mice", 5, b), "mmmmmiiiiiccccceeeee"));
	assert(!strcmp(repeat("hello", 3, b), "hhheeellllllooo"));
	assert(!strcmp(repeat("stop", 1, b), "stop"));
	assert(!strcmp(repeat("tomato", 2, b), "ttoommaattoo"));

	return 0;
}
