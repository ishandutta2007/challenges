/*

Requirements:

Take an input on stdin including new lines / carriage returns of unlimited length (only bounded by system memory; that is, there is no inherent limit in the program.)
Output the reverse of the input on stdout.

Example:

Input:

Quick brown fox
He jumped over the lazy dog
Output:

god yzal eht revo depmuj eH
xof nworb kciuQ

*/

#include <stdio.h>
#include <stdlib.h>

typedef struct Line Line;

struct Line {
	Line *next;
	size_t len;
	size_t cap;
	char buf[];
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

void *
xrealloc(void *ptr, size_t size)
{
	void *p;

	p = realloc(ptr, size);
	if (!p)
		abort();
	return p;
}

Line *
newline(void)
{
	Line *l;
	size_t n;

	n = 8192;
	l = xcalloc(1, sizeof(*l) + n);
	l->cap = n;
	return l;
}

Line *
append(Line *l, int ch)
{
	if (l->len >= l->cap) {
		l->cap *= 2;
		l = xrealloc(l, sizeof(*l) + l->cap);
	}
	l->buf[l->len++] = ch;

	return l;
}

void
print(void *u)
{
	Line *l;
	size_t i;

	l = u;
	for (i = l->len; i > 0; i--)
		printf("%c", l->buf[i - 1]);
	printf("\n");
}

void
iterate(Line *l, void (*f)(void *))
{
	Line *p;

	for (; l; l = p) {
		p = l->next;
		f(l);
	}
}

void
reverse(FILE *in)
{
	Line *l, *p;
	int c;

	l = newline();
	while ((c = fgetc(in)) != EOF) {
		if (c == '\n') {
			p = newline();
			p->next = l;
			l = p;
		} else
			l = append(l, c);
	}

	iterate(l, print);
	iterate(l, free);
}

int
main(void)
{
	reverse(stdin);

	return 0;
}
