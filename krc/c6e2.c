// Write a program that reads a C program and prints in alphabetical order each
// group of variable names that are identical in the first 6 characters, but different
// somewhere after. Make 6 a parameter that can be set from the command line.
#define _GNU_SOURCE
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>
#include <ctype.h>

enum {
	MAXWORD = 1024,
};

typedef struct Node Node;

struct Node {
	char *word;
	bool match;
	Node *left;
	Node *right;
};

Node *
talloc(void)
{
	Node *n;

	n = calloc(1, sizeof(*n));
	if (!n)
		abort();
	return n;
}

char *
xstrdup(const char *s)
{
	char *p;

	p = strdup(s);
	if (!p)
		abort();
	return p;
}

int
compare(const char *s, Node *n, size_t num, bool *found)
{
	const char *t;
	size_t i;

	t = n->word;
	for (i = 0; s[i] == t[i]; i++) {
		if (s[i] == '\0')
			return 0;
	}

	if (i >= num) {
		n->match = true;
		*found = true;
	}

	return s[i] - t[i];
}

Node *
addtreex(Node *n, const char *word, int num, bool *found)
{
	int r;
	if (n == NULL) {
		n = talloc();
		n->word = xstrdup(word);
		n->match = *found;
	} else if ((r = compare(word, n, num, found)) < 0)
		n->left = addtreex(n->left, word, num, found);
	else if (r > 0)
		n->right = addtreex(n->right, word, num, found);
	return n;
}

void
treexprint(Node *n)
{
	if (n == NULL)
		return;
	treexprint(n->left);
	if (n->match)
		printf("%s\n", n->word);
	treexprint(n->right);
}

void
treexfree(Node *n)
{
	if (n == NULL)
		return;
	treexfree(n->left);
	treexfree(n->right);
	free(n->word);
	free(n);
}

int
getword(FILE *fp, char *s, size_t n)
{
	size_t i;
	int rv;

	if (n == 0)
		return EOF;

	rv = 0;
	for (i = 0; i < n; i++) {
		s[i] = fgetc(fp) & 0xff;
		if (s[i] == EOF) {
			rv = EOF;
			break;
		}
		if (isspace(s[i]))
			break;
	}
	s[i] = '\0';

	return rv;
}

int
main(int argc, char *argv[])
{
	Node *root;
	char word[MAXWORD];
	bool found;
	int num;

	num = 6;
	if (argc >= 2)
		num = atoi(argv[1]);
	if (num <= 0)
		num = 6;

	root = NULL;
	found = false;
	while (getword(stdin, word, MAXWORD) != EOF) {
		if (isalpha(word[0]) && strlen(word) >= (size_t)num)
			root = addtreex(root, word, num, &found);
		found = false;
	}

	treexprint(root);
	treexfree(root);

	return 0;
}
