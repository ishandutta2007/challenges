/*

Challenge
Write a program that reorders the ASCII characters!

It should output a single string containing all of the printable ASCII characters exactly once. The first character of this string is assigned the value 1, the second character the value 2, and so on.

If two characters are normally next to each other (the difference between their character codes is 1), they may not appear next to each other in the output.

Scoring
Your score will be the sum of the values for all of the characters in your source code, as dictated by your program's output.

Please see the Verification section to calculate your score.

Lowest score wins!

Rules
"Printable ASCII" is defined to mean character codes 32 - 126, inclusive.

You may write a full program or a function.

Your code may only contain printable ASCII characters and newlines.

Your program may not take any input.

Newlines will always have the value 1. Your program's output should not include a newline.

*/

#include <assert.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int
remap(char *b)
{
	int i, j;

	j = 0;
	for (i = 32; i <= 126; i += 2)
		b[j++] = i;
	for (i = 33; i <= 126; i += 2)
		b[j++] = i;
	b[j] = '\0';
	return j;
}

void
test(void)
{
	char b[128], f[128];
	int i, n;

	n = remap(b);
	printf("%s\n", b);

	memset(f, 0, sizeof(f));
	for (i = 0; i < n; i++)
		f[b[i] & 0xff] = 1;
	for (i = 32; i <= 126; i++)
		assert(f[i] != 0);
	for (i = 1; i < n; i++)
		assert(abs(b[i] - b[i - 1]) != 1);
}

int
main(void)
{
	test();
	return 0;
}
