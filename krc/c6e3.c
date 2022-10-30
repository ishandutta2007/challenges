// Write a cross-referencer that prints a list of all words in a document and for
// each word, a list of the line numbers on which it occurs. Remove noise words
// like "the", "and", and so on.

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define nelem(x) (sizeof(x) / sizeof(x[0]))

typedef struct List List;
typedef struct Node Node;

struct List {
	unsigned long num;
	List *next;
};

struct Node {
	char *word;
	List *lines;
	Node *left;
	Node *right;
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
	if (!p)
		abort();
	return p;
}

char *
xstrdup(const char *s)
{
	return strcpy(xcalloc(1, strlen(s) + 1), s);
}

int
comment(FILE *fp)
{
	int c;

	while ((c = fgetc(fp)) != EOF) {
		if (c == '*') {
			if ((c = fgetc(fp)) == '/')
				break;
			else
				ungetc(c, fp);
		}
	}
	return c;
}

int
getword(FILE *fp, char *word, size_t lim)
{
	char *w;
	int c, d;

	if (lim < 2)
		return EOF;

	w = word;
	for (;;) {
		c = fgetc(fp);
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

	if (isalpha(c) || c == '_' || c == '#') {
		for (; --lim > 1; w++) {
			*w = fgetc(fp);
			if (!isalnum(*w) && *w != '_') {
				ungetc(*w, fp);
				break;
			}
		}
	} else if (c == '\'' || c == '*') {
		for (; --lim > 1; w++) {
			*w = fgetc(fp);
			if (*w == '\\')
				*++w = fgetc(fp);
			else if (*w == c) {
				w++;
				break;
			} else if (*w == EOF)
				break;
		}
	} else if (c == '/') {
		d = fgetc(fp);
		if (d == '*')
			c = comment(fp);
		else
			ungetc(d, fp);
	}
	*w = '\0';
	return c;
}

void
addln(Node *p, unsigned long linenum)
{
	List *l;

	l = p->lines;
	while (l->next && l->num != linenum)
		l = l->next;
	if (l->num != linenum) {
		l->next = xcalloc(1, sizeof(*l->next));
		l->next->num = linenum;
	}
}

Node *
addtreex(Node *p, const char *word, unsigned long linenum)
{
	int cond;
	if (p == NULL) {
		p = xcalloc(1, sizeof(*p));
		p->word = xstrdup(word);
		p->lines = xcalloc(1, sizeof(*p->lines));
		p->lines->num = linenum;
	} else if ((cond = strcmp(word, p->word)) == 0)
		addln(p, linenum);
	else if (cond < 0)
		p->left = addtreex(p->left, word, linenum);
	else
		p->right = addtreex(p->right, word, linenum);

	return p;
}

void
treexprint(Node *p)
{
	List *l;

	if (!p)
		return;
	treexprint(p->left);
	printf("%-32s: ", p->word);
	for (l = p->lines; l; l = l->next)
		printf("%4lu ", l->num);
	printf("\n");
	treexprint(p->right);
}

void
treexfree(Node *p)
{
	List *l, *ln;

	if (!p)
		return;
	treexfree(p->left);
	treexfree(p->right);
	free(p->word);
	for (l = p->lines; l; l = ln) {
		ln = l->next;
		free(l);
	}
	free(p);
}

int
noiseword(const char *word)
{
	static const char *tab[] = {
	    "a",
	    "an",
	    "and",
	    "are",
	    "in",
	    "is",
	    "of",
	    "or",
	    "that",
	    "the",
	    "this",
	    "to",
	};
	int cond, lo, mid, hi;

	lo = 0;
	hi = nelem(tab) - 1;
	while (lo <= hi) {
		mid = (lo + hi) / 2;
		if ((cond = strcmp(word, tab[mid])) < 0)
			hi = mid - 1;
		else if (cond > 0)
			lo = mid + 1;
		else
			return mid;
	}
	return -1;
}

int
main(void)
{
	unsigned long linenum;
	char word[BUFSIZ];
	Node *root;

	root = NULL;
	linenum = 1;
	while (getword(stdin, word, sizeof(word)) != EOF) {
		if (isalpha(word[0]) && noiseword(word) == -1)
			root = addtreex(root, word, linenum);
		else if (word[0] == '\n')
			linenum++;
	}
	treexprint(root);
	treexfree(root);
	return 0;
}
