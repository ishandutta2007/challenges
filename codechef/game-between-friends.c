/*

Nitin and Sobhagya were playing a game with coins. If Sobhagya has more coins then he is winning, otherwise Nitin is winning.
Note that this means if both Nitin and Sobhagya have the same number of coins, then Nitin is winning.

Initially Nitin has A coins while Sobhagya has B coins.
Then Ritik came and gave his C coins to the player who is not winning currently,
after which Satyarth came and repeated the same process (gave his D coins to the player who is not winning currently).

Find the final winner of the game.

Input Format

The first line of the input contains an integer T - the number of test cases. The test cases then follow.
The only line of each test case contains four space-separated integers A, B, C, and D.

Output Format

For each test case, output on a single line N if Nitin is the final winner of the game, or S if Sobhagya is the final winner of the game.

Constraints
1≤T≤1000
0≤A,B,C,D≤10^6

*/

#include <assert.h>

int
winner(int a, int b, int c, int d)
{
	if (a < b)
		a += c;
	else
		b += c;

	if (a < b)
		a += d;
	else
		b += d;

	return (a < b) ? 'S' : 'N';
}

int
main(void)
{
	assert(winner(2, 3, 4, 5) == 'S');
	assert(winner(3, 3, 3, 3) == 'N');
	assert(winner(2, 3, 1, 2) == 'S');

	return 0;
}
