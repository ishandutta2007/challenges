/*

Two players draw a pair of numbered cards so that both players can form a 2 digit number. A winner can be decided if one player's number is larger than the others.

However, there is a rule where a player can swap any one of their cards with any one of the other player's cards in a gamble to get a higher number!
Note that it is illegal to swap the order of your own cards. That means if you draw a 1 then a 9, you cannot swap them to get 91.

Numbered Cards

Paul's strategy is to always swap his lowest number with the opponent's ten's digit. Return whether this results in Paul winning the round.

    n1 is Paul's number
    n2 is his opponent's number

Worked Example

swap_cards(41, 79) ➞ true
// Paul's lowest number is 1
// The opponent's ten's digit is 7
// After the swap: 47 > 19
// Paul wins the round

Examples

swapCards(41, 98) ➞ true

swapCards(12, 28) ➞ true

swapCards(67, 53) ➞ false

swapCards(77, 54) ➞ false

Notes

    If both of Paul's digits are the same, swap the ten's digit with the opponent's (paul likes to live riskily).
    The cards don't include the number 0.

*/

#include <assert.h>
#include <stdbool.h>

#define min(a, b) (((a) < (b)) ? (a) : (b))
#define max(a, b) (((a) > (b)) ? (a) : (b))

void
swap(unsigned *x, unsigned *y)
{
	unsigned t;

	t = *y;
	*y = *x;
	*x = t;
}

bool
swapcards(unsigned x, unsigned y)
{
	unsigned u[2], v[2];

	u[0] = x % 10;
	u[1] = x / 10;
	v[0] = y % 10;
	v[1] = y / 10;

	if (u[0] >= u[1])
		swap(&u[1], &v[1]);
	else
		swap(&u[0], &v[1]);

	return u[0] + u[1] * 10 > v[0] + v[1] * 10;
}

int
main(void)
{
	assert(swapcards(41, 98) == true);
	assert(swapcards(12, 28) == true);
	assert(swapcards(67, 53) == false);
	assert(swapcards(77, 54) == false);
	assert(swapcards(45, 23) == false);
	assert(swapcards(74, 81) == true);
	assert(swapcards(75, 35) == true);
	assert(swapcards(21, 25) == true);
	assert(swapcards(22, 34) == true);
	assert(swapcards(24, 12) == false);
	assert(swapcards(52, 46) == true);
	assert(swapcards(88, 45) == false);
	assert(swapcards(48, 54) == true);
	assert(swapcards(75, 87) == true);
	assert(swapcards(13, 12) == true);
	assert(swapcards(25, 41) == true);
	assert(swapcards(48, 14) == false);

	return 0;
}
