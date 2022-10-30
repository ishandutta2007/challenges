/*

Task
Your task is to convert strings like this:

abc^d+ef^g + hijk^l - M^NO^P (Ag^+)
To strings like this:

   d   g       l    N P    +
abc +ef  + hijk  - M O  (Ag )
Which is an approximation to abcd+efg + hijkl - MNOP (Ag+)

In words, raise the characters directly next to carets to the upper line, one character for one caret.

Specs
Extra trailing whitespaces in the output are allowed.
No chained carets like m^n^o will be given as input.
A caret will not be followed immediately by a space or by another caret.
A caret will not be preceded immediately by a space.
All carets will be preceded by at least one character and followed by at least one character.
The input string will only contain printable ASCII characters (U+0020 - U+007E)
Instead of two lines of output, you are allowed to output an array of two strings.
To those who speak regex: the input string will match this regex:

/^(?!.*(\^.\^|\^\^|\^ | \^))(?!\^)[ -~]*(?<!\^)$/

*/

#include <stdio.h>

int
next(int c)
{
	return (c == '^') ? 2 : 1;
}

void
expart(const char *s)
{
	const char *p;

	for (p = s; *p; p += next(*p))
		printf("%c", (*p == '^') ? p[1] : ' ');
	printf("\n");

	for (p = s; *p; p += next(*p))
		printf("%c", (*p != '^') ? p[0] : ' ');
	printf("\n");
}

int
main(void)
{
	expart("abc^d+ef^g + hijk^l - M^NO^P (Ag^+)");

	return 0;
}
