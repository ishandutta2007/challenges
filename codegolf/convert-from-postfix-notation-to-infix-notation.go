/*

This question may not be that creative, but I believe that it is different enough to pose a new challenge.

The Challenge
Your challenge is to write the shortest program possible that can take any valid expression in Reverse Polish Notation and convert it to infix notation that obeys the order of operations and has the necessary parentheses.

Input
Your program will receive a valid RPN expression on STDIN. This expression will consist of numbers and operators.
There can be an arbitrary number of spaces between each item, but there will always be a space between two numbers.
Likewise, there will never be a space within a number. Here is a formal grammer description, stolen and modified from the linked question above.

expression := expression expression operator | number
operator   := "+" | "-" | "*" | "/" | "^"
number     := digit number | digit
digit      := "0" | "1" | "2" | "3" | "4" | "5" | "6" | "7" | "8" | "9"
Here are some simple examples

2 3 -10000 +
16 4    12 3 / * -
1 2 +2 3 +^
In the first example, that is not a negation sign, it is a subtraction operator.

Output
Your program should output an equivalent infix expression to STDOUT, which should be a valid infix expression, with numbers, operators, and parentheses.

Here is a formal grammer description, again stolen.

expression     := number | subexpression | expression operator expression
subexpression  := "(" expression ")"
operator       := "+" | "-" | "*" | "/"
number         := digit | digit number
digit          := "0" | "1" | "2" | "3" | "4" | "5" | "6" | "7" | "8" | "9"
With infix notation, there must be an order of operations and a way to group subexpressions. The order of operations will be this:

Expressions inside parentheses
Exponents right to left
Multiplication and division (of equal importance) left to right
Addition and subtraction (of equal importance) left to right
As an example, 2^3^2-(2^3)^2 should equal 448.

The output should not contain any unneeded parentheses. ((2+1))-1 should reduce to 2+1-1. Also, you should not evaluate any expression.
You should also not assume the commutative or associative properties. This means that, while the operators will move around, the numbers will always remain in the same order.

Here are the outputs for the above inputs. Note that what would normally be unneeded parenthesis are in the second example: removing them would invoke the associative property.

2-3+10000
16-4*(12/3)
(1+2)^(2+3)
I will add more examples later.

Rules, Regulations, and Notes
This is code golf, standard rules apply.

*/

package main

import (
	"fmt"
	"strings"
	"text/scanner"
)

func main() {
	fmt.Println(post2in("2 3 -10000 +"))
	fmt.Println(post2in("16 4    12 3 / * -"))
	fmt.Println(post2in("1 2 +2 3 +^"))
}

// https://www.geeksforgeeks.org/postfix-to-infix/
func post2in(expr string) string {
	var (
		sc  scanner.Scanner
		stk []string
	)

	sc.Init(strings.NewReader(expr))
	sc.Mode = scanner.ScanInts | scanner.ScanChars
	for {
		tok := sc.Scan()
		if tok == scanner.EOF {
			break
		}

		txt := sc.TokenText()
		switch tok {
		case scanner.Int:
			stk = append(stk, txt)
		default:
			if n := len(stk); n >= 2 {
				stk[n-2] = fmt.Sprintf("(%s%s%s)", stk[n-2], txt, stk[n-1])
				stk = stk[:n-1]
			}
		}
	}
	if len(stk) == 0 {
		return ""
	}
	return stk[0]
}
