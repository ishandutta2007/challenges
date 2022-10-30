/*

Write a function that takes two base-26 numbers in which digits are represented by letters with A=0, B=1, … Z=25 and returns their product using the same notation. As an example, CSGHJ × CBA = FNEUZJA.

Your task is to write the base-26 multiplication function.

Try to be very efficient in your code!

*/

package main

import (
	"bytes"
)

func main() {
	assert(mul("CSGHJ", "CBA") == "FNEUZJA")
}

func assert(x bool) {
	if !x {
		panic("assertion failed")
	}
}

func mul(a, b string) string {
	return convs(convi(a) * convi(b))
}

func convi(s string) int {
	r := 0
	for _, c := range s {
		switch {
		case 'a' <= c && c <= 'z':
			c -= 'a'
		case 'A' <= c && c <= 'Z':
			c -= 'A'
		}
		r = (r * 26) + int(c)
	}
	return r
}

func convs(n int) string {
	var p []rune
	for ; n != 0; n /= 26 {
		p = append(p, 'A'+rune(n%26))
	}

	w := new(bytes.Buffer)
	for i := len(p) - 1; i >= 0; i-- {
		w.WriteRune(p[i])
	}
	return w.String()
}
