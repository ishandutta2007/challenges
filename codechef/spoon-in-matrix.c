/*

Chef recently saw the movie Matrix. He loved the movie overall but he didn't agree with some things in it.
Particularly he didn't agree with the bald boy when he declared - There is no spoon.
Being a chef, he understands the importance of the spoon and realizes that the universe can't survive without it.
Furthermore, he is sure there is a spoon; he saw it in his kitchen this morning.
So he has set out to prove the bald boy is wrong and find a spoon in the matrix.
He has even obtained a digital map already. Can you help him?
Formally you're given a matrix of lowercase and uppercase Latin letters.
Your job is to find out if the word "Spoon" occurs somewhere in the matrix or not.
A word is said to be occurred in the matrix if it is presented in some row from left to
right or in some column from top to bottom. Note that match performed has to be case insensitive. 

*/
#include <stdio.h>
#include <ctype.h>

const char *
find(size_t r, size_t c, int m[r][c])
{
	static const char w[] = "spoon";
	size_t i, j, k;
	int f;

	for (i = 0; i < r; i++) {
		for (j = 0; j < c; j++) {
			f = 0x0;
			for (k = 0; w[k] != '\0'; k++) {
				if (j + k >= c || w[k] != tolower(m[i][j + k]))
					f |= 0x1;
				if (i + k >= r || w[k] != tolower(m[i + k][j]))
					f |= 0x2;
				if ((f & 0x3) == 0x3)
					break;
			}
			if ((f & 0x3) != 0x3)
				return "There is a spoon!";
		}
	}
	return "There is indeed no spoon!";
}

int
main(void)
{
	int a[3][6] = {
	    {'a', 'b', 'D', 'e', 'f', 'b'},
	    {'b', 'S', 'p', 'o', 'o', 'n'},
	    {'N', 'I', 'K', 'H', 'i', 'l'},
	};
	printf("%s\n", find(3, 6, a));

	int b[6][6] = {
	    {'a', 'a', 'a', 'a', 'a', 'a'},
	    {'s', 's', 's', 's', 's', 's'},
	    {'x', 'u', 'i', 's', 'd', 'P'},
	    {'o', 'o', 'o', 'o', 'o', 'o'},
	    {'i', 'o', 'o', 'w', 'o', 'o'},
	    {'b', 'd', 'y', 'l', 'a', 'n'},
	};
	printf("%s\n", find(6, 6, b));

	int c[6][5] = {
	    {'b', 'd', 'f', 'h', 'j'},
	    {'c', 'a', 'c', 'a', 'c'},
	    {'o', 'p', 'q', 'r', 's'},
	    {'d', 'd', 'd', 'd', 'd'},
	    {'i', 'n', 'd', 'i', 'a'},
	    {'y', 'u', 'c', 'k', 'y'},
	};
	printf("%s\n", find(6, 5, c));

	return 0;
}
