/*

Resistors are electrical components that add resistance to a circuit. Resistance is measured in ohms. When resistors are connected in series, the total resistance is merely the sum of the individual resistances:

Rtotal = R1 + R2 + R3 + ...

When resistors are connected in parallel, the reciprocal of the total resistance is equal to the sum of the reciprocals of the individual resistances:

1/(Rtotal) = 1/R1 + 1/R2 + 1/R3 + ...

Let's specify that series resistors be designated by enclosing them in parentheses, and parallel resistors by enclosing them in square brackets. Now we can calculate the equivalent resistance of the network:

    (2, 3, 6) = 11 ohms
    [2, 3, 6]= 1 ohm

Nesting these structures in the same way tuples and arrays are nested allows us to model complex resistor networks.

Create a function that takes a nested network as a string and returns the equivalent resistance of the network. Round results to the nearest tenth of an ohm.
Examples

resist("(10, [20, 30])") ➞ 22.0
// 10 in series with [20, 30] in parallel.

resist("[10, (20, 30)]") ➞ 8.3
// 10 in parallel with (20, 30) in series.

resist("([10, 20], (30, 40))") ➞ 76.7
// [10, 20] in parallel in series with (30, 40) in series.

resist("(1, [12, 4, (1, [10, (2, 8)])])") ➞ 3.0

resist("(6, [8, (4, [8, (4, [6, (8, [6, (10, 2)])])])])") ➞ 10

Notes

This is the schematic for the last example above:
https://www.electronics-tutorials.ws/wp-content/uploads/2018/05/resistor-res54.gif

*/

package main

import (
	"math"
	"strconv"
	"strings"
	"text/scanner"
)

func main() {
	assert(eq(resist("(2, 3, 6)"), 11))
	assert(eq(resist("[2, 3, 6]"), 1))
	assert(eq(resist("[10, 20, [30, (40, 50), 60, (70, 80)], 90]"), 4.4))
	assert(eq(resist("(1, [12, 4, (1, [10, (2, 8)])])"), 3))
	assert(eq(resist("(10, [20, 30])"), 22))
	assert(eq(resist("[10, (20, 30)]"), 8.3))
	assert(eq(resist("[22, 6, (10, 18, [33, 15]), (10, [63, 50], 45)]"), 4.0))
	assert(eq(resist("[([(470, 1000), 330], 470), 680]"), 354.3))
	assert(eq(resist("([10, 20], (30, 40))"), 76.7))
	assert(eq(resist("(1, [12, 4, (1, [10, (2, 8)])])"), 3))
	assert(eq(resist("([([(470, 680), 330], 1000), 470], 680)"), 1022))
	assert(eq(resist("(6, [8, (4, [8, (4, [6, (8, [6, (10, 2)])])])])"), 10))
}

func resist(s string) float64 {
	var (
		sc      scanner.Scanner
		sp      []rune
		lasttok rune
	)
	res := make([]float64, 1)

	sc.Init(strings.NewReader(s))
loop:
	for {
		tok := sc.Scan()
		switch tok {
		case scanner.EOF:
			break loop

		case scanner.Int, scanner.Float:
			l := len(sp)
			if lasttok == scanner.Int || lasttok == scanner.Float || l == 0 {
				return -1
			}
			v, err := strconv.ParseFloat(sc.TokenText(), 64)
			if err != nil {
				return -2
			}
			if sp[l-1] == '[' {
				v = 1 / v
			}
			res[l] += v

		case '(', '[':
			sp = append(sp, tok)
			res = append(res, 0)

		case ')', ']':
			l := len(sp)
			if l == 0 {
				return -3
			}
			if tok == ')' && sp[l-1] != '(' {
				return -4
			}
			if tok == ']' && sp[l-1] != '[' {
				return -5
			}
			if tok == ']' {
				res[l] = 1 / res[l]
			}
			sp = sp[:l-1]

			l = len(sp)
			v := res[l+1]
			if l > 0 && sp[l-1] == '[' {
				v = 1 / v
			}
			res[l] += v
			res = res[:l+1]

		case ',':
			if !(lasttok == scanner.Int || lasttok == scanner.Float || lasttok == ']' || lasttok == ')') {
				return -6
			}

		default:
			return -7
		}

		lasttok = tok
	}
	if len(sp) > 0 {
		return -1
	}

	return res[0]
}

func eq(x, y float64) bool {
	return math.Abs(x-y) < 1e-1
}

func assert(x bool) {
	if !x {
		panic("assertion failed")
	}
}
