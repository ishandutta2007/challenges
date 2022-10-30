/*

Write the shortest parser for the grammar:

M -> M + n | n
Output must be some representation of a structured value representing the concrete syntax tree produced by the input n+n+n.
The code to produce the textual output from the structured value is not necessary.
The code to read/validate input is not necessary.
Solution is anything that can somehow be called; a function, an object, doesn't matter.
How your solution receives input (currying character-by-character, whole-string, some kind of input reader) does not matter.
For example a bottom-up parser (Javascript, 284 characters):

function M(d){function c(a){throw"unexpected "+a;}function f(a){if("+"==a)return b.push(a),e;if(null==a)return b;c(a)}function e(a){if("n"==a)return b.push(a),b=[b],g;c(a)}function g(a){if("+"==a)return b.push(a),e;if(null==a)return b;c(a)}var b=[];if("n"==d)return b.push(d),f;c(d)};

When called:

 M('n')('+')('n')('+')('n')(null)
will return an array that in JSON-notation looks like this:

[["n", "+", "n"], "+", "n"]
Edit for the uninitiated in parsing: This is one of those questions where making a program produce the correct output is easy but the form of the program is essential for up-boats.

M -> M + n | n
Means that M consists of a previous M, a plus sign and a literal "n". Or good M is a single "n" literal character.

There are several way of approaching this challenge, I'll describe my own solution, which is called bottom-up parsing. Character by character:

 Stack               Incoming Character         Action on stack
                     n                          
 n                   +                          reduce "n" to M
 M+                  n
 M+n                 +                          reduce "M + n" to M
 M+                  n                          
 M+n                 EOF                        reduce "M + n" to M
 M

 The twist in this question is that the simplest form of parsers called "recursive-descent" parsers won't work because the grammar is left-recursive and that throws a recursive-descent parser into an infinite loop.

*/

%{

#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

typedef struct {
	const char *p;
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

%%

M: M '+' 'n' | 'n'

%%

int
yylex(YYSTYPE *lv, YYLTYPE *ll, Line *ln)
{
	int t;

	while (isspace(ln->p[0]))
		ln->p++;

	t = 0;
	switch (ln->p[0]) {
	case '\0':
	case '+':
	case 'n':
		t = ln->p[0];
		break;

	default:
		yyerror(ll, ln, "invalid input");
		break;
	}
	ln->p++;
	return t;

	(void) lv;
}

void
yyerror(YYLTYPE *ll, Line *ln, const char *msg)
{
	ln->e = 1;

	(void) ll;
	(void) ln;
	(void) msg;
}

int
grammar(const char *s)
{
	Line ln = { s, 0 };
	if (yyparse(&ln) || ln.e)
		return 0;
	return 1;
}

int
main(void)
{
	assert(grammar("n") == 1);
	assert(grammar("n+n+n+n") == 1);
	assert(grammar("n+") == 0);
	assert(grammar("m") == 0);
	assert(grammar("n+n") == 1);
	assert(grammar("n+n+") == 0);

	return 0;
}
