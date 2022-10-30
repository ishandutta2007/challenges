package main

import (
	"fmt"
	"unicode"
)

func main() {
	fmt.Println(count("Hello"))
	fmt.Println(count("137"))
	fmt.Println(count("H3LL0"))
	fmt.Println(count("149990"))
	fmt.Println(count("edabit 2018"))
	fmt.Println(count("    "))
}

func count(s string) map[string]int {
	l, d := 0, 0
	for _, r := range s {
		switch {
		case unicode.IsLetter(r):
			l++
		case unicode.IsDigit(r):
			d++
		}
	}
	return map[string]int{
		"LETTERS": l,
		"DIGITS":  d,
	}
}
