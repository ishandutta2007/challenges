/*

Infix notation is a method of printing mathematical expressions where each operator sits between its two arguments, such as (5⋅4)+3.

Prefix notation is a method of printing expressions where operators sit before their arguments. The equivalent of the above is +*543. It's a bit harder to understand than infix, but here's a sort of explanation:

+*543 # Expression
+     # Adding
 *54  # Expression
 *    # The product of
  5   # 5 and
   4  # 4
    3 # And 3

Your challenge is to, given an expression in prefix, convert it to infix notation.

The input will contain lowercase letters and digits, and can be assumed to be a valid expression - that is, each operator (letter) has exactly two operands and there is only one value left at the end

The output should be a valid expression in infix - that is, it should be an expression in the following recursive grammar:

digit := 0-9
operator := a-z
expression := digit | (expression operator expression)

That is, each expression should be a digit, or two expressions joined by an operator and wrapped in parentheses for unambiguity.

Example

Note: Spaces are for clarity and are optional in the input and output.

Expression: x 3 u f 4 3 h 5 9
You could read this as x(3, u(f(4, 3), h(5, 9))) or something.

The x is taking 3 and the expression with a u as operands:

Result: (3 x ...)
Expression: u f 4 3 h 5 9

The u is taking the expression with a f and the expression with an h as operands.

Result: (3 x ((...) u (...)))
Expression: f 4 3

The f is taking 4 and 3 as operands.

Result: (3 x ((4 f 3) u (...)))
Expression: h 5 9

The h is taking 5 and 9 as operands.

Expression: (3 x ((4 f 3) u (5 h 9)))

And that's the result! Spaces are optional.

Testcases

As usual, these are manually created, so comment if I've stuffed these up.

a34 -> (3a4)
ba567 -> ((5a6)b7)
cba1234 -> (((1a2)b3)c4)
a1b23 -> (1a(2b3))
a1fcb46d4e95ig6h42kj32l68 -> (1a(((4b6)c(4d(9e5)))f((6g(4h2))i((3j2)k(6l8)))))

Standard code-golf rules apply.

*/

package main

import "fmt"

func main() {
	assert(pre2in("a34") == "(3a4)")
	assert(pre2in("ba567") == "((5a6)b7)")
	assert(pre2in("cba1234") == "(((1a2)b3)c4)")
	assert(pre2in("a1b23") == "(1a(2b3))")
	assert(pre2in("a1fcb46d4e95ig6h42kj32l68") == "(1a(((4b6)c(4d(9e5)))f((6g(4h2))i((3j2)k(6l8)))))")
}

func assert(x bool) {
	if !x {
		panic("assertion failed")
	}
}

func pre2in(s string) string {
	var p []string
	for i := len(s) - 1; i >= 0; i-- {
		if n := len(p); '0' <= s[i] && s[i] <= '9' {
			p = append(p, fmt.Sprintf("%c", s[i]))
		} else if n >= 2 {
			p[n-2] = fmt.Sprintf("(%s%c%s)", p[n-1], s[i], p[n-2])
			p = p[:n-1]
		}
	}

	if len(p) != 1 {
		return ""
	}
	return p[0]
}
