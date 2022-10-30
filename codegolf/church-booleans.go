/*

Church booleans

A Church boolean is a function that returns x for true and y for false where x is the first argument to the function and y is the second argument to the function.
Further functions can be composed from these functions which represent the and not or xor and implies logical operations.

Challenge

Construct the Church booleans and and not or xor and implies Church gates in a language of your choice. and or and xor should take in two functions (representing Church booleans) and return a function (representing another Church boolean).
Likewise, not should invert the function it takes and the implies gate should perform boolean implies logic where the first argument implies the second.

Scoring

The total length of all of the code required to make Church true and false in your language and the and not or xor and implies Church gates excluding the function's name. (for example, false=lambda x,y:y in Python would be 13 bytes).
You can reuse these names later in your code with them counting 1 byte toward the byte total of that gate.

Pseudo code Examples:

The functions you create should be able to be called later in your code like so.

true(x, y) -> x
false(x, y) -> y
and(true, true)(x, y) -> x
and(true, false)(x, y) -> y
# ... etc

*/

package main

func main() {
	test(1, 0)
	test(0, 1)
}

func test(x, y int) {
	assert(true(x, y) == x)
	assert(false(x, y) == y)

	assert(not(true)(x, y) == y)
	assert(not(false)(x, y) == x)

	assert(and(false, false)(x, y) == y)
	assert(and(false, true)(x, y) == y)
	assert(and(true, false)(x, y) == y)
	assert(and(true, true)(x, y) == x)

	assert(or(false, false)(x, y) == y)
	assert(or(false, true)(x, y) == x)
	assert(or(true, false)(x, y) == x)
	assert(or(true, true)(x, y) == x)

	assert(xor(false, false)(x, y) == y)
	assert(xor(false, true)(x, y) == x)
	assert(xor(true, false)(x, y) == x)
	assert(xor(true, true)(x, y) == y)

	assert(implies(false, false)(x, y) == x)
	assert(implies(false, true)(x, y) == x)
	assert(implies(true, false)(x, y) == y)
	assert(implies(true, true)(x, y) == x)
}

func assert(x bool) {
	if !x {
		panic("assertion failed")
	}
}

type binary func(int, int) int

func true(x, y int) int  { return x }
func false(x, y int) int { return y }

func not(f binary) binary {
	return func(x, y int) int {
		if f(x, y) == x {
			return y
		}
		return x
	}
}

func and(f, g binary) binary {
	return func(x, y int) int {
		if f(x, y) == x && g(x, y) == x {
			return x
		}
		return y
	}
}

func or(f, g binary) binary {
	return func(x, y int) int {
		if f(x, y) == x || g(x, y) == x {
			return x
		}
		return y
	}
}

func xor(f, g binary) binary {
	return func(x, y int) int {
		a := f(x, y)
		b := g(x, y)
		if a == x && b == x || a == y && b == y {
			return y
		}
		return x
	}
}

func implies(f, g binary) binary {
	return func(x, y int) int {
		if f(x, y) == x && g(x, y) == y {
			return y
		}
		return x
	}
}
