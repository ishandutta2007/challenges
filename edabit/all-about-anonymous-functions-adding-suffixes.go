/*

Write a function that returns an anonymous function, which transforms its input by adding a particular suffix at the end.
Examples

add_ly = add_suffix("ly")

add_ly("hopeless") ➞ "hopelessly"
add_ly("total") ➞"totally"

add_less = add_suffix("less")

add_less("fear") ➞ "fearless"
add_less("ruth") ➞ "ruthless"

*/

package main

import "fmt"

func main() {
	addly := addsuffix("ly")
	addless := addsuffix("less")
	adding := addsuffix("ing")

	assert(addly("hopeless") == "hopelessly")
	assert(addly("total") == "totally")

	assert(addless("fear") == "fearless")
	assert(addless("ruth") == "ruthless")

	assert(adding("cheer") == "cheering")
	assert(adding("book") == "booking")
}

func addsuffix(s string) func(string) string {
	return func(p string) string {
		return fmt.Sprintf("%v%v", p, s)
	}
}

func assert(x bool) {
	if !x {
		panic("assertion failed")
	}
}
