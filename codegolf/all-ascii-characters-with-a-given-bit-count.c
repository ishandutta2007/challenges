/*

The Background

This challenge is inspired by a question that I recently posted on Puzzling Stack Exchange. Please feel free to follow the link if you are interested in the original question. If not then I won't bore you with the details here.

The Facts

Every printable standard ASCII character has a decimal value between 32 and 126 inclusive.
These can be converted to their corresponding binary numbers in the range 100000 to 1111110 inclusive.
When you sum the bits of these binary numbers you will always end up with an integer between 1 and 6 inclusive.

The Challenge

Given an integer between 1 and 6 inclusive as input, write a program or function which will output in any acceptable format all of the printable standard ASCII characters where the sum of the bits of their binary value is equal to the input integer.

The Examples/Test Cases

1 -> ' @'
2 -> '!"$(0ABDHP`'
3 -> '#%&)*,1248CEFIJLQRTXabdhp'
4 -> ''+-.3569:<GKMNSUVYZ\cefijlqrtx'
5 -> '/7;=>OW[]^gkmnsuvyz|'
6 -> '?_ow{}~'
An ungolfed Python reference implementation is available here (TIO).

The Rules

Assume the input will always be an integer (or string representation of an integer) between 1 and 6 inclusive.
You may write a program to display the results or a function to return them.
Output may be in any reasonable format but must be consistent for all inputs. If you choose to output a quoted string then the same type of quotes must be used for all inputs.
Standard loopholes prohibited as usual.
This is code golf so shortest code in each language wins.

*/

#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int
ones(int n)
{
	int c;

	for (c = 0; n; c++)
		n &= (n - 1);
	return c;
}

void
chars(int n, char *b)
{
	int i, j;

	j = 0;
	for (i = 32; i < 128; i++) {
		if (ones(i) == n)
			b[j++] = i;
	}
	b[j] = '\0';
}

void
test(int n, const char *r)
{
	char b[128];

	chars(n, b);
	printf("'%s'\n", b);
	assert(!strcmp(b, r));
}

int
main(void)
{
	test(1, " @");
	test(2, "!\"$(0ABDHP`");
	test(3, "#%&)*,1248CEFIJLQRTXabdhp");
	test(4, "'+-.3569:<GKMNSUVYZ\\cefijlqrtx");
	test(5, "/7;=>OW[]^gkmnsuvyz|");
	test(6, "?_ow{}~");

	return 0;
}
