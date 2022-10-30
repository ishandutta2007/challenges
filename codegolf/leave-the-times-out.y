// goyacc -o leave-the-times-out.go leave-the-times-out.y

/*

Everyone knows, that you can leave out the multiplication symbol (×, or *) in

    a*b
    23*a
    (2+3)*a
    a^(b*c)
    (a+b)*(c+d)

but not in

    2*3 => you don't want it to be 23
    a*23 => most mathematicians just don't do it
    a^2*b => now it's (a^2)*b, if you remove the *, it's a^(2b)
    a/2*b => now it's (a/2)*b, if you remove the *, it's a/(2b)
    a*(2+3) => most mathematicians just don't do it

But does a program know it to?
Notes

    The input is an equation which has the basic operations (+, -, *, /, ^), parentheses ((, )) and sometimes some 1-letter variables
    The output should be the input with unnecessary *s removed where possible

Examples

a*b
> ab

2+3*a
> 2+3a

23+67/(56+7)
> 23+67/(56+7)

2t
> 2t

2*3+5/6*b
> 2*3+5/6*b

2*a*3
> 2a*3

2*-3
> 2*-3

a*-3
> a*-3

a^2*b
> a^2*b

a/2*b
> a/2*b

a*(2+5)
> a*(2+5)

(2+5)*a
> (2+5)a

23+(2*a)^(45*b)-c/5+24d+(2a)*(2b)
> 23+(2a)^(45b)-c/5+24d+(2a)(2b)

(a-b)*(2+e)
> (a-b)(2+e)

a*b*c
> abc

2*(3)
> 2(3)

(2)*(3)
> (2)(3)

2(3)
> 2(3)

(2)*3
> (2)3

*/

%{

package main

import (
	"bytes"
	"errors"
	"fmt"
	"go/ast"
	"go/token"
	"strings"
	"text/scanner"
)

%}

%union {
	line  *Line
	value string
	node  ast.Expr
}

%type <line> top
%type <node> expr

%left '+' '-'
%left '*' '/' '%'
%right '^'

%token <value> NUM
%token <value> VAR
%token BINOP UNOP PAREN

%%

top:
	expr
	{
		$$.root = $1
	}

expr:
	NUM
	{
		$$ = &ast.BasicLit{Kind: token.INT, Value: $1}
	}
|
	VAR
	{
		$$ = &ast.Ident{Name: $1}
	}
|
	'+' expr
	{
		$$ = &ast.UnaryExpr{Op: token.ADD, X: $2}
	}
|
	'-' expr
	{
		$$ = &ast.UnaryExpr{Op: token.SUB, X: $2}
	}
|
	expr '+' expr
	{
		$$ = &ast.BinaryExpr{Op: token.ADD, X: $1, Y: $3}
	}
|
	expr '-' expr
	{
		$$ = &ast.BinaryExpr{Op: token.SUB, X: $1, Y: $3}
	}
|
	expr '*' expr
	{
		$$ = &ast.BinaryExpr{Op: token.MUL, X: $1, Y: $3}
	}
|
	expr '/' expr
	{
		$$ = &ast.BinaryExpr{Op: token.QUO, X: $1, Y: $3}
	}
|
	expr '%' expr
	{
		$$ = &ast.BinaryExpr{Op: token.REM, X: $1, Y: $3}
	}
|
	expr '^' expr
	{
		$$ = &ast.BinaryExpr{Op: token.XOR, X: $1, Y: $3}
	}
|
	'(' expr ')'
	{
		$$ = &ast.ParenExpr{X: $2}
	}
%%

func main() {
	test("a*b", "ab")
	test("23*a", "23a")
	test("(2+3)*a", "(2+3)a")
	test("a^(b*c)", "a^(bc)")
	test("(a+b)*(c+d)", "(a+b)(c+d)")
	test("2*3", "2*3")
	test("a*23", "a*23")
	test("a^2*b", "a^2*b")
	test("a/2*b", "a/2*b")
	test("a*(2+3)", "a*(2+3)")
	test("2+3*a", "2+3a")
	test("23+67/(56+7)", "23+67/(56+7)") 
	test("2t", "2t")
	test("2*3+5/6*b", "2*3+5/6*b")
	test("2*a*3", "2a*3")
	test("2*-3", "2*-3")
	test("a*-3", "a*-3")
	test("a^2*b", "a^2*b")
	test("a/2*b", "a/2*b")
	test("a*(2+5)", "a*(2+5)")
	test("(2+5)*a", "(2+5)a")
	test("23+(2*a)^(45*b)-c/5+24*d+(2*a)*(2*b)", "23+(2a)^(45b)-c/5+24d+(2a)(2b)")
	test("(a-b)*(2+e)", "(a-b)(2+e)")
	test("a*b*c", "abc")
	test("2*(3)", "2(3)")
	test("(2)*(3)", "(2)(3)")
	test("(2)*3", "(2)3")
	test("a*b*c*d*e*f", "abcdef")
}

func test(s, r string) {
	p := tidy(s)
	fmt.Println(p, r)
	assert(p == r)
}

func assert(x bool) {
	if !x {
		panic("assertion failed")
	}
}

func tidy(s string) string {
	l := &Line{}
	l.sc.Init(strings.NewReader(s))

	if yyParse(l) != 0 || l.err != nil {
		return s
	}

	w := new(bytes.Buffer)
	format(w, l.root)
	return w.String()
}

func format(w *bytes.Buffer, e ast.Expr) int {
	switch e := e.(type) {
	case *ast.BinaryExpr:
		p := new(bytes.Buffer)
		q := new(bytes.Buffer)
		x := format(p, e.X)
		y := format(q, e.Y)

		typ := BINOP
		op := e.Op.String()
		if e.Op == token.MUL {
			switch {
			case x == VAR && y == VAR,
				x == NUM && y == VAR,
				x == PAREN:
				op = ""
				typ = VAR

			case x == NUM && y == PAREN:
				op = ""
				typ = NUM
			}
		}

		fmt.Fprintf(w, "%v%s%v", p, op, q)
		return typ
	case *ast.ParenExpr:
		fmt.Fprintf(w, "(")
		format(w, e.X)
		fmt.Fprintf(w, ")")
		return PAREN
	case *ast.UnaryExpr:
		fmt.Fprintf(w, "%v", e.Op)
		format(w, e.X)
		return UNOP
	case *ast.BasicLit:
		fmt.Fprintf(w, "%v", e.Value)
		return NUM
	case *ast.Ident:
		fmt.Fprintf(w, "%v", e.Name)
		if len(e.Name) > 1 {
			return NUM
		}
		return VAR
	default:
		panic(fmt.Errorf("unsupported expression type: %T", e))
	}
}

type Line struct {
	root ast.Expr
	sc   scanner.Scanner
	err  error
}

func (l *Line) Lex(lv *yySymType) int {
	tok := l.sc.Scan()
	lv.line, lv.value = l, l.sc.TokenText()
	switch tok {
	case scanner.EOF:
		return 0
	case scanner.Ident:
		return VAR
	case scanner.Int, scanner.Float:
		return NUM
	}
	return int(lv.value[0])
}

func (l *Line) Error(s string) {
	l.err = errors.New(s)
}
