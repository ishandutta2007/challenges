/*

For the purposes of this challenge, we define a binary search tree to be a binary tree with the following properties:

The data value of every node in a node's left subtree is less than the data value of that node.
The data value of every node in a node's right subtree is greater than the data value of that node.
The data value of every node is distinct.

For example, the image on the left below is a valid BST. The one on the right fails on several counts:
- All of the numbers on the right branch from the root are not larger than the root.
- All of the numbers on the right branch from node 5 are not larger than 5.
- All of the numbers on the left branch from node 5 are not smaller than 5.
- The data value 1 is repeated. 

*/
#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>

typedef struct Node Node;

struct Node {
	int data;
	Node *left;
	Node *right;
};

void *
xcalloc(size_t nmemb, size_t size)
{
	void *p;

	p = calloc(nmemb, size);
	if (!p)
		abort();
	return p;
}

Node *
nod(int d)
{
	Node *n;

	n = xcalloc(1, sizeof(*n));
	n->data = d;
	return n;
}

Node *
mklvl(size_t n, ...)
{
	Node **q, *r, *p;
	size_t i, j, k;
	va_list ap;

	if (n == 0)
		return NULL;

	va_start(ap, n);

	r = p = nod(va_arg(ap, int));
	j = k = 0;
	q = xcalloc(n, sizeof(*q));

	for (i = 1; i < n;) {
		if (!p->left) {
			p->left = q[k++] = nod(va_arg(ap, int));
			i++;
		} else if (!p->right) {
			p->right = q[k++] = nod(va_arg(ap, int));
			i++;
		} else
			p = q[j++];
	}

	va_end(ap);
	free(q);
	return r;
}

void
preprint(Node *n)
{
	if (!n)
		return;
	printf("%d\n", n->data);
	preprint(n->left);
	preprint(n->right);
}

int
isbst(Node *n)
{
	if (n == NULL)
		return 1;
	if (n->left && n->left->data >= n->data)
		return 0;
	if (n->right && n->right->data <= n->data)
		return 0;
	return isbst(n->left) && isbst(n->right);
}

void
freebst(Node *n)
{
	if (!n)
		return;
	freebst(n->left);
	freebst(n->right);
	free(n);
}

int
main(void)
{
	Node *r;

	r = mklvl(7, 4, 2, 6, 1, 3, 5, 7);
	printf("%s\n", (isbst(r)) ? "Yes" : "No");
	freebst(r);

	r = mklvl(3, 2, 5, 1, 6, 1);
	printf("%s\n", (isbst(r)) ? "Yes" : "No");
	freebst(r);

	return 0;
}
