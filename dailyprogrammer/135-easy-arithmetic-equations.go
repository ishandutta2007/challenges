/*

Unix, the famous multitasking and multi-user operating system, has several standards that defines Unix commands, system calls, subroutines, files, etc.
Specifically within Version 7 (though this is included in many other Unix standards), there is a game called "arithmetic". To quote the Man Page:

Arithmetic types out simple arithmetic problems, and waits for an answer to be typed in.
If the answer is correct, it types back "Right!", and a new problem. If the answer is wrong, it replies "What?", and waits for another answer.
Every twenty problems, it publishes statistics on correctness and the time
required to answer.

Your goal is to implement this game, with some slight changes, to make this an [Easy]-level challenge.
You will only have to use three arithmetic operators (addition, subtraction, multiplication) with four integers.
An example equation you are to generate is "2 x 4 + 2 - 5".

Author: nint22

Formal Inputs & Outputs
Input Description
The first line of input will always be two integers representing an inclusive range of integers you are to pick from when filling out the constants of your equation.
After that, you are to print off a single equation and wait for the user to respond. The user may either try to solve the equation by writing the integer result into the console, or the user may type the letters 'q' or 'Q' to quit the application.

Output Description
If the user's answer is correct, print "Correct!" and randomly generate another equation to show to the user.
Otherwise print "Try Again" and ask the same equation again. Note that all equations must randomly pick and place the operators, as well as randomly pick the equation's constants (integers) from the given range.
You are allowed to repeat constants and operators. You may use either the star '*' or the letter 'x' characters to represent multiplication.

Sample Inputs & Outputs
Sample Input / Output
Since this is an interactive application, lines that start with '>' are there to signify a statement from the console to the user, while any other lines are from the user to the console.

0 10
> 3 * 2 + 5 * 2
16
> Correct!
> 0 - 10 + 9 + 2
2
> Incorrect...
> 0 - 10 + 9 + 2
3
> Incorrect...
> 0 - 10 + 9 + 2
1
> Correct!
> 2 * 0 * 4 * 2
0
> Correct!
q

*/

package main

import (
	"bufio"
	"bytes"
	"fmt"
	"go/ast"
	"go/parser"
	"go/token"
	"io"
	"math/rand"
	"os"
	"strconv"
	"strings"
	"time"
)

func main() {
	rand.Seed(time.Now().UnixNano())
	play()
}

func play() {
	const (
		correct   = "> Correct!"
		incorrect = "> Incorrect..."
	)

	lo, hi, eof := readrange()
	if eof {
		return
	}

	eq := equation(4, lo, hi)
	for {
		fmt.Printf("> %s\n", eq)

		val, err := readinput()
		if err == io.EOF {
			break
		}
		if err != nil {
			fmt.Println(incorrect)
			continue
		}

		res, err := eval(eq)
		if err != nil {
			fmt.Println(incorrect)
			continue
		}

		if val == res {
			fmt.Println(correct)
			eq = equation(4, lo, hi)
		} else {
			fmt.Println(incorrect)
		}
	}
}

func readrange() (lo, hi int, eof bool) {
	s := bufio.NewScanner(os.Stdin)
	for s.Scan() {
		l := s.Text()
		l = strings.TrimSpace(l)
		n, err := fmt.Sscanf(l, "%d %d", &lo, &hi)
		if err == io.EOF {
			eof = true
			return
		}

		if n == 2 && err == nil && hi >= lo {
			return
		}

		fmt.Printf("?\n")
	}

	eof = true
	return
}

func readinput() (val int, err error) {
	s := bufio.NewScanner(os.Stdin)
	if !s.Scan() {
		err = io.EOF
		return
	}

	l := s.Text()
	l = strings.TrimSpace(l)
	if l == "q" || l == "Q" {
		err = io.EOF
		return
	}

	return strconv.Atoi(l)
}

func equation(vars int, lo, hi int) string {
	const ops = "+-*"

	w := new(bytes.Buffer)
	for i := 0; i < vars; i++ {
		fmt.Fprintf(w, "%d", randrange(lo, hi))
		if i+1 < vars {
			fmt.Fprintf(w, " %c ", ops[rand.Intn(len(ops))])
		}
	}
	return w.String()
}

func randrange(lo, hi int) int {
	return rand.Intn(abs(hi-lo)+1) + lo
}

func abs(x int) int {
	if x < 0 {
		x = -x
	}
	return x
}

func eval(str string) (int, error) {
	e, err := parser.ParseExpr(str)
	if err != nil {
		return 0, err
	}
	return walk(e)
}

func walk(e ast.Expr) (int, error) {
eval:
	switch e := e.(type) {
	case *ast.BasicLit:
		switch e.Kind {
		case token.INT:
			return strconv.Atoi(e.Value)
		}

	case *ast.BinaryExpr:
		x, xe := walk(e.X)
		y, ye := walk(e.Y)
		if xe != nil || ye != nil {
			break eval
		}

		switch e.Op {
		case token.ADD:
			return x + y, nil
		case token.SUB:
			return x - y, nil
		case token.MUL:
			return x * y, nil
		}

	case *ast.UnaryExpr:
		x, err := walk(e.X)
		if err != nil {
			break eval
		}

		switch e.Op {
		case token.ADD:
			return x, nil
		case token.SUB:
			return -x, nil
		}
	}

	return 0, fmt.Errorf("invalid expression")
}
