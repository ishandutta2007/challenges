/*

The Task

Your task is to create a program or a function that, given an input, outputs the input text with random letters capitalized, while keeping already capitalized letters capitalized.

Every combination of capitalizations of the lowercase letters should be possible. For example, if the input was abc, there should be a non-zero probability of outputting any of the following combinations: abc, Abc, aBc, abC, ABc, AbC, aBC or ABC.

Input

Your input is a string, containing any number of printable ASCII characters, for example Hello World. The outputs for that input include HeLLo WoRlD, HElLO WOrld, etc.

Scoring

This is code-golf, so the shortest answer in each language wins!

*/

package main

import (
	"bytes"
	"fmt"
	"math/rand"
	"time"
	"unicode"
)

func main() {
	rand.Seed(time.Now().UnixNano())
	test("abc", 10)
	test("Hello World", 20)
}

func test(s string, n int) {
	for i := 0; i < n; i++ {
		fmt.Println(capitalize(s))
	}
}

func capitalize(s string) string {
	w := new(bytes.Buffer)
	for _, r := range s {
		if !unicode.IsUpper(r) && rand.Intn(2) == 1 {
			r = unicode.ToUpper(r)
		}
		w.WriteRune(r)
	}
	return w.String()
}
