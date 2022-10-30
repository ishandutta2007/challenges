/*

Forget BIDMAS! Write a program that takes an equation and an operator precedence order, and prints the result.

Example input format:

1.2+3.4*5.6/7.8-9.0 *,/,+,-
Rules & guidelines:

The only operators that are defined are addition (+), subtraction (-), multiplication (*), and division (/). No parentheses, no exponentiation.
Associativity is always left-to-right. For example, 10/4/2 is to be interpreted as (10/4)/2 with a result of 1.25, rather than 10/(4/2).
The input format is as follows:
An equation, followed by a space, followed by the operator precedence specification (or two string arguments, one for the equation and the other for the precedence).
The equation comprises base-10 decimal numbers separated by operators, with no spaces. Integer values do not have to contain a period character, i.e. both 5 and 5.0 are to be accepted values.
For simplicity, negative numbers may not be included in the input, e.g. 6/3 is valid but 6/-3 is not. Input also may not contain a leading or trailing operator, so -6/3 isn't considered valid, nor is 6-3+.
The precedence specification string is always 4 characters long and always contains the characters +, -, /, and * once each.
Precedence is read as left-to-right, e.g. * /+- specifies multiplication with the highest precedence, division next, then addition, and finally subtraction.
EDIT: It is acceptable to take the precedence string in reverse order (lowest to highest) as long as you specify this in your answer.
Input is a string to be taken via command line arguments, STDIN, or the default input format in programming languages that do not support these input methods.
You are free to assume that the given input will be in the correct format.
Output is via STDOUT or your language's normal output method.
The printed result should be in base-10 decimal.
Results must be computed to at least 4 decimal points of accuracy when compared to a correct implementation that uses double precision (64-bit) floating point arithmetic.
This degree of freedom is designed to allow for the use of fixed-point arithmetic in languages that have no floating-point support.
Divide by zero, overflow, and underflow are undefined behaviour. Your code is free to assume that no inputs will be given that will trigger these cases.
You may not call out to any external services (e.g. Wolfram Alpha)
You may not call out to any programs whose primary function is to solve these types of problems.
Test cases:

6.3*7.8 followed by any operator precedence specification prints 49.14
2.2*3.3+9.9/8.8-1.1 *,/,+,- is parsed as ((2.2*3.3)+(9.9/8.8))-1.1 and should print 7.285
2.2*3.3+9.9/8.8-1.1 +,*,/,- is parsed as ((2.2*(3.3+9.9))/8.8)-1.1 and should print 2.2
10/2+5-1 +-/* is parsed as 10/((2+5)-1) and the printed result should be 1.6666666...
2147480/90+10*5 +,/,-,* is parsed as (2147480/(90+10))*5 and the printed result should be 107374
3*55-5/8/4+1 -,/,+,* is parsed as 3*((((55-5)/8)/4)+1) should print 7.6875
An input containing one thousand instances of the number 1.015 separated by multiplier operators (i.e. the expanded multiplicative form of 1.015^1000), followed by any operated precedence specification, should print a number within 0.0001 of 2924436.8604.

*/

%{

#include <assert.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#include <math.h>

typedef struct {
	const char *p;
	double r;
	int prec[4];
	int err;
} Line;

%}

%define api.pure full
%locations
%param { Line *ln };

%code
{
	int yylex(YYSTYPE *, YYLTYPE *, Line *);
	void yyerror(YYLTYPE *, Line *, const char *);
	double binop(int, double, double);
}

%union
{
	int op;
	double v;
}

%left LOP1
%left LOP2
%left LOP3
%left LOP4

%type <v> expr val
%token <v> LNUM
%token <op> LOP1 LOP2 LOP3 LOP4

%%

expr:
	val
	{
		ln->r = $1;
	}
|
	expr LOP1 expr
	{
		$$ = ln->r = binop($2, $1, $3);
	}
|
	expr LOP2 expr
	{
		$$ = ln->r = binop($2, $1, $3);
	}
|
	expr LOP3 expr
	{
		$$ = ln->r = binop($2, $1, $3);
	}
|
	expr LOP4 expr
	{
		$$ = ln->r = binop($2, $1, $3);
	}

val: LNUM

%%

int
yylex(YYSTYPE *lv, YYLTYPE *ll, Line *ln)
{
	char *ep;
	int t;

	while (isspace(ln->p[0]))
		ln->p++;

	if (isdigit(ln->p[0])) {
		lv->v = strtod(ln->p, &ep);
		ln->p = ep;
		return LNUM;
	}

	lv->op = ln->p[0];
	
	t = 0;
	switch (*ln->p++) {
	case '\0':
		break;
	case '+':
		t = ln->prec[0];
		break;
	case '-':
		t = ln->prec[1];
		break;
	case '*':
		t = ln->prec[2];
		break;
	case '/':
		t = ln->prec[3];
		break;

	default:
		yyerror(ll, ln, "invalid input");
		break;
	}

	return t;
}

void
yyerror(YYLTYPE *ll, Line *ln, const char *msg)
{
	ln->err = 1;

	(void) ll;
	(void) ln;
	(void) msg;
}

double
binop(int op, double x, double y)
{
	switch (op) {
	case '+':
		return x + y;
	case '-':
		return x - y;
	case '*':
		return x * y;
	case '/':
		return x / y;
	}
	return 0;
}

void
mkprec(const char *s, int p[4])
{
	static const int toks[] = { LOP4, LOP3, LOP2, LOP1 };
	static const char ops[] = "+-*/";

	const char *t;
	int c, f, l;
	size_t i;

	c = f = 0;
	for (i = 0; s[i]; i++) {
		t = strchr(ops, s[i]);
		if (!t)
			continue;
		
		l = t - ops;
		if (f & (1 << l))
			continue;

		p[l] = c++;
		f |= 1 << l;
	}

	for (l = 0; l < 4; l++) {
		if (!(f & (1 << l)))
			p[l] = c++;

		p[l] = toks[p[l]];
	}
}

double
eval(const char *s, const char *t)
{
	Line ln;

	memset(&ln, 0, sizeof(ln));
	ln.p = s;
	mkprec(t, ln.prec);

	if (yyparse(&ln) || ln.err)
		return -1;
	return ln.r;
}

void
test(const char *s, const char *t, double r)
{
	double v;
	
	v = eval(s, t);
	printf("'%s' -> %f %f\n", s, v, r);
	assert(fabs(v - r) < 1e-6);
}

int
main(void)
{
	test("6.3*7.8", "+-*/", 49.14);
	test("2.2*3.3+9.9/8.8-1.1", "*/+-", 7.285);
	test("2.2*3.3+9.9/8.8-1.1", "+*/-", 2.2);
	test("10/2+5-1", "+-/*", 1.6666666);
	test("2147480/90+10*5", "+/-*", 107374);
	test("3*55-5/8/4+1", "-/+*", 7.6875);

	return 0;
}
