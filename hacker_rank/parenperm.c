// insert parentheses inside an expression and calculate the expression
// find all the different combination of result you can make doing it
// solution cheats by not inserting parens but changing the operator
// precedences as it iterates through and evaluating it, then inserting
// the unique solutions into the list
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>
#include <errno.h>
#include <ctype.h>
#include <limits.h>

typedef struct Token Token;

struct Token {
	int op;
	long value;
};

long binadd(long, long, bool *);
long binsub(long, long, bool *);

void *
ecalloc(size_t nmemb, size_t size)
{
	void *p;

	p = calloc(nmemb, size);
	if (p == NULL) {
		perror("calloc");
		exit(1);
	}
	return p;
}

void *
erealloc(void *ptr, size_t size)
{
	void *p;

	p = realloc(ptr, size);
	if (p == NULL) {
		perror("realloc");
		exit(1);
	}
	return p;
}

char *
strjoin(char *const *s, size_t n)
{
	char *p;
	size_t i, l;

	l = 1;
	for (i = 0; i < n; i++)
		l += strlen(s[i]) + 1;

	p = ecalloc(l, sizeof(*p));
	for (i = 0; i < n; i++) {
		strcat(p, s[i]);
		if (i < n - 1)
			strcat(p, " ");
	}

	return p;
}

long
xatol(const char *nptr, bool *err)
{
	char *endptr;
	long v;

	*err = false;
	errno = 0;
	v = strtol(nptr, &endptr, 10);
	if ((errno == ERANGE && (v == LONG_MAX || v == LONG_MIN)) || (errno != 0 && v == 0)) {
		perror("strtol");
		*err = true;
	} else if (endptr == nptr) {
		fprintf(stderr, "strtol: no digit were found '%s'\n", nptr);
		*err = true;
	} else if (*endptr != '\0') {
		fprintf(stderr, "strtol: further characters after number: '%s'\n", nptr);
		*err = true;
	}

	return v;
}

Token *
tokenize(const char *expr, size_t *len)
{
	Token *t;
	const char *p;
	char *d;
	size_t n, l;
	bool err;

	*len = 0;
	if (expr == NULL)
		return NULL;

	n = l = 0;
	for (p = expr; *p != '\0'; p++) {
		n = (isdigit(*p)) ? n + 1 : 0;
		l++;
	}

	t = ecalloc(l + 1, sizeof(*t));
	d = ecalloc(n + 1, sizeof(*d));

	n = l = 0;
	for (p = expr; *p != '\0'; p++) {
		if (isdigit(*p)) {
			d[n++] = *p;
			d[n] = '\0';
			continue;
		}

		switch (*p) {
		case '+':
		case '-':
		case '*':
		case ' ':
		case '\t':
		case '\r':
		case '\b':
		case '\n':
			if (n != 0) {
				t[l++].value = xatol(d, &err);
				if (err)
					goto error;

				n = 0;
			}

			if (!isspace(*p))
				t[l++].op = *p;

			break;

		default:
			fprintf(stderr, "tokenize: unknown token: ");
			if (isprint(*p))
				fprintf(stderr, "'%c'\n", *p);
			else
				fprintf(stderr, "character code 0x%x\n", *p);

			goto error;
		}
	}
	if (n != 0) {
		t[l++].value = xatol(d, &err);
		if (err)
			goto error;
	}

	t[l].op = -1;
	*len = l;

out:
	free(d);
	return t;

error:
	fprintf(stderr, "tokenize: failed to tokenize string \"%s\"\n", expr);
	free(t);
	t = NULL;
	goto out;
}

void
appendsolution(long **solution, size_t *len, size_t *cap, long v)
{
	long *s;
	size_t i, l, c;

	s = *solution;
	l = *len;
	c = *cap;

	if (s == NULL) {
		l = 0;
		c = 256;
		s = ecalloc(c, sizeof(*s));
	}

	for (i = 0; i < l; i++) {
		if (s[i] == v)
			return;
	}

	if (l >= c) {
		c *= 2;
		s = erealloc(s, c);
	}
	s[l++] = v;

	*solution = s;
	*len = l;
	*cap = c;
}

void
printsolution(const char *expr, long *solution, size_t len)
{
	size_t i;
	int s;

	printf("expression \"%s\"\n", expr);
	s = printf("%zu unique {", len);
	if (s < 1)
		s = 8;

	for (i = 0; i < len; i++) {
		printf(" %ld", solution[i]);
		if (i < len - 1)
			printf(",");

		if ((i & 31) == 31)
			printf("\n%*s", s, " ");
	}

	printf(" }\n\n");
}

