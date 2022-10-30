/*

In typography, a counter is the area of a letter that is entirely or partially enclosed by a letter form or a symbol.
A closed counter is a counter that is entirely enclosed by a letter form or symbol.
You must write a program takes a string as input and prints the total number of closed counters in the text.

Your input:

May be a command line input, or from STDIN, but you must specify which.

Will consist entirely of the printable ASCII characters, meaning all ASCII values between 32 and 126 inclusive. This does include spaces. More information.

Now, this does vary slightly between fonts. For example, the font you're reading this in considers 'g' to have one closed counter, whereas the google font has 'g' with two closed counters.
So that this is not an issue, here are the official number of closed counters per character.

All the symbols with no closed counters:

 !"'()*+,-./12357:;<=>?CEFGHIJKLMNSTUVWXYZ[\]^_`cfhijklmnrstuvwxyz{|}~
Note that this includes space.

Here are all the symbols with one closed counter:

#0469@ADOPQRabdegopq
And here are all the symbols with 2 closed counters:

$%&8B
And last but not least, here are some sample inputs and outputs.

Programming Puzzles and Code-Golf should print 13

4 8 15 16 23 42 should print 5

All your base are belong to us should print 12

Standard loopholes apply should print 12

Shortest answer in bytes is the winner! should print 8

*/

#include <assert.h>
#include <stdio.h>
#include <string.h>

size_t
closed(const char *s)
{
	static const char c1[] = "#0469@ADOPQRabdegopq";
	static const char c2[] = "$%&8B";

	size_t c, i;

	for (c = i = 0; s[i]; i++) {
		if (strchr(c1, s[i]))
			c += 1;
		else if (strchr(c2, s[i]))
			c += 2;
	}
	return c;
}

int
main(void)
{
	assert(closed("Programming Puzzles and Code-Golf") == 13);
	assert(closed("4 8 15 16 23 42") == 5);
	assert(closed("All your base are belong to us") == 12);
	assert(closed("Standard loopholes apply") == 12);
	assert(closed("Shortest answer in bytes is the winner!") == 8);

	return 0;
}
