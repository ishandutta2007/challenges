/*

The name of the challenge was prompted by this GIF and the GIF also gave me the idea.

Your challenge today is to take a input guaranteed to be 2<=n<=100

and output a sequence of x and - characters.

The output for a number N represents a sequence of operations applied to 1 where x means "multiply by 2" and - means "subtract 1". Starting from 1, reading left to right and doing them in order will give you the number N that was inputted.

If you want, you can output using characters other than x and - so long as the choice is consistent through all outputs.

Your strings may be outputted in reverse so long as all are reversed or there is some indication of which are in reverse.

Your score is the source code's size in characters plus the total length of all outputs (again in characters). Have fun everyone!

*/

#include <stdio.h>

char *
seq(unsigned n, char *b)
{
	unsigned m;
	char *p;

	p = b;
	for (m = 1; m < n; m <<= 1)
		*p++ = 'x';
	for (; m > n; m--)
		*p++ = '-';

	*p = '\0';
	return b;
}

int
main(void)
{
	unsigned i;
	char b[128];

	for (i = 2; i <= 100; i++)
		printf("%u: %s\n", i, seq(i, b));

	return 0;
}
