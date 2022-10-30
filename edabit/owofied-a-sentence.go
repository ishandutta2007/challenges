/*

Create a function that takes a sentence and turns every "i" into "wi" and "e" into "we", and add "owo" at the end.

Notes

    Don't forget to return the value!
	There's a space in front of owo!
	uwu

*/

package main

import (
	"bytes"
	"fmt"
)

func main() {
	fmt.Println(owofied("I'm gonna ride 'til I can't no more"))
	fmt.Println(owofied("Do you ever feel like a plastic bag"))
	fmt.Println(owofied("Cause baby you're a firework"))
	fmt.Println(owofied("Never gonna give you up"))
	fmt.Println(owofied("We've known each other for so long"))
	fmt.Println(owofied("Never gonna let you down"))
	fmt.Println(owofied("Shine bright like a diamond"))
}

func owofied(s string) string {
	p := new(bytes.Buffer)
	for _, r := range s {
		switch r {
		case 'i', 'e':
			p.WriteRune('w')
		}
		p.WriteRune(r)
	}
	p.WriteString(" owo")
	return p.String()
}
