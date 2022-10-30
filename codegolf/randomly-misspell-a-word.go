/*

Inspired by this CR question (please don't kill me for browsing CR)

Spec
The probabilities of misspelling a word are:

1/3 of the time don't change the output
1/3 of the time remove a random character
1/3 of the time duplicate a random character
The chance for removing/duplicating a given character in the input should be the same for all chars.

If two consecutive characters are the same (case-sensitive), the probability of one of them being modified should be the same as if they are one character. I.e. the outputs for AA (which are AA or A or AAA) should all have the same probability.

The input will only contain of letters for simplicity.

Examples
First line is input, following lines are all possible misspellings. Each line should have the same probability of being output, the input is excluded in the examples but it should still have a 1/3 probability of output.

foo

fo
oo
ffoo
fooo
PPCG

PPC
PPG
PCG
PPPCG
PPCCG
PPCGG

*/

package main

import (
	"fmt"
	"math/rand"
	"time"
)

func main() {
	rand.Seed(time.Now().UnixNano())
	test("foo")
	test("PPCG")
}

func test(s string) {
	n := len(s)
	for i := 0; i < n*n*n; i++ {
		fmt.Println(misspell(s))
	}
	fmt.Println()
}

func misspell(s string) string {
	p := s
	if len(s) == 0 {
		return p
	}

	r := []rune(s)
	n := rand.Intn(len(r))
	switch rand.Intn(3) {
	case 1:
		r = append(r[:n], r[n+1:]...)
		p = string(r)
	case 2:
		r = append(r[:n], append([]rune{r[n]}, r[n:]...)...)
		p = string(r)
	}
	return p
}
