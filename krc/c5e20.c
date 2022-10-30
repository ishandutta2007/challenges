// Expand dcl to handle declarations with function argument types,
// qualifiers like const, and so on.

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdarg.h>
#include <ctype.h>

#define nelem(x) (sizeof(x) / sizeof(x[0]))

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

int
typespec(void)
{
	static const char *types[] = {
	    "char",
	    "int",
	    "void",
	};
	size_t i;

	for (i = 0; i < nelem(types); i++) {
		if (!strcmp(types[i], token))
			return 1;
	}
	return 0;
}

int
typequal(void)
{
	static const char *typeq[] = {
	    "const",
	    "volatile",
	};
	size_t i;

	for (i = 0; i < nelem(typeq); i++) {
		if (!strcmp(typeq[i], token))
			return 1;
	}
	return 0;
}

void
dclspec(void)
{
	char tmp[MAXTOKEN];

	tmp[0] = '\0';
	gettoken();
	do {
		if (tokentype != NAME) {
			prevtoken = 1;
			dcl();
		} else if (typespec()) {
			outlen += snprint(out + outlen, sizeof(out) - outlen, " %s", token);
			gettoken();
		} else if (typequal()) {
			outlen += snprint(out + outlen, sizeof(out) - outlen, " %s", token);
			gettoken();
		} else
			errmsg("unknown type in parameter list");
	} while (tokentype != ',' && tokentype != ')');
	outlen += snprint(out + outlen, sizeof(out) - outlen, " %s", tmp);
	if (tokentype == ',')
		outlen += snprint(out + outlen, sizeof(out) - outlen, ",");
}

void
parmdcl(void)
{
	do {
		dclspec();
	} while (tokentype == ',');
	if (tokentype != ')')
		errmsg("missing ) in parameter declaration");
}

void
dirdcl(void)
{
	int type;

	if (tokentype == '(') {
		dcl();
		if (tokentype != ')')
			errmsg("error: missing )");
	} else if (tokentype == NAME) {
		if (name[0] == '\0')
			strcpy(name, token);
	} else
		prevtoken = 1;

	while ((type = gettoken()) == PARENS || type == BRACKETS || type == '(') {
		if (type == PARENS)
			outlen += snprint(out + outlen, sizeof(out) - outlen, " function returning");
		else if (type == '(') {
			outlen += snprint(out + outlen, sizeof(out) - outlen, " function expecting");
			parmdcl();
			outlen += snprint(out + outlen, sizeof(out) - outlen, " and returning");
		} else
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

// void *(*comp)(int *, char *, int (*fnc)())
// comp:  pointer to function expecting int pointer to , char pointer to ,
// int pointer to function returning  and returning pointer to void

int
main(void)
{
	while (gettoken() != EOF) {
		strcpy(datatype, token);
		out[0] = '\0';
		outlen = 0;
		dcl();
		if (tokentype != '\n')
			errmsg("syntax error");
		else
			printf("%s: %s %s\n", name, out, datatype);
	}
	return 0;
}
