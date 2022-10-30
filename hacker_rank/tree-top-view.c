/*

You are given a pointer to the root of a binary tree. Print the top view of the binary tree.
Top view means when you look the tree from the top the nodes, what you will see will be called the top view of the tree. See the example below.
You only have to complete the function.
For example :

   1
    \
     2
      \
       5
      /  \
     3    6
      \
       4

Top View : 1 -> 2 -> 5 -> 6

*/

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

typedef struct Node Node;

struct Node {
	int data;
	Node *left;
	Node *right;
};

Node *
nod(int d)
{
	Node *n;

	n = calloc(1, sizeof(*n));
	assert(n);
	n->data = d;
	return n;
}

void
topview(Node *r)
{
	Node *n;

	if (!r)
		return;

	for (n = r->left; n; n = n->left)
		printf("%d ", n->data);
	printf("%d ", r->data);
	for (n = r->right; n; n = n->right)
		printf("%d ", n->data);
	printf("\n");
}

int
main(void)
{
	Node *r, *p, *q;

	r = p = nod(1);
	p->right = q = nod(2);
	q->right = p = nod(5);
	p->right = nod(6);
	p->left = q = nod(3);
	q->right = nod(4);
	topview(r);

	return 0;
}
