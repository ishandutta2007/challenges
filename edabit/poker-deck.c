/*

Create a function that generates a poker deck.

A poker deck contains 52 cards in total, 13 cards for each of the four suits (♦ diamonds, ♠ clubs, ♥ hearts and ♣ spades) ranked 2, 3, 4, 5, 6, 7, 8, 9, 10, J, Q, K, A.

Your function should return a list (deck) containing each card as a tuple in the following format:

(rank, suit)

Where rank is a number from 2 to 14 (11, 12, 13 & 14 being J, Q, K & A respectively) and
suit is a string with the first letter of the the card's suit ("d", "c", "h" & "s" for diamonds, clubs, hearts & spades respectively).

Examples

Five of hearts ➞ (5, "h")

Queen of Spades ➞ (12, "s")

Ace of Clubs ➞ (14, "c")

Notes

Extra points for shuffling the deck.

*/

#include <stdio.h>

void
deck(int d[52][2])
{
	static const char suit[] = "cdhs";
	size_t i, j, k;

	k = 0;
	for (i = 2; i <= 14; i++) {
		for (j = 0; j < 4; j++) {
			d[k][0] = i;
			d[k][1] = suit[j];
			k++;
		}
	}
}

void
dump(int d[52][2])
{
	size_t i;

	for (i = 0; i < 52; i++)
		printf("(%d, %c)\n", d[i][0], d[i][1]);
}

int
main(void)
{
	int d[52][2];

	deck(d);
	dump(d);
	return 0;
}
