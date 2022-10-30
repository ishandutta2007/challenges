/*

Let us take a break from the brain-wrecking questions and answer some of the simpler ones

You have recently read something extremely funny, and want to express your laughter to the world! But how can you?

Task

You have to display the string: Lolololololololololololololololololololololololololololololololololololololololololololololololololololololololol...

...to STDOUT.

The string should be of infinite length, or will constantly be printed until the end of time.

It is just as simple!

But remember, this is code-golf, so the source code must be as short as possible!

Note: Some languages may throw errors since excecution can be timed out, or for other reasons. That is okay! It can be weird when you laugh forever!

*/

#include <stdio.h>

void
lol(void)
{
	unsigned i;

	putchar('L');
	for (i = 0;; i++)
		putchar((i & 1) ? 'l' : 'o');
}

int
main(void)
{
	lol();
	return 0;
}
