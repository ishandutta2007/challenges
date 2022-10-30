/*

Suppose you have a guest list of students and the country they are from, stored as key-value pairs in an object.

const GUEST_LIST = {
  Randy: "Germany",
  Karla: "France",
  Wendy: "Japan",
  Norman: "England",
  Sam: "Argentina"
}

Write a function that takes in a name and returns a name tag, that should read:

"Hi! I'm [name], and I'm from [country]."

If the name is not in the object, return:

"Hi! I'm a guest."

Examples

greeting("Randy") ➞ "Hi! I'm Randy, and I'm from Germany."

greeting("Sam") ➞ "Hi! I'm Sam, and I'm from Argentina."

greeting("Monti") ➞ "Hi! I'm a guest."

*/

package main

import "fmt"

func main() {
	assert(greeting("Randy") == "Hi! I'm Randy, and I'm from Germany.")
	assert(greeting("Sam") == "Hi! I'm Sam, and I'm from Argentina.")
	assert(greeting("Monti") == "Hi! I'm a guest.")
	assert(greeting("Trudy") == "Hi! I'm a guest.")
	assert(greeting("Wendy") == "Hi! I'm Wendy, and I'm from Japan.")
}

func greeting(s string) string {
	m := map[string]string{
		"Randy":  "Germany",
		"Karla":  "France",
		"Wendy":  "Japan",
		"Norman": "England",
		"Sam":    "Argentina",
	}
	c, f := m[s]
	if !f {
		return "Hi! I'm a guest."
	}
	return fmt.Sprintf("Hi! I'm %s, and I'm from %s.", s, c)
}

func assert(x bool) {
	if !x {
		panic("assertion failed")
	}
}
