/*

We have two arrays N and P, where N represents the value of a node in Binary Tree, and P is the parent of N.
N	P
1	2
3	2
6	8
9	8
2	5
8	5
5	-1

Write a function to find the node type of Binary Tree ordered by the value of the node. Output one of the following:

    Root: If node is root node.
    Leaf: If node is leaf node.
    Inner: If node is neither root nor leaf node.
    Not exist: If node not exist.

nodeType([1, 3, 6, 9, 2, 8, 5], [2, 2, 8, 8, 5, 5, -1], 5) ➞ "Root"

nodeType([1, 3, 6, 9, 2, 8, 5], [2, 2, 8, 8, 5, 5, -1], 6) ➞ "Leaf"

nodeType([1, 3, 6, 9, 2, 8, 5], [2, 2, 8, 8, 5, 5, -1], 2) ➞ "Inner"

nodeType([1, 3, 6, 9, 2, 8, 5], [2, 2, 8, 8, 5, 5, -1], 10) ➞ "Not exist"

Notes

All values of N array are unique.

*/

#include <assert.h>
#include <string.h>

#define nelem(x) (sizeof(x) / sizeof(x[0]))

const char *
nodetype(int *N, int *P, size_t n, int v)
{
	size_t i, j;

	for (i = 0; i < n; i++) {
		if (v == N[i])
			break;
	}

	if (i == n)
		return "Not exist";

	if (P[i] < 0)
		return "Root";

	for (j = 0; j < n; j++) {
		if (P[j] == N[i])
			return "Inner";
	}

	return "Leaf";
}

int
main(void)
{
	int N1[] = { 1, 3, 6, 9, 2, 8, 5 };
	int P1[] = { 2, 2, 8, 8, 5, 5, -1 };

	int N2[] = { 6, 3, 1, 2, 5, 7, 4, 6, 8 };
	int P2[] = { 3, 1, 6, 1, 2, 3, 8, -1, 6 };

	int N3[] = { 5, 6, 8, 7, 1, 9, 4, 11, 10, 2 };
	int P3[] = { 8, 8, -1, 8, 7, 4, 5, 4, 1, 1 };

	int N4[] = { 3, 2, 4, 9, 11, 10, 8, 5, 6, 7 };
	int P4[] = { -1, 3, 3, 2, 3, 4, 4, 9, 10, 8 };

	assert(!strcmp(nodetype(N1, P1, nelem(P1), 1), "Leaf"));
	assert(!strcmp(nodetype(N1, P1, nelem(P1), 2), "Inner"));
	assert(!strcmp(nodetype(N1, P1, nelem(P1), 3), "Leaf"));
	assert(!strcmp(nodetype(N1, P1, nelem(P1), 5), "Root"));
	assert(!strcmp(nodetype(N1, P1, nelem(P1), 6), "Leaf"));
	assert(!strcmp(nodetype(N1, P1, nelem(P1), 8), "Inner"));
	assert(!strcmp(nodetype(N1, P1, nelem(P1), 9), "Leaf"));
	assert(!strcmp(nodetype(N1, P1, nelem(P1), 10), "Not exist"));

	assert(!strcmp(nodetype(N2, P2, nelem(P2), 8), "Inner"));
	assert(!strcmp(nodetype(N2, P2, nelem(P2), 5), "Leaf"));

	assert(!strcmp(nodetype(N3, P3, nelem(P3), 11), "Leaf"));
	assert(!strcmp(nodetype(N3, P3, nelem(P3), 4), "Inner"));
	assert(!strcmp(nodetype(N3, P3, nelem(P3), 8), "Root"));

	assert(!strcmp(nodetype(N4, P4, nelem(P4), 3), "Root"));
	assert(!strcmp(nodetype(N4, P4, nelem(P4), 6), "Leaf"));
	assert(!strcmp(nodetype(N4, P4, nelem(P4), 10), "Inner"));

	return 0;
}
