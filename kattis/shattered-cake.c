/*

A rectangular cake is transported via a truck to a restaurant.
On the way to the destination, the truck hits a pothole,
which shatters the cake into N perfectly rectangular pieces of width wi and length li, for 1⩽i⩽N.

At the destination, the damage is assessed, and the customer decides to order a replacement cake of the same dimensions.
Unfortunately, the original order form was incompletely filled and only the width W of the cake is known.
The restaurant asks for your help to find out the length L of the cake.
Fortunately, all pieces of the shattered cake have been kept.

Input

The input consists of the following integers:

    on the first line, the width W of the cake;

    on the second line, the number N of shattered pieces;

    on each of the next N lines, the width wi and length li of each piece.

Limits

    1⩽N⩽5000000;

1⩽W,L⩽10000;

for each 1≤i≤N, 1⩽wi,li⩽10000.

Output

The output should be the integer L.

*/

#include <assert.h>
#include <stdio.h>

#define nelem(x) (sizeof(x) / sizeof(x[0]))

int
length(int w, int p[][2], size_t n)
{
	size_t i;
	int t;

	if (w == 0)
		return 0;

	t = 0;
	for (i = 0; i < n; i++)
		t += p[i][0] * p[i][1];
	return t / w;
}

int
main(void)
{
	int p1[][2] = {
	    {2, 3},
	    {1, 4},
	    {1, 2},
	    {1, 2},
	    {2, 2},
	    {2, 2},
	    {2, 1},
	};

	assert(length(4, p1, nelem(p1)) == 6);

	return 0;
}
