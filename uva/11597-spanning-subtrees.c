/*

Let Kn denote the complete undirected graph with n vertices where n is an even number.
In other words, Kn is a graph with n vertices where every two vertices are connected.
Your task is to find the maximum number of spanning trees of Kn that can be formed in such a way that no two of these spanning trees have a common edge.

Input
Each test case will have an even integer n (2 ≤ n ≤ 400), the number of vertices. The last test case
will be followed by a single ‘0’ denoting end of input.

Output
For each test case, print a line in the format, ‘Case X: Y ’, where X is the case number & Y is the
maximum possible number of spanning trees.

Sample Input
4
0

Sample Output
Case 1: 2

*/

#include <assert.h>

int
trees(int n)
{
	return n / 2;
}

int
main(void)
{
	assert(trees(4) == 2);
	return 0;
}
