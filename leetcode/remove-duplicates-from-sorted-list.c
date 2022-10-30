/*

Given a sorted linked list, delete all duplicates such that each element appear only once.

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
dedup(List *l)
{
	List *p, *q;

	for (p = l; p; p = p->next) {
		while (p->next && p->val == p->next->val) {
			q = p->next;
			p->next = q->next;
			free(q);
		}
	}
	return l;
}

void
test(size_t n, ...)
{
	List *l;
	va_list ap;

	va_start(ap, n);
	l = vmklist(n, ap);
	va_end(ap);
	print(l);
	l = dedup(l);
	print(l);
	freelist(l);
}

int
main(void)
{
	test(3, 1, 1, 2);
	test(8, 1, 1, 2, 3, 3, 3, 3, 3);
	return 0;
}
