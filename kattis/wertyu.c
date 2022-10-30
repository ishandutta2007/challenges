/*

A common typing error is to place the hands on the keyboard one row to the right of the correct position. So "Q" is typed as "W" and "J" is typed as "K" and so on. You are to decode a message typed in this manner.

Input

Input consists of several lines of text. Each line may contain digits, spaces, upper case letters (except Q, A, Z), or punctuation shown above [except back-quote (‘)]. Keys labelled with words [Tab, BackSp, Control, etc.] are not represented in the input.

There will be at most 10000 characters in the input.

Output

Replace each letter or punctuation symbol by the one immediately to its left on the QWERTY keyboard shown above. Spaces in the input should be echoed in the output.

*/

#include <assert.h>
#include <stdio.h>
#include <string.h>

char *
wertyu(const char *s, char *b)
{
	static const char tab[256] = {
	    ['1'] = '`',
	    ['2'] = '1',
	    ['3'] = '2',
	    ['4'] = '3',
	    ['5'] = '4',
	    ['6'] = '5',
	    ['7'] = '6',
	    ['8'] = '7',
	    ['9'] = '8',
	    ['0'] = '9',
	    ['-'] = '0',
	    ['='] = '-',
	    ['W'] = 'Q',
	    ['E'] = 'W',
	    ['R'] = 'E',
	    ['T'] = 'R',
	    ['Y'] = 'T',
	    ['U'] = 'Y',
	    ['I'] = 'U',
	    ['O'] = 'I',
	    ['P'] = 'O',
	    ['['] = 'P',
	    [']'] = '[',
	    ['\\'] = ']',
	    ['S'] = 'A',
	    ['D'] = 'S',
	    ['F'] = 'D',
	    ['G'] = 'F',
	    ['H'] = 'G',
	    ['J'] = 'H',
	    ['K'] = 'J',
	    ['L'] = 'K',
	    [';'] = 'L',
	    ['\''] = ';',
	    ['X'] = 'Z',
	    ['C'] = 'X',
	    ['V'] = 'C',
	    ['B'] = 'V',
	    ['N'] = 'B',
	    ['M'] = 'N',
	    [','] = 'M',
	    ['.'] = ',',
	    ['/'] = '.',
	    [' '] = ' ',
	};

	size_t i;
	int c;

	for (i = 0; s[i]; i++) {
		c = tab[s[i] & 0xff];
		b[i] = (c) ? c : s[i];
	}
	b[i] = '\0';
	return b;
}

int
main(void)
{
	char b[128];

	assert(!strcmp(wertyu("O S, GOMR YPFSU/", b), "I AM FINE TODAY."));
	return 0;
}
