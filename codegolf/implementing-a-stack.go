/*

I can't believe we don't have this already.. It's one of the most important data-structures in programming, yet still simple enough to implement it in a code-golf:
Challenge

Your task is to implement a stack that allows pushing and popping numbers, to test your implementation and keep I/O simple we'll use the following setup:

    Input will be a list of non-negative integers

Every positive integer n indicates a push(n) and every 0 indicates a pop() - discarding the top element.

    Output will be the resulting stack

Rules

    Input will be a list of non-negative integers in any default I/O format
        you may use a negative integer to signify the end of a stream of integers
    Output will be a list/matrix/.. of the resulting stack
        your choice where the top element will be (at the beginning or end), the output just has to be consistent
        output is flexible (eg. integers separated by new-lines would be fine), the only thing that matters is the order
        you may use a negative integer to signify the bottom of the stack
    You're guaranteed that there will never be a 0 when the stack is empty

Examples

[] -> []
[1] -> [1]
[1,0,2] -> [2]
[4,0,1,12] -> [12,1]
[8,3,1,2,3] -> [3,2,1,3,8]
[1,3,7,0,0,0] -> []
[13,0,13,10,1,0,1005,5,0,0,0] -> [13]
[12,3,0,101,11,1,0,0,14,0,28] -> [28,101,12]

*/

package main

import (
	"fmt"
	"reflect"
)

func main() {
	test([]int{}, []int{})
	test([]int{1}, []int{1})
	test([]int{1, 0, 2}, []int{2})
	test([]int{4, 0, 1, 12}, []int{12, 1})
	test([]int{8, 3, 1, 2, 3}, []int{3, 2, 1, 3, 8})
	test([]int{1, 3, 7, 0, 0, 0}, []int{})
	test([]int{13, 0, 13, 10, 1, 0, 1005, 5, 0, 0, 0}, []int{13})
	test([]int{12, 3, 0, 101, 11, 1, 0, 0, 14, 0, 28}, []int{28, 101, 12})
}

func assert(x bool) {
	if !x {
		panic("assertion failed")
	}
}

func test(a, r []int) {
	p := stacky(a)
	fmt.Println(p)
	assert(reflect.DeepEqual(p, r))
}

func stacky(a []int) []int {
	r := []int{}
	for _, v := range a {
		n := len(r)
		if v != 0 {
			r = append(r, v)
		} else if n > 0 {
			r = r[:n-1]
		}
	}
	for i, j := 0, len(r)-1; i < j; i, j = i+1, j-1 {
		r[i], r[j] = r[j], r[i]
	}
	return r
}
