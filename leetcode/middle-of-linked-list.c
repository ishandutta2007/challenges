/*

Given a non-empty, singly linked list with head node head, return a middle node of linked list.

If there are two middle nodes, return the second middle node.

*/

#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>

typedef struct List List;

struct List {
	int val;
	List *next;
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

List *
vmklist(size_t n, va_list ap)
{
	List *h, *t, *p;
	size_t i;

	h = NULL;
	for (i = 0; i < n; i++) {
		p = xcalloc(1, sizeof(*p));
		p->val = va_arg(ap, int);
		if (!h)
			h = t = p;
		else {
			t->next = p;
			t = p;
		}
	}
	return h;
}

List *
mklist(size_t n, ...)
{
	List *l;
	va_list ap;

	va_start(ap, n);
	l = vmklist(n, ap);
	va_end(ap);
	return l;
}

void
print(List *l)
{
	for (; l; l = l->next)
		printf("%d ", l->val);
	printf("\n");
}

void
freelist(List *l)
{
	List *p;

	for (p = l; p;) {
		p = l->next;
		free(l);
		l = p;
	}
}

List *
middle(List *l)
{
	List *p;

	p = l;
	while (l && l->next) {
		p = p->next;
		l = l->next->next;
	}
	return p;
}

void
test(size_t n, ...)
{
	List *l, *m;
	va_list ap;

	va_start(ap, n);
	l = vmklist(n, ap);
	va_end(ap);
	m = middle(l);
	if (m)
		printf("%d\n", m->val);
	else
		printf("%p\n", (void*)m);
	freelist(l);
}

int
main(void)
{
	test(5, 1, 2, 3, 4, 5);
	test(6, 1, 2, 3, 4, 5, 6);
	test(1, 1);
	test(2, 35, 60);
	test(3, 103, 21, 221);
	test(4, 25, 356, 23, 20);
	return 0;
}
