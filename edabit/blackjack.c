/*

Create a function that takes an array of card numbers and checks if the sum of their value exceeds 21.
If the sum exceeds 21, return true and if the sum is under or equal to 21, return false. Values of the cards are as follows:

    2-10 are their value.
    J-K (face cards) count as 10.
    Aces count either as 1 or 11 - play conservatively, so that if giving an ace a value of 11 causes you to lose and 1 allows you to win, then go with 1.

Examples

overTwentyOne(["2", "8", "J"]) ➞ false

overTwentyOne(["A", "J", "K"]) ➞ false

overTwentyOne(["5", "5", "3", "9"]) ➞ true

overTwentyOne(["2", "6", "4", "4", "5"]) ➞ false

overTwentyOne(["J", "Q", "K"]) ➞ true

Notes

There will be a maximum of one ace in each hand.

*/

#include <assert.h>
#include <stdio.h>
#include <stdbool.h>

bool
over21(const char *s)
{
	size_t i;
	unsigned v;

	v = 0;
	for (i = 0; s[i]; i++) {
		if ('2' <= s[i] && s[i] <= '9')
			v += s[i] - '0';
		else if (s[i] == 'J' || s[i] == 'Q' || s[i] == 'K')
			v += 10;
		else if (s[i] == 'A')
			v += 1;
	}

	return v > 21;
}

int
main(void)
{
	assert(over21("28J") == false);
	assert(over21("AJK") == false);
	assert(over21("5539") == true);
	assert(over21("26445") == false);
	assert(over21("JQK") == true);
	assert(over21("A23") == false);
	assert(over21("AJKQ") == true);
	assert(over21("536679") == true);

	return 0;
}
