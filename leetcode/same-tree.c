/*

Given two binary trees, write a function to check if they are the same or not.

Two binary trees are considered the same if they are structurally identical and the nodes have the same value.

*/

#include <stdio.h>
#include <stdlib.h>

typedef struct Node Node;

struct Node {
	int data;
	Node *left;
	Node *right;
};

int
same(Node *p, Node *q)
{
	if (!p && !q)
		return 1;
	if (p && !q)
		return 0;
	if (!p && q)
		return 0;

	return p->data == q->data && same(p->left, q->left) && same(p->right, q->right);
}

Node *
nod(int data)
{
	Node *n;

	n = calloc(1, sizeof(*n));
	if (!n)
		abort();
	n->data = data;
	return n;
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
	Node *p, *q;

	p = nod(1);
	p->left = nod(2);
	p->right = nod(3);
	q = nod(1);
	q->left = nod(2);
	q->right = nod(3);
	printf("%d\n", same(p, q));
	freenode(p);
	freenode(q);

	p = nod(1);
	p->left = nod(2);
	q = nod(1);
	q->right = nod(2);
	printf("%d\n", same(p, q));
	freenode(p);
	freenode(q);

	p = nod(1);
	p->left = nod(2);
	p->right = nod(1);
	q = nod(1);
	q->left = nod(1);
	q->right = nod(2);
	printf("%d\n", same(p, q));
	freenode(p);
	freenode(q);

	return 0;
}
