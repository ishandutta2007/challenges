/*

I'm a huge video game music fan. One of my favorite OSTs is that from Kingdom Hearts, by Yoko Shimomura.

The challenge

Create a program or function that takes two arguments in any format: an abbreviated Kingdom Hearts game and a boss in that game.
It must return the name of the song that plays for that boss. The program should handle any input case, but you can decide what case the output will be.
You may assume the input is always valid. Here is a list of all the valid inputs:

Game   Boss                       Song

1      Ansem                      Guardando nel Buio
1      Riku                       Forze de Male
1      Sephiroth                  One Winged Angel
1      Kurt Zisa                  The Deep End
1      Unknown                    Disappeared
2      Organization XIII          The 13th Struggle, Dilemma, Reflection
2      Xemnas I                   A Fight to the Death
2      Xemnas II                  Darkness of the Unknown
2      Sephiroth                  One Winged Angel
2      Lingering Sentiment        Rage Awakened
CoM    Organization XIII          The 13th Struggle
CoM    Marluxia 1                 Graceful Assasin
CoM    Marluxia 2                 Scythe of Petals
CoM    Marluxia 3                 Lord of the Castle
CoM    Riku Replica               The Force in You
CoM    Ansem                      Revenge of Chaos
BBS    Master Xehanort            Black Powder
BBS    Terra vs Master Xehanort   Rage Awakened
BBS    Vanitas                    Enter the Darkness
BBS    Ventus vs Vanitas          The Key
BBS    Vanitas Remnant            Enter the Void
BBS    Terranort                  Dismiss
BBS    Mysterious Figure          Dark Impetus
Coded  Riku                       Riku
Coded  Pete                       Rowdy Rumble
Coded  Maleficent                 Vim and Vigor
Coded  Sora's Heartless           Guardando nel Buio
Coded  Roxas                      The Other Promise
Days   Xion                       Vector to the Heavens
Days   Riku                       Another Side
DDD    Anti Black Coat Nightmare  Dread of Night
DDD    Ansem I                    L'Eminenza Oscura I
DDD    Ansem II                   L'Eminenza Oscura II
DDD    Xemnas                     L'Oscurita dell'Ignoto
DDD    Young Xehanort             L'Impeto Oscuro
DDD    Armored Ventus Nightmare   Eye of Darkness
DDD    Julius                     The Encounter

Scoring
Your score is not your byte count. You do not need to implement the entire list, but you must implement at least 10 items.
Your score is byte count / # of items implemented. For instance, say you write a 90-byte program that implements 25 items of the above table. Your score would be 90/25=3.6. Lowest score wins.

Bonus
-1 off your score of you implement an additional item, from Final Fantasy:

Game    Boss        Song

XV      Behemoth    Omnis Lacrima
AND make it so that any other requested bosses from XV return TBD.

-0.5 if your code also takes in the games 1.5 and 2.5, which take the same bosses as 1 and 2 but return the song name followed by (Orchestrated).

Another -0.5 if your program accepts bosses from CoM and Days when given 1.5 and accepts bosses from Coded and BBS when given 2.5. It must return the songs followed by (Orchestrated).

If you know of any other significant bosses I left out, let me know in the comments.

Also, I'm hoping I'm not the only person here who has memorized all of these songs...

*/

#include <assert.h>
#include <stdio.h>
#include <string.h>

#define nelem(x) (sizeof(x) / sizeof(x[0]))

const char *
getsong(const char *game, const char *boss)
{
	static const char tab[][3][64] = {
	    {"1", "Ansem", "Guardando nel Buio"},
	    {"1", "Riku", "Forze de Male"},
	    {"1", "Sephiroth", "One Winged Angel"},
	    {"1", "Kurt Zisa", "The Deep End"},
	    {"1", "Unknown", "Disappeared"},
	    {"2", "Organization XIII", "The 13th Struggle, Dilemma, Reflection"},
	    {"2", "Xemnas I", "A Fight to the Death"},
	    {"2", "Xemnas II", "Darkness of the Unknown"},
	    {"2", "Sephiroth", "One Winged Angel"},
	    {"2", "Lingering Sentiment", "Rage Awakened"},
	    {"CoM", "Organization XIII", "The 13th Struggle"},
	    {"CoM", "Marluxia 1", "Graceful Assasin"},
	    {"CoM", "Marluxia 2", "Scythe of Petals"},
	    {"CoM", "Marluxia 3", "Lord of the Castle"},
	    {"CoM", "Riku Replica", "The Force in You"},
	    {"CoM", "Ansem", "Revenge of Chaos"},
	    {"BBS", "Master Xehanort", "Black Powder"},
	    {"BBS", "Terra vs Master Xehanort", "Rage Awakened"},
	    {"BBS", "Vanitas", "Enter the Darkness"},
	    {"BBS", "Ventus vs Vanitas", "The Key"},
	    {"BBS", "Vanitas Remnant", "Enter the Void"},
	    {"BBS", "Terranort", "Dismiss"},
	    {"BBS", "Mysterious Figure", "Dark Impetus"},
	    {"Coded", "Riku", "Riku"},
	    {"Coded", "Pete", "Rowdy Rumble"},
	    {"Coded", "Maleficent", "Vim and Vigor"},
	    {"Coded", "Sora's Heartless", "Guardando nel Buio"},
	    {"Coded", "Roxas", "The Other Promise"},
	    {"Days", "Xion", "Vector to the Heavens"},
	    {"Days", "Riku", "Another Side"},
	    {"DDD", "Anti Black Coat Nightmare", "Dread of Night"},
	    {"DDD", "Ansem I", "L'Eminenza Oscura I"},
	    {"DDD", "Ansem II", "L'Eminenza Oscura II"},
	    {"DDD", "Xemnas", "L'Oscurita dell'Ignoto"},
	    {"DDD", "Young Xehanort", "L'Impeto Oscuro"},
	    {"DDD", "Armored Ventus Nightmare", "Eye of Darkness"},
	    {"DDD", "Julius", "The Encounter"},
	};

	size_t i;

	for (i = 0; i < nelem(tab); i++) {
		if (!strcmp(game, tab[i][0]) && !strcmp(boss, tab[i][1]))
			return tab[i][2];
	}
	return NULL;
}

void
test(const char *game, const char *boss, const char *result)
{
	const char *song;

	song = getsong(game, boss);
	if (song == NULL)
		assert(song == result);
	else
		assert(!strcmp(song, result));
}

int
main(void)
{
	test("1", "Ansem", "Guardando nel Buio");
	test("DDD", "Julius", "The Encounter");

	return 0;
}
