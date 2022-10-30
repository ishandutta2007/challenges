/*

Description

Create a fully working "Guess the number" game. The game is played by two players as follows:

    player one chooses a number (A) between 1 and N
    player two tries to guess A choosing a number (B) in the same range
    the first player responds "higher" if A > B, "lower" if A < B or "correct" if A = B.
    steps 2-3 are repeated I times or until "correct" is responded.
    If "correct" is heard, player two wins otherwise he loses.

Specs

Minimum specs for a valid entry:

    user can play either as player one or player two.
    computer plays the other role.
    computer must really try to guess the number while playing as player two (so, guessing against the given data or ignoring the given data is cheating)
    N = 100 or input by the user (your choice)
    I = 5 or input by the user (your choice)
    program must announce then winner at the end.
    full human readable instructions of what to do in each step (e.g "Play as player one or player two?", "Enter another guess:", etc) - don't go nuts on this one; just keep it simple.

Winning conditions

In that order:

    Highest voted entry wins if it's at least 3 votes ahead of the second highest voted entry.
    Shortest entry wins.

*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int
randn(int n)
{
	int r;

	if (n == 0)
		return 0;

	do {
		r = rand();
	} while (r >= (RAND_MAX - (RAND_MAX % n)));

	return (r % n) + 1;
}

void
play(unsigned n, unsigned m)
{
	char b[80];
	int u, v;

	u = randn(m);
	while (n) {
		printf("%u | guess: ", n);
		if (!(fgets(b, sizeof(b), stdin))) {
			printf("\n");
			return;
		}

		if (sscanf(b, "%i", &v) != 1)
			continue;

		if (u > v)
			printf("higher\n");
		else if (u < v)
			printf("lower\n");
		else {
			printf("correct\n");
			break;
		}

		n--;
	}
	if (n)
		printf("you win\n");
	else
		printf("you lose, correct number was %d\n", u);
}

int
main(void)
{
	srand(time(NULL));
	play(10, 10000);
	return 0;
}
