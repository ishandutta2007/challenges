// Write a program that prints the distinct words in its input sorted into 
// decreasing order of frequency of occurrence. 
// Precede each word by its count.

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

struct tnode {
	char *word;
	int count;
	struct tnode *left;
	struct tnode *right;
};

enum {
	MAXWORD = 256,
	NDISTINCT = 1024,
};

struct tnode *list[NDISTINCT];
int ntn;

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

struct tnode *
addtree(struct tnode *p, const char *word)
{
	int cond;

	if (p == NULL) {
		p = xcalloc(1, sizeof(*p));
		p->word = xstrdup(word);
		p->count = 1;
	} else if ((cond = strcmp(word, p->word)) == 0)
		p->count++;
	else if (cond < 0)
		p->left = addtree(p->left, word);
	else
		p->right = addtree(p->right, word);

	return p;
}

void
sortlist(void)
{
	struct tnode *temp;
	int gap, i, j;

	for (gap = ntn / 2; gap > 0; gap /= 2) {
		for (i = gap; i < ntn; i++) {
			for (j = i - gap; j >= 0; j -= gap) {
				if (list[j]->count >= list[j + gap]->count)
					break;
				temp = list[j];
				list[j] = list[j + gap];
				list[j + gap] = temp;
			}
		}
	}
}

void
treestore(struct tnode *p)
{
	if (p) {
		treestore(p->left);
		if (ntn < NDISTINCT)
			list[ntn++] = p;
		treestore(p->right);
	}
}

int
main(void)
{
	struct tnode *root;
	char word[MAXWORD];
	int i;

	root = NULL;
	while (getword(stdin, word, MAXWORD) != EOF) {
		if (isalpha(word[0]))
			root = addtree(root, word);
	}
	treestore(root);
	sortlist();
	for (i = 0; i < ntn; i++)
		printf("%2d:%20s\n", list[i]->count, list[i]->word);

	return 0;
}
