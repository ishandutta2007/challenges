// Add commands to print the top element of the stack without popping,
// to duplicate it, and to swap the top two elements.
// Add a command to clear the stack.

#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>
#include <math.h>
#include <ctype.h>

enum {
	MAXOP = 1024,
	NUMBER = '0',
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

int
main(void)
{
	char str[BUFSIZ];
	double op1, op2;
	int op;

	while ((op = getop(stdin, str, sizeof(str))) != EOF) {
		switch (op) {
		case NUMBER:
			push(atof(str));
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
		case '\n':
			printf("\t%.8g\n", pop());
			break;
		default:
			printf("error: unknown command '%s'\n", str);
			break;
		}
	}

	return 0;
}
