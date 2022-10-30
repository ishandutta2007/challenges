/*

Suppose we have an array ps of length n with pointers pointing to some location in the array: The process of "pointer jumping" will set every pointer to the location the pointer it points to points to.

For the purpose of this challenge a pointer is the (zero-based) index of an element of the array, this implies that every element in the array will be greater or equal to 0
and less than n.

Using this notation the process can be formulated as follows:

for i = 0..(n-1) {
  ps[i] = ps[ps[i]]
}

This means (for this challenge) that the pointers are updated in-place in sequential order (ie. lower indices first).
Example

Let's work through an example, ps = [2,1,4,1,3,2]:

i = 0:the element at position ps[0] = 2 points to 4→ps = [4,1,4,1,3,2]
i = 1:the element at position ps[1] = 1 points to 1→ps = [4,1,4,1,3,2]
i = 2:the element at position ps[2] = 4 points to 3→ps = [4,1,3,1,3,2]
i = 3:the element at position ps[3] = 1 points to 1→ps = [4,1,3,1,3,2]
i = 4:the element at position ps[4] = 3 points to 1→ps = [4,1,3,1,1,2]
i = 5:the element at position ps[5] = 2 points to 3→ps = [4,1,3,1,1,3]

So after one iteration of "pointer jumping" we get the array [4,1,3,1,1,3].

Challenge

Given an array with indices output the array obtained by iterating the above described pointer jumping until the array does not change anymore.
Rules

Your program/function will take and return/output the same type, a list/vector/array etc. which

    is guaranteed to be non-empty and
    is guaranteed to only contain entries 0≤p<n.

Variants: You may choose

    to use 1-based indexing or
    use actual pointers,

however you should mention this in your submission.

Test cases

[0] → [0]
[1,0] → [0,0]
[1,2,3,4,0] → [2,2,2,2,2]
[0,1,1,1,0,3] → [0,1,1,1,0,1]
[4,1,3,0,3,2] → [3,1,3,3,3,3]
[5,1,2,0,4,5,6] → [5,1,2,5,4,5,6]
[9,9,9,2,5,4,4,5,8,1,0,0] → [1,1,1,1,4,4,4,4,8,1,1,1]

*/

package main

import (
	"fmt"
	"reflect"
)

func main() {
	test([]int{0}, []int{0})
	test([]int{1, 0}, []int{0, 0})
	test([]int{0, 1, 1, 1, 0, 3}, []int{0, 1, 1, 1, 0, 1})
	test([]int{4, 1, 3, 0, 3, 2}, []int{3, 1, 3, 3, 3, 3})
	test([]int{5, 1, 2, 0, 4, 5, 6}, []int{5, 1, 2, 5, 4, 5, 6})
	test([]int{9, 9, 9, 2, 5, 4, 4, 5, 8, 1, 0, 0}, []int{1, 1, 1, 1, 4, 4, 4, 4, 8, 1, 1, 1})
}

func test(a, r []int) {
	p := jump(a)
	fmt.Println(p)
	assert(reflect.DeepEqual(p, r))
}

func assert(x bool) {
	if !x {
		panic("assertion failed")
	}
}

func jump(a []int) (r []int) {
	defer func() {
		if err := recover(); err != nil {
			r = nil
			return
		}
	}()

	x := append([]int{}, a...)
	y := append([]int{}, a...)
	for {
		for i := range x {
			x[i] = x[x[i]]
		}
		if reflect.DeepEqual(x, y) {
			break
		}
		copy(y, x)
	}
	return x
}
