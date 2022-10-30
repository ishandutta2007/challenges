/*

Given string s of even length as input, randomly capitalize exactly half of the letters.

    You can assume the input will always be a non-zero, even length
    You can assume the input will consist of only lowercase letters ([a-z])
    Exactly half of the letters should be capitalized in the output
    Every permutation that has exactly half of the characters capitalized should have an equal probability of being output

Scoring

This is code-golf so fewest bytes in each language wins!

*/

package main

import (
	"fmt"
	"math/rand"
	"time"
	"unicode"
)

func main() {
	rand.Seed(time.Now().UnixNano())
	fmt.Println(halfcap("xxxyyy"))
	fmt.Println(halfcap("wowsig"))
}

func halfcap(s string) string {
	r := []rune(s)
	n := len(r)
	p := rand.Perm(n)
	for i := 0; i < n/2; i++ {
		j := p[i]
		r[j] = unicode.ToUpper(r[j])
	}
	return string(r)
}
