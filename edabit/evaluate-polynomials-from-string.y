/*

You will be given a polynomial expression in string form. The expression will contain any of the following operations, written using standard mathematical notation for a single variable, "x", as illustrated in the examples below:

    addition: x + 1
    subtraction: x – 2
    multiplication: 3x
    division: x / 4
    exponentation: x^5
    brackets: x(x + 1)

Your task is to write a function that can evaluate such a polynomial for a given value of x. You will receive two arguments: the polynomial string and the input number.

If the mathematical expression contains an error, you should return -1.

Examples

evalPolynomial("x+1", 5) ➞ 6

evalPolynomial("5x^2", 3) ➞ 45

evalPolynomial("(x(x+1))/2", 4) ➞ 10

evalPolynomial("4(x + 3))/2", 5) ➞ -1
// Invalid because parentheses not balanced.

Notes

The string will not contain spaces.

*/

%{

#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <math.h>

typedef struct {
	const char *p;
	long x;
	long r;
	int e;
} Line;

%}

%define api.pure full
%locations
%param { Line *ln };

%code
{
	int yylex(YYSTYPE *, YYLTYPE *, Line *);
	void yyerror(YYLTYPE *, Line *, const char *);
}

%union
{
	long v;
}

%left '+' '-'
%left '*' '/'
%right '^'

%type <v> expr val
%token <v> LNUM LVAR

%%

expr:
val
	{
		ln->r = $1;
	}
|
	expr '+' expr
	{
		$$ = ln->r = $1 + $3;
	}
|
	expr '-' expr
	{
		$$ = ln->r = $1 - $3;
	}
|
	expr '*' expr
	{
		$$ = ln->r = $1 * $3;
	}
|
	expr '/' expr
	{
		$$ = ln->r = $1 / $3;
	}
|
	val '^' expr
	{
		$$ = ln->r = pow($1, $3);
	}
|
	val val '^' expr
	{
		$$ = ln->r = $1 * pow($2, $4);
	}
|
	'(' expr ')' '^' expr
	{
		$$ = ln->r = pow($2, $5);
	}
|
	'(' expr ')'
	{
		$$ = ln->r = $2;
	}
|
	'+' expr
	{
		$$ = ln->r = $2;
	}
|
	'-' expr
	{
		$$ = ln->r = -$2;
	}
|
	val '(' expr ')'
	{
		$$ = ln->r = $1 * $3;
	}
|
	val val
	{
		$$ = ln->r = $1 * $2;
	}

val: LVAR | LNUM

%%

int
yylex(YYSTYPE *lv, YYLTYPE *ll, Line *ln)
{
	char *ep;
	int t;

	while (isspace(ln->p[0]))
		ln->p++;

	if (isdigit(ln->p[0])) {
		lv->v = strtol(ln->p, &ep, 10);
		ln->p = ep;
		return LNUM;
	}

	t = 0;
	switch (ln->p[0]) {
	case 'x':
		t = LVAR;
		lv->v = ln->x;
		break;

	case '\0':
	case '+':
	case '-':
	case '*':
	case '/':
	case '^':
	case '(':
	case ')':
		t = ln->p[0];
		break;

	default:
		yyerror(ll, ln, "invalid input");
		break;
	}
	ln->p++;

	return t;
}

void
yyerror(YYLTYPE *ll, Line *ln, const char *msg)
{
	ln->e = 1;

	(void) ll;
	(void) ln;
	(void) msg;
}

long
eval(const char *s, long x)
{
	Line ln = { s, x, 0 , 0 };
	if (yyparse(&ln) || ln.e)
		return -1;
	return ln.r;
}

void
test(const char *s, long x, long r)
{
	long v;
	
	v = eval(s, x);
	printf("'%s' [%ld] -> %ld %ld\n", s, x, v, r);
	assert(v == r);
}

int
main(void)
{
	test("x+1", 5, 6);
	test("5x^2", 3, 45);
	test("(x(x+1))/2", 4, 10);
	test("4(x + 3))/2", 5, -1);
	test("x+1", 1, 2);
	test("x^2", 2, 4);
	test("2(x+2)+x(x-1)", 3, 16);
	test("3x^2/8", 4, 6);
	test("3x&2/8", 5, -1);
	test("print(x)", 6, -1);
	test("x//2", 7, -1);
	test("", 8, -1);
	test("3x", 5, 15);
	test("4x + 5 * 12", 1, 64);
	test("(2+x)^5", 3, 3125);
	test("(56x*57x)^x", 2, 163021824l);

	return 0;
}
