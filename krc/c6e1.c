// Our version of getword does not properly handle underscores, string constants,
// comments, or preprocessor control lines. Write a better version.

#include <stdio.h>
#include <ctype.h>

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

	if (lim == 0)
		return EOF;

	for (;;) {
		c = fgetc(fp);
		if (!isspace(c))
			break;
	}

	w = word;
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

int
main(void)
{
	char word[80];
	while (getword(stdin, word, sizeof(word)) != EOF)
		printf("word: %s\n", word);
	return 0;
}
