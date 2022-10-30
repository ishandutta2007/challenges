/*

Boolean logic is something all programmers have to deal with, whether we like it or not. Why not automate the task to make it easier?

Your objective, if you choose to accept it, is to make a boolean logic calculator that can parse boolean logic statements. Given:

| = or
* = and
^ = xor
! = not

Take input of 1s and 0s (or T and F) and output the evaluation of that statement.
Try not to use statement evaluators built into your language of choice, like eval.
Your parser should be able to evaluate statements in parentheses as well

*/

package main

import (
	"fmt"
	"go/ast"
	"go/parser"
	"go/token"
	"strconv"
	"strings"
)

func main() {
	fmt.Println(eval("T|F"))
	fmt.Println(eval("1*1"))
	fmt.Println(eval("1*T"))
	fmt.Println(eval("1*(T*F)"))
	fmt.Println(eval("!F"))
	fmt.Println(eval("!T*T*T"))
}

func eval(s string) (b bool, err error) {
	defer func() {
		if xerr := recover(); xerr != nil {
			err = fmt.Errorf("invalid boolean expression")
		}
	}()

	s = strings.Replace(s, "*", "&", -1)
	e, err := parser.ParseExpr(s)
	if err != nil {
		return
	}
	return walk(e), nil
}

func walk(e ast.Expr) bool {
	switch e := e.(type) {
	case *ast.BinaryExpr:
		a := walk(e.X)
		b := walk(e.Y)
		switch e.Op {
		case token.AND:
			return a && b
		case token.OR:
			return a || b
		case token.XOR:
			return truth(a)^truth(b) != 0
		}

	case *ast.UnaryExpr:
		b := walk(e.X)
		switch e.Op {
		case token.NOT:
			return !b
		}

	case *ast.ParenExpr:
		return walk(e.X)

	case *ast.Ident:
		return parsebool(e.Name)

	case *ast.BasicLit:
		return parsebool(e.Value)
	}

	panic("invalid boolean expression")
}

func truth(x bool) int {
	if x {
		return 1
	}
	return 0
}

func parsebool(s string) bool {
	b, err := strconv.ParseBool(s)
	if err != nil {
		panic(err)
	}
	return b
}