long
binadd(long a, long b, bool *overflow)
{
	if (b < 0)
		return binsub(a, -b, overflow);

	if (LONG_MAX - b < a) {
		*overflow = true;
		return LONG_MAX;
	}

	return a + b;
}

long
binsub(long a, long b, bool *overflow)
{
	if (b < 0)
		return binadd(a, -b, overflow);

	if (LONG_MIN + b > a) {
		*overflow = true;
		return LONG_MIN;
	}

	return a - b;
}

long
binmul(long a, long b, bool *overflow)
{
	int sign;

	if (a == 0 || b == 0)
		return 0;

	sign = 1;
	if (a < 0) {
		a = -a;
		sign = -sign;
	}
	if (b < 0) {
		b = -b;
		sign = -sign;
	}

	if (LONG_MAX / b < a) {
		*overflow = true;
		return (sign > 0) ? LONG_MAX : LONG_MIN;
	}

	return sign * a * b;
}

long
binop(int op, long a, long b, bool *overflow)
{
	switch (op) {
	case '+':
		return binadd(a, b, overflow);

	case '-':
		return binsub(a, b, overflow);

	case '*':
		return binmul(a, b, overflow);
	}

	return -1;
}

long
eval(const Token *expr, const size_t *prec, long *operand, long *operator, bool * invalid, bool *overflow)
{
	const Token *p;
	long op;
	size_t i, j, k, opprec;

	*invalid = false;
	*overflow = false;
	if (expr == NULL)
		return 0;

	operand[0] = 0;
	i = j = k = 0;
	for (p = expr; p->op != -1; p++) {
		switch (p->op) {
		case '+':
		case '-':
		case '*':
			while (j > 0) {
				opprec = operator[j - 1]>> 8;
				op = operator[j - 1] & 0xff;
				if (opprec < prec[k])
					break;

				if (i < 2)
					goto error;

				operand[i - 2] = binop(op, operand[i - 2], operand[i - 1], overflow);
				i--;
				j--;
			}

			operator[j++] = p->op | prec[k++] << 8;
			break;

		default:
			operand[i++] = p->value;
			break;
		}
	}

	for (; j > 0; j--, i--) {
		if (i < 2)
			goto error;

		op = operator[j - 1] & 0xff;
		operand[i - 2] = binop(op, operand[i - 2], operand[i - 1], overflow);
	}

	if (i != 1)
		goto error;

	return operand[0];

error:
	*invalid = true;
	return -1;
}

void
parenperm(const char *expression)
{
	Token *expr;
	long *operator, * operand, *solution;
	size_t *prec, numsolution, maxsolution, numop, len;

	size_t i;
	long value;
	bool invalid, overflow;

	numsolution = maxsolution = 0;
	prec = NULL;
	solution = operand = operator= NULL;

	expr = tokenize(expression, &len);
	if (expr == NULL)
		goto error;

	numop = 0;
	for (i = 0; expr[i].op != -1; i++) {
		switch (expr[i].op) {
		case '+':
		case '-':
		case '*':
			numop++;
			break;
		}
	}

	prec = ecalloc(numop + 1, sizeof(*operator));
	operator= ecalloc(numop + 1, sizeof(*operator));
	operand = ecalloc(len - numop, sizeof(*operand));

	for (;;) {
		value = eval(expr, prec, operand, operator, & invalid, &overflow);
		if (invalid)
			goto error;

		if (!overflow) {
			appendsolution(&solution, &numsolution, &maxsolution, value);
		}

		for (i = 0; i < numop; i++) {
			if (++prec[i] >= numop)
				prec[i] = 0;
			else
				break;
		}

		for (i = 0; i < numop; i++) {
			if (prec[i] != 0)
				break;
		}
		if (i == numop)
			break;
	}

	printsolution(expression, solution, numsolution);

out:
	free(expr);
	free(prec);
	free(operand);
	free(operator);
	free(solution);
	return;

error:
	fprintf(stderr, "parenperm: invalid expression: \"%s\", aborting!\n", expression);
	goto out;
}

int
main(int argc, char *argv[])
{
	char *expression;

	if (argc < 2) {
		parenperm("1+2-3*4");
		parenperm("1-1+1");
		parenperm("10");
		parenperm("1 + 2 + 3 * 4 - 5 * 2");
		return 0;
	}

	expression = strjoin(argv + 1, argc - 1);
	parenperm(expression);
	free(expression);

	return 0;
}
