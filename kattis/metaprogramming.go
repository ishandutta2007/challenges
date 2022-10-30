/*

EIGER is a brand-new, made-up computer language.
It’s very exciting, and very simple! EIGER only allows the programmer to do two things: define a name for an integer, and compare two names.
Write a metaprogram – a program which can simulate the EIGER language.

Input

Input consists of one command per line, up to 10000 commands, ending at end of file.
A definition command has the form define i x, where i is an integer in the range [−10000,10000] 1and x is a string of up to 20 lowercase alphabet characters (a–z).
A comparison command has the form eval x y z, where x and z are strings of the same format as in definitions, and y is one of <, >, or =.

Output

For each definition, use the string as a label for the given integer, but don’t output anything. Redefinitions are allowed.
For each comparison, state whether it is true or false, depending on the current definitions. If the result is not known, output ‘undefined’.

*/

package main

import (
	"fmt"
	"strconv"
	"strings"
)

func main() {
	test([]string{
		"define 5 hellothere",
		"define 6 goodbye",
		"eval hellothere < goodbye",
		"eval hellothere > goodbye",
		"eval hellothere = goodbye",
		"eval hellothere = hi",
		"define 5 hi",
		"eval hellothere = hi",
		"define 6 hi",
		"eval hellothere = hi",
	})
}

func test(lines []string) {
	e := NewEiger()
	for _, l := range lines {
		r, err := e.Line(l)
		if err != nil {
			panic(fmt.Errorf("%s: %v", l, err))
		}
		if r != "success" {
			fmt.Println(r)
		}
	}
}

type Eiger struct {
	vars map[string]int
}

func NewEiger() *Eiger {
	return &Eiger{
		vars: make(map[string]int),
	}
}

func (c *Eiger) Line(line string) (string, error) {
	ftab := map[string]string{
		"define": "is",
		"eval":   "scs",
	}
	toks := strings.Split(line, " ")

	fn := toks[0]
	arg, ok := ftab[fn]
	if !ok {
		return "error", fmt.Errorf("unknown operation %q", fn)
	}
	if len(arg) != len(toks)-1 {
		return "error", fmt.Errorf("invalid number of arguments passed")
	}

	var (
		iv  [4]int
		cv  [4]rune
		sv  [4]string
		err error
	)
	for i := range arg {
		switch arg[i] {
		case 'i':
			_, err = fmt.Sscan(toks[i+1], &iv[i])

		case 'c':
			cv[i] = rune(toks[i+1][0])

		case 's':
			_, err = fmt.Sscan(toks[i+1], &sv[i])
		}
		if err != nil {
			return "error", fmt.Errorf("invalid argument %d", i)
		}
	}

	r := "success"
	switch fn {
	case "define":
		c.vars[sv[1]] = iv[0]

	case "eval":
		x, xf := c.vars[sv[0]]
		y, yf := c.vars[sv[2]]
		if !xf || !yf {
			r = "undefined"
			break
		}

		switch cv[1] {
		case '<':
			r = strconv.FormatBool(x < y)
		case '>':
			r = strconv.FormatBool(x > y)
		case '=':
			r = strconv.FormatBool(x == y)
		default:
			return "error", fmt.Errorf("invalid operation %q", cv[1])
		}
	}

	return r, nil
}
