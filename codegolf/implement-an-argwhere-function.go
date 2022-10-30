/*

The argwhere function takes a list of values and a predicate/boolean function as arguments and returns a list of indices where the predicate function returns true in the input list. For example,

argwhere([1, 2, 3, -5, 5], x -> x > 2)

would produce an output of [2, 4] because those are the (0-indexed) indices whose values are greater than two.

Challenge
Implement the argwhere function in your language of choice.

Format

For the purposes of this challenge, we will deal with lists of integers.
You must accept a list of integers and a black box function and return a list of integers in any reasonable format.
You may assume the input list will never be empty. Your output may be either 0-indexed or 1-indexed — please specify which.

Rules

Builtins are allowed, but please consider adding a less trivial answer so we can see how argwhere might be implemented in your language.
Explaining your answer(s) is encouraged!
Standard loopholes are forbidden.
This is code-golf, so the code with the fewest bytes (in each language) wins.

Why argwhere?
argfoo is a naming convention where you don't want the elements themselves — you want their indices or some other quality. argmax, argmin, and argsort are examples of this.
Read more about it here. (Also, because my favorite programming language comes with this function and it's called arg-where. 🤫)

Test cases
0-indexed

Input	Output
[1, 2, 0, 0, 3, 0, 0, 0, 4], x -> x == 0
[4, 3, 5, 7, 11, 13, 17], x -> x % 2 == 0
[8, 9, 10, 11, 12, 13], x -> x + 10 > 20
[5, -5, 2, -2, 0], x -> x < 0
[5, 2, 0], x -> x < 0
[2, 3, 5, 6, 7]
[0]
[3, 4, 5]
[1, 3]
[]
1-indexed

Input	Output
[1, 2, 0, 0, 3, 0, 0, 0, 4], x -> x == 0
[4, 3, 5, 7, 11, 13, 17], x -> x % 2 == 0
[8, 9, 10, 11, 12, 13], x -> x + 10 > 20
[5, -5, 2, -2, 0], x -> x < 0
[5, 2, 0], x -> x < 0
[3, 4, 6, 7, 8]
[1]
[4, 5, 6]
[2, 4]
[]

*/

package main

import (
	"fmt"
	"reflect"
)

func main() {
	test(
		[]int{1, 2, 0, 0, 3, 0, 0, 0, 4},
		func(x int) bool { return x == 0 },
		[]int{2, 3, 5, 6, 7},
	)

	test(
		[]int{4, 3, 5, 7, 11, 13, 17},
		func(x int) bool { return x%2 == 0 },
		[]int{0},
	)

	test(
		[]int{8, 9, 10, 11, 12, 13},
		func(x int) bool { return x+10 > 20 },
		[]int{3, 4, 5},
	)

	test(
		[]int{5, -5, 2, -2, 0},
		func(x int) bool { return x < 0 },
		[]int{1, 3},
	)

	test(
		[]int{5, 2, 0},
		func(x int) bool { return x < 0 },
		[]int{},
	)
}

func assert(x bool) {
	if !x {
		panic("assertion failed")
	}
}

func test(a []int, f func(int) bool, r []int) {
	p := argwhere(a, f)
	fmt.Println(p)
	assert(reflect.DeepEqual(p, r))
}

func argwhere(a []int, f func(int) bool) []int {
	r := []int{}
	for i := range a {
		if f(a[i]) {
			r = append(r, i)
		}
	}
	return r
}
