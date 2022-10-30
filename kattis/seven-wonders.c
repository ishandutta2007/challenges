/*

Seven Wonders is a card drafting game in which players build structures to earn points. The player who ends with the most points wins.
One winning strategy is to focus on building scientific structures.
There are three types of scientific structure cards: Tablet (‘T’), Compass (‘C’), and Gear (‘G’). For each type of cards, a player earns a number of points that is equal to the squared number of that type of cards played.
Additionally, for each set of three different scientific cards, a player scores 7 points.

For example, if a player plays 3 Tablet cards, 2 Compass cards and 1 Gear card, she gets 32+22+12+7=21 points.

It might be tedious to calculate how many scientific points a player gets by the end of each game. Therefore, you are here to help write a program for the calculation to save everyone’s time.

Input

The input has a single string with no more than 50 characters. The string contains only letters ‘T’, ‘C’ or ‘G’, which denote the scientific cards a player has played in a Seven Wonders game.

Output

Output the number of scientific points the player earns.

Note

Seven Wonders was created by Antoine Bauza, and published by Repos Production. Antoine Bauza and Repos Production do not endorse and have no involvement with the ProgNova contest.

*/

#include <assert.h>
#include <stdio.h>
#include <string.h>

#define min(a, b) (((a) < (b)) ? (a) : (b))

unsigned
score(const char *s)
{
	unsigned t, c, g, r;
	size_t i;

	t = c = g = 0;
	for (i = 0; s[i]; i++) {
		t += (s[i] == 'T');
		c += (s[i] == 'C');
		g += (s[i] == 'G');
	}

	r = (t * t) + (c * c) + (g * g);
	r += min(t, min(c, g)) * 7;
	return r;
}

int
main(void)
{
	assert(score("TCGTTC") == 21);
	assert(score("CCC") == 9);
	assert(score("TTCCGG") == 26);
	return 0;
}
