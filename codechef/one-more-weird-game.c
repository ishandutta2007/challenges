/*

Leha is playing a very interesting game. The game will be played on a rectangular grid consisting of N rows and M columns. Initially all the cells of the grid are uncolored.

Leha's initial score is zero. At each turn, he chooses some cell that is yet not colored, and colors that cell.
The score obtained in this step will be number of neighboring colored cells of the cell that Leha colored in this step.
Two cells are neighbors of each other if they share a side between them. The game will end when all the cells are colored.
Finally, total score obtained at the end of the game will sum of score obtained in each turn.

Leha wants to know what maximum score he can get? Can you please help him in finding this out?

Input

The first line contains a single integer T denoting the number of test cases. T test cases follow.

Each of the following T lines contains two space-separated integers N, M denoting the dimensions of the grid.

Output

For each test case, output a single line containing an integer corresponding to the maximal possible score Leha can obtain.

Constraints
1 ≤ T ≤ 100
1 ≤ N, M ≤ 1 000

*/

#include <assert.h>
#include <stdio.h>

int
maxscore(int n, int m)
{
	return (2 * m * n) - m - n;
}

int
main(void)
{
	assert(maxscore(2, 2) == 4);

	return 0;
}
