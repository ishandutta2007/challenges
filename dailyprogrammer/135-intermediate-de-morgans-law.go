/*

De Morgan's Law is a neat law of Boolean propositional logic, helpful in every-day programming.
It helps with inverting a boolean expression to get the opposite expression.
Wolfram Mathworld has a much more correct definition using set theory, being equivalent to Boolean expressions.

That's important since programming is all about Boolean-expressions! If you want to invert some "if" conditional code (that is, to compute the test for the "else" fall-through case), you need to apply the Law's two transformations:

The not ( of expression-A and expression-B) is-equivalent-to not expression-A or not expression-B

The not ( of expression-A or expression-B) is-equivalent-to not expression-A and not expression-B

An interpretation of these rules, helpful for applying it, is that you first apply the not-operator on all expressions, then replace all ands with ors, and vice-versa.
This gets much more tricky and complex when order of operations come in play with parentheses (nested expressions).

Your goal is to take a C-like language's Boolean expression, and apply De Morgan's Law on it.
You may choose to simplify the resulting expression as much as possible for epic bonus poinst; consider reading into Karnaugh maps as one approach.
"Simplified" is measured in the least-amount of variables and operators required (not counting parentheses).

Formal Inputs & Outputs

Input Description
The grammar of this C-like language is English-language space-delimited words, uses parentheses for nested expressions, with variables strictly being lower-case alpha-numeric.
The reserved key-word for logical-and is "AND", with logical-or "OR", and logical-not "NOT". The expression will be in Infix-notation.

Note that the "NOT" is a unary operator, meaning it always applies first to variables on the right of itself, or to a full expression. The expression "NOT a OR b" is equivalent to "(NOT a) OR b", but not "NOT (a or b)".

Output Description
Given the expression, print it's inverse using the same grammar and given variables. Simplify the expression for epic bonus points.

Sample Inputs & Outputs

Sample Inputs
a
NOT a
a AND b
NOT a AND b
NOT (a AND b)
NOT (a OR b AND C) OR NOT(a AND NOT b)

Sample Outputs
NOT a
a
NOT a or NOT b
a OR NOT b
a AND b
a AND NOT b

*/

package main

import (
	"fmt"
	"go/ast"
	"go/parser"
	"go/token"
	"strings"
)

func main() {
	test("a")
	test("NOT a")
	test("a AND b")
	test("NOT a AND b")
	test("NOT (a AND b)")
	test("NOT (a OR b AND c) OR NOT(a AND NOT b)")
	test("NOT a OR b")
}

func test(s string) {
	t, err := negate(s)
	if err != nil {
		panic(err)
	}
	fmt.Printf("%v -> %v\n", s, t)
}

func negate(s string) (t string, err error) {
	defer func() {
		if e := recover(); e != nil {
			err = e.(error)
		}
	}()

	s = strings.Replace(s, "NOT", "!", -1)
	s = strings.Replace(s, "AND", "*", -1)
	s = strings.Replace(s, "OR", "+", -1)

	e, err := parser.ParseExpr(s)
	if err != nil {
		return
	}

	e = rewrite(e)
	e = deparen(e, true)
	t = stringify(e)
	return
}

func rewrite(e ast.Expr) ast.Expr {
	switch n := e.(type) {
	case *ast.UnaryExpr:
		n.X = rewrite(n.X)

	case *ast.BinaryExpr:
		switch n.Op {
		case token.ADD:
			n.Op = token.MUL
		case token.MUL:
			n.Op = token.ADD
		}
		n.X = rewrite(n.X)
		n.Y = rewrite(n.Y)
		e = &ast.ParenExpr{X: n}

	case *ast.ParenExpr:
		n.X = rewrite(n.X)

	case *ast.Ident:
		e = &ast.UnaryExpr{Op: token.NOT, X: n}
	}

	return simplify(e)
}

func simplify(e ast.Expr) ast.Expr {
	e = deparen(e, false)
	e = notu(e)
	return e
}

func deparen(e ast.Expr, top bool) ast.Expr {
	p, ok := e.(*ast.ParenExpr)
	if !ok {
		return e
	}

	for {
		x, ok := p.X.(*ast.ParenExpr)
		if !ok {
			break
		}
		p = x
	}

	if top {
		return p.X
	}
	return p
}

func notu(e ast.Expr) ast.Expr {
	var (
		r = []byte("uu")
		l []ast.Expr
		d []int
	)

	if !match(e, &r, &l, &d) {
		return e
	}

	return l[d[1]+1]
}

func match(e ast.Expr, r *[]byte, l *[]ast.Expr, i *[]int) bool {
	if len(*r) == 0 {
		return true
	}
	if (*r)[0] == '.' {
		(*r) = (*r)[1:]
		return true
	}

	switch e := e.(type) {
	case *ast.UnaryExpr:
		if (*r)[0] != 'u' || e.Op != token.NOT {
			return false
		}

		*i = append(*i, len(*l))
		*l = append(*l, e)
		*l = append(*l, e.X)
		(*r) = (*r)[1:]
		return match(e.X, r, l, i)

	case *ast.BinaryExpr:
		if (*r)[0] != 'b' || (e.Op != token.ADD && e.Op != token.MUL) {
			return false
		}

		*i = append(*i, len(*l))
		*l = append(*l, e)
		*l = append(*l, e.X)
		*l = append(*l, e.Y)
		(*r) = (*r)[1:]
		return match(e.X, r, l, i) && match(e.Y, r, l, i)

	case *ast.ParenExpr:
		return match(e.X, r, l, i)

	case *ast.Ident:
		if (*r)[0] != 'i' {
			return false
		}

		*i = append(*i, len(*l))
		*l = append(*l, e)
		(*r) = (*r)[1:]
		return true
	}

	return false
}

func stringify(e ast.Expr) string {
	switch e := e.(type) {
	case *ast.UnaryExpr:
		op := e.Op.String()
		if e.Op == token.NOT {
			op = "NOT"
		}
		return fmt.Sprintf("%v %v", op, stringify(e.X))

	case *ast.BinaryExpr:
		op := e.Op.String()
		switch e.Op {
		case token.ADD:
			op = "OR"
		case token.MUL:
			op = "AND"
		}
		return fmt.Sprintf("%v %v %v", stringify(e.X), op, stringify(e.Y))

	case *ast.ParenExpr:
		return fmt.Sprintf("(%v)", stringify(e.X))

	case *ast.Ident:
		return e.Name
	}

	panic(fmt.Errorf("invalid expression"))
}
