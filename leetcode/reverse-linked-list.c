/*

Example:

Input: 1->2->3->4->5->NULL
Output: 5->4->3->2->1->NULL

Follow up:

A linked list can be reversed either iteratively or recursively. Could you implement both?

*/

#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>

typedef struct List List;

struct List {
	int data;
	List *next;
};

List *
insert(List *l, int v)
{
	List *lp, *n;

	n = calloc(1, sizeof(*n));
	if (n == NULL)
		return NULL;
	n->data = v;

	for (lp = l; l != NULL; l = l->next)
		lp = l;

	if (lp != NULL)
		lp->next = n;

	return n;
}

List *
mklist(int n, ...)
{
	List *h, *t;
	int i, v;
	va_list ap;

	h = t = NULL;
	va_start(ap, n);
	for (i = 0; i < n; i++) {
		v = va_arg(ap, int);
		t = insert(t, v);
		if (h == NULL)
			h = t;
	}
	va_end(ap);

	return h;
}

void
freelist(List *l)
{
	List *lp;

	while (l != NULL) {
		lp = l->next;
		free(l);
		l = lp;
	}
}

List *
reversei(List *l)
{
	List *p, *n;

	if (l == NULL)
		return l;

	p = NULL;
	n = l->next;
	do {
		l->next = p;
		p = l;
		l = n;
		if (n != NULL)
			n = n->next;
	} while (l != NULL);

	return p;
}

List *
reverser(List *l)
{
	List *p;

	if (l == NULL || l->next == NULL)
		return l;

	p = reverser(l->next);
	l->next->next = l;
	l->next = NULL;
	return p;
}

void
print(List *l)
{
	for (; l != NULL; l = l->next)
		printf("%d->", l->data);
	printf("NULL\n");
}

int
main(void)
{
	List *l;

	l = mklist(5, 1, 2, 3, 4, 5);
	print(l);
	l = reversei(l);
	print(l);
	l = reverser(l);
	print(l);
	freelist(l);

	return 0;
}
