/*

It's a Pokemon battle! Your task is to calculate the damage that a particular move would do using the following formula (not the actual one from the game):

damage = 50 * (attack / defense) * effectiveness

    attack = your attack power
    defense = the opponent's defense
    effectiveness = the effectiveness of the attack based on the matchup (see explanation below)

Effectiveness:

Attacks can be super effective, neutral, or not very effective depending on the matchup. For example, water would be super effective against fire, but not very effective against grass.

    Super effective: 2x damage
    Neutral: 1x damage
    Not very effective: 0.5x damage

To prevent this challenge from being tedious, you'll only be dealing with four types: fire, water, grass, and electric. Here is the effectiveness of each matchup:

    fire > grass
    fire < water
    fire = electric
    water < grass
    water < electric
    grass = electric

The function you must implement takes in:

    your type
    the opponent's type
    your attack power
    the opponent's defense

Examples

calculateDamage("fire", "water", 100, 100) ➞ 25

calculateDamage("grass", "fire", 35, 5) ➞ 175

calculateDamage("electric", "fire", 100, 100) ➞ 50

Notes

Any type against itself is not very effective. Also, assume that the relationships between different types are symmetric (if A is super effective against B, then B is not very effective against A).

*/

#include <assert.h>
#include <stdio.h>
#include <string.h>

#define nelem(x) (sizeof(x) / sizeof(x[0]))

int
element(const char *s)
{
	static const char *tab[] = {
	    "fire",
	    "water",
	    "grass",
	    "electric",
	};
	size_t i;

	for (i = 0; i < nelem(tab); i++) {
		if (!strcmp(s, tab[i]))
			return i;
	}
	return -1;
}

double
effectiveness(const char *s, const char *t)
{
	static const double tab[4][4] = {
	    {1, 0.5, 2, 1},
	    {2, 1, 0.5, 0.5},
	    {0.5, 2, 1, 1},
	    {1, 2, 1, 1},
	};
	int x, y;

	x = element(s);
	y = element(t);
	if (x < 0 || y < 0)
		return 0;
	return tab[x][y];
}

int
damage(const char *s, const char *t, int a, int d)
{
	return 50.0 * a / d * effectiveness(s, t);
}

int
main(void)
{
	assert(damage("fire", "water", 100, 100) == 25);
	assert(damage("grass", "water", 100, 100) == 100);
	assert(damage("electric", "fire", 100, 100) == 50);
	assert(damage("grass", "electric", 57, 19) == 150);
	assert(damage("grass", "water", 40, 40) == 100);
	assert(damage("grass", "fire", 35, 5) == 175);
	assert(damage("fire", "electric", 10, 2) == 250);

	return 0;
}
