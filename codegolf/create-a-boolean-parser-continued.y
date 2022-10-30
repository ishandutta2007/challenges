/*

Continuation of this challenge because the author is gone and the question is closed.

What you need to do is create a Boolean parser.

Boolean expressions, in case you haven't heard of them yet, have two inputs and one output.

There are four "gates" in boolean arithmetic, namely:

    OR (represented by |) (binary operator, between arguments)
    AND (represented by &) (binary operator, between arguments)
    XOR (represented by ^) (binary operator, between arguments)
    NOT (represented by !) (unary operator, argument on right)

These gates operate on their inputs which are either true (represented by 1) or false (represented by 0). We can list the possible inputs (A and B in this case) and the outputs (O) using a truth table as follows:

XOR
A|B|O
-----
0|0|0
0|1|1
1|0|1
1|1|0

OR
A|B|O
-----
0|0|0
0|1|1
1|0|1
1|1|1

AND
A|B|O
-----
0|0|0
0|1|0
1|0|0
1|1|1

NOT
A|O
---
0|1
1|0

An example input would be 1^((1|0&0)^!(1&!0&1)), which would evaluate to:

 1^((1|0&0)^!(1&!0&1))
=1^(( 1 &0)^!(1&!0&1))
=1^(   0   ^!(1&!0&1))
=1^(   0   ^!(1& 1&1))
=1^(   0   ^!(  1 &1))
=1^(   0   ^!    1   )
=1^(   0   ^    0    )
=1^0
=1

The output would be 1.
Details

    As seen in the example, there is no order of prevalence. All are evaluated from left to right, except when inside parentheses, which should be evaluated first.
    The input will only contain ()!^&|01.
    You can choose any 8-byte character to replace the 8 characters above, but they must have a 1-to-1 mapping and must be stated.
    Specifically, the function eval is not allowed to be used on any string derived from the input. Specifically, the function input (or the equivalent in the language) and any function that calls it cannot be used by eval. You also cannot concatenate the input into your string inside the eval.

Scoring

This is code-golf. Shortest solution in bytes wins.

*/

%{

#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <math.h>

typedef struct {
	const char *p;
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

%left '&' '|' '^'
%left '!'

%type <v> expr
%token <v> LNUM

%%

expr:
	LNUM
	{
		ln->r = $1;
	}
|
	expr '&' expr
	{
		$$ = ln->r = $1 & $3;
	}
|
	expr '|' expr
	{
		$$ = ln->r = $1 | $3;
	}
|
	expr '^' expr
	{
		$$ = ln->r = $1 ^ $3;
	}
|
	'(' expr ')'
	{
		$$ = ln->r = $2;
	}
|
	'!' expr
	{
		$$ = ln->r = !$2;
	}

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
	case '\0':
	case '&':
	case '|':
	case '^':
	case '!':
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
eval(const char *s)
{
	Line ln = { s, 0 , 0 };
	if (yyparse(&ln) || ln.e)
		return -1;
	return ln.r;
}

void
test(const char *s, long r)
{
	long v;
	
	v = eval(s);
	printf("'%s' -> %ld\n", s, r);
	assert(v == r);
}

int
main(void)
{
	test("1^((1|0&0)^!(1&!0&1))", 1);
	return 0;
}
