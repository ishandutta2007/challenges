/*

Create a function that expands a decimal number into a string as shown below:

25.24 ➞ "20 + 5 + 2/10 + 4/100"
70701.05 ➞ "70000 + 700 + 1 + 5/100"
685.27 ➞ "600 + 80 + 5 + 2/10 + 7/100"

Examples

expandedForm(87.04) ➞ "80 + 7 + 4/100"

expandedForm(123.025) ➞ "100 + 20 + 3 + 2/100 + 5/1000"

expandedForm(50.270) ➞ "50 + 2/10 + 7/100"

Notes

N/A

*/

package main

import (
	"bytes"
	"fmt"
	"math/big"
	"strings"
)

func main() {
	test(87.04, "80 + 7 + 4/100")
	test(123.025, "100 + 20 + 3 + 2/100 + 5/1000")
	test(50.270, "50 + 2/10 + 7/100")
	test(207.333, "200 + 7 + 3/10 + 3/100 + 3/1000")
	test(0.57, "5/10 + 7/100")
	test(140.023, "100 + 40 + 2/100 + 3/1000")
	test(90.99, "90 + 9/10 + 9/100")
	test(84.5, "80 + 4 + 5/10")
	test(76.02, "70 + 6 + 2/100")
	test(44.5, "40 + 4 + 5/10")
	test(37.49, "30 + 7 + 4/10 + 9/100")
	test(60.0007, "60 + 7/10000")
	test(29.22, "20 + 9 + 2/10 + 2/100")
	test(10.99, "10 + 9/10 + 9/100")
	test(63.09, "60 + 3 + 9/100")
	test(37.022, "30 + 7 + 2/100 + 2/1000")
	test(43.21, "40 + 3 + 2/10 + 1/100")
	test(309.028, "300 + 9 + 2/100 + 8/1000")
	test(447.33, "400 + 40 + 7 + 3/10 + 3/100")
	test(65.05, "60 + 5 + 5/100")
	test(47.34, "40 + 7 + 3/10 + 4/100")
	test(68.699, "60 + 8 + 6/10 + 9/100 + 9/1000")
	test(1.24, "1 + 2/10 + 4/100")
	test(4.28, "4 + 2/10 + 8/100")
	test(7.304, "7 + 3/10 + 4/1000")
	test(0.04, "4/100")
	test(0.1234, "1/10 + 2/100 + 3/1000 + 4/10000")
	test(0, "0")
	test(10, "10")
	test(1051, "1000 + 50 + 1")
}

func test(x float64, r string) {
	p := expand(x)
	fmt.Printf("%v %q\n", x, p)
	assert(p == r)
}

func assert(x bool) {
	if !x {
		panic("assertion failed")
	}
}

func expand(x float64) string {
	z := big.NewFloat(x)
	s := z.String()

	u, v := s, ""
	if i := strings.IndexRune(s, '.'); i >= 0 {
		u = s[:i]
		v = s[i+1:]
	}

	w := new(bytes.Buffer)
	for i := range u {
		if u[i] != '0' {
			fmt.Fprintf(w, "%c%s + ", u[i], strings.Repeat("0", len(u)-i-1))
		}
	}

	for i := range v {
		if v[i] != '0' {
			fmt.Fprintf(w, "%c/1%s + ", v[i], strings.Repeat("0", i+1))
		}
	}

	r := w.String()
	r = strings.TrimSuffix(r, " + ")
	if r == "" {
		r = "0"
	}
	return r
}
