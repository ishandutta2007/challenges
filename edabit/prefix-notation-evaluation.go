/*

Create a function that takes a mathematical expression in prefix notation as a string and evaluates the expression.

Examples

Prefix("+ 5 4") ➞ 9

Prefix("* 12 2") ➞ 24

Prefix("+ -10 10") ➞ 0

Notes

    The mathematical expression is valid.
    Check the Resources.

*/

package main

import (
	"strconv"
	"strings"
)

func main() {
	assert(prefixeval("- -14 -15") == 1)
	assert(prefixeval("+ 12 13") == 25)
	assert(prefixeval("* 3 3") == 9)
	assert(prefixeval("+ -15 15") == 0)
	assert(prefixeval("- 2200 100") == 2100)
	assert(prefixeval("/ 1000 10") == 100)
	assert(prefixeval("+ 20 20") == 40)
	assert(prefixeval("* - 8 6 10") == 20)
	assert(prefixeval("+ 13 100") == 113)
	assert(prefixeval("* / 40 4 3") == 30)
	assert(prefixeval("- + 200 300 500") == 0)
	assert(prefixeval("+ - * / 100 10 4 100 20") == -40)
	assert(prefixeval("* + 20 2 5") == 110)
	assert(prefixeval("/ + 12 8 * 2 2") == 5)
}

func assert(x bool) {
	if !x {
		panic("assertion failed")
	}
}

func prefixeval(s string) int {
	p := []int{}
	t := strings.Split(s, " ")
	for i := len(t) - 1; i >= 0; i-- {
		v, err := strconv.Atoi(t[i])
		if err == nil {
			p = append(p, v)
			continue
		}

		switch t[i] {
		case "+", "-", "*", "/":
			p = binop(t[i], p)
		}
	}

	r := 0
	if n := len(p); n > 0 {
		r = p[n-1]
	}
	return r
}

func binop(op string, p []int) []int {
	n := len(p)
	if n < 2 {
		return p
	}
	switch op {
	case "+":
		p[n-2] = p[n-1] + p[n-2]
	case "-":
		p[n-2] = p[n-1] - p[n-2]
	case "*":
		p[n-2] = p[n-1] * p[n-2]
	case "/":
		if p[n-2] != 0 {
			p[n-2] = p[n-1] / p[n-2]
		}
	}
	return p[:n-1]
}
