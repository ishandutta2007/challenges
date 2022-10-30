/*

You’ve been put in charge of an art exhibit from the famous minimalist sculptor J (even his name is minimalist!).
J’s work involves the careful layout of vertically dispositioned orthogonal parallelpipeds in a set of tapering obelisks — in other words, he puts smaller boxes on top of larger boxes.
His most recent triumph is called “2 by 3’s Decreasing,” in which he has various sets of six boxes arranged in two stacks of three boxes each.
One such set is shown below:

\includegraphics[width=0.20\textwidth ]{tower_image.pdf}

J has sent you the art exhibit and it is your job to set up each of the six-box sets at various locations throughout the museum.
But when the sculptures arrived at the museum, uncultured barbarians (i.e., delivery men) simply dropped each set of six boxes on the floor,
not realizing the aesthetic appeal of their original layout.
You need to reconstruct each set of two towers, but you have no idea which box goes on top of the other!
All you know is the following: for each set of six, you have the heights of the two towers,
and you know that in any tower the largest height box is always on the bottom and the smallest height box is on the top.
Armed with this information, you hope to be able to figure out which boxes go together before tomorrow night’s grand opening gala.

Input

The input consists of eight positive integers. The first six represent the heights of the six boxes. These values will be given in no particular order and no two will be equal.

The last two values (which will never be the same) are the heights of the two towers.

All box heights will be ≤100 and the sum of the box heights will equal the sum of the tower heights.

Output

Output the heights of the three boxes in the first tower (i.e., the tower specified by the first tower height in the input),
then the heights of the three boxes in the second tower.
Each set of boxes should be output in order of decreasing height.
Each test case will have a unique answer.

*/

#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int
cmp(const void *a, const void *b)
{
	int x, y;

	x = *(int *)a;
	y = *(int *)b;
	if (x > y)
		return -1;
	if (x == y)
		return 0;
	return 1;
}

int
heights(int h[8], int r[6])
{
	int i, j, k;
	int f, v;

	qsort(h, 6, sizeof(*h), cmp);

	f = 0;
	for (i = 0; i < 6; i++) {
		for (j = i + 1; j < 6; j++) {
			for (k = j + 1; k < 6; k++) {
				v = h[i] + h[j] + h[k];
				if (v == h[6]) {
					r[0] = h[i];
					r[1] = h[j];
					r[2] = h[k];
					f |= 1;
				} else if (v == h[7]) {
					r[3] = h[i];
					r[4] = h[j];
					r[5] = h[k];
					f |= 2;
				}
				if (f == 3)
					return 1;
			}
		}
	}
	return 0;
}

void
test(int h[8], int r[6])
{
	int p[6];

	assert(heights(h, p) > 0);
	printf("%d %d %d %d %d %d\n", p[0], p[1], p[2], p[3], p[4], p[5]);
	assert(!memcmp(r, p, sizeof(p)));
}

int
main(void)
{
	int h1[] = {12, 8, 2, 4, 10, 3, 25, 14};
	int r1[] = {12, 10, 3, 8, 4, 2};

	int h2[] = {12, 17, 36, 37, 51, 63, 92, 124};
	int r2[] = {63, 17, 12, 51, 37, 36};

	test(h1, r1);
	test(h2, r2);

	return 0;
}
