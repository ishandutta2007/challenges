/*

You are to print this exact text:

A
ABA
ABCBA
ABCDCBA
ABCDEDCBA
ABCDEFEDCBA
ABCDEFGFEDCBA
ABCDEFGHGFEDCBA
ABCDEFGHIHGFEDCBA
ABCDEFGHIJIHGFEDCBA
ABCDEFGHIJKJIHGFEDCBA
ABCDEFGHIJKLKJIHGFEDCBA
ABCDEFGHIJKLMLKJIHGFEDCBA
ABCDEFGHIJKLMNMLKJIHGFEDCBA
ABCDEFGHIJKLMNONMLKJIHGFEDCBA
ABCDEFGHIJKLMNOPONMLKJIHGFEDCBA
ABCDEFGHIJKLMNOPQPONMLKJIHGFEDCBA
ABCDEFGHIJKLMNOPQRQPONMLKJIHGFEDCBA
ABCDEFGHIJKLMNOPQRSRQPONMLKJIHGFEDCBA
ABCDEFGHIJKLMNOPQRSTSRQPONMLKJIHGFEDCBA
ABCDEFGHIJKLMNOPQRSTUTSRQPONMLKJIHGFEDCBA
ABCDEFGHIJKLMNOPQRSTUVUTSRQPONMLKJIHGFEDCBA
ABCDEFGHIJKLMNOPQRSTUVWVUTSRQPONMLKJIHGFEDCBA
ABCDEFGHIJKLMNOPQRSTUVWXWVUTSRQPONMLKJIHGFEDCBA
ABCDEFGHIJKLMNOPQRSTUVWXYXWVUTSRQPONMLKJIHGFEDCBA
ABCDEFGHIJKLMNOPQRSTUVWXYZYXWVUTSRQPONMLKJIHGFEDCBA
ABCDEFGHIJKLMNOPQRSTUVWXYXWVUTSRQPONMLKJIHGFEDCBA
ABCDEFGHIJKLMNOPQRSTUVWXWVUTSRQPONMLKJIHGFEDCBA
ABCDEFGHIJKLMNOPQRSTUVWVUTSRQPONMLKJIHGFEDCBA
ABCDEFGHIJKLMNOPQRSTUVUTSRQPONMLKJIHGFEDCBA
ABCDEFGHIJKLMNOPQRSTUTSRQPONMLKJIHGFEDCBA
ABCDEFGHIJKLMNOPQRSTSRQPONMLKJIHGFEDCBA
ABCDEFGHIJKLMNOPQRSRQPONMLKJIHGFEDCBA
ABCDEFGHIJKLMNOPQRQPONMLKJIHGFEDCBA
ABCDEFGHIJKLMNOPQPONMLKJIHGFEDCBA
ABCDEFGHIJKLMNOPONMLKJIHGFEDCBA
ABCDEFGHIJKLMNONMLKJIHGFEDCBA
ABCDEFGHIJKLMNMLKJIHGFEDCBA
ABCDEFGHIJKLMLKJIHGFEDCBA
ABCDEFGHIJKLKJIHGFEDCBA
ABCDEFGHIJKJIHGFEDCBA
ABCDEFGHIJIHGFEDCBA
ABCDEFGHIHGFEDCBA
ABCDEFGHGFEDCBA
ABCDEFGFEDCBA
ABCDEFEDCBA
ABCDEDCBA
ABCDCBA
ABCBA
ABA
A

Specs

    Extra trailing newlines are allowed at the end of the output.
    Extra trailing spaces (U+0020) are allowed at the end of each line, including the extra trailing newlines.
    You can use all lowercase instead of all uppercase, but you cannot print partially lowercase partially uppercase.
    You can return the text as a function output instead of printing it in a full program.

Scoring

Since this is a triangle, and a triangle has 3 sides, and 3 is a small number, your code should be small in terms of byte-count.

*/

#include <stdio.h>
#include <stdlib.h>

void
gen(void)
{
	int i, j, k;

	for (i = -25; i < 26; i++) {
		k = 26 - abs(i);
		for (j = 0; j < k; j++)
			printf("%c", 'A' + j);
		for (j = k - 1; j > 0; j--)
			printf("%c", 'A' + j - 1);
		printf("\n");
	}
}

int
main(void)
{
	gen();
	return 0;
}
