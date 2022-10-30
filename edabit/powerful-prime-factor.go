/*

Create a function that takes a positive integer and returns a string expressing how the number can be made by multiplying powers of its prime factors.

Examples

expressFactors(2) ➞ "2"

expressFactors(4) ➞ "2^2"

expressFactors(10) ➞ "2 x 5"

expressFactors(60) ➞ "2^2 x 3 x 5"

Notes

    All inputs will be positive integers in the range 1 < n < 10,000.
    If a factor is repeated express it in the form "x^y" where x is the factor and y is the number of repetitions of the factor.
    If n is a prime number, return n as a string as in example #1 above.
    Factors should appear in ascending order in the expression.
    Make sure you include the space either side of the multiplication sign, " x ".
    Check the Resources if you need to understand Prime Factorization.

*/

package main

import (
	"bytes"
	"fmt"
)

func main() {
	assert(express(2) == "2")
	assert(express(4) == "2^2")
	assert(express(10) == "2 x 5")
	assert(express(11) == "11")
	assert(express(29) == "29")
	assert(express(60) == "2^2 x 3 x 5")
	assert(express(100) == "2^2 x 5^2")
	assert(express(151) == "151")
	assert(express(323) == "17 x 19")
	assert(express(997) == "997")
	assert(express(3349) == "17 x 197")
	assert(express(5040) == "2^4 x 3^2 x 5 x 7")
	assert(express(6097) == "7 x 13 x 67")
	assert(express(8192) == "2^13")
	assert(express(9870) == "2 x 3 x 5 x 7 x 47")
	assert(express(9973) == "9973")
	assert(express(9999) == "3^2 x 11 x 101")
}

func assert(x bool) {
	if !x {
		panic("assertion failed")
	}
}

func express(n uint) string {
	if n == 0 {
		return "0"
	}
	if n == 1 {
		return "1"
	}

	w := new(bytes.Buffer)
	p := factorize(n)
	for i := 0; i < len(p); {
		j := i + 1
		for j < len(p) && p[i] == p[j] {
			j++
		}

		fmt.Fprintf(w, "%d", p[i])
		if k := j - i; k != 1 {
			fmt.Fprintf(w, "^%d", k)
		}
		if i = j; i < len(p) {
			fmt.Fprintf(w, " x ")
		}
	}
	return w.String()
}

func factorize(n uint) []uint {
	var r []uint
loop:
	for n > 1 {
		for i := uint(2); i <= n; i++ {
			if n%i == 0 {
				n /= i
				r = append(r, i)
				continue loop
			}
		}
	}
	return r
}
