/*

Given a string representing an infix expression, return the postfix equivalent.
The operands stay in their original order, and any parentheses are removed.
Only the operator order is changed.
Operands and operators will be separated by a single space, with the exception of parentheses (see examples).

Examples

infixToPostfix("7 + 3") ➞ "7 3 +"

infixToPostfix("(8 + 4) / 4") ➞ "8 4 + 4 /"

infixToPostfix("4 * (5 - (7 + 2))") ➞ "4 5 7 2 + - *"

Notes

Converting infix expressions to postfix expressions is an example of operator-precedence parsing,
the most famous of which is Dijkstra's "shunting-yard" algorithm (see the resources tab for more information).

*/

#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

int
precedence(int op)
{
	switch (op) {
	case '^':
		return 3;
	case '*':
	case '/':
		return 2;
	case '+':
	case '-':
		return 1;
	}
	return -1;
}

int
isident(int c)
{
	return isalnum(c) || c == '_';
}

char *
in2post(const char *s)
{
	char *p, *stk, op;
	size_t i, j, sp, len;

	len = strlen(s);
	p = calloc(3, len);
	stk = calloc(1, len);
	if (!p || !stk)
		goto error;

	sp = 0;
	for (i = j = 0; i < len; i++) {
		if (isspace(s[i]))
			continue;

		if (isident(s[i])) {
			do {
				p[j++] = s[i++];
			} while (isident(s[i]));
			i--;

			p[j++] = ' ';
		} else if (s[i] == '(')
			stk[sp++] = '(';
		else if (s[i] == ')') {
			while (sp > 0 && (op = stk[--sp]) != '(') {
				p[j++] = op;
				p[j++] = ' ';
			}
		} else {
			while (sp > 0 && precedence(s[i]) <= precedence(stk[sp - 1])) {
				p[j++] = stk[--sp];
				p[j++] = ' ';
			}
			stk[sp++] = s[i];
		}
	}
	while (sp > 0) {
		p[j++] = stk[--sp];
		p[j++] = ' ';
	}
	p[j] = '\0';

	while (j > 0 && p[j - 1] == ' ')
		p[--j] = '\0';

	if (0) {
	error:
		free(p);
		p = NULL;
	}

	free(stk);
	return p;
}

void
test(const char *s, const char *t)
{
	char *p;

	p = in2post(s);
	assert(p && strcmp(p, t) == 0);
	free(p);
}

int
main(void)
{
	test("7 + 3", "7 3 +");
	test("(8 + 4) / 4", "8 4 + 4 /");
	test("8 + 1", "8 1 +");
	test("9 / 3", "9 3 /");
	test("8 + 2 * 5", "8 2 5 * +");
	test("(8 + 2) * 5", "8 2 + 5 *");
	test("1 + 2 + 3 + 4 + 5", "1 2 + 3 + 4 + 5 +");
	test("3 * (12 / (32 / 8))", "3 12 32 8 / / *");
	test("2 + 3 * 1 - 9", "2 3 1 * + 9 -");
	test("(3 + 4) * 2 / 7", "3 4 + 2 * 7 /");
	test("4 * (5 - (7 + 2))", "4 5 7 2 + - *");
	test("(10 + 8 - 3 * 4) / 6", "10 8 + 3 4 * - 6 /");
	test("13 + (6 + 7 - 8 / (4 * 9))", "13 6 7 + 8 4 9 * / - +");
	test("(5 - 7) * (6 + 9)", "5 7 - 6 9 + *");
	test("(6 + 2) * 5 - 8 / 4", "6 2 + 5 * 8 4 / -");
	test("9 * 2 + 3 - 12", "9 2 * 3 + 12 -");
	test("6 - (4 + 18 / (2 + 7))", "6 4 18 2 7 + / + -");
	test("3 * (10 + 5)", "3 10 5 + *");
	test("(8 + 1 + 3) * 7 - 6", "8 1 + 3 + 7 * 6 -");
	test("(3 + 2) * (15 / 3 - 8)", "3 2 + 15 3 / 8 - *");
	test("10 / (7 - (8 / 4)) * 6 + 3 - (5 * 4)", "10 7 8 4 / - / 6 * 3 + 5 4 * -");
	test("(6 - 45) / (3 + 12) * 6 / 2", "6 45 - 3 12 + / 6 * 2 /");

	return 0;
}
