/*

Everybody is worried about Rakesh as the boy does not have much knowledge about the real world.
He can not go from one place to another on his own. It's high time he learned to explore the city.
He is going to a relative's house situated on the other side of the city on his own.
As this is his first time, he is carrying a GPS tracker of a special kind. The tracker continuously sends information to the family of Rakesh about his movement.
The information is sent using the following four letters: U, D, R, and L. Those letters indicate the moves taken by Rakesh.

The city can be considered as a grid. Rakesh starts his journey from (0, 0) position of the grid. His relative's house is situated at (Rx, Ry). Rakesh can move in four directions: up, down, right, or left indicated by U, D, R, and L respectively.

Any position of the city with x coordinate negative or greater than M is considered as dangerous.
Also, any position of the city with y coordinate negative or greater than N is considered as dangerous.
You will be given the total sequence of Rakesh's movement. You need to determine if Rakesh ended up being at his relative's house, at a dangerous place, or at a random place in the city.

To make things clear,

U indicates a move that increases position along y-axis by 1
D indicates a move that decreases position along y-axis by 1
R indicates a move that increases position along x-axis by 1
L indicates a move that decreases position along x-axis by 1
Note that we are interested in the position of Rakesh at the end of his journey only. He may visit some dangerous place or his relative's house at some intermediate point but that won't affect the answer.

Input

The first line of the input contains an integer T denoting the number of test cases. The description of each test case follows.
The first line of each test case contains two integers M and N.
The second line contains two integers Rx and Ry.
The third line contains the length of Rakesh's move sequence.
The next line contains the move sequence containing letters U, D, R, and L only with no space.

Output

For each test case, print "Case i: ", and then the answer, where i is the testcase number, 1-indexed. The answer should be any of the following three strings:

"REACHED" if Rakesh could reach his relative's house
"DANGER" if Rakesh ended up being in a dangerous place
"SOMEWHERE" if Rakesh ended up being in somewhere safe place in the city other than his relative's place
Don't print any quotation mark. Check the sample output.

Constraints
1 ≤ T ≤ 10
0 ≤ M, N ≤ 10000
0 ≤ Rx ≤ M
0 ≤ Ry ≤ N
0 ≤ Sum of the lengths of all sequences ≤ 10000

*/

#include <assert.h>
#include <stdio.h>
#include <string.h>

const char *
endup(int m, int n, int rx, int ry, const char *s)
{
	size_t i;
	int x, y;

	x = y = 0;
	for (i = 0; s[i]; i++) {
		x += (s[i] == 'R');
		x -= (s[i] == 'L');
		y += (s[i] == 'U');
		y -= (s[i] == 'D');
	}

	if (x == rx && y == ry)
		return "REACHED";
	if (x < 0 || x > m || y < 0 || y > n)
		return "DANGER";
	return "SOMEWHERE";
}

void
test(int m, int n, int rx, int ry, const char *s, const char *t)
{
	const char *p;

	p = endup(m, n, rx, ry, s);
	printf("%s\n", p);
	assert(!strcmp(p, t));
}

int
main(void)
{
	test(20, 20, 4, 5, "LLUUUUURRRRRR", "REACHED");
	test(10, 10, 3, 4, "UDUDDRR", "DANGER");
	test(100, 100, 1, 1, "", "SOMEWHERE");

	return 0;
}
