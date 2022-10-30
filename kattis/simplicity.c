/*

For a string of letters, define the Simplicity of the string to be the number of distinct letters in the string.
For example, the string string has simplicity 6, and the string letter has simplicity 4.

You like strings which have simplicity either 1 or 2.
Your friend has given you a string and you want to turn it into a string that you like.
You have a magic eraser which will delete one letter from any string.
Compute the minimum number of letters you must erase in order to turn the string into a string with simplicity at most 2.

Input

Each input will consist of a single test case. Note that your program may be run multiple times on different inputs.
The input will consist of a line with a single string consisting of at least 1 and at most 100 lowercase letters ‘a’-‘z’.

Output

Output a single integer, indicating the minimum number letters you need to erase in order to give the string a simplicity of 1 or 2.

*/

#include <assert.h>
#include <stdio.h>
#include <string.h>

#define nelem(x) (sizeof(x) / sizeof(x[0]))

size_t
deletions(const char *s)
{
	size_t h[256];
	size_t t, x, y;
	size_t i;

	memset(h, 0, sizeof(h));
	for (i = 0; s[i]; i++)
		h[s[i] & 0xff]++;

	t = x = y = 0;
	for (i = 0; i < nelem(h); i++) {
		t += h[i];
		if (h[i] >= x) {
			y = x;
			x = h[i];
		} else if (h[i] > y)
			y = h[i];
	}
	return t - x - y;
}

int
main(void)
{
	assert(deletions("string") == 4);
	assert(deletions("letter") == 2);
	assert(deletions("aaaaaa") == 0);
	assert(deletions("uncopyrightable") == 13);
	assert(deletions("ambidextrously") == 12);
	assert(deletions("assesses") == 1);
	assert(deletions("assassins") == 2);
	return 0;
}
