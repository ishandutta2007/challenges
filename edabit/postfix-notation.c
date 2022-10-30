/*

Postfix notation is a mathematical notation in which operators follow their operands.
In other words, pfexp1 pfexp2 op, where pfexp1 and pfexp2 are both postfix expressions.

Some examples:

    2 2 + is the postfix notation of the expression 2 + 2.
    2 3 * 1 - 5 / is the postfix notation of the expression ((2 * 3) - 1) / 5.

Here you have to compute the result from a postfix expression.
Examples

postfix("2 2 +") ➞ 4
// 2 + 2 = 4

postfix("2 3 * 1 - 5 /") ➞ 1
// ((2 * 3) - 1) / 5 = (6 - 1) / 5 = 5 / 5 = 1

Note

    Operators and operands are separated by a space.
    The operators +, -, *, / may be supported.

*/

#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

long
binop(int op, long x, long y)
{
	switch (op) {
	case '+':
		return x + y;
	case '-':
		return x - y;
	case '*':
		return x * y;
	case '/':
		if (y == 0)
			return 0;
		return x / y;
	}
	return 0;
}

long
postfix(const char *s)
{
	size_t i, n, sp;
	long *stk, r;
	char *ep;

	n = strlen(s);
	stk = calloc(n + 1, sizeof(*stk));
	if (!stk)
		return 0;

	sp = 0;
	for (i = 0; s[i]; i++) {
		while (isspace(s[i]))
			i++;

		if (isdigit(s[i])) {
			stk[sp++] = strtol(s + i, &ep, 10);
			i = ep - s - 1;
			continue;
		}

		switch (s[i]) {
		case '+':
		case '-':
		case '*':
		case '/':
			if (sp >= 2) {
				stk[sp - 2] = binop(s[i], stk[sp - 2], stk[sp - 1]);
				sp--;
			}
			break;
		}
	}

	r = stk[0];
	free(stk);
	return r;
}

int
main(void)
{
	assert(postfix("2 2 +") == 4);
	assert(postfix("2 3 * 1 - 5 /") == 1);
	assert(postfix("5") == 5);
	assert(postfix("10 10 * 10 /") == 10);
	assert(postfix("5 6 * 2 1 + /") == 10);
	assert(postfix("1 1 + 2 2 + -") == -2);
	assert(postfix("8 4 / 9 * 3 1 * /") == 6);

	return 0;
}
