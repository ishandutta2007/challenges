// Implement a simple version of the define processor (i.e., no arguments)
// suitable for use with C programs, based on the routines of this section.
// You may also find getch and ungetch helpful.

#define _GNU_SOURCE
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

struct nlist {
	char *name;
	char *defn;
	struct nlist *next;
};

#define HASHSIZE 101
#define MAXWORD 100

static int peekbuf[BUFSIZ];
static int peekpos;
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
getch(void)
{
	return (peekpos > 0) ? peekbuf[--peekpos] : getchar();
}

void
ungetch(int c)
{
	if (peekpos >= BUFSIZ)
		fprintf(stderr, "ungetch: too many characters\n");
	else
		peekbuf[peekpos++] = c;
}

void
ungets(const char *s)
{
	size_t i, n;

	n = strlen(s);
	if (n == 0)
		return;
	for (i = n - 1;; i--) {
		ungetch(s[i]);
		if (i == 0)
			break;
	}
}

int
comment(void)
{
	int c;

	while ((c = getch()) != EOF) {
		if (c == '*') {
			if ((c = getch()) == '/')
				break;
			else
				ungetch(c);
		}
	}
	return c;
}

int
getword(char *word, size_t lim)
{
	char *w;
	int c, d;

	if (lim < 2)
		return EOF;

	w = word;
	for (;;) {
		c = getch();
		if (c == '\n') {
			*w++ = '\n';
			*w = '\0';
			return '\n';
		}
		if (!isspace(c))
			break;
	}

	if (c != EOF)
		*w++ = c;

	if (isalpha(c) || c == '_') {
		for (; --lim > 1; w++) {
			*w = getch();
			if (!isalnum(*w) && *w != '_') {
				ungetch(*w);
				break;
			}
		}
	} else if (c == '\'' || c == '*') {
		for (; --lim > 1; w++) {
			*w = getch();
			if (*w == '\\')
				*++w = getch();
			else if (*w == c) {
				w++;
				break;
			} else if (*w == EOF)
				break;
		}
	} else if (c == '/') {
		d = getch();
		if (d == '*')
			c = comment();
		else
			ungetch(d);
	}
	*w = '\0';
	return c;
}

void
skipblanks(void)
{
	int c;

	while (isspace(c = getch()))
		;
	ungetch(c);
}

void
error(int c, const char *s)
{
	printf("error: %s\n", s);
	while (c != EOF && c != '\n')
		c = getch();
}

void
getdef(void)
{
	char def[MAXWORD], dir[MAXWORD], name[MAXWORD];
	int i;

	skipblanks();
	if (!isalpha(getword(dir, MAXWORD)))
		error(dir[0], "getdef: expecting a directive after #");
	else if (!strcmp(dir, "define")) {
		skipblanks();
		if (!isalpha(getword(name, MAXWORD)))
			error(name[0], "getdef: non-alpha - name expected");
		else {
			skipblanks();
			for (i = 0; i < MAXWORD - 1; i++) {
				if ((def[i] = getch()) == EOF || def[i] == '\n')
					break;
			}
			def[i] = '\0';
			if (i <= 0)
				error('\n', "getdef: incomplete define");
			else
				install(name, def);
		}
	} else if (!strcmp(dir, "undef")) {
		skipblanks();
		if (!isalpha(getword(name, MAXWORD)))
			error(name[0], "getdef: non-alpha in undef");
		else
			undef(name);
	} else
		error(dir[0], "getdef: expecting a directive after #");
}

int
main(void)
{
	struct nlist *p;
	char w[MAXWORD];

	while (getword(w, MAXWORD) != EOF) {
		if (!strcmp(w, "#"))
			getdef();
		else if (!isalpha(w[0]))
			printf("%s", w);
		else if (!(p = lookup(w)))
			printf("%s", w);
		else
			ungets(p->defn);
	}
	return 0;
}
