// Write a function undef that will remove a name and definition
// from the table maintained by lookup and install.

#define _GNU_SOURCE
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct nlist {
	char *name;
	char *defn;
	struct nlist *next;
};

#define HASHSIZE 101

static struct nlist *hashtab[HASHSIZE];

unsigned
hash(const char *s)
{
	unsigned v;

	for (v = 0; *s; s++)
		v = *s + 31 * v;
	return v % HASHSIZE;
}

struct nlist *
lookup(const char *s)
{
	struct nlist *np;

	np = hashtab[hash(s)];
	while (np != NULL) {
		if (!strcmp(s, np->name))
			return np;
		np = np->next;
	}
	return NULL;
}

struct nlist *
install(const char *name, const char *defn)
{
	struct nlist *np;
	unsigned hv;

	np = lookup(name);
	if (!np) {
		np = calloc(1, sizeof(*np));
		if (np == NULL)
			return NULL;

		np->name = strdup(name);
		if (!np->name) {
			free(np);
			return NULL;
		}
		hv = hash(name);
		np->next = hashtab[hv];
		hashtab[hv] = np;
	}

	free(np->defn);
	np->defn = strdup(defn);
	if (!np->defn)
		return NULL;

	return np;
}

void
undef(const char *s)
{
	struct nlist *prev, *np;
	int h;

	prev = NULL;
	h = hash(s);
	for (np = hashtab[h]; np; np = np->next) {
		if (!strcmp(s, np->name))
			break;
		prev = np;
	}
	if (np != NULL) {
		if (prev == NULL)
			hashtab[h] = np->next;
		else
			prev->next = np->next;
		free(np->name);
		free(np->defn);
		free(np);
	}
}

int
main(void)
{
	const char key[] = "boot";
	const char val[] = "zeko";
	int i;

	for (i = 0; i < 8; i++) {
		printf("install %p\n", (void *)install(key, val));
		printf("lookup %p\n", (void *)lookup(key));
		undef(key);
		printf("lookup after undef %p\n", (void *)lookup(key));
	}
	return 0;
}
