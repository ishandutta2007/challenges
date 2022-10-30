/*

Given an infix expression, determine whether all constants are of the same type.

Operators will consist only of these dyadic operators: +-/*

Your program or function should take a valid expression string as input, and output a truthy value if the constants in the expression are of the same time, and a falsey value otherwise.

The expression will consist solely of constants, and may contain any of the following types:

String, of the form "String" (Always double quotes, can be empty, no escape characters, may contain any ASCII text)
Integer, of the form 14 (Always positive or zero)
Float, of the form 7.3f (Always positive or zero, always has a decimal component, eg 14.0f)
Byte, of the form 0x42 (0-255, Always 2 hexadecimal characters)
Boolean, of the form true (true or false, case insensitive)
The expression will not contain parentheses, as order of operation doesn't affect type when no type coercion is present.

A lone constant with no operators is a valid expression.

An empty expression is not a valid expression.

You may assume that the expression string contains no whitespace outside of string literals.
Note: Alternatively you may assume that there will always be spaces between constants and operators, as seen in the testcases. If you make this assumption, please specify as such in your answer

You do not have to handle invalid expressions such as 1 +.

Scoring
This is code-golf, so fewest bytes wins!

Test cases
(Whitespace added for readability)

2 + 3
True

"Hello" / "World"
True

true * false
True

"Hello" + 4
False

"Hello" + "4"
True

3 + 2.4f / 8
False

0xff * 0xff
True

0xff + 2
False

6
True

" " + ""
True

"4 + false" + "word"
True

*/

package main

import (
	"bytes"
	"go/ast"
	"go/parser"
	"go/token"
	"strconv"
	"strings"
	"unicode"
)

func main() {
	assert(typecheck(`2 + 3`) == true)
	assert(typecheck(`"Hello" / "World"`) == true)
	assert(typecheck(`true * false`) == true)
	assert(typecheck(`"Hello" + 4`) == false)
	assert(typecheck(`"Hello" + "4"`) == true)
	assert(typecheck(`3 + 2.4f / 8`) == false)
	assert(typecheck(`0xff * 0xff`) == true)
	assert(typecheck(`0xff + 2`) == false)
	assert(typecheck(`6`) == true)
	assert(typecheck(`" " + ""`) == true)
	assert(typecheck(`"4 + false" + "word"`) == true)
}

func assert(x bool) {
	if !x {
		panic("assertion failed")
	}
}

func clean(s string) string {
	w := new(bytes.Buffer)
	l := rune(0)
	for _, r := range s {
		if !(r == 'f' && unicode.IsDigit(l)) {
			w.WriteRune(r)
		}
		l = r
	}
	return w.String()
}

func typecheck(s string) bool {
	defer func() { recover() }()

	e, err := parser.ParseExpr(clean(s))
	if err != nil {
		return false
	}
	return walk(e) > 0
}

func walk(e ast.Expr) int {
	switch e := e.(type) {
	case *ast.BinaryExpr:
		x := walk(e.X)
		y := walk(e.Y)
		switch e.Op {
		case token.ADD, token.SUB, token.MUL, token.QUO:
			if x != y {
				return 0
			}
			return x
		}

	case *ast.Ident:
		switch strings.ToLower(e.Name) {
		case "true", "false":
			return 'b'
		}

	case *ast.BasicLit:
		_, err := strconv.Atoi(e.Value)
		if err == nil {
			return 'i'
		}

		_, err = strconv.ParseInt(e.Value, 0, 0)
		if err == nil {
			return 'x'
		}

		_, err = strconv.ParseFloat(e.Value, 64)
		if err == nil {
			return 'f'
		}

		if strings.HasPrefix(e.Value, `"`) {
			return 's'
		}
	}

	panic("unsupported expression")
}
