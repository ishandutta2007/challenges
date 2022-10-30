/*

Given three arguments ⁠— an object obj of the stolen items, the pets name and a value —
return an object with that name and value in it (as key-value pairs).

Examples

addName({}, "Brutus", 300) ➞ { Brutus: 300 }

addName({ piano: 500 }, "Brutus", 400) ➞ { piano: 500, Brutus: 400 }

addName({ piano: 500, stereo: 300 }, "Caligula", 440) ➞ { piano: 500, stereo: 300, Caligula: 440 }

Notes

The value argument will be a number.

*/

package main

import "fmt"

func main() {
	fmt.Println(add(map[string]int{}, "Brutus", 300))
	fmt.Println(add(map[string]int{"piano": 500}, "Brutus", 400))
	fmt.Println(add(map[string]int{"piano": 500, "stereo": 300}, "Caligula", 440))
}

func add(m map[string]int, name string, value int) map[string]int {
	m[name] = value
	return m
}
