/*

When you select a contiguous block of text in a PDF viewer,
the selection is highlighted with a blue rectangle.
In this PDF viewer, each word is highlighted independently.

In this challenge, you will be given a list of letter heights in the alphabet and a string. Using the letter heights given,
determine the area of the rectangle highlight in mm^2 assuming all letters are mm wide.

For example, the highlighted word=torn.
Assume the heights of the letters are t=2 o=1 r=1 and n=1. The tallest letter is 2 high and there are 4 letters.
The hightlighted area will be 2*4=8mm^2 so the answer is 8.

*/
#include <stdio.h>
#include <limits.h>

#define nelem(x) (sizeof(x) / sizeof(x[0]))

int
wordbox(const char *w, int *h, size_t nh)
{
	size_t i;
	int mh;

	if (nh != 26)
		return -1;

	mh = INT_MIN;
	for (i = 0; w[i] != '\0'; i++) {
		if (!('a' <= w[i] && w[i] <= 'z'))
			return -1;

		if (mh < h[w[i] - 'a'])
			mh = h[w[i] - 'a'];
	}

	return mh * i;
}

int
main(void)
{
	int ha[] = {1, 3, 1, 3, 1, 4, 1, 3, 2, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5};
	printf("%d\n", wordbox("abc", ha, nelem(ha)));

	int hb[] = {1, 3, 1, 3, 1, 4, 1, 3, 2, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 7};
	printf("%d\n", wordbox("zaba", hb, nelem(hb)));

	int hc[26] = {
	    ['t' - 'a'] 2,
	    ['o' - 'a'] 1,
	    ['r' - 'a'] 1,
	    ['n' - 'a'] 1,
	};
	printf("%d\n", wordbox("torn", hc, nelem(hc)));
	return 0;
}
