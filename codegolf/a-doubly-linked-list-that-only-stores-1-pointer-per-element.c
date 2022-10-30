/*

A favorite puzzle of mine. Not massively difficult but a tad interesting.

The Objective

Using a low level language (C/C++/similar level) - create a doubly linked list of elements that only stores a single pointer instead of storing both a previous and next element pointer as you normally would.

You must be able to find each element in your linked list, starting from either the first element you created, or the most recently created element.

You must use malloc(sizeof(*node)) or similar to store each element (the addresses are likely to be non-sequential as a result)

The Restrictions

    The data type you use to store your value must be the length of a function pointer (No using long values to store 2 pointer addresses one after another)
    You may not use any external libraries (only the standard libc methods are permitted if you're using C/C++, apply the spirit of this rule to other languages)
    You may not store any additional metadata elsewhere (or in the list elements themselves) to solve this. The list element may only contain two fields - the 'data' value and the value you will use to find the previous and next elements. It may look something like:


    struct node
    {
       int myValue;
       struct node* prevAndNextNode;
    }

Golf or Challenge?

You can either find the most elegant/interesting solution, or the shortest. Take your pick!

Have fun ;)

*/

#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

// https://en.wikipedia.org/wiki/XOR_linked_list
typedef struct Xlist Xlist;

struct Xlist {
	int value;
	uintptr_t link;
};

Xlist *
insert(Xlist *l, int v)
{
	Xlist *x;

	x = calloc(1, sizeof(*x));
	if (!x)
		return NULL;

	x->value = v;
	if (l) {
		l->link ^= (uintptr_t)x;
		x->link ^= (uintptr_t)l;
	}
	return x;
}

void
iterate(Xlist *l, void (*f)(Xlist *, void *), void *ud)
{
	uintptr_t p, q;

	p = q = 0;
	if (l)
		q = l->link;

	while (l) {
		f(l, ud);
		p ^= q;
		q = (uintptr_t)l;
		l = (Xlist *)p;
		if (l)
			p = l->link;
	}
}

void
destroy(Xlist *l, void *ud)
{
	free(l);
	(void)ud;
}

void
print(Xlist *l, void *ud)
{
	printf("%d\n", l->value);
	(void)ud;
}

int
main(void)
{
	Xlist *h, *l;
	int i;

	h = l = NULL;
	for (i = 0; i <= 10; i++) {
		l = insert(l, i * 2);
		if (h == NULL)
			h = l;
	}
	iterate(h, print, NULL);
	iterate(h, destroy, NULL);

	return 0;
}
