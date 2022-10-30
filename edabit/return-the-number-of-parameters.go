/*

Create a function that returns the total number of parameters passed in.
Examples

numberArgs("a", "b", "c") ➞ 3

numberArgs(10, 20, 30, 40, 50) ➞ 5

numberArgs(x, y) ➞ 2

numberArgs() ➞ 0

Notes

    How can you express the input parameter so it takes a variable number of arguments?
    Check the Resources tab for additional info.

*/

package main

func main() {
	assert(numargs('a', 'b', 'c') == 3)
	assert(numargs(10, 20, 30, 40, 50) == 5)
	assert(numargs('x', 'y') == 2)
	assert(numargs() == 0)
}

func numargs(v ...interface{}) int {
	return len(v)
}

func assert(x bool) {
	if !x {
		panic("assertion failed")
	}
}
