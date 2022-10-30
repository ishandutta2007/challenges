/*

Create a function that takes a integer number n and returns the formula for (a+b)^n as a string.
Examples

formula(0) ➞ "1"

formula(1) ➞ "a+b"

formula(2) ➞ "a^2+2ab+b^2"

formula(-2) ➞ "1/(a^2+2ab+b^2)"

formula(3) ➞ "a^3+3a^2b+3ab^2+b^3"

formula(5) ➞ "a^5+5a^4b+10a^3b^2+10a^2b^3+5ab^4+b^5"

Notes

Don't put the following in your string:

spaces
*
^1
a^0
b^0

*/

package main

import (
	"bytes"
	"fmt"
)

func main() {
	assert(formula(0) == "1")
	assert(formula(1) == "a+b")
	assert(formula(2) == "a^2+2ab+b^2")
	assert(formula(-2) == "1/(a^2+2ab+b^2)")
	assert(formula(3) == "a^3+3a^2b+3ab^2+b^3")
	assert(formula(5) == "a^5+5a^4b+10a^3b^2+10a^2b^3+5ab^4+b^5")
	assert(formula(-1) == "1/(a+b)")
	assert(formula(-4) == "1/(a^4+4a^3b+6a^2b^2+4ab^3+b^4)")
	assert(formula(7) == "a^7+7a^6b+21a^5b^2+35a^4b^3+35a^3b^4+21a^2b^5+7ab^6+b^7")
	assert(formula(13) == "a^13+13a^12b+78a^11b^2+286a^10b^3+715a^9b^4+1287a^8b^5+1716a^7b^6+1716a^6b^7+1287a^5b^8+715a^4b^9+286a^3b^10+78a^2b^11+13ab^12+b^13")
	assert(formula(17) == "a^17+17a^16b+136a^15b^2+680a^14b^3+2380a^13b^4+6188a^12b^5+12376a^11b^6+19448a^10b^7+24310a^9b^8+24310a^8b^9+19448a^7b^10+12376a^6b^11+6188a^5b^12+2380a^4b^13+680a^3b^14+136a^2b^15+17ab^16+b^17")
	assert(formula(19) == "a^19+19a^18b+171a^17b^2+969a^16b^3+3876a^15b^4+11628a^14b^5+27132a^13b^6+50388a^12b^7+75582a^11b^8+92378a^10b^9+92378a^9b^10+75582a^8b^11+50388a^7b^12+27132a^6b^13+11628a^5b^14+3876a^4b^15+969a^3b^16+171a^2b^17+19ab^18+b^19")
	assert(formula(-23) == "1/(a^23+23a^22b+253a^21b^2+1771a^20b^3+8855a^19b^4+33649a^18b^5+100947a^17b^6+245157a^16b^7+490314a^15b^8+817190a^14b^9+1144066a^13b^10+1352078a^12b^11+1352078a^11b^12+1144066a^10b^13+817190a^9b^14+490314a^8b^15+245157a^7b^16+100947a^6b^17+33649a^5b^18+8855a^4b^19+1771a^3b^20+253a^2b^21+23ab^22+b^23)")
	assert(formula(27) == "a^27+27a^26b+351a^25b^2+2925a^24b^3+17550a^23b^4+80730a^22b^5+296010a^21b^6+888030a^20b^7+2220075a^19b^8+4686825a^18b^9+8436285a^17b^10+13037895a^16b^11+17383860a^15b^12+20058300a^14b^13+20058300a^13b^14+17383860a^12b^15+13037895a^11b^16+8436285a^10b^17+4686825a^9b^18+2220075a^8b^19+888030a^7b^20+296010a^6b^21+80730a^5b^22+17550a^4b^23+2925a^3b^24+351a^2b^25+27ab^26+b^27")
}

func assert(x bool) {
	if !x {
		panic("assertion failed")
	}
}

func formula(n int) string {
	if n == 0 {
		return "1"
	}

	r := false
	if n < 0 {
		n = -n
		r = true
	}

	w := new(bytes.Buffer)
	for i := n; i >= 0; i-- {
		j := n - i
		b := binomial(n, j)
		if b != 1 {
			fmt.Fprintf(w, "%d", b)
		}

		if i > 0 {
			fmt.Fprintf(w, "a")
			if i > 1 {
				fmt.Fprintf(w, "^%d", i)
			}
		}
		if j > 0 {
			fmt.Fprintf(w, "b")
			if j > 1 {
				fmt.Fprintf(w, "^%d", j)
			}
		}
		fmt.Fprintf(w, "+")
	}

	s := w.String()
	s = s[:len(s)-1]
	if r {
		s = fmt.Sprintf("1/(%s)", s)
	}
	return s
}

func binomial(n, k int) int {
	if k < 0 || k > n {
		return 0
	}
	if k == 0 || k == n {
		return 1
	}

	k = min(k, n-k)
	c := 1
	for i := 0; i < k; i++ {
		c = c * (n - i) / (i + 1)
	}
	return c
}

func min(a, b int) int {
	if a < b {
		return a
	}
	return b
}
