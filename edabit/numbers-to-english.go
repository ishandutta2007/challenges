/*

Write a function that accepts a positive integer between 0 and 999 inclusive and returns a string representation of that integer written in English.

Examples

numToEng(0) ➞ "zero"

numToEng(18) ➞ "eighteen"

numToEng(126) ➞ "one hundred twenty six"

numToEng(909) ➞ "nine hundred nine"

Notes

    There are no hyphens used (e.g. "thirty five" not "thirty-five").
    The word "and" is not used (e.g. "one hundred one" not "one hundred and one").

*/

package main

import (
	"bytes"
	"fmt"
)

func main() {
	assert(numeng(0) == "zero")
	assert(numeng(26) == "twenty six")
	assert(numeng(519) == "five hundred nineteen")
	assert(numeng(106) == "one hundred six")
	assert(numeng(999) == "nine hundred ninety nine")
	assert(numeng(909) == "nine hundred nine")
	assert(numeng(126) == "one hundred twenty six")
	assert(numeng(18) == "eighteen")
	assert(numeng(101) == "one hundred one")
	for i := uint(0); i <= 999; i++ {
		fmt.Println(i, numeng(i))
	}
}

func assert(x bool) {
	if !x {
		panic("assertion failed")
	}
}

func numeng(n uint) string {
	ones := []string{
		"zero",
		"one",
		"two",
		"three",
		"four",
		"five",
		"six",
		"seven",
		"eight",
		"nine",
		"ten",
		"eleven",
		"twelve",
		"thirteen",
		"fourteen",
		"fifteen",
		"sixteen",
		"seventeen",
		"eighteen",
		"nineteen",
	}
	tens := []string{
		"twenty",
		"thirty",
		"forty",
		"fifty",
		"sixty",
		"seventy",
		"eighty",
		"ninety",
	}

	if n > 999 {
		return "unsupported"
	}

	s := fmt.Sprint(n)
	m := len(s)
	i := 0
	o := false
	w := new(bytes.Buffer)
	for {
		t := 0
		r := m % 3
		switch r {
		case 0:
			t += int(s[i]-'0') * 100
			i += 1
			fallthrough
		case 2:
			t += int(s[i]-'0') * 10
			i += 1
			fallthrough
		case 1:
			t += int(s[i] - '0')
			i += 1
		}

		if t >= 100 {
			fmt.Fprintf(w, "%s hundred", ones[t/100])
			t %= 100
			if t != 0 {
				fmt.Fprintf(w, " ")
			}
		}
		if t >= 20 {
			fmt.Fprintf(w, "%s", tens[t/10-2])
			if t%10 != 0 {
				fmt.Fprintf(w, " %s", ones[t%10])
			}
		} else if !(r == 0 && t == 0) || (!o && t != 0) {
			fmt.Fprintf(w, "%s", ones[t])
		}

		if r == 0 {
			m -= 3
		} else {
			m -= r
		}
		if m <= 0 {
			break
		}

		o = true
	}
	return w.String()
}
