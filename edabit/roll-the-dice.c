/*

Las Vegas style dice have 6 sides numbered 1 to 6.
When rolling 2 dice, a six is 5 times more likely than a two because a six can be rolled 5 different ways (1 + 5, 5 + 1, 2 + 4, 4 + 2, 3 + 3),
while a two can only be rolled 1 way (1 + 1).

Create a function that accepts two arguments:the number of dice rolled, and the outcome of the roll.
The function returns the number of possible combinations that could produce that outcome.
The number of dice can vary from 1 to 6.

For the example given above:

    dice_roll(2, 6) would return 5
    dice_roll(2, 2) would return 1

Examples

dice_roll(1, 3) ➞ 1

dice_roll(2, 5) ➞ 4
# 1 + 4, 4 + 1, 2 + 3, 3 + 2

dice_roll(3, 4) ➞ 3
# 1 + 1 + 2, 1 + 2 + 1, 2 + 1 + 1

dice_roll(4, 18) ➞ 80

dice_roll(6, 20) ➞ 4221

Notes

1 + 5 and 5 + 1 are distinct combinations because die #1 can show 1 while die #2 can show 5, or die #1 can show 5 while die #2 can show 1.

*/

#include <assert.h>
#include <stdio.h>

unsigned
sim(unsigned n, unsigned r, unsigned v)
{
	unsigned i, s;

	if (n == 0)
		return v == r;
	if (v > r)
		return 0;

	s = 0;
	for (i = 1; i <= 6; i++)
		s += sim(n - 1, r, v + i);
	return s;
}

unsigned
diceroll(unsigned n, unsigned r)
{
	return sim(n, r, 0);
}

int
main(void)
{
	assert(diceroll(2, 6) == 5);
	assert(diceroll(1, 3) == 1);
	assert(diceroll(2, 5) == 4);
	assert(diceroll(3, 4) == 3);
	assert(diceroll(4, 18) == 80);
	assert(diceroll(6, 20) == 4221);
	assert(diceroll(1, 6) == 1);
	assert(diceroll(2, 2) == 1);
	assert(diceroll(2, 9) == 4);
	assert(diceroll(3, 7) == 15);
	assert(diceroll(3, 18) == 1);
	assert(diceroll(4, 11) == 104);
	assert(diceroll(4, 21) == 20);
	assert(diceroll(5, 6) == 5);
	assert(diceroll(5, 26) == 70);
	assert(diceroll(6, 6) == 1);
	assert(diceroll(6, 21) == 4332);
	assert(diceroll(6, 31) == 252);

	return 0;
}
