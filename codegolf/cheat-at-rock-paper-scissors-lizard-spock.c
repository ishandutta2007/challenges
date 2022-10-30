/*

When playing Rock-Paper-Scissors-Lizard-Spock, your robot reflexes let you see your opponent's throw before they make it. You just need to choose a throw that beats theirs, in as few bytes as possible of course.

There's always two winning throws, and either one will work.

RPSLS throws diagram

Input    -> Possible outputs
------------------------------
Rock     -> Spock or Paper
Spock    -> Paper or Lizard
Paper    -> Lizard or Scissors
Lizard   -> Scissors or Rock
Scissors -> Rock or Spock

Take a string as input, and output one of the strings that beats it. Strings must be exactly as given, with capitalization. List of characters may substitute for strings.

*/

#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define nelem(x) (sizeof(x) / sizeof(x[0]))

const char *
cheat(const char *s)
{
	static const char *tab[][3] = {
	    {"Rock", "Spock", "Paper"},
	    {"Spock", "Paper", "Lizard"},
	    {"Paper", "Lizard", "Scissors"},
	    {"Lizard", "Scissors", "Rock"},
	    {"Scissors", "Rock", "Spock"},
	};

	size_t i;

	for (i = 0; i < nelem(tab); i++) {
		if (!strcmp(s, tab[i][0]))
			return tab[i][(rand() & 1) + 1];
	}
	return NULL;
}

int
main(void)
{
	srand(time(NULL));

	printf("%s\n", cheat("Rock"));
	printf("%s\n", cheat("Spock"));
	printf("%s\n", cheat("Paper"));
	printf("%s\n", cheat("Lizard"));
	printf("%s\n", cheat("Scissors"));

	return 0;
}
