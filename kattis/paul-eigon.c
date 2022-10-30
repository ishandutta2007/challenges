/*

Paul Eigon recently got a new job at a famous company in town.
They have all sorts of cool stuff at the office.
Video games, a swimming pool, a sauna, and even a ping-pong table! Paul really loves his enjoyable new workplace.

Mr. Eigon plays a lot of ping-pong at work. While he is playing, he enjoys having a nice conversation with his opponent.
Discussions are jolly fun to have, but they can also be a bit distracting, enough for Paul to sometimes completely forget whose turn it is to serve the ball the upcoming round!

Paul’s ping-pong games are played with simple rules. The game is played by two players.
The game starts with one of the players serving the ball, and that player does so during the N first rounds.
After that, the other player serves the ball for N rounds, and so on.
Each round is won by exactly one of the players and a player gets one point for each won round (there can be no draws).
When one of the players has reached a certain number of points, that player wins the game.

Paul is in desperate need of a new way to figure out which player should serve the ball the upcoming round, and he wants you to help him.
You should write a program that given N and the current score of the game prints out whose turn it is to serve the ball the upcoming round.
His plan is to run your program on his secret high technology pocket computer, in order to impress his opponent.
And by the way, Paul always serves the first ball (if that makes it easier for you).

Input

Input consists of three integers N, P and Q on a single line. 1≤N≤10^9 denotes the number of serves a player will perform in a row before it is the other player’s turn to serve the ball.
0≤P≤109 denotes Paul’s current score in the ongoing ping-pong game, and 0≤Q≤10^9 denotes his opponent’s score.

Output

Output should consists of a single word on a single line. If it is Paul’s turn to serve the ball, your program should output paul. Otherwise, your program should output opponent.

*/

#include <assert.h>
#include <string.h>

typedef unsigned long long uvlong;

const char *
turn(uvlong n, uvlong p, uvlong q)
{
	return (((p + q) / n) & 1) ? "opponent" : "paul";
}

int
main(void)
{
	assert(!strcmp(turn(5, 3, 7), "paul"));
	assert(!strcmp(turn(1, 1, 4), "opponent"));

	return 0;
}
