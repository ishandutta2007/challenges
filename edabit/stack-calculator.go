/*

A stack machine processes instructions by pushing and popping values to an internal stack. A simple example of this is a calculator.

The argument passed to run(instructions) will always be a string containing a series of instructions.
The instruction set of the calculator will be this:

    +: Pop the last 2 values from the stack, add them, and push the result onto the stack.
    -: Pop the last 2 values from the stack, subtract the lower one from the topmost one, and push the result.
    *: Pop the last 2 values, multiply, and push the result.
    /: Pop the last 2 values, divide the topmost one by the lower one, and push the result.
    DUP: Duplicate (not double) the top value on the stack.
    POP: Pop the last value from the stack and discard it.
    PSH: Performed whenever a number appears as an instruction. Push the number to the stack.
    Any other instruction (for example, a letter) should result in the value "Invalid instruction: [instruction]"

Examples

StackCalc("") ➞ 0

StackCalc("5 6 +") ➞ 11

StackCalc("3 DUP +") ➞ 6

StackCalc("6 5 5 7 * - /") ➞ 5

StackCalc("x y +") ➞ Invalid instruction: x

Notes

    If there are no instructions, the value should remain 0.
    The return value of get value() should be the topmost value on the stack.

*/

package main

import (
	"fmt"
	"strconv"
	"strings"
	"unicode"
)

func main() {
	test("12", 12)
	test("5 6 +", 11)
	test("3 6 -", 3)
	test("3 DUP +", 6)
	test("2 5 - 5 + DUP +", 16)
	test("9 14 DUP + - 3 POP", 19)
	test("1 2 3 4 5 POP POP POP", 2)
	test("13 DUP 4 POP 5 DUP + DUP + -", 7)
	test("6 5 5 7 * - /", 5)
	test("4 2 4 * 3 + 5 + / 5 -", 1)
	test("x", "Invalid instruction: x")
	test("4 6 + x", "Invalid instruction: x")
	test("y x *", "Invalid instruction: y")
	test("", 0)
	test("4 POP", 0)
}

func test(s string, r interface{}) {
	v, err := stack(s)
	fmt.Println(v, err)
	switch u := r.(type) {
	case int:
		assert(u == v)
	case string:
		assert(err != nil)
		assert(err.Error() == u)
	}
}

func assert(x bool) {
	if !x {
		panic("assertion failed")
	}
}

func stack(s string) (int, error) {
	var (
		p []int
		t string
	)

	r := strings.NewReader(s)
	for {
		_, err := fmt.Fscan(r, &t)
		if err != nil {
			break
		}

		if unicode.IsDigit(rune(t[0])) {
			v, _ := strconv.Atoi(t)
			p = append(p, v)
			continue
		}

		switch t {
		case "+", "-", "*", "/":
			p = binop(t, p)
		case "DUP", "POP":
			p = unop(t, p)
		default:
			return 0, fmt.Errorf("Invalid instruction: %v", t)
		}
	}

	v := 0
	if n := len(p); n > 0 {
		v = p[n-1]
	}
	return v, nil
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

func unop(op string, p []int) []int {
	n := len(p)
	if n < 1 {
		return p
	}

	switch op {
	case "DUP":
		p = append(p, p[n-1])
	case "POP":
		p = p[:n-1]
	}
	return p
}
