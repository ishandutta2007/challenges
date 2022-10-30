/*

Description

Scrabble is a popular word game where players remove tiles with letters on them from a bag and use them to create words on a board. The total number of tiles as well as the frequency of each letter does not change between games.

For this challenge we will be using the tile set from the English edition, which has 100 tiles total. Here's a reference for the distribution and point value of each tile.

Each tile will be represented by the letter that appears on it, with the exception that blank tiles are represented by underscores _.

Input Description
The tiles already in play are inputted as an uppercase string. For example, if 14 tiles have been removed from the bag and are in play, you would be given an input like this:

AEERTYOXMCNB_S
Output Description
You should output the tiles that are left in the bag. The list should be in descending order of the quantity of each tile left in the bag, skipping over amounts that have no tiles.

In cases where more than one letter has the same quantity remaining, output those letters in alphabetical order, with blank tiles at the end.

10: E
9: I
8: A
7: O
5: N, R, T
4: D, L, U
3: G, S
2: F, H, P, V, W
1: B, C, J, K, M, Q, Y, Z, _
0: X
If more tiles have been removed from the bag than possible, such as 3 Qs, you should give a helpful error message instead of printing the list.

Invalid input. More Q's have been taken from the bag than possible.
Challenge Inputs
PQAREIOURSTHGWIOAE_

LQTOONOEFFJZT

AXHDRUIOR_XHJZUQEE

Challenge Outputs
10: E
7: A, I
6: N, O
5: T
4: D, L, R
3: S, U
2: B, C, F, G, M, V, Y
1: H, J, K, P, W, X, Z, _
0: Q
2.

11: E
9: A, I
6: R
5: N, O
4: D, S, T, U
3: G, L
2: B, C, H, M, P, V, W, Y, _
1: K, X
0: F, J, Q, Z
3.

Invalid input. More X's have been taken from the bag than possible.

Bonus

After the normal output, output the distribution of tiles in play and the total point score of both sets of tiles.

Finally
Have a good challenge idea? Consider submitting it to r/dailyprogrammer_ideas

Thanks to /u/genderdoom for this challenge idea.

*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define nelem(x) (sizeof(x) / sizeof(x[0]))

int
cmp(const void *a, const void *b)
{
	const int *x, *y;

	x = a;
	y = b;

	if (x[0] > y[0])
		return -1;
	if (x[0] < y[0])
		return 1;

	if (x[1] < y[1])
		return -1;
	if (x[1] > y[1])
		return 1;

	return 0;
}

void
bag(const char *s)
{
	static const char letters[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZ_";
	static const int counts[] = {9, 2, 2, 4, 12, 2, 3, 2, 9, 1, 1, 4, 2, 6, 8, 2, 1, 6, 4, 6, 4, 2, 2, 1, 2, 1, 2};

	int h[27][2];
	size_t i, j;

	memset(h, 0, sizeof(h));
	for (i = 0; letters[i]; i++) {
		h[i][0] = counts[i];
		h[i][1] = letters[i];
	}

	for (i = 0; s[i]; i++) {
		if ('A' <= s[i] && s[i] <= 'Z')
			j = s[i] - 'A';
		else if (s[i] == '_')
			j = 26;
		else
			continue;

		if (h[j][0])
			h[j][0]--;
		else {
			printf("Invalid input. More %c's have been taken from the bag than possible.\n", s[i]);
			return;
		}
	}

	qsort(h, nelem(h), sizeof(*h), cmp);

	for (i = 0; i < nelem(h); i = j) {
		printf("%d: ", h[i][0]);
		for (j = i; j < nelem(h) && h[i][0] == h[j][0]; j++) {
			printf("%c ", h[j][1]);
		}
		printf("\n");
	}
	printf("\n");
}

int
main(void)
{
	bag("AEERTYOXMCNB_S");
	bag("PQAREIOURSTHGWIOAE_");
	bag("LQTOONOEFFJZT");
	bag("AXHDRUIOR_XHJZUQEE");

	return 0;
}
