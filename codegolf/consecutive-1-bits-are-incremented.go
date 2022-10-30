/*

Given a pattern (string or array format) of Bits : [0,1,1,1,0,1,1,0,0,0,1,1,1,1,1,1]

The tasks is to replace any number of consecutive 1-Bits with an ascending number sequence starting at 1.

Input

Pattern (can be received as an string or array) Example:
String: 1001011010110101001
Array: [1, 0, 0, 1, 0, 1, 1, 0, 1, 0, 1, 1, 0, 1, 0, 1, 0, 0, 1]
Output

Ascending number sequence (can be returned as an string or array) Example:
String: 1 0 0 1 0 1 2 0 1 0 1 2 0 1 0 1 0 0 1
Array: [1, 0, 0, 1, 0, 1, 2, 0, 1, 0, 1, 2, 0, 1, 0, 1, 0, 0, 1]
Rules

(only apply for strings) Input wont contain spaces between 1 and 0
Assume Input length > 0
(only apply for strings) Output is separated by space (use any other separator if you need as long as is not a number or a letter from the alphabet)
Example:

Given [0,1,1,1,0,1,1,0,0,0,1,1,1,1,1,1]
Output [0,1,2,3,0,1,2,0,0,0,1,2,3,4,5,6]

--------------------------------------------------------------------------

Given 0110101111101011011111101011111111
Output 0 1 2 0 1 0 1 2 3 4 5 0 1 0 1 2 0 1 2 3 4 5 6 0 1 0 1 2 3 4 5 6 7 8

---------------------------------------------------------------------------

Given 11111111111101
Output 1 2 3 4 5 6 7 8 9 10 11 12 0 1

*/

package main

import (
	"fmt"
	"reflect"
)

func main() {
	test([]int{1, 0, 0, 1, 0, 1, 1, 0, 1, 0, 1, 1, 0, 1, 0, 1, 0, 0, 1}, []int{1, 0, 0, 1, 0, 1, 2, 0, 1, 0, 1, 2, 0, 1, 0, 1, 0, 0, 1})
	test([]int{0, 1, 1, 1, 0, 1, 1, 0, 0, 0, 1, 1, 1, 1, 1, 1}, []int{0, 1, 2, 3, 0, 1, 2, 0, 0, 0, 1, 2, 3, 4, 5, 6})
	test([]int{0, 1, 1, 0, 1, 0, 1, 1, 1, 1, 1, 0, 1, 0, 1, 1, 0, 1, 1, 1, 1, 1, 1, 0, 1, 0, 1, 1, 1, 1, 1, 1, 1, 1}, []int{0, 1, 2, 0, 1, 0, 1, 2, 3, 4, 5, 0, 1, 0, 1, 2, 0, 1, 2, 3, 4, 5, 6, 0, 1, 0, 1, 2, 3, 4, 5, 6, 7, 8})
	test([]int{1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 1}, []int{1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 0, 1})
}

func assert(x bool) {
	if !x {
		panic("assertion failed")
	}
}

func test(a, r []int) {
	inc(a)
	fmt.Println(a)
	assert(reflect.DeepEqual(a, r))
}

func inc(a []int) {
	n := len(a)
	for i := 0; i < n; {
		for i < n && a[i] == 0 {
			i = i + 1
		}
		for v := 0; i < n && a[i] == 1; v++ {
			a[i], i = a[i]+v, i+1
		}
	}
}
