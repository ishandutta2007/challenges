/*

"Loves me, loves me not" is a traditional game in which a person plucks off all the petals of a flower one by one, saying the phrase "Loves me" and "Loves me not" when determining whether the one that they love, loves them back.

Given a number of petals, return a string which repeats the phrases "Loves me" and "Loves me not" for every alternating petal, and return the last phrase in all caps. Remember to put a comma and space between phrases.
Examples

lovesMe(3) ➞ "Loves me, Loves me not, LOVES ME"

lovesMe(6) ➞ "Loves me, Loves me not, Loves me, Loves me not, Loves me, LOVES ME NOT"

lovesMe(1) ➞ "LOVES ME"

Notes

    Remember to return a string.
    The first phrase is always "Loves me".

*/

package main

import (
	"fmt"
	"strings"
	"unicode"
)

func main() {
	for i := 1; i <= 70; i++ {
		fmt.Println(i, lovesme(i))
	}
}

func lovesme(n int) string {
	if n <= 0 {
		return ""
	}

	var s strings.Builder
	for i := 0; i < n; i++ {
		w := "Loves me"
		if i&1 != 0 {
			w += " not"
		}
		if i+1 >= n {
			w = strings.Map(unicode.ToUpper, w)
		}

		s.WriteString(w)
		if i+1 < n {
			s.WriteString(", ")
		}
	}
	return s.String()
}
