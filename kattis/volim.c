/*

Croatia’s national television programme is broadcasting an entertainment show titled “I Love Croatia”, modeled on the licensed format I love my country.
In this show two teams of celebrities and public figures play various games which require knowledge about Croatia.
One of the games is Happy Birthday, which will be used in this task, although somewhat altered.

 \includegraphics[width=0.15\textwidth ]{circle}

Eight players numbered one through eight are seated in a circle (see picture).
One of them is holding a box which will explode after 3 minutes and 30 seconds from the beginning of the game when some colorful confetti will be blown out.
The game begins with a question to the player holding the box.
If the players answers incorrectly or skips the question, he is immediately given the next question.
If the player answers correctly, he passes the box to the first player seated on his left and then that player gets the next question.

You are given the numbered label of the player who has the box in the beginning and the outcomes of the first N questions asked.
Determine the numbered label of the player who had the box when it finally exploded.
The question outcome is described with the following data - time passed from the beginning of the question being asked to the moment
an answer was given and whether the answer was true (“T”), false (“N”) or skipped (“P”).
The time between giving the answer and asking the next question shouldn’t be taken into consideration, as well as time necessary for the box to be passed to the next player.
The box will surely explode on a player’s turn.

Input

The first line of input contains a positive integer K (1≤K≤8), the numbered label of the player who has the box initially.
The second line of input contains a positive integer N (1≤N≤100), the number of questions asked during the game.
Each of the following N lines contains a positive integer T (1≤T≤100), time passed from the beginning of the i-th question being asked to the moment an answer was given,
measured in seconds, and a single character Z (“T”, “N” or “P”), the type of answer given.

Output

The first and only line of output must contain the numbered label of the player who had the box when it finally exploded.

*/

#include <assert.h>
#include <stdio.h>

#define nelem(x) (sizeof(x) / sizeof(x[0]))

int
explosion(int k, int a[][2], size_t n)
{
	static const int limit = 210;
	size_t i;
	int t;

	t = 0;
	for (i = 0; i < n; i++) {
		t += a[i][0];
		if (t >= limit)
			return k;
		if (a[i][1] == 'T')
			k = (k == 8) ? 1 : k + 1;
	}
	return -1;
}

int
main(void)
{
	int a1[][2] = {
	    {20, 'T'},
	    {50, 'T'},
	    {80, 'T'},
	    {50, 'T'},
	    {30, 'T'},
	};

	int a2[][2] = {
	    {70, 'T'},
	    {50, 'P'},
	    {30, 'N'},
	    {50, 'T'},
	    {30, 'P'},
	    {80, 'T'},
	};

	assert(explosion(1, a1, nelem(a1)) == 5);
	assert(explosion(5, a2, nelem(a2)) == 7);
	return 0;
}
