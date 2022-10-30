/*

One of the reasons I've always loved Pokemon is because for such a simple-seeming game, it has so many layers of complexity.
Let's consider the move Hidden Power. In game, the type and power (at least before Generation VI) of Hidden Power is different for every Pokemon that uses it!
That's pretty cool, right? Now, would you be surprised if I told you that the type and power of Hidden Power isn't generated randomly?

In all Pokemon games, all Pokemon (not just ones in your party, ALL POKEMON) have six internally-stored integers
(one for the HP stat, one for the attack stat, one for the defense stat, one for the special attack stat, one for the special defense stat and one for the speed stat) called their individual values, or IVs.
These values range between 0 and 31, and they essentially are one of a few factors that influence a Pokemon's overall stats. HOWEVER, they also determine the type and power of Hidden Power!

In Generation III to V (the generations whose algorithm we'll be implementing), the type of Hidden Power is determined by the following formula (note the floor brackets, that means you need to round down the result):

where a, b, c, d, e and f are the least significant bits of the HP, Attack, Defense, Speed, Sp. Attack, and Sp. Defense IVs respectively. (Least significant bit is IV mod 2.) The number produced here then can be converted to the actual type using this chart:

0 Fighting
1 Flying
2 Poison
3 Ground
4 Rock
5 Bug
6 Ghost
7 Steel
8 Fire
9 Water
10 Grass
11 Electric
12 Psychic
13 Ice
14 Dragon
15 Dark
For power, a similar formula is used:

Here, however, u, v, w, x, y and z represent the second least significant bit of the HP, Attack, Defense, Speed, Sp. Attack and Sp. Defense IVs (in that order again).
(Second least significant bit is more complicated then least significant bit. If IV mod 4 is 2 or 3, then the bit is 1, otherwise it is 0.
If your language has some sort of built-in or at least a more clever way to do this, you should probably use it.)

So, as you probably figured out already, the challenge here is to write a program that takes in six integers separated by
spaces via STDIN that represent the HP, Attack, Defense, Speed, Sp. Attack and Sp. Defense IVs of a Pokemon (in that order)
and output the type and power of that Pokemon's Hidden Power.

Sample input:

30 31 31 31 30 31
Sample output:

Grass 70
Sample input:

16 18 25 13 30 22
Sample output:

Poison 61
This is code-golf, so shortest code wins. Good luck!

(And before people ask, I used the Generation V algorithm here because Generation VI gets rid of the power randomization and makes it always 60.
Not only do I think this is incredibly lame, I think it makes the challenge a LOT LESS INTERESTING.
So for the purposes of the challenge, we're running a Gen V game.)

*/

#include <assert.h>
#include <stdio.h>
#include <string.h>

#define nelem(x) (sizeof(x) / sizeof(x[0]))

void
classify(int hp, int atk, int def, int spd, int spa, int spf, char *hpt, int *hpp)
{
	static const char *types[] = {
	    "Fighting",
	    "Flying",
	    "Poison",
	    "Ground",
	    "Rock",
	    "Bug",
	    "Ghost",
	    "Steel",
	    "Fire",
	    "Water",
	    "Grass",
	    "Electric",
	    "Psychic",
	    "Ice",
	    "Dragon",
	    "Dark",
	};

	int val[] = {hp, atk, def, spd, spa, spf};

	int a, b;
	size_t i;

	a = b = 0;
	for (i = 0; i < nelem(val); i++) {
		a += (1 << i) * !!(val[i] & 1);
		b += (1 << i) * !!(val[i] & 2);
	}
	a = (a * 15) / 63;
	b = (b * 40) / 63 + 30;

	strcpy(hpt, types[a]);
	*hpp = b;
}

void
test(int hp, int atk, int def, int spd, int spa, int spf, const char *rhtp, int rhpp)
{
	char htp[80];
	int hpp;

	classify(hp, atk, def, spd, spa, spf, htp, &hpp);
	printf("%s %d\n", htp, hpp);
	assert(!strcmp(htp, rhtp));
	assert(hpp == rhpp);
}

int
main(void)
{
	test(30, 31, 31, 31, 30, 31, "Grass", 70);
	test(16, 18, 25, 13, 30, 22, "Poison", 61);

	return 0;
}
