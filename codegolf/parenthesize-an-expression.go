/*

Recently I've been writing a new language, to avoid needing to handle order of operations, I simply parenthesize each expression properly to avoid this entirely.

Because parenthesis are at char-codes 40-41, your code will need to be as short as possible.

Examples
1+2*3
(1+(2*3))

2*(3+4)
(2*(3+4))

2*3/4+3
(((2*3)/4)+3)

342*32/8
((342*32)/8)
Rules
The only operations you'll need to handle are: * (multiplication), / (division), + (addition), and - (subtraction).

The order of operations is:
Parenthesis
Multiplication, Division
Adition, Subtraction
You should prefer to go left-right
The input numbers will always be positive integers (see bonuses)
Bonuses
-20% if you handle negation:

3+-5
(3+(-5))
-5% if you allow spaces to be placed inside the input:

3  + 4
(3+4)
-10% if you can handle decimals in the input:

1+.12
(1+.12)
1+0.21/3
(1+(0.21/3))
500 bounty: if you manage to write an answer in Unnamed/Blocks.

*/

package main

import (
	"fmt"
	"go/ast"
	"go/parser"
)

func main() {
	assert(paren("1+2*3") == "(1+(2*3))")
	assert(paren("2*(3+4)") == "(2*(3+4))")
	assert(paren("2*3/4+3") == "(((2*3)/4)+3)")
	assert(paren("342*32/8") == "((342*32)/8)")
	assert(paren("-5") == "-5")
	assert(paren("1+2") == "(1+2)")
}

func assert(x bool) {
	if !x {
		panic("assertion failed")
	}
}

func paren(s string) (r string) {
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
		return walk(e.X)
	case *ast.BinaryExpr:
		return fmt.Sprintf("(%v%v%v)", walk(e.X), e.Op, walk(e.Y))
	case *ast.UnaryExpr:
		return fmt.Sprintf("%v%v", e.Op, walk(e.X))
	case *ast.Ident:
		return e.Name
	case *ast.BasicLit:
		return e.Value
	}
	panic("unsupported expression")
}
