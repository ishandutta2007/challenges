// Modify undcl so that it does not add redundant parentheses to declarations.

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdarg.h>
#include <ctype.h>

#define MAXTOKEN 100

enum {
	NAME,
	PARENS,
	BRACKETS,
};

int prevtoken;
int tokentype;
char token[MAXTOKEN];
char name[MAXTOKEN];
char datatype[MAXTOKEN];

char out[BUFSIZ];
size_t outlen;

void dcl(void);

void
errmsg(const char *fmt, ...)
{
	va_list ap;

	va_start(ap, fmt);
	vfprintf(stderr, fmt, ap);
	va_end(ap);
	fprintf(stderr, "\n");
	prevtoken = 1;
}

int
snprint(char *buf, size_t size, const char *fmt, ...)
{
	va_list ap;
	size_t n;

	va_start(ap, fmt);
	n = vsnprintf(buf, size, fmt, ap);
	va_end(ap);
	return (n < size) ? n : size;
}

int
gettoken(void)
{
	size_t i;
	int c;

	if (prevtoken) {
		prevtoken = 0;
		return tokentype;
	}

	while ((c = fgetc(stdin)) == ' ' || c == '\t')
		;
	if (c == '(') {
		if ((c = fgetc(stdin)) == ')') {
			strcpy(token, "()");
			tokentype = PARENS;
		} else {
			ungetc(c, stdin);
			tokentype = '(';
		}
	} else if (c == '[') {
		i = 0;
		do {
			token[i++] = c;
			if (c == ']')
				break;
			c = fgetc(stdin);
		} while (i + 1 < sizeof(token));
		token[i] = '\0';
		tokentype = BRACKETS;
	} else if (isalpha(c)) {
		i = 0;
		do {
			token[i++] = c;
			c = fgetc(stdin);
			if (!isalnum(c))
				break;
		} while (i + 1 < sizeof(token));
		ungetc(c, stdin);
		token[i] = '\0';
		tokentype = NAME;
	} else
		tokentype = c;

	return tokentype;
}

int
nexttoken(void)
{
	int type;

	type = gettoken();
	prevtoken = 1;
	return type;
}

void
dirdcl(void)
{
	int type;

	if (tokentype == '(') {
		dcl();
		if (tokentype != ')')
			errmsg("error: missing )");
	} else if (tokentype == NAME)
		strcpy(name, token);
	else
		errmsg("error: expected name or (dcl)");

	while ((type = gettoken()) == PARENS || type == BRACKETS) {
		if (type == PARENS)
			outlen += snprint(out + outlen, sizeof(out) - outlen, " function returning");
		else
			outlen += snprint(out + outlen, sizeof(out) - outlen, " array %s of", token);
	}
}

void
dcl(void)
{
	int ns;

	for (ns = 0; gettoken() == '*'; ns++)
		;
	dirdcl();
	while (ns-- > 0)
		outlen += snprint(out + outlen, sizeof(out) - outlen, " pointer to");
}

// x * char          -> char *x
// daytab * [13] int -> int (*daytab)[13]
void
undcl(void)
{
	char tmp[2 * BUFSIZ];
	int type;

	while (gettoken() != EOF) {
		strcpy(out, token);
		while ((type = gettoken()) != '\n') {
			if (type == PARENS || type == BRACKETS)
				outlen += snprint(out + outlen, sizeof(out) - outlen, "%s", token);
			else if (type == '*') {
				if ((type == nexttoken()) == PARENS || type == BRACKETS)
					snprint(tmp, sizeof(tmp), "(*%s)", out);
				else
					snprint(tmp, sizeof(tmp), "*%s", out);
				outlen = snprint(out, sizeof(out), "%s", tmp);
			} else if (type == NAME) {
				snprint(tmp, sizeof(tmp), "%s %s", token, out);
				outlen = snprint(out, sizeof(out), "%s", tmp);
			} else
				printf("invalid input at %s\n", token);
		}
		printf("%s\n", out);
	}
}

int
main(void)
{
	undcl();
	return 0;
}
