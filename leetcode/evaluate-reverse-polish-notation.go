/*

Evaluate the value of an arithmetic expression in Reverse Polish Notation.

Valid operators are +, -, *, /. Each operand may be an integer or another expression.

Note:

    Division between two integers should truncate toward zero.
    The given RPN expression is always valid. That means the expression would always evaluate to a result and there won't be any divide by zero operation.

*/
package main

import (
	"fmt"
	"strconv"
	"strings"
)

func main() {
	fmt.Println(rpn([]string{"2", "1", "+", "3", "*"}))
	fmt.Println(rpn([]string{"4", "13", "5", "/", "+"}))
	fmt.Println(rpn([]string{"10", "6", "9", "3", "+", "-11", "*", "/", "*", "17", "+", "5", "+"}))
	fmt.Println(rpn([]string{"9 5 +", "210", "+"}))
}

func rpn(expr []string) (r int, err error) {
	defer func() {
		if e := recover(); e != nil {
			err = fmt.Errorf("invalid expression")
		}
	}()

	var v []int
	for _, s := range expr {
		l := len(v)
		switch s {
		case "+":
			v = append(v[:l-2], v[l-2]+v[l-1])
		case "-":
			v = append(v[:l-2], v[l-2]-v[l-1])
		case "*":
			v = append(v[:l-2], v[l-2]*v[l-1])
		case "/":
			v = append(v[:l-2], v[l-2]/v[l-1])
		default:
			n, xerr := strconv.Atoi(s)
			if xerr != nil {
				n, xerr = rpn(strings.Split(s, " "))
			}
			if xerr == nil {
				v = append(v, n)
			}
		}
	}
	return v[0], nil
}
