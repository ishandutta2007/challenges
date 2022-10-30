/*

Create a function that takes two numbers and returns their sum as a binary string.

Examples

addBinary(1, 1) ➞ "10"

addBinary(1, 2) ➞ "11"

addBinary(4, 5) ➞ "1001"

Notes

    Remember to return the converted result to a string.
    Check the resources tab in case you are stuck :)

*/
package main

import "fmt"

func main() {
	assert(add(1, 1) == "10")
	assert(add(1, 2) == "11")
	assert(add(4, 5) == "1001")
	assert(add(8, 20) == "11100")
	assert(add(100, 20) == "1111000")
	assert(add(40, 50) == "1011010")
	assert(add(65, 77) == "10001110")
	assert(add(40, 50) == "1011010")
	assert(add(1, 0) == "1")
}

func add(x, y int) string {
	return fmt.Sprintf("%b", x+y)
}

func assert(x bool) {
	if !x {
		panic("assertion failed")
	}
}
