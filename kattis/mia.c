/*

Mia is a dice game for two players. Each roll consist of two dice. Mia involves bluffing about what a player has rolled, but in this problem we focus only on its scoring rules.
Unlike most other dice games, the score of a roll is not simply the sum of the dice.

Instead, a roll is scored as follows:

Mia (12 or 21) is always highest.

Next come doubles (11, 22, and so on). Ties are broken by value, with 66 being highest.

All remaining rolls are sorted such that the highest number comes first, which results in a two-digit number.
The value of the roll is the value of that number, e.g. 3 and 4 becomes 43.

Input

The input will contain multiple, distinct test cases. Each test case contains on a single line four integers s0 s1 r0 r1 where s0 s1 represent the dice rolled by player 1 and r0 r1 represents the dice rolled by player 2.
The input will be terminated by a line containing 4 zeros.

Output

For each test case, output which player won, or whether there was a tie, using exactly the format shown below.

*/

#include <assert.h>
#include <stdio.h>

#define max(a, b) (((a) > (b)) ? (a) : (b))
#define min(a, b) (((a) < (b)) ? (a) : (b))

int
score(int s0, int s1, int r0, int r1)
{
	int x, y;

	x = max(s0, s1) * 10 + min(s0, s1);
	y = max(r0, r1) * 10 + min(r0, r1);

	if (x == y)
		return 0;

	if (x == 21)
		return 1;
	if (y == 21)
		return 2;

	if (s0 == s1 && r0 != r1)
		return 1;
	if (s0 != s1 && r0 == r1)
		return 2;

	if (x > y)
		return 1;
	return 2;
}

int
main(void)
{
	assert(score(1, 2, 1, 3) == 1);
	assert(score(3, 3, 2, 1) == 2);
	assert(score(6, 6, 4, 4) == 1);
	assert(score(6, 5, 1, 1) == 2);
	assert(score(4, 2, 2, 4) == 0);

	return 0;
}
