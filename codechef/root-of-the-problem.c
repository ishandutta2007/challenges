/*

Chef has a binary tree. The binary tree consists of 1 or more nodes. Each node has a unique integer id. Each node has up to 2 children, which are identified by their ids, and each node is the child of at most 1 other node.
A node X is considered to be an ancestor of node Y if node Y is a child of node X or if there is some node Z for which X is an ancestor of Z and Y is a child of Z.
No node is an ancestor of itself. A special node called the root node is an ancestor of all other nodes.

Chef has forgotten which node of his tree is the root, and wants you to help him to figure it out.
Unfortunately, Chef's knowledge of the tree is incomplete.
He does not remember the ids of the children of each node, but only remembers the sum of the ids of the children of each node.

Input

Input begins with an integer T, the number of test cases. Each test case begins with an integer N, the number of nodes in the tree.
N lines follow with 2 integers each: the id of a node, and the sum of the ids of its children. The second number will be 0 if the node has no children.

Output

For each test case, output on a line a space separated list of all possible values for the id of the root node in increasing order. It is guaranteed that at least one such id exists for each test case.

Constraints
1 ≤ T ≤ 50
1 ≤ N ≤ 30
All node ids are between 1 and 1000, inclusive

*/

#include <assert.h>
#include <stdio.h>

#define nelem(x) (sizeof(x) / sizeof(x[0]))

int
id(int a[][2], size_t n)
{
	size_t i;
	int r;

	r = 0;
	for (i = 0; i < n; i++)
		r += a[i][0] - a[i][1];
	return r;
}

int
main(void)
{
	int a1[][2] = {
	    {4, 0},
	};

	int a2[][2] = {
	    {1, 5},
	    {2, 0},
	    {3, 0},
	    {4, 0},
	    {5, 5},
	    {6, 5},
	};

	assert(id(a1, nelem(a1)) == 4);
	assert(id(a2, nelem(a2)) == 6);

	return 0;
}
