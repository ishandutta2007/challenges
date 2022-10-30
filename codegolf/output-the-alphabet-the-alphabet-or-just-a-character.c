/*

The challenge is simple:

Write a function or program that takes an input x, and outputs the lower case alphabet if x is part of the lower case alphabet, outputs the upper case alphabet if x is part of the upper case alphabet and outputs just x if it's not part of either.

Rules:

    The input can be function argument or from STDIN
    The input will be any of the printable ASCII characters from 32 to 126 (space to tilde).
    The input may be inside quotation marks,'x' or "x", but remember that ' and " are valid input and should be supported.
    The input can be any of the letters in the alphabet, i.e. you can't assume it will be a or A.
    The output should be only one of the alphabets or the single symbol, but trailing newlines are OK.
    The letters in the alphabet should not be separated by spaces, commas or anything else.

Some examples:

F
ABCDEFGHIJKLMNOPQRSTUVWXYZ

z
abcdefghijklmnopqrstuvwxyz

"
"

    <- Input:  Space
    <- Output: Space

Shortest code in bytes win.

Optional but appreciated: If your language has an online interpreter, please also post a link so that it can be easily tested by others.

*/

#include <stdio.h>

void
output(char c)
{
	int i, j;

	i = j = c;
	if ('a' <= c && c <= 'z') {
		i = 'a';
		j = 'z';
	} else if ('A' <= c && c <= 'Z') {
		i = 'A';
		j = 'Z';
	}

	for (; i <= j; i++)
		printf("%c", i);
	printf("\n");
}

int
main(void)
{
	output('F');
	output('z');
	output('"');
	output(' ');

	return 0;
}
