/*

A binary tree is univalued if every node in the tree has the same value.

Return true if and only if the given tree is univalued.

*/

#include <stdio.h>
#include <stdlib.h>

#define nelem(x) (sizeof(x) / sizeof(x[0]))

typedef struct Node Node;

struct Node {
	int val;
	Node *left;
	Node *right;
};

int
univaluedrec(Node *n, int v)
{
	if (!n)
		return 1;
	if (n->val != v)
		return 0;
	return univaluedrec(n->left, v) && univaluedrec(n->right, v);
}

int
univalued(Node *r)
{
	if (!r)
		return 1;
	return univaluedrec(r, r->val);
}

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
nod(int v)
{
	Node *n;

	if (v < 0)
		return NULL;
	n = xcalloc(1, sizeof(*n));
	n->val = v;
	return n;
}

Node *
mklvl(int *a, size_t n)
{
	Node **q, *r, *p;
	size_t i, j, k;

	if (n == 0)
		return NULL;

	r = p = nod(a[0]);
	j = k = 0;
	q = xcalloc(n, sizeof(*q));

	for (i = 1; i < n;) {
		if (!p->left) {
			p->left = q[k++] = nod(a[i]);
			i++;
		} else if (!p->right) {
			p->right = q[k++] = nod(a[i]);
			i++;
		} else
			p = q[j++];
	}

	free(q);
	return r;
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

void
test(int *a, size_t n)
{
	Node *r;

	r = mklvl(a, n);
	printf("%d\n", univalued(r));
	freebst(r);
}

int
main(void)
{
	int a[] = {1, 1, 1, 1, 1, -1, 1};
	test(a, nelem(a));

	int b[] = {2, 2, 2, 5, 2};
	test(b, nelem(b));

	return 0;
}
