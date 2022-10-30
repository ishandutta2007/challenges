/*

Consider the translation from letters to numbers a -> 1 through z -> 26.
Every sequence of letters can be translated into a string of numbers this way, with the numbers being mushed together.
For instance hello -> 85121215. Unfortunately the reverse translation is not unique. 85121215 could map to hello, but also to heaubo.
Write a program that, given a string of digits, outputs every possible translation back to letters.

Sample input:

123

Sample output:

abc

aw

lc

Thanks to ashashwat for posting this idea in r/dailyprogrammer_ideas!

*/

#include <stdio.h>

typedef struct Sym Sym;

struct Sym {
	int ch;
	int len;
	Sym *next;
};

void
print(Sym *s)
{
	if (!s)
		return;

	for (; s; s = s->next)
		printf("%c", s->ch);
	printf("\n");
}

size_t
syms(const char *b, Sym *s)
{
	if (!b[0])
		return 0;

	s->ch = b[0];
	s->len = 1;
	s->next = NULL;
	if ('1' <= b[0] && b[0] <= '9')
		s->ch = 'a' + (b[0] - '1');

	if (!('1' <= b[0] && b[0] <= '2' && '1' <= b[1] && b[1] <= '6'))
		return 1;

	s++;
	s->ch = 'a' + (10 * (b[0] - '0')) + (b[1] - '0') - 1;
	s->len = 2;
	s->next = NULL;
	return 2;
}

void
gen(const char *b, Sym *h, Sym *s)
{
	Sym v[2], *p;
	size_t i, n;

	n = syms(b, v);
	if (n == 0) {
		print(h);
		return;
	}

	for (i = 0; i < n; i++) {
		p = v + i;
		if (s)
			s->next = p;

		gen(b + p->len, (h) ? h : p, p);
	}
}

void
decodings(const char *b)
{
	gen(b, NULL, NULL);
	printf("\n");
}

int
main(void)
{
	decodings("123");
	decodings("85121215");
	decodings("Xaw26");

	return 0;
}
