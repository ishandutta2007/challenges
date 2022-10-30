/*

Given a number, find the "round "of each digit of the number. An integer is called "round" if all its digits except the leftmost (most significant) are equal to zero.

    Round numbers: 4000, 1, 9, 800, 90
    Not round numbers: 110, 707, 222, 1001

Create a function that takes a number and returns the "round" of each digit (except if the digit is zero) as a string. Check out the following examples for more clarification.
Examples

sum_round(101) ➞ "1 100"

sum_round(1234) ➞ "4 30 200 1000"

sum_round(54210) ➞ "10 200 4000 50000"

Notes

N/A

*/

package main

import (
	"bytes"
	"fmt"
)

func main() {
	assert(sumround(101) == "1 100")
	assert(sumround(1010) == "10 1000")
	assert(sumround(1234) == "4 30 200 1000")
	assert(sumround(54213) == "3 10 200 4000 50000")
	assert(sumround(548741) == "1 40 700 8000 40000 500000")
	assert(sumround(1234567) == "7 60 500 4000 30000 200000 1000000")
}

func assert(x bool) {
	if !x {
		panic("assertion failed")
	}
}

func sumround(n uint) string {
	w := new(bytes.Buffer)
	s := fmt.Sprint(n)
	p := uint(1)
	for i := len(s) - 1; i >= 0; i-- {
		if s[i] != '0' {
			fmt.Fprintf(w, "%d ", uint(s[i]-'0')*p)
		}
		p *= 10
	}

	r := w.String()
	if r == "" {
		r = "0"
	} else {
		r = r[:len(r)-1]
	}
	return r
}
