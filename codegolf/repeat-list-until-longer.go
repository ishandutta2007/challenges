/*

The Challenge

The challenge is simple: given an input list a and another list b, repeat a until it is longer than b. Call the repeated list ra.
Then the following condition must hold true: len(b) < len(ra) <= len(b) + len(a). That is, a must not be repeated more than is required.

Sample Python Implementation
def repeat(a, b):
    ra = a.copy()
    while len(b) >= len(ra):
        ra += a
    return ra
Try it online!

Examples
[1,2,3] [2,4] -> [1,2,3]
[1,2,3] [2,3,4] -> [1,2,3,1,2,3]
[1,2,3] [18,26,43,86] -> [1,2,3,1,2,3]
[2,3,5] [1,2,3,4,5,6,7] -> [2,3,5,2,3,5,2,3,5]
[1,123] [1,12,123,1234] -> [1,123,1,123,1,123]

Scoring

This is code-golf, shortest answer in bytes wins. Have fun!

*/

package main

import (
	"fmt"
	"reflect"
)

func main() {
	test([]int{1, 2, 3}, []int{2, 4}, []int{1, 2, 3})
	test([]int{1, 2, 3}, []int{2, 3, 4}, []int{1, 2, 3, 1, 2, 3})
	test([]int{1, 2, 3}, []int{18, 26, 43, 86}, []int{1, 2, 3, 1, 2, 3})
	test([]int{2, 3, 5}, []int{1, 2, 3, 4, 5, 6, 7}, []int{2, 3, 5, 2, 3, 5, 2, 3, 5})
	test([]int{1, 123}, []int{1, 12, 123, 1234}, []int{1, 123, 1, 123, 1, 123})
}

func assert(x bool) {
	if !x {
		panic("assertion failed")
	}
}

func test(a, b, r []int) {
	p := repeat(a, b)
	fmt.Println(p)
	assert(reflect.DeepEqual(p, r))
}

func repeat(a, b []int) []int {
	r := append([]int{}, a...)
	for len(b) >= len(r) {
		r = append(r, a...)
	}
	return r
}
