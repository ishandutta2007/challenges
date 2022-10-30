/*

You met a 4-th dimensional being who challenged you to a game of dice. The rules are simple: each player rolls 3 6-sided dice and takes the sum of each combination of 2 dice. The player with the highest sum wins. If the first-highest sum is a tie, consider the second-highest sum, and so on.

Your opponent's dice look normal, but you think they might have more than 6 sides! Your goal is to find out if the alien rolled a number higher than 6.

Your input is a set of 3 integers, separated by at least one character (space or otherwise). Input must not be hard coded.

// All valid inputs
6 7 9
6, 7, 9
(6, 7, 9)
Your output is a string representing if the alien cheated. Any output is allowed, as long as two distinct values exist for cheating/valid. Appended whitespace is permitted.

"😀" // (U+1F600) Valid set of dice
"😠" // (U+1F620) Invalid set of dice
Examples:

<-: 8 11 9
->: 😀       // Dice can be found to be 3, 5, and 6, which are all on 6-side die
<-: 9 11 6
->: 😠       // Dice can be found to be 2, 7, and 4, which means the alien cheated!
Assumptions:

Input will be 3 integers, 2-12
Input numbers can be in any order
Die values will be positive integers
Alien only cheated if they rolled greater than 6
Write a program or function that takes inputs, returns or prints outputs.

Fewest bytes wins!

*/

#include <assert.h>
#include <stdio.h>
#include <string.h>

void
swap(int *a, int *b)
{
	int t;

	t = *a;
	*a = *b;
	*b = t;
}

void
sort3(int *a, int *b, int *c)
{
	if (*a > *b)
		swap(a, b);
	if (*a > *c)
		swap(a, c);
	if (*b > *c)
		swap(b, c);
}

const char *
cheated(int a, int b, int c)
{
	int i, j, k;
	int u, v, w;

	sort3(&a, &b, &c);
	for (i = 1; i <= 6; i++) {
		for (j = 1; j <= 6; j++) {
			for (k = 1; k <= 6; k++) {
				u = i + j;
				v = i + k;
				w = j + k;
				sort3(&u, &v, &w);

				if (a == u && b == v && c == w)
					return u8"😀";
			}
		}
	}
	return u8"😠";
}

void
test(int a, int b, int c, const char *r)
{
	const char *p;

	p = cheated(a, b, c);
	printf("%s\n", p);
	assert(!strcmp(p, r));
}

int
main(void)
{
	test(6, 7, 9, u8"😀");
	test(8, 11, 9, u8"😀");
	test(9, 11, 6, u8"😠");

	return 0;
}
