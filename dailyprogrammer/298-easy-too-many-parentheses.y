// goyacc -o 298-easy-too-many-parentheses.go 298-easy-too-many-parentheses.y 

/*

Difficulty may be higher than easy,

(((3))) is an expression with too many parentheses.

The rule for "too many parentheses" around part of an expression is that if removing matching parentheses around a section of text still leaves that section enclosed by parentheses, then those parentheses should be removed as extraneous.

(3) is the proper stripping of extra parentheses in above example.

((a((bc)(de)))f) does not have any extra parentheses. Removing any matching set of parentheses does not leave a "single" parenthesesed group that was previously enclosed by the parentheses in question.

inputs:

((a((bc)(de)))f)
(((zbcd)(((e)fg))))
ab((c))
outputs:

((a((bc)(de)))f)
((zbcd)((e)fg))
ab(c)
bonus
A 2nd rule of too many parentheses can be that parentheses enclosing nothing are not needed, and so should be removed. A/white space would not be nothing.

inputs:

  ()
  ((fgh()()()))
  ()(abc())
outputs:

  NULL
  (fgh)
  (abc)

*/

%{

package main

import (
	"errors"
	"fmt"
	"go/ast"
)

%}

%union {
	line  *Line
	value string
	node  ast.Expr
}

%type <line> top
%type <node> expr

%token <value> VALUE

%%

top:
	expr
	{
		$$.result = exprstring($1)
	}

expr:
	VALUE
	{
		$$ = &ast.BasicLit{Value: $1} 
	}
|
	VALUE '(' ')'
	{
		$$ = &ast.BasicLit{Value: $1}
	}
|
	VALUE '(' ')' expr
	{
		$$ = &ast.BasicLit{Value: $1 + exprstring($4)}
	}
|
	'(' ')' expr
	{
		$$ = $3
	}
|
	'(' expr ')'
	{
		$$ = $2
		_, ok := $2.(*ast.ParenExpr)
		if !ok {
			$$ = &ast.ParenExpr{X: $2}
		}
	}
|
	'(' expr ')' expr
	{
		x, ok := $2.(*ast.ParenExpr)
		if !ok {
			x = &ast.ParenExpr{X: $2}
		}
		$$ = &ast.BasicLit{Value: exprstring(x) + exprstring($4)}
	}
|
	VALUE '(' expr ')'
	{
		x, ok := $3.(*ast.ParenExpr)
		if !ok {
			x = &ast.ParenExpr{X: $3}
		}
		$$ = &ast.BasicLit{Value: $1 + exprstring(x)} 
	}
|
	'(' ')'
	{
		$$ = &ast.BasicLit{}
	}
%%

func main() {
	test("fgh()()", "fgh")
	test("abc", "abc")
	test("(((3)))", "(3)")
	test("((a((bc)(de)))f)", "((a((bc)(de)))f)")
	test("(((zbcd)(((e)fg))))", "((zbcd)((e)fg))")
	test("ab((c))", "ab(c)")
	test("()", "")
	test("((fgh()()()))", "(fgh)")
	test("()(abc())", "(abc)")
}

func test(s, r string) {
	p := simplify(s)
	fmt.Println(p)
	fmt.Println(r)
	fmt.Println()
	assert(p == r)
}

func assert(x bool) {
	if !x {
		panic("assertion failed")
	}
}

func simplify(s string) string {
	l := &Line{ buf: s }
	if yyParse(l) != 0 || l.err != nil {
		return s
	}
	return l.result
}

type Line struct {
	result string
	buf    string
	err    error
}

func (l *Line) Lex(lv *yySymType) int {
	lv.line = l

	if len(l.buf) == 0 {
		return 0
	}

	if ischar(l.buf[0]) {
		n := 1
		for n < len(l.buf) && ischar(l.buf[n]) {
			n++
		}
		lv.value = string(l.buf[:n])
		l.buf = l.buf[n:]
		return VALUE
	}

	tok := l.buf[0]
	l.buf = l.buf[1:]
	return int(tok)
}

func (l *Line) Error(s string) {
	l.err = errors.New(s)
}

func ischar(c byte) bool {
	switch {
	case '0' <= c && c <= '9':
		return true
	case 'a' <= c && c <= 'z':
		return true
	case 'A' <= c && c <= 'Z':
		return true
	case c == '_' || c == ' ':
		return true
	}
	return false
}

func exprstring(e ast.Expr) string {
	switch e := e.(type) {
	case *ast.ParenExpr:
		return "(" + exprstring(e.X) + ")"
	case *ast.BasicLit:
		return e.Value
	default:
		panic("unknown expression")
	}
}
