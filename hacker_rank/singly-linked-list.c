// some common single linked list operations
#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>
#include <stdbool.h>

typedef struct List List;

struct List {
	int data;
	List *next;
};

void
printrev_rec(List *l)
{
	if (l == NULL)
		return;
	printrev_rec(l->next);
	printf("%d\n", l->data);
}

void
printrev(List *l)
{
	printrev_rec(l);
	printf("\n");
}

void
print(List *l)
{
	for (; l != NULL; l = l->next)
		printf("%d->", l->data);
	printf("nil\n");
}

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
reverse(List *l)
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

List *
mergesorted(List *a, List *b)
{
	List *h, *p, *q;

	h = NULL;
	p = NULL;
	while (a != NULL && b != NULL) {
		if (a->data < b->data) {
			q = a;
			a = a->next;
		} else {
			q = b;
			b = b->next;
		}

		if (p == NULL) {
			p = q;
			h = p;
		} else
			p = p->next = q;
		p->next = NULL;
	}

	if (p != NULL) {
		if (a != NULL)
			p->next = a;
		else
			p->next = b;
	}

	return h;
}

List *
find(List *l, int v)
{
	for (; l != NULL; l = l->next) {
		if (v == l->data)
			return l;
	}
	return NULL;
}

List *
insertat(List *l, size_t n, int v)
{
	List *p, *q;
	size_t i;

	p = NULL;
	for (i = 0; i < n; i++) {
		if (l == NULL)
			return NULL;

		p = l;
		l = l->next;
	}

	q = insert(NULL, v);
	q->next = l;
	if (p != NULL)
		p->next = q;

	return q;
}

bool
samelist(List *a, List *b)
{
	for (;;) {
		if (a == NULL && b == NULL)
			break;

		if (a == NULL || b == NULL || a->data != b->data)
			return false;

		a = a->next;
		b = b->next;
	}
	return true;
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

bool
detectcycle(List *l)
{
	List *a, *b;

	a = b = l;
	while (b && b->next) {
		a = a->next;
		b = b->next->next;
		if (a == b)
			return true;
	}
	return false;
}

List *
tail(List *l)
{
	if (!l)
		return NULL;
	while (l->next)
		l = l->next;
	return l;
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

int
main(void)
{
	List *l = mklist(5, 16, 12, 4, 2, 5);
	printrev(l);
	freelist(l);

	l = mklist(3, 7, 3, 9);
	printrev(l);
	freelist(l);

	l = mklist(5, 5, 1, 18, 3, 13);
	printrev(l);
	freelist(l);

	l = mklist(6, 1, 2, 3, 4, 5, 6);
	l = reverse(l);
	print(l);
	l = reverse(l);
	print(l);
	freelist(l);

	List *l1 = mklist(6, 1, 2, 3, 8, 9, 10);
	List *l2 = mklist(6, 1, 2, 3, 4, 5, 6);
	List *l3 = mergesorted(l1, l2);
	print(l3);
	l3 = reverse(l3);
	print(l3);
	l3 = reverser(l3);
	print(l3);
	printf("%p\n", (void *)find(l3, 9));
	printf("%p\n", (void *)find(l3, 100));
	printf("%p\n", (void *)find(l3, 3));
	freelist(l3);

	l = mklist(3, 3, 91, 100);
	print(l);
	insertat(l, 1, 30);
	l = insertat(l, 0, 50);
	print(l);
	freelist(l);

	l1 = mklist(2, 1, 2);
	l2 = mklist(1, 1);
	printf("%d\n", samelist(l1, l2));
	insert(l2, 2);
	printf("%d\n", samelist(l1, l2));
	freelist(l1);
	freelist(l2);

	l1 = mklist(1, 2, 3, 4);
	l2 = tail(l1);
	l2->next = l1;
	printf("cycle: %d\n", detectcycle(l1));
	l2->next = NULL;
	printf("cycle: %d\n", detectcycle(l1));
	freelist(l1);

	return 0;
}
