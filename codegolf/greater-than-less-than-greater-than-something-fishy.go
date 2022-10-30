/*

Given a length N string of less-than and greater-than signs (<, >), insert the integers 0 through N at the start and end and in between each pair of signs such that all the inequalities are satisfied.
Output the resulting string. If there are multiple valid outputs, output any one (and just one) of them.

For example

<<><><<

has 7 characters so all the numbers from 0 to 7 inclusive must be inserted. A valid output is

2<3<4>1<5>0<6<7

because all the inequalities taken one at a time

2<3
3<4
4>1
1<5
5>0
0<6
6<7

are true.

If desired, the output may have spaces surrounding the signs, e.g. 2 < 3 < 4 > 1 < 5 > 0 < 6 < 7.

The shortest code in bytes wins.
Test Cases

The first line after an empty line is the input and the next line(s) are each valid output examples.

[empty string]
0

<
0<1

>
1>0

<<
0<1<2

<>
1<2>0

><
1>0<2
2>0<1

>>
2>1>0

<<<
0<1<2<3

><>
1>0<3>2

>><
3>2>0<1
3>1>0<2
2>1>0<3

>>>
3>2>1>0

>>><<<
3>2>1>0<4<5<6
6>3>1>0<2<4<5
4>2>1>0<3<5<6
4>3>1>0<2<5<6

<<><><<
2<3<4>1<5>0<6<7

>><><>>
7>6>0<5>1<4>3>2

<<<<<<<<<<<<<<
0<1<2<3<4<5<6<7<8<9<10<11<12<13<14

>><<<<><>><><<
6>5>4<7<8<9<10>3<11>2>1<12>0<13<14
14>5>4<7<8<9<10>3<11>2>1<12>0<13<6

*/

package main

import (
	"bytes"
	"fmt"
	"go/ast"
	"go/parser"
	"go/token"
	"math/rand"
	"strconv"
	"strings"
	"text/scanner"
	"time"
)

func main() {
	test("")
	test("<")
	test(">")
	test("<<")
	test("<>")
	test("><")
	test(">>")
	test("<<<")
	test("><>")
	test(">><")
	test(">>>")
	test(">>><<<")
	test("<<><><<")
	test(">><><>>")
	test("<<<<<<<<<<<<<<")
	test(">><<<<><>><><<")
	test("<><<>>><<")

	rand.Seed(time.Now().UnixNano())
	for i := 1; i <= 1000; i++ {
		test(inequality(i))
	}
}

func test(s string) {
	p := fishies(s)
	l := logicize(p)
	fmt.Println(p)
	e, err := parser.ParseExpr(l)
	assert(err == nil)
	assert(eval(e) == true)
}

func assert(x bool) {
	if !x {
		panic("assertion failed")
	}
}

func inequality(n int) string {
	p := make([]byte, n)
	for i := range p {
		p[i] = '<'
		if rand.Intn(2) != 0 {
			p[i] = '>'
		}
	}
	return string(p)
}

func eval(e ast.Expr) bool {
	switch e := e.(type) {
	case *ast.BinaryExpr:
		switch e.Op {
		case token.LAND:
			return eval(e.X) && eval(e.Y)
		case token.LSS:
			return number(e.X) < number(e.Y)
		case token.GTR:
			return number(e.X) > number(e.Y)
		default:
			panic(fmt.Errorf("unsupported binary operator %v", e.Op))
		}
	case *ast.ParenExpr:
		return eval(e.X)
	default:
		panic(fmt.Errorf("unsupported type %T", e))
	}
}

func number(e ast.Expr) int {
	n := e.(*ast.BasicLit)
	v, _ := strconv.Atoi(n.Value)
	return v
}

func logicize(s string) string {
	var (
		w  = new(bytes.Buffer)
		sc scanner.Scanner
		p  [3]string
	)

	sc.Init(strings.NewReader(s))
	for i, f := 0, 0; ; {
		tok := sc.Scan()
		if tok == scanner.EOF {
			break
		}

		p[i], i = sc.TokenText(), i+1
		if i == len(p) {
			if f != 0 {
				fmt.Fprintf(w, "&&")
			}
			fmt.Fprintf(w, "(%s)", strings.Join(p[:], ""))
			p[0], i, f = p[i-1], 1, 1
		}
	}

	r := w.String()
	if r == "" {
		return "0<1"
	}

	return w.String()
}

/*

@Martin Ender
A simple way to find a valid permutation is to start by inserting the numbers from 0 to N in order, and then to reverse the numbers surrounding each substring of >s. Take <><<>>><< as an example:

0<1>2<3<4>5>6>7<8<9
  ---   -------      these sections are wrong, so we reverse them
0<2>1<3<7>6>5>4<8<9

*/

func fishies(s string) string {
	w := new(bytes.Buffer)
	v := make([]int, len(s)+1)
	for i := range v {
		v[i] = i
	}

	for i, j := 0, 0; i < len(s); i = j {
		j = i
		for j < len(s) && s[i] == s[j] {
			j++
		}

		if s[i] == '>' {
			rev(v, i, j)
		}
	}
	for i := range v {
		fmt.Fprintf(w, "%d", v[i])
		if i < len(s) {
			fmt.Fprintf(w, "%c", s[i])
		}
	}

	return w.String()
}

func rev(v []int, i, j int) {
	for ; i < j; i, j = i+1, j-1 {
		v[i], v[j] = v[j], v[i]
	}
}
