// Add commands for handling variables.
// (It's easy to provide twenty-six variables with single-letter names.)
// Add a variable for the most recently printed value.

#define _GNU_SOURCE
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdarg.h>
#include <math.h>
#include <ctype.h>

enum {
	MAXOP = 1024,
	NUMBER = '0',
	NAME = 'n',
};

int
snprint(char *str, size_t size, const char *fmt, ...)
{
	va_list ap;
	size_t n;

	va_start(ap, fmt);
	n = vsnprintf(str, size, fmt, ap);
	va_end(ap);
	return (n < size) ? n : size;
}

int
peekc(FILE *fp)
{
	int ch;
	ch = fgetc(fp);
	if (ch != EOF)
		ungetc(ch, fp);
	return ch;
}

int
getop(FILE *fp, char *s, size_t n)
{
	int op, ch;
	size_t l;

loop:
	ch = fgetc(fp);
	if (ch == EOF || ch == '*' || ch == '/' || ch == '%' || ch == '\n')
		return ch;

	if (isspace(ch))
		goto loop;

	op = NUMBER;
	if (ch == '+' || ch == '-') {
		if (!isdigit(peekc(fp)))
			return ch;
	} else if (!isdigit(ch))
		op = ch;

	l = 0;
	do {
		l += snprint(s + l, n - l, "%c", ch);
		ch = fgetc(fp);
	} while (ch != EOF && !isspace(ch));

	if (op == '.')
		op = NUMBER;
	else if (l == 1 && op == 'e')
		op = NAME;
	else if (l > 1 && op != NUMBER)
		op = NAME;

	return op;
}

double stack[MAXOP];
int sp;

void
push(double v)
{
	if (sp >= MAXOP) {
		printf("error: stack overflow\n");
		return;
	}
	stack[sp++] = v;
}

double
pop(void)
{
	if (sp <= 0)
		return 0;
	return stack[--sp];
}

void
clear(void)
{
	sp = 0;
}

void
mathfnc(const char *s)
{
	int op2;

	if (!strcmp(s, "sin"))
		push(sin(pop()));
	else if (!strcmp(s, "cos"))
		push(cos(pop()));
	else if (!strcmp(s, "tan"))
		push(tan(pop()));
	else if (!strcmp(s, "asin"))
		push(asin(pop()));
	else if (!strcmp(s, "acos"))
		push(acos(pop()));
	else if (!strcmp(s, "atan"))
		push(atan(pop()));
	else if (!strcmp(s, "atan2")) {
		op2 = pop();
		push(atan2(pop(), op2));
	} else if (!strcmp(s, "exp"))
		push(exp(pop()));
	else if (!strcmp(s, "pow")) {
		op2 = pop();
		push(pow(pop(), op2));
	} else if (!strcmp(s, "sqrt"))
		push(sqrt(pop()));
	else if (!strcmp(s, "cbrt"))
		push(cbrt(pop()));
	else if (!strcmp(s, "pi"))
		push(M_PI);
	else if (!strcmp(s, "tau"))
		push(2 * M_PI);
	else if (!strcmp(s, "phi"))
		push((1 + sqrt(5)) / 2);
	else if (!strcmp(s, "e"))
		push(exp(1));
	else if (!strcmp(s, "gamma"))
		push(gamma(pop()));
	else
		printf("error: %s is not supported\n", s);
}

int
main(void)
{
	char str[BUFSIZ];
	double op1, op2;
	double variable[26], v;
	int op, var;

	memset(variable, 0, sizeof(variable));
	var = v = 0;
	while ((op = getop(stdin, str, sizeof(str))) != EOF) {
		switch (op) {
		case NUMBER:
			push(atof(str));
			break;
		case NAME:
			mathfnc(str);
			break;
		case '+':
			push(pop() + pop());
			break;
		case '-':
			op2 = pop();
			push(pop() - op2);
			break;
		case '*':
			push(pop() * pop());
			break;
		case '/':
		case '%':
			op2 = pop();
			if (op2 != 0.0)
				push((op == '/') ? (pop() / op2) : fmod(pop(), op2));
			else
				printf("error: zero divisor\n");
			break;
		case '?':
			op2 = pop();
			printf("\t%.8g\n", op2);
			push(op2);
			break;
		case 'c':
			clear();
			break;
		case 'd':
			op2 = pop();
			push(op2);
			push(op2);
			break;
		case 's':
			op1 = pop();
			op2 = pop();
			push(op1);
			push(op2);
			break;
		case '=':
			pop();
			if ('A' <= var && var <= 'Z')
				variable[var - 'A'] = pop();
			else
				printf("error: no variable name\n");
			break;
		case '\n':
			v = pop();
			printf("\t%.8g\n", v);
			break;
		default:
			if ('A' <= op && op <= 'Z')
				push(variable[op - 'A']);
			else if (op == 'v')
				push(v);
			else
				printf("error: unknown command '%s'\n", str);
			break;
		}
		var = op;
	}

	return 0;
}
