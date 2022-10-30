/*

This question is inspired by the popular Uno card game.

Write a function that takes in two arguments: (1) a player's current hand and (2) the current face-up card on the table.
The function will return true if the player can make a play, or false if the player has to draw from the deck.

A player can make a play if either:

    They have a card that is the same color as the face-up card.
    They have a card that is the same number as the face-up card.

canPlay(["yellow 3", "yellow 7", "blue 8", "red 9", "red 2"], "red 1") => true
// Since the player has two red cards, and the face-up card is red.

canPlay(["yellow 3", "yellow 7"], "blue 7") => true
// Since the player has a 7, and the face-up card is a 7.

Examples

canPlay(["yellow 3", "yellow 5", "red 8"], "red 2") ➞ true

canPlay(["yellow 3", "yellow 5", "red 8"], "blue 5") ➞ true

canPlay(["yellow 3", "blue 5", "red 8", "red 9"], "green 4") ➞ false

canPlay(["yellow 3", "red 8"], "green 2") ➞ false

Notes

    Return false if the player is not holding any cards (an empty array).
    There are no special cards or wild cards in this deck.

*/

#include <assert.h>
#include <stdbool.h>
#include <stdio.h>
#include <string.h>

#define nelem(x) (sizeof(x) / sizeof(x[0]))

bool
playable(const char **s, size_t n, const char *t)
{
	char a[32], b[32];
	int u, v;
	size_t i;

	if (sscanf(t, "%31s %d", a, &u) != 2)
		return false;

	for (i = 0; i < n; i++) {
		if (sscanf(s[i], "%31s %d", b, &v) != 2)
			continue;
		if (u == v || !strcmp(a, b))
			return true;
	}

	return false;
}

int
main(void)
{
	const char *s1[] = {"yellow 3", "yellow 7", "blue 8", "red 9", "red 2"};
	const char *s2[] = {"yellow 3", "yellow 7"};
	const char *s3[] = {"yellow 3", "yellow 5", "red 8"};
	const char *s4[] = {"yellow 3", "yellow 5", "red 8"};
	const char *s5[] = {"yellow 3", "blue 5", "red 8", "red 9"};
	const char *s6[] = {"yellow 3", "red 8"};
	const char *s7[] = {"yellow 5", "yellow 8", "red 0", "blue 0", "green 4"};
	const char *s8[] = {"red 2"};
	const char *s9[] = {"red 2", "red 8", "red 5"};

	assert(playable(s1, nelem(s1), "red 1") == true);
	assert(playable(s2, nelem(s2), "blue 7") == true);
	assert(playable(s3, nelem(s3), "red 2") == true);
	assert(playable(s4, nelem(s4), "blue 5") == true);
	assert(playable(s5, nelem(s5), "green 4") == false);
	assert(playable(s6, nelem(s6), "green 2") == false);
	assert(playable(s7, nelem(s7), "green 2") == true);
	assert(playable(NULL, 0, "green 2") == false);
	assert(playable(s8, nelem(s8), "red 0") == true);
	assert(playable(s9, nelem(s9), "blue 1") == false);

	return 0;
}
