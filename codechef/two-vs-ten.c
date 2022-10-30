/*

Chef Two and Chef Ten are playing a game with a number X.
In one turn, they can multiply X by 2. The goal of the game is to make X divisible by 10.

Help the Chefs find the smallest number of turns necessary to win the game
(it may be possible to win in zero turns) or determine that it is impossible.

*/
#include <stdio.h>

int
turns(int x)
{
	if (x % 10 == 0)
		return 0;
	if (x % 5 != 0)
		return -1;
	return 1;
}

int
main(void)
{
	printf("%d\n", turns(10));
	printf("%d\n", turns(25));
	printf("%d\n", turns(1));
	printf("%d\n", turns(20));
	return 0;
}
