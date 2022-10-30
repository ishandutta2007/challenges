/*

Given a number, n, return a function which adds n to the number passed to it.
Examples

add(10)(20) ➞ 30

add(0)(20) ➞ 20

add(-30)(80) ➞ 50

Notes

    All numbers used in the tests will be integers (whole numbers).
    Returning a function from a function is a key part of understanding higher order functions (functions which operate on and return functions).

*/

package main

func main() {
	assert(add(20)(10) == 30)
	assert(add(30)(10) == 40)
	assert(add(100)(100) == 200)
	assert(add(-30)(80) == 50)
	assert(add(-10)(-10) == -20)
}

func add(x int) func(y int) int {
	return func(y int) int {
		return x + y
	}
}

func assert(x bool) {
	if !x {
		panic("assertion failed")
	}
}
