/*

"Let the games begin."

Squid Game has become a blockbuster hit and the frontman is now finding it difficult to accommodate all the participants in Squid Game 2.0. So, he decided that he will allow only those participants who could solve the following problem.

There are a total of N players who are competing in the Squid Game, numbered from 1 to N. When the ith player gets eliminated from the game, Ai amount of money is added to the prize pool.
The game is played until N−1 players get eliminated, and the only player left is declared as the winner. The winner gets all the money present in the prize pool.

You are given an array A consisting of N elements, where Ai denotes the prize money added to the prize pool when the ith player gets eliminated from the game. Find the maximum prize that the winner can get, given that you can choose any player to be the winner.

Input Format

The first line of input contains a single integer T, denoting the number of test cases. The description of T test cases follows.
The first line of each test case contains an integer N, denoting the number of players.
The second line of each test case contains N space-separated integers A1,A2,…,AN, denoting the amount of money added to the prize pool when the ith (1≤i≤N) player dies.

Output Format

For each test case, output in a single line the maximum prize that the winner can get, given that you can choose any player to be the winner.

Constraints
1≤T≤1000
2≤N≤10^5
0≤Ai≤10^4

The sum of N across all test cases does not exceed 10^6

*/

#include <assert.h>
#include <stdio.h>
#include <limits.h>

#define nelem(x) (sizeof(x) / sizeof(x[0]))
#define min(a, b) (((a) < (b)) ? (a) : (b))

typedef unsigned long long uvlong;

uvlong
maxprize(uvlong *a, size_t n)
{
	uvlong s, m;
	size_t i;

	s = 0;
	m = UINT_MAX;
	for (i = 0; i < n; i++) {
		s += a[i];
		m = min(a[i], m);
	}
	return s - m;
}

int
main(void)
{
	uvlong a1[] = {3, 1, 2};
	uvlong a2[] = {1, 1, 1, 1, 1};
	uvlong a3[] = {3, 6, 4, 2, 5, 1};

	assert(maxprize(a1, nelem(a1)) == 5);
	assert(maxprize(a2, nelem(a2)) == 4);
	assert(maxprize(a3, nelem(a3)) == 20);

	return 0;
}
