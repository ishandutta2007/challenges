/*

Solve a given equation and return the value of x in the form of string "x=#value". The equation contains only '+', '-' operation, the variable x and its coefficient.

If there is no solution for the equation, return "No solution".

If there are infinite solutions for the equation, return "Infinite solutions".

If there is exactly one solution for the equation, we ensure that the value of x is an integer.

*/

package main

import (
	"bytes"
	"fmt"
	"go/ast"
	"go/parser"
	"go/token"
	"log"
	"strconv"
	"strings"
	"unicode"
)

func main() {
	fmt.Println(solve("x+5-3+x=6+x-2"))
	fmt.Println(solve("x=x"))
	fmt.Println(solve("2x=x"))
	fmt.Println(solve("2x+3x-6x=x+2"))
	fmt.Println(solve("x=x+2"))
}

func solve(s string) (p string, err error) {
	var r [2]int
	t := strings.Split(s, "=")
	for i, t := range t {
		e, err := parser.ParseExpr(conv(t))
		if err != nil {
			return p, err
		}

		v := eval(e)
		if i == 0 {
			r = v
		} else {
			r[0] -= v[0]
			r[1] -= v[1]
		}
	}

	switch {
	case r[0] == 0 && r[1] == 0:
		p = "Infinite solutions"
	case r[0] == 0:
		p = "No solution"
	default:
		p = fmt.Sprintf("x=%d", -r[1]/r[0])
	}
	return
}

func eval(e ast.Expr) (r [2]int) {
	switch e := e.(type) {
	case *ast.BinaryExpr:
		x := eval(e.X)
		y := eval(e.Y)
		switch e.Op {
		case token.ADD:
			r[0] = x[0] + y[0]
			r[1] = x[1] + y[1]
		case token.SUB:
			r[0] = x[0] - y[0]
			r[1] = x[1] - y[1]
		case token.MUL:
			r[0] = x[1] * y[0]
		default:
			log.Fatalf("unknown binary op %v", e.Op)
		}
	case *ast.UnaryExpr:
		r = eval(e.X)
		switch e.Op {
		case token.ADD:
		case token.SUB:
			r[0], r[1] = -r[0], -r[1]
		default:
			log.Fatalf("unknown unary op %v", e.Op)
		}
	case *ast.BasicLit:
		r[1], _ = strconv.Atoi(e.Value)
	case *ast.Ident:
		r[0] = 1
	default:
		log.Fatalf("unknown type %T", e)
	}
	return
}

func conv(s string) string {
	b := new(bytes.Buffer)
	for i := 0; i < len(s); i++ {
		if s[i] == 'x' && i > 0 && unicode.IsDigit(rune(s[i-1])) {
			b.WriteByte('*')
		}
		b.WriteByte(s[i])
	}
	return b.String()
}
