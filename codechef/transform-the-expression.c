/*

Reverse Polish Notation (RPN) is a mathematical notation where every operator follows all of its operands.
For instance, to add three and four, one would write "3 4 +" rather than "3 + 4".
If there are multiple operations, the operator is given immediately after its second operand;
so the expression written "3 − 4 + 5" would be written "3 4 − 5 +" first subtract 4 from 3, then add 5 to that.

Transform the algebraic expression with brackets into RPN form.

You can assume that for the test cases below only single letters will be used, brackets [] will not be used and each expression has only one RPN form (no expressions like a*b*c) 

*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int
prec(int op)
{
	switch (op) {
	case '+':
	case '-':
		return 1;
	case '*':
	case '/':
	case '%':
		return 2;
	case '^':
		return 3;
	}
	return -1;
}

char *
in2post(const char *s)
{
	char *p, *op, c;
	size_t i, j, k;

	p = strdup(s);
	op = strdup(s);
	if (p == NULL || op == NULL)
		goto error;

	for (i = j = k = 0; s[i]; i++) {
		switch (s[i]) {
		case ' ':
			break;

		case '(':
			op[k++] = s[i];
			break;

		case ')':
			while (k >= 1 && op[--k] != '(')
				p[j++] = op[k];
			break;

		case '+':
		case '-':
		case '*':
		case '/':
		case '%':
		case '^':
			while (k >= 1 && prec(op[k - 1]) >= prec(s[i]))
				p[j++] = op[--k];
			op[k++] = s[i];
			break;

		default:
			p[j++] = s[i];
			break;
		}
	}

	while (k >= 1) {
		c = op[--k];
		if (c != '(')
			p[j++] = c;
	}
	p[j] = '\0';

	if (0) {
	error:
		free(p);
		p = NULL;
	}
	free(op);
	return p;
}

void
transform(const char *s)
{
	char *p;

	p = in2post(s);
	printf("%s\n", p);
	free(p);
}

int
main(void)
{
	transform("(a+(b*c))");
	transform("((a+b)*(z+x))");
	transform("((a+t)*((b+(a+c))^(c+d)))");
	transform("(3+5");
	transform("(");
	transform("(3)+(5*2");
	transform("3-4+5");
	return 0;
}
