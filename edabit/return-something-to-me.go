/*

Write a function that returns the string "something" joined with a space and the given parameter a.
Examples

giveMeSomething("is better than nothing") ➞ "something is better than nothing"

giveMeSomething("Bob Jane") ➞ "something Bob Jane"

giveMeSomething("something") ➞ "something something"

Notes

Assume an input is given.

*/

package main

func main() {
	assert(something("is better than nothing") == "something is better than nothing")
	assert(something("Bob Jane") == "something Bob Jane")
	assert(something("something") == "something something")
	assert(something("a") == "something a")
	assert(something("is cooking") == "something is cooking")
	assert(something(" is cooking") == "something  is cooking")
}

func something(s string) string {
	return "something " + s
}

func assert(x bool) {
	if !x {
		panic("assertion failed")
	}
}
