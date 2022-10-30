/*

Introduction
The four basic math operators (+, -, *, /) can be reduced to just two, due to the fact that:

x + y = x - (-y)
x * y = x / (1/y), y != 0
x * 0 = 0/x
Challenge
The challenge is to take input as a "string" containing:

Numbers
Single character variables ("x", "y")
The four basic math operators (+, -, *, /)
Parenthesis
and output a string manipulated so that it would produce the same mathematical result as the input, but containing only the mathematical symbols '-' and '/'

Specifics
Input can be in any acceptable form (file, STDIN, etc.) and may be represented as a string or character array (but not an array of arrays)
Output can be in any acceptable form (file, STDIN, etc.) and may be represented as a string or character array (but not an array of arrays)
You must recognize and maintain balanced parenthesis
Standard loopholes are disallowed
It is your choice if you want to represent x + y as x - -y or x - (-y)
You must maintain the order of operations
You never have to handle invalid input
Input can be empty or a single number/variable, in that case the program should output the input
Note: You do not have to use the substitutions in the introduction, so long as input = output, your program could change 2 * 2 to 8/2, if you wanted
You can assume that "0" is the only way a zero will appear in the equation (I.e. you don't have to handle 1 * (4 - 4))
Suggestion: to test your program, go to this website type in input = output, where input is the input, and output is the output, and if the result is "true" your program handled that case successfully (example, example)
Test Cases
Below are some test cases, input as a single string and output as a single string.

x + y
x - (-y)

x * y
x / (1/y)

x / y
x / y

x - y
x - y

1
1

5
5

-6
-6

+x
x

1 + (x * 4) - (512 * 3)
1 - (-(x / (1/4))) - (512 / (1/3))

1 - 3 / 4 + l / g
1 - 3/4 - (-(l / g))

5 * 0 / 2
0/5 / 2

(a + g) * 0
0/(a - (-g))

Scoring
It's code-golf, so shortest answer in bytes wins. Ties are resolved by first-post.

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
	test("x + y", "x - (-y)")
	test("x * y", "x / (1/y)")
	test("x / y", "x / y")
	test("x - y", "x - y")
	test("1", "1")
	test("5", "5")
	test("-6", "-6")
	test("+x", "x")
	test("1 + (x * 4) - (512 * 3)", "1 - (-(x / (1/4))) - (512 / (1/3))")
	test("1 - 3 / 4 + l / g", "1 - 3/4 - (-l / g)")
	test("5 * 0 / 2", "0/5 / 2")
	test("(a + g) * 0", "0/(a - (-g))")
}

func assert(x bool) {
	if !x {
		panic("assertion failed")
	}
}

func test(s, r string) {
	p := rewrite(s)
	fmt.Println(p)
	p = strings.Replace(p, " ", "", -1)
	r = strings.Replace(r, " ", "", -1)
	assert(p == r)
}

func rewrite(s string) (r string) {
	defer func() {
		if err := recover(); err != nil {
			r = s
		}
	}()

	e, err := parser.ParseExpr(s)
	if err != nil {
		return s
	}
	return walk(e)
}

func walk(e ast.Expr) string {
	switch e := e.(type) {
	case *ast.ParenExpr:
		return fmt.Sprintf("(%v)", walk(e.X))
	case *ast.UnaryExpr:
		x := walk(e.X)
		if e.Op == token.ADD {
			return x
		}
		return fmt.Sprintf("%v%v", e.Op, x)
	case *ast.BinaryExpr:
		x := walk(e.X)
		y := walk(e.Y)
		switch e.Op {
		case token.ADD:
			return fmt.Sprintf("%v - (-%v)", x, y)
		case token.MUL:
			switch {
			case x == "0" && y == "0":
				return "0"
			case x == "0" && y != "0":
				return fmt.Sprintf("0/%v", y)
			case x != "0" && y == "0":
				return fmt.Sprintf("0/%v", x)
			default:
				return fmt.Sprintf("%v / (1/%v)", x, y)
			}

		default:
			return fmt.Sprintf("%v %v %v", x, e.Op, y)
		}
	case *ast.Ident:
		return e.Name
	case *ast.BasicLit:
		return e.Value
	}
	panic("unsupported expression")
}
