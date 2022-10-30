/*

Abigail and Benson are playing Rock, Paper, Scissors.

Each game is represented by an array of length 2, where the first element represents what Abigail played and the second element represents what Benson played.

Given a sequence of games, determine who wins the most number of matches. If they tie, output "Tie".

    R stands for Rock
    P stands for Paper
    S stands for Scissors

Examples

calculateScore([["R", "P"], ["R", "S"], ["S", "P"]]) ➞ "Abigail"

// Benson wins the first game (Paper beats Rock).
// Abigail wins the second game (Rock beats Scissors).
// Abigail wins the third game (Scissors beats Paper). 
// Abigail wins 2/3.

calculateScore([["R", "R"], ["S", "S"]]) ➞ "Tie"

calculateScore([["S", "R"], ["R", "S"], ["R", "R"]]) ➞ "Tie"

*/

#include <assert.h>
#include <stdio.h>
#include <string.h>

#define nelem(x) (sizeof(x) / sizeof(x[0]))

int
rps(int c)
{
	switch (c) {
	case 'R':
		return 0;
	case 'P':
		return 1;
	case 'S':
		return 2;
	}
	return -1;
}

int
score(int a, int b)
{
	static const int tab[3][3] = {
	    {0, 2, 1},
	    {1, 0, 2},
	    {2, 1, 0},
	};

	a = rps(a);
	b = rps(b);
	if (a < 0 || b < 0)
		return 0;
	return tab[a][b];
}

const char *
tally(char s[][2], size_t n)
{
	size_t i;
	unsigned p[3];
	int c;

	p[0] = p[1] = p[2] = 0;
	for (i = 0; i < n; i++) {
		c = score(s[i][0], s[i][1]);
		p[c]++;
	}
	if (p[1] == p[2])
		return "Tie";
	return (p[1] > p[2]) ? "Abigail" : "Benson";
}

int
main(void)
{
	char s1[][2] = {
	    {'R', 'P'},
	    {'R', 'S'},
	    {'S', 'P'},
	};
	char s2[][2] = {
	    {'R', 'R'},
	    {'S', 'S'},
	};
	char s3[][2] = {
	    {'S', 'R'},
	    {'R', 'S'},
	    {'R', 'R'},
	};
	char s4[][2] = {
	    {'S', 'R'},
	    {'P', 'R'},
	};
	char s5[][2] = {
	    {'S', 'S'},
	    {'S', 'P'},
	    {'R', 'S'},
	    {'S', 'R'},
	    {'R', 'R'},
	};
	char s6[][2] = {
	    {'S', 'R'},
	    {'S', 'R'},
	    {'S', 'R'},
	    {'R', 'S'},
	    {'R', 'S'},
	};

	assert(!strcmp(tally(s1, nelem(s1)), "Abigail"));
	assert(!strcmp(tally(s2, nelem(s2)), "Tie"));
	assert(!strcmp(tally(s3, nelem(s3)), "Tie"));
	assert(!strcmp(tally(s4, nelem(s4)), "Tie"));
	assert(!strcmp(tally(s5, nelem(s5)), "Abigail"));
	assert(!strcmp(tally(s6, nelem(s6)), "Benson"));

	return 0;
}
