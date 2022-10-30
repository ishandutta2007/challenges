/*

The goal of this challenge is to print the following tongue twister:

She sells seashells by the seashore,
The shells she sells are seashells, I'm sure.
So if she sells seashells on the seashore,
Then I'm sure she sells seashore shells.

This is more complicated than just calling your language's print equivalent. Since there are a lot of repeated words and phrases, you can greatly decrease the size of your code by using other tactics.

Rules:

    No querying another website which will respond with the full twister
    You must include all the punctuation and line breaks in the original text.
    You can end with a trailing newline

This is code-golf, so the shortest code wins!

*/

#include <stdio.h>

void
twister(void)
{
	printf("She sells seashells by the seashore,\n");
	printf("The shells she sells are seashells, I'm sure.\n");
	printf("So if she sells seashells on the seashore,\n");
	printf("Then I'm sure she sells seashore shells.\n");
}

int
main(void)
{
	twister();
	return 0;
}
