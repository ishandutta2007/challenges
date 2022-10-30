/*

Chef loves Chess and has thus invented a new piece named "Disabled King".

Let's denote the cell at the intersection of the i-th column from the left and j-th row from the top by (i,j).

If he is currently in cell (x,y), the disabled king can move to the following positions in one move (provided that he remains in the chessboard):

(x,y+1)
(x,y−1)
(x+1,y+1)
(x+1,y−1)
(x−1,y+1)
(x−1,y−1)
In short, the Disabled King cannot move horizontally.

In an N×N chessboard, the Disabled King is currently situated at the top-left corner (cell (1,1)) and wants to reach the top-right corner (cell (N,1)). Determine the minimum number of moves in which the task can be accomplished.

Input Format

The first line will contain T, the number of test cases. Then the test cases follow.
Each test case contains a single integer N in a separate line.

Output Format

Output the minimum number of moves to get from the top-left cell to the top-right one.

Constraints
1≤T≤500
2≤N≤500

*/

#include <assert.h>

int
moves(int n)
{
	return (n & 1) ? n - 1 : n;
}

int
main(void)
{
	assert(moves(2) == 2);
	assert(moves(3) == 2);

	return 0;
}
