// common doubly linked list operations
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct List List;
typedef struct Node Node;

struct List {
	Node *head;
	Node *tail;
};

struct Node {
	int data;
	Node *prev;
	Node *next;
};

void *
xcalloc(size_t nmemb, size_t size)
{
	void *p;

	if (nmemb == 0)
		nmemb = 1;
	if (size == 0)
		size = 1;
	p = calloc(nmemb, size);
	if (p == NULL)
		abort();
	return p;
}

List *
newlist(void)
{
	List *l;

	l = xcalloc(1, sizeof(*l));
	if (l == NULL)
		return NULL;
	return l;
}

void
freelist(List *l)
{
	Node *n;

	if (l == NULL)
		return;

	for (n = l->head; n != NULL; n = n->next)
		free(n);
	free(l);
}

Node *
search(List *l, int v)
{
	Node *n;

	for (n = l->head; n != NULL; n = n->next) {
		if (n->data == v)
			break;
	}
	return n;
}

Node *
push(List *l, int v)
{
	Node *n;

	n = xcalloc(1, sizeof(*n));
	if (n == NULL)
		return NULL;
	n->data = v;
	n->prev = l->tail;
	if (l->tail != NULL)
		l->tail->next = n;
	l->tail = n;
	if (l->head == NULL)
		l->head = n;
	return n;
}

int
pop(List *l)
{
	int d;
	Node *n;

	if (l->tail == NULL)
		return -1;
	d = l->tail->data;
	if (l->tail == l->head)
		l->head = NULL;
	n = l->tail->prev;
	if (n != NULL)
		n->next = NULL;
	free(l->tail);
	l->tail = n;
	return d;
}

void
print(List *l)
{
	Node *n;

	if (l->head == NULL) {
		printf("(nil)\n");
		return;
	}
	for (n = l->head; n != NULL; n = n->next)
		printf("%d ", n->data);
	printf("\n");
}

void
reverse(List *l)
{
	Node *n, *nl;

	n = l->tail;
	l->tail = l->head;
	l->head = n;
	while (n != NULL) {
		nl = n->prev;
		n->prev = n->next;
		n->next = nl;
		n = nl;
	}
}

int
main(void)
{
	List *l;
	int i;

	l = newlist();
	printf("pushing\n");
	for (i = 0; i <= 32; i++) {
		push(l, i);
		print(l);
	}
	printf("\nreversing\n");
	for (i = 0; i < 10; i++) {
		print(l);
		reverse(l);
	}
	printf("\npopping\n");
	for (i = 0; i <= 32; i++) {
		print(l);
		pop(l);
	}
	print(l);
	return 0;
}
