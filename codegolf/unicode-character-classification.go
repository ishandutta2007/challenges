/*

Real-world programs often use libraries like ICU to support Unicode.

The puzzle is to create the smallest possible function that can determine whether a given Unicode character is lowercase, uppercase, or neither (a commonly used Unicode character property).

You may indicate the property in any way (whatever is shortest for your language); just explain what the output means in your answer.

Of course, using a language feature or a function from the standard library that already provides this distinction is forbidden.

This could potentially have some practical use, since some embedded programs have to choose between including a bulky library and not supporting Unicode.

*/

package main

import (
	"fmt"
	"unicode"
)

func main() {
	for i := 0; i < unicode.MaxRune; i++ {
		classify(string(i))
	}
}

func classify(s string) {
	for _, r := range s {
		t := "neither"
		switch {
		case unicode.IsLower(r):
			t = "lower"
		case unicode.IsUpper(r):
			t = "upper"
		}
		fmt.Printf("%q -> %s\n", r, t)
	}
}
