/*

Create a function that checks if the argument is an integer or a string.
Return int if it's an integer and str if it's a string.

Examples

intOrString(8) ➞ "int"

intOrString("Hello") ➞ "str"

intOrString(9843532) ➞ "int"

*/

package main

func main() {
	assert(ios(8) == "int")
	assert(ios("Hello") == "str")
	assert(ios(9843532) == "int")
	assert(ios(1) == "int")
	assert(ios("HELLO") == "str")
	assert(ios("edabit") == "str")
	assert(ios(873432874) == "int")
	assert(ios(5) == "int")
}

func ios(v interface{}) string {
	switch v.(type) {
	case int:
		return "int"
	case string:
		return "str"
	}
	return "unk"
}

func assert(x bool) {
	if !x {
		panic("assertion failed")
	}
}
