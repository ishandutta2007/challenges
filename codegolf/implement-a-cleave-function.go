/*

Think of cleave as the conceptual inverse of map. If map applies a function to each number in a list...

map([1, 2, 3], x -> x * 5) -> [5, 10, 15]

then cleave applies each function in a list to a number.

cleave(5, [x -> x * 2, x -> x - 1, x -> x * x]) -> [10, 4, 25]

More formally, given:

n is an integer and
L is a list of black box functions with type signature integer -> integer or equivalent

Apply each function in L to n, collecting the results in a list the same length as L

Challenge

Implement the cleave function in your language of choice.

Format

You must accept an integer and a list of black box functions and output a list of integers in any reasonable format. Argument order doesn't matter. The list of functions is flexible. You may accept:

    A list of black box functions (including a list of function pointers, etc.).
    A variable number of black box functions as parameters (varargs).
    A number indicating how many functions to accept.
    Etc.

Rules

    Builtins are allowed, but please consider adding a less trivial answer so we can see how cleave might be implemented in your language.
    Explaining your answer(s) is encouraged!
    Standard loopholes are forbidden.
    This is code-golf, so the code with the fewest bytes (in each language) wins.

Test cases

Note: for simplicity, instead of showing functions like x -> 10 * x, I will show them like 10x. Imagine there is an f(x)=

in front of each of these.

  3, [] -> []
 42, [x] -> [42]
  0, [10x, x/2, abs(x), -x] -> [0, 0, 0, 0]
  8, [10x, x/2, abs(x), -x] -> [80, 4, 8, -8]
 -5, [abs(x), -x, x+10] -> [5, 5, 5]
  5, [abs(x), -x, x+10] -> [5, -5, 15]
 10, [x*x, x/10, x*x + 2x + 1, 13, x%3 - 3] -> [100, 1, 121, 13, -2]
950, [x*x, x/10, x*x + 2x + 1, 13, x%3 - 3] -> [902500, 95, 904401, 13, -1]

*/

package main

import (
	"fmt"
	"reflect"
)

func main() {
	I := func(n int) int { return n }
	A := func(n int) int {
		if n < 0 {
			n = -n
		}
		return n
	}
	N := func(n int) int { return -n }
	P10 := func(n int) int { return n + 10 }
	M10 := func(n int) int { return n * 10 }
	D10 := func(n int) int { return n / 10 }
	D2 := func(n int) int { return n / 2 }
	S2 := func(n int) int { return n * n }
	F2 := func(n int) int { return n*n + 2*n + 1 }
	U3 := func(n int) int { return n%3 - 3 }
	C13 := func(int) int { return 13 }

	test(3, []fn{}, []int{})
	test(42, []fn{I}, []int{42})
	test(0, []fn{M10, D2, A, N}, []int{0, 0, 0, 0})
	test(8, []fn{M10, D2, A, N}, []int{80, 4, 8, -8})
	test(-5, []fn{A, N, P10}, []int{5, 5, 5})
	test(5, []fn{A, N, P10}, []int{5, -5, 15})
	test(10, []fn{S2, D10, F2, C13, U3}, []int{100, 1, 121, 13, -2})
	test(950, []fn{S2, D10, F2, C13, U3}, []int{902500, 95, 904401, 13, -1})
}

func test(n int, f []fn, r []int) {
	p := cleave(n, f)
	fmt.Println(p)
	assert(reflect.DeepEqual(p, r))
}

func assert(x bool) {
	if !x {
		panic("assertion failed")
	}
}

type fn func(int) int

func cleave(n int, f []fn) []int {
	p := make([]int, len(f))
	for i := range p {
		p[i] = f[i](n)
	}
	return p
}
