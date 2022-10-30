/*

Background
The number of values for a given type is called the cardinality of that type, and that of type T is written as |T|.

Haskell and a few other languages have a certain set of enum types, each of which has a small finite number of values (the exact names vary, so this challenge uses some arbitrarily chosen names).

Name  | Cardinality
------+-------------
Never | 0
Unit  | 1
Bool  | 2 (true or false)
Order | 3 (LT, EQ, or GT)
And they also have some derived types which have one or more type parameters.
Their cardinality depends on which types they get as parameters (written as T and U in the table below).
Func(T,U) represents the function commonly written as T -> U, i.e. a function that takes a parameter of type T and returns a value of type U.

Name(Params) | Cardinality
-------------+-------------
Option(T)    | |T| + 1     (some value from T, or absence)
Either(T,U)  | |T| + |U|   (some value from T or some value from U)
Pair(T,U)    | |T| * |U|   (any combination of values from T and U)
Func(T,U)    | |U| ** |T|  (any combination of U for every value of T)
Note: A "function" here is to be understood as a mathematical concept rather than a programming one. A mathematical function Func(T,U) maps every possible value of T to some value of U, disregarding the "how". For programmers, it is OK to think of it as functions of the form of (in Haskell-like pseudocode):

\(x :: T) -> case x of
  value1OfT -> someValue1OfU
  value2OfT -> someValue2OfU
  ...
  valueXOfT -> someValueXOfU
with all cases provided.

For example, Option(Never) has cardinality 1, and Func(Bool,Order) has cardinality 3**2 = 9. Func(Never,Never) has cardinality 1; 0**0 is defined to be 1 in this system.

A type parameter can itself be a derived type, so Pair(Func(Never,Never),Pair(Either(Bool,Bool),Option(Order))) is also a valid type, which has cardinality of (0**0) * ((2+2) * (3+1)) = 16.

For this challenge, assume that no types other than the 8 presented above are available.

Challenge
Given a string that represents a valid type in this system, output its cardinality. You can assume the input does not contain spaces.

Standard code-golf rules apply. The shortest code in bytes wins.

Test cases
Never -> 0
Unit -> 1
Bool -> 2
Order -> 3
Func(Never,Never) -> 1
Func(Unit,Never) -> 0
Option(Unit) -> 2
Option(Order) -> 4
Either(Bool,Bool) -> 4
Either(Bool,Order) -> 5
Pair(Bool,Order) -> 6
Pair(Func(Never,Never),Pair(Either(Bool,Bool),Option(Order))) -> 16
Func(Func(Order,Order),Order) -> 7625597484987

*/

package main

import (
	"fmt"
	"go/ast"
	"go/parser"
	"math/big"
)

func main() {
	test("Never", "0")
	test("Unit", "1")
	test("Bool", "2")
	test("Order", "3")
	test("Func(Never,Never)", "1")
	test("Func(Unit,Never)", "0")
	test("Option(Unit)", "2")
	test("Option(Order)", "4")
	test("Either(Bool,Bool)", "4")
	test("Either(Bool,Order)", "5")
	test("Pair(Bool,Order)", "6")
	test("Pair(Func(Never,Never),Pair(Either(Bool,Bool),Option(Order)))", "16")
	test("Func(Func(Order,Order),Order)", "7625597484987")
}

func test(s, r string) {
	p := cardinality(s)
	fmt.Println(p)
	assert(p.String() == r)
}

func assert(x bool) {
	if !x {
		panic("assertion failed")
	}
}

func cardinality(s string) (n *big.Int) {
	defer func() {
		if err := recover(); err != nil {
			n = big.NewInt(-1)
		}
	}()

	e, err := parser.ParseExpr(s)
	if err != nil {
		return big.NewInt(-1)
	}

	return walk(e)
}

func walk(e ast.Expr) *big.Int {
	switch e := e.(type) {
	case *ast.CallExpr:
		arity := map[string]int{
			"Option": 1,
			"Either": 2,
			"Pair":   2,
			"Func":   2,
		}

		f, ok := e.Fun.(*ast.Ident)
		if !ok {
			panic("invalid function")
		}
		n, ok := arity[f.Name]
		if !ok || n != len(e.Args) {
			panic("invalid function")
		}

		var v []*big.Int
		for _, arg := range e.Args {
			v = append(v, walk(arg))
		}

		r := v[0]
		switch f.Name {
		case "Option":
			r.Add(r, big.NewInt(1))
		case "Either":
			r.Add(r, v[1])
		case "Pair":
			r.Mul(r, v[1])
		case "Func":
			r.Exp(v[1], r, nil)
		}
		return r

	case *ast.Ident:
		switch e.Name {
		case "Never":
			return big.NewInt(0)
		case "Unit":
			return big.NewInt(1)
		case "Bool":
			return big.NewInt(2)
		case "Order":
			return big.NewInt(3)
		default:
			panic("invalid type")
		}

	default:
		panic("invalid expression")
	}
}
