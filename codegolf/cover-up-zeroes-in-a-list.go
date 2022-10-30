/*

Inspired by this SO question

As input you will be given a non-empty list of integers, where the first value is guaranteed to be non-zero.
To construct the output, walk from the start of the list, outputting each non-zero value along the way. When you encounter a zero, instead repeat the value you most recently added to the output.

You may write a program or function, and have input/output take any convenient format which does not encode extra information, as long as is still an ordered sequence of integers.
If outputting from a program, you may print a trailing newline. Except for this trailing newline, your output should be an acceptable input for your submission.

The shortest code in bytes wins.
Test Cases

[1, 0, 2, 0, 7, 7, 7, 0, 5, 0, 0, 0, 9] -> [1, 1, 2, 2, 7, 7, 7, 7, 5, 5, 5, 5, 9]
[1, 0, 0, 0, 0, 0] -> [1, 1, 1, 1, 1, 1]
[-1, 0, 5, 0, 0, -7] -> [-1, -1, 5, 5, 5, -7]
[23, 0, 0, -42, 0, 0, 0] -> [23, 23, 23, -42, -42, -42, -42]
[1, 2, 3, 4] -> [1, 2, 3, 4]
[-1234] -> [-1234]

*/

package main

import (
	"fmt"
	"reflect"
)

func main() {
	test([]int{1, 0, 2, 0, 7, 7, 7, 0, 5, 0, 0, 0, 9}, []int{1, 1, 2, 2, 7, 7, 7, 7, 5, 5, 5, 5, 9})
	test([]int{1, 0, 0, 0, 0, 0}, []int{1, 1, 1, 1, 1, 1})
	test([]int{-1, 0, 5, 0, 0, -7}, []int{-1, -1, 5, 5, 5, -7})
	test([]int{23, 0, 0, -42, 0, 0, 0}, []int{23, 23, 23, -42, -42, -42, -42})
	test([]int{1, 2, 3, 4}, []int{1, 2, 3, 4})
	test([]int{-1234}, []int{-1234})
}

func assert(x bool) {
	if !x {
		panic("assertion failed")
	}
}

func test(a, r []int) {
	p := coverzeroes(a)
	fmt.Println(p)
	assert(reflect.DeepEqual(p, r))
}

func coverzeroes(a []int) []int {
	r := make([]int, len(a))
	p := 0
	for i, v := range a {
		if v == 0 {
			v = p
		} else {
			p = v
		}
		r[i] = v
	}
	return r
}
