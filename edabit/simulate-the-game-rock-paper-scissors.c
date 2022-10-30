/*

Create a function which simulates the game "rock, paper, scissors". The function takes the input of both players (rock, paper or scissors), first parameter from first player, second from second player. The function returns the result as such:

    "Player 1 wins"
    "Player 2 wins"
    "TIE" (if both inputs are the same)

The rules of rock, paper, scissors, if not known:

    Both players have to say either "rock", "paper" or "scissors" at the same time.
    Rock beats scissors, paper beats rock, scissors beat paper.

*/

#include <stdio.h>
#include <string.h>

#define nelem(x) (sizeof(x) / sizeof(x[0]))

const char *
rps(const char *a, const char *b)
{
	static const char *tab[] = {
		"rock",
		"scissors",

		"paper",
		"rock",

		"scissors",
		"paper",
	};
	size_t i;

	for (i = 0; i < nelem(tab); i += 2) {
		if (!strcmp(a, tab[i]) && !strcmp(b, tab[i + 1]))
			return "Player 1 wins";
		if (!strcmp(b, tab[i]) && !strcmp(a, tab[i + 1]))
			return "Player 2 wins";
	}
	return "TIE";
}

int
main(void)
{
	printf("%s\n", rps("rock", "paper"));
	printf("%s\n", rps("paper", "rock"));
	printf("%s\n", rps("paper", "scissors"));
	printf("%s\n", rps("scissors", "scissors"));
	printf("%s\n", rps("scissors", "paper"));
	return 0;
}
