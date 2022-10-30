/*

The ABACABA pattern is a recursive fractal pattern that shows up in many places in the real world (such as in geometry, art, music, poetry, number systems, literature and higher dimensions).

Create a function that takes a number n as an argument and returns a string that represents the full pattern.

*/

package main

import "fmt"

func main() {
	for i := uint(0); i < 10; i++ {
		fmt.Println(i, gen(i))
	}
}

func gen(n uint) string {
	p := ""
	c := 0
	for i := uint(0); i < n; i++ {
		p = p + string('A'+c) + p
		c = (c + 1) % 26
	}
	return p
}
