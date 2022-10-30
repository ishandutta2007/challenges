/*

Find the sum of all left leaves in a given binary tree.

Example:

    3
   / \
  9  20
    /  \
   15   7

There are two left leaves in the binary tree, with values 9 and 15 respectively. Return 24.

*/

#include <stdio.h>
#include <stdlib.h>

typedef struct Node Node;

struct Node {
	int val;
	Node *left;
	Node *right;
};

Node *
nod(int val)
{
	Node *n;

	n = calloc(1, sizeof(*n));
	if (!n)
		abort();
	n->val = val;
	return n;
}

int
leftsum(Node *n)
{
	int v;

	if (!n)
		return 0;

	v = 0;
	if (n->left)
		v = n->left->val;
	return v + leftsum(n->left) + leftsum(n->right);
}

void
freenode(Node *n)
{
	if (!n)
		return;
	freenode(n->left);
	freenode(n->right);
	free(n);
}

int
main(void)
{
	Node *n;

	n = nod(3);
	n->left = nod(9);
	n->right = nod(20);
	n->right->left = nod(15);
	n->right->right = nod(7);
	printf("%d\n", leftsum(n));
	freenode(n);
	return 0;
}
