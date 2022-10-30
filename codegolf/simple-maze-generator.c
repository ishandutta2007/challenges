/*

Just had a 'spirited' conversation with a co-worker about the succinctness of the following BASIC statement:

10 PRINT CHR$(205.5+RND(1)); : GOTO 10

It's the title of this book, and will simply print a sequence of / and \ characters, alternating between the two randomly, resulting in a pattern similar to this:

enter image description here

(Image borrowed from http://www.flickr.com/photos/rndmcnlly/5058442151/sizes/o/in/photostream/)

Being of a PHP proclivity, we wondered what the most compact way of writing the same thing in PHP would be, and came up with this:

while(1) { echo chr(47 + 45 * rand(0,1)); }

chr(47) is a / character, and chr(92) is a \. So the statement echo chr(47 + 45 * rand(0,1)); will randomly alternative between the two, ad nauseum.

In a language of your choosing, write the shortest program or function to output an infinite random sequence of \ and / characters, where each character has an equal probability of being chosen.

*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void
gen(int w, int h)
{
	int x, y;

	for (y = 0; y < h; y++) {
		for (x = 0; x < w; x++)
			printf("%c", 47 + 45 * (rand() & 1));
		printf("\n");
	}
}

int
main(void)
{
	srand(time(NULL));
	gen(50, 50);
	return 0;
}
