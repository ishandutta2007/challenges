/*

Given an array where elements are sorted in ascending order, convert it to a height balanced BST.

For this problem, a height-balanced binary tree is defined as a binary tree in which the depth of the two subtrees of every node never differ by more than 1.

Example:

Given the sorted array: [-10,-3,0,5,9],

One possible answer is: [0,-3,9,-10,null,5], which represents the following height balanced BST:

     0
   /   \
  -3    9
  /    /
-10   5

*/

#define _GNU_SOURCE
#include <stdio.h>
#include <stdlib.h>
#include <inttypes.h>

#define nelem(x) (sizeof(x) / sizeof(x[0]))

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
arr2bstrec(int *a, ssize_t lo, ssize_t hi)
{
	Node *n;
	ssize_t mid;

	if (lo > hi)
		return NULL;

	mid = lo + (hi - lo) / 2;
	n = xcalloc(1, sizeof(*n));
	n->data = a[mid];
	n->left = arr2bstrec(a, lo, mid - 1);
	n->right = arr2bstrec(a, mid + 1, hi);
	return n;
}

Node *
arr2bst(int *a, size_t n)
{
	if (n == 0)
		return NULL;
	return arr2bstrec(a, 0, n - 1);
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
preorder(Node *n, void (*f)(int))
{
	if (!n)
		return;
	f(n->data);
	preorder(n->left, f);
	preorder(n->right, f);
}

void
print(int a)
{
	printf("%d ", a);
}

void
printbst(Node *n)
{
	preorder(n, print);
	printf("\n");
}

int
main(void)
{
	int a1[] = {-10, -3, 0, 5, 9};
	int a2[] = {1, 2, 3, 4, 5, 6, 7};

	Node *n1 = arr2bst(a1, nelem(a1));
	Node *n2 = arr2bst(a2, nelem(a2));

	printbst(n1);
	printbst(n2);

	freebst(n1);
	freebst(n2);

	return 0;
}
