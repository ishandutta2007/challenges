/*

zipwith is a functional construct that takes three arguments: one binary function and two lists of the same length, and returns a single list where each element is constructed by applying the binary function to each pair of elements from the two lists:

zipwith (a+b) [1,2,3] [4,5,6] = [5,7,9]

You are to take a black-box function which takes exactly two arguments and two non-empty arrays of the same length consisting of positive integers, and output the result of applying zipwith to this function and arrays.

For the sake of simplicity, you can assume that the black-box function will always input and output integers within your language's integer domain.

If your answer consists solely of a builtin which does this (for example Haskell's zipWith), please edit into this Community Wiki answer. You may input and output in any convenient method.

This is code-golf so the shortest code in bytes wins
Test Cases

function, array, array -> output
a = b, [1, 2, 3], [3, 2, 1] -> [0, 1, 0]
a - b, [8, 3], [3, 8] -> [5, -5]
a² + b/2, [6, 8, 1, 3], [5, 3, 6, 2] -> [38, 65, 4, 10]
a × φ(b), [4, 2, 5, 8, 3], [7, 6, 10, 2, 1] -> [24, 4, 20, 8, 3]

The third test case uses integer (floor) division. The fourth uses the Euler Totient function

*/

package main

import (
	"fmt"
	"reflect"
)

func main() {
	test(f1, []int{1, 2, 3}, []int{3, 2, 1}, []int{0, 1, 0})
	test(f2, []int{8, 3}, []int{3, 8}, []int{5, -5})
	test(f3, []int{6, 8, 1, 3}, []int{5, 3, 6, 2}, []int{38, 65, 4, 10})
	test(f4, []int{4, 2, 5, 8, 3}, []int{7, 6, 10, 2, 1}, []int{24, 4, 20, 8, 3})
}

func assert(x bool) {
	if !x {
		panic("assertion failed")
	}
}

func test(f func(int, int) int, a, b, r []int) {
	p := zipwidth(f, a, b)
	fmt.Println(p)
	assert(reflect.DeepEqual(p, r))
}

func zipwidth(f func(int, int) int, a, b []int) []int {
	r := make([]int, len(a))
	for i := range a {
		r[i] = f(a[i], b[i])
	}
	return r
}

func f1(a, b int) int {
	if a == b {
		return 1
	}
	return 0
}

func f2(a, b int) int {
	return a - b
}

func f3(a, b int) int {
	return a*a + b/2
}

func f4(a, b int) int {
	return a * phi(b)
}

func phi(n int) int {
	if n <= 1 {
		return 1
	}

	r := int(1)
	p := factor(n)
	for i := 0; i < len(p); {
		j := i + 1
		u := p[i]
		for ; j < len(p) && p[i] == p[j]; j++ {
			u *= p[i]
		}

		r *= (u / p[i]) * (p[i] - 1)
		i = j
	}
	return r
}

func factor(n int) (f []int) {
	if n == 1 {
		return []int{1}
	}
	for i := int(2); i <= n; i++ {
		for n%i == 0 {
			n /= i
			f = append(f, i)
		}
	}
	return
}
