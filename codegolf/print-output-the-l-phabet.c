/*

Inspired by George Gibson's Print a Tabula Recta.

You are to print/output this exact text:

ABCDEFGHIJKLMNOPQRSTUVWXYZ
BBCDEFGHIJKLMNOPQRSTUVWXYZ
CCCDEFGHIJKLMNOPQRSTUVWXYZ
DDDDEFGHIJKLMNOPQRSTUVWXYZ
EEEEEFGHIJKLMNOPQRSTUVWXYZ
FFFFFFGHIJKLMNOPQRSTUVWXYZ
GGGGGGGHIJKLMNOPQRSTUVWXYZ
HHHHHHHHIJKLMNOPQRSTUVWXYZ
IIIIIIIIIJKLMNOPQRSTUVWXYZ
JJJJJJJJJJKLMNOPQRSTUVWXYZ
KKKKKKKKKKKLMNOPQRSTUVWXYZ
LLLLLLLLLLLLMNOPQRSTUVWXYZ
MMMMMMMMMMMMMNOPQRSTUVWXYZ
NNNNNNNNNNNNNNOPQRSTUVWXYZ
OOOOOOOOOOOOOOOPQRSTUVWXYZ
PPPPPPPPPPPPPPPPQRSTUVWXYZ
QQQQQQQQQQQQQQQQQRSTUVWXYZ
RRRRRRRRRRRRRRRRRRSTUVWXYZ
SSSSSSSSSSSSSSSSSSSTUVWXYZ
TTTTTTTTTTTTTTTTTTTTUVWXYZ
UUUUUUUUUUUUUUUUUUUUUVWXYZ
VVVVVVVVVVVVVVVVVVVVVVWXYZ
WWWWWWWWWWWWWWWWWWWWWWWXYZ
XXXXXXXXXXXXXXXXXXXXXXXXYZ
YYYYYYYYYYYYYYYYYYYYYYYYYZ
ZZZZZZZZZZZZZZZZZZZZZZZZZZ

(Yes, I typed that by hand)

You are allowed to use all lowercase instead of all uppercase.

However, your choice of case must be consistent throughout the whole text.
Rules/Requirements

    Each submission should be either a full program or function. If it is a function, it must be runnable by only needing to add the function call to the bottom of the program. Anything else (e.g. headers in C), must be included.
    If it is possible, provide a link to a site where your program can be tested.
    Your program must not write anything to STDERR.
    Standard Loopholes are forbidden.
    Your program can output in any case, but it must be printed (not an array or similar).

Scoring

Programs are scored according to bytes, in UTF-8 by default or a different character set of your choice.

Eventually, the answer with the least bytes will win.

*/

#include <stdio.h>

void
gen(void)
{
	int i, j;

	for (i = 0; i < 26; i++) {
		for (j = 0; j <= i; j++)
			printf("%c", 'A' + i);
		for (; j < 26; j++)
			printf("%c", 'A' + j);
		printf("\n");
	}
}

int
main(void)
{
	gen();
	return 0;
}
