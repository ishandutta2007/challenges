/*

Print a Tabula Recta!

The Tabula Recta (sometimes called a 'Vigenere Table'), was created by Johannes Trithemius, and has been used in several ciphers, including all variants of Bellaso's Vigenere cipher and the Trithemius cipher. It looks like this:

ABCDEFGHIJKLMNOPQRSTUVWXYZ
BCDEFGHIJKLMNOPQRSTUVWXYZA
CDEFGHIJKLMNOPQRSTUVWXYZAB
DEFGHIJKLMNOPQRSTUVWXYZABC
EFGHIJKLMNOPQRSTUVWXYZABCD
FGHIJKLMNOPQRSTUVWXYZABCDE
GHIJKLMNOPQRSTUVWXYZABCDEF
HIJKLMNOPQRSTUVWXYZABCDEFG
IJKLMNOPQRSTUVWXYZABCDEFGH
JKLMNOPQRSTUVWXYZABCDEFGHI
KLMNOPQRSTUVWXYZABCDEFGHIJ
LMNOPQRSTUVWXYZABCDEFGHIJK
MNOPQRSTUVWXYZABCDEFGHIJKL
NOPQRSTUVWXYZABCDEFGHIJKLM
OPQRSTUVWXYZABCDEFGHIJKLMN
PQRSTUVWXYZABCDEFGHIJKLMNO
QRSTUVWXYZABCDEFGHIJKLMNOP
RSTUVWXYZABCDEFGHIJKLMNOPQ
STUVWXYZABCDEFGHIJKLMNOPQR
TUVWXYZABCDEFGHIJKLMNOPQRS
UVWXYZABCDEFGHIJKLMNOPQRST
VWXYZABCDEFGHIJKLMNOPQRSTU
WXYZABCDEFGHIJKLMNOPQRSTUV
XYZABCDEFGHIJKLMNOPQRSTUVW
YZABCDEFGHIJKLMNOPQRSTUVWX
ZABCDEFGHIJKLMNOPQRSTUVWXY

I frequently need this, but can't find it anywhere on the internet to copy and paste from. Because the square table is so long, and takes frigging ages to type, your code must be as short as possible.
Rules/Requirements

    Each submission should be either a full program or function. If it is a function, it must be runnable by only needing to add the function call to the bottom of the program. Anything else (e.g. headers in C), must be included.
    If it is possible, provide a link to a site where your program can be tested.
    Your program must not write anything to STDERR.
    Standard Loopholes are forbidden.
    Your program can output in any case, but it must be printed (not an array or similar).

Scoring

Programs are scored according to bytes, in UTF-8 by default or a different character set of your choice.

Eventually, the answer with the least bytes will win.
Submissions

To make sure that your answer shows up, please start your answer with a headline, using the following Markdown template:

# Language Name, N bytes

where N is the size of your submission. If you improve your score, you can keep old scores in the headline, by striking them through. For instance:

# Ruby, <s>104</s> <s>101</s> 96 bytes

If there you want to include multiple numbers in your header (e.g. because your score is the sum of two files or you want to list interpreter flag penalties separately), make sure that the actual score is the last number in the header:

# Perl, 43 + 2 (-p flag) = 45 bytes

You can also make the language name a link which will then show up in the leaderboard snippet:

# [><>](http://esolangs.org/wiki/Fish), 121 bytes

Leaderboard

Here is a Stack Snippet to generate both a regular leaderboard and an overview of winners by language.

Show code snippet

*/

#include <stdio.h>

void
vigenere(void)
{
	int i, j;

	for (i = 0; i < 26; i++) {
		for (j = 0; j < 26; j++)
			printf("%c", 'A' + ((i + j) % 26));
		printf("\n");
	}
}

int
main(void)
{
	vigenere();
	return 0;
}
