/*

This is my 12th question, so I thought of this idea.

Goal:

Output 12, with any preceding or trailing whitespace permitted
In as many languages as possible (where different versions or flags count as the same language)
Without using any numbers
The criteria for a valid programming language are the same as those of The Programming Language Quiz, Mark II - Cops:
It has an English Wikipedia article, an esolangs article or a Rosetta Code article at the time this challenge was posted, or is on Try It Online! (or ATO). Having an interpreter linked in any of these pages makes that interpreter completely legal.
It must satisfy our rules on what constitutes a programming language.
It must have a free interpreter (as in beer). Free here means that anyone can use the program without having to pay to do so.
Each answer must run in less than a minute on a reasonable PC.
Your score is BytesLanguages2. Obviously the lowest score wins. This means that you can't submit something that runs in no languages (wink).

*/

#include <stdio.h>

int
main(void)
{
	static int n;

	n++;
	n++;
	n++;
	n++;
	n++;
	n++;
	n++;
	n++;
	n++;
	n++;
	n++;
	n++;

	printf("%d\n", n);
	return !n;
}
