/*

You are given a sorted list A of size N.You have to make a new list B such that B[i] is equal to the number of elements strictly greater than A[i] in the list A.

Print the new list.

Input

The first line consists of T, denoting the number of test cases.

First line of each test case consists of one integer denoting N, where N is the size of the list given to you.

Second line of each test case contains the list given to you containing N elements.

Output

For each test case print the list in a single line and the elements of the list should be separated by space.

Print the answer to each test case in a new line.

Constraints
1≤T≤100 , where T is the number of test cases.
1≤N≤100, where N is the number of elements in the list.
1≤A[i]≤1000000 ,where A[i] is the ith element in the list given to you.

*/

package main

import (
	"fmt"
	"reflect"
)

func main() {
	test([]int{1, 2, 4, 4}, []int{3, 2, 0, 0})
	test([]int{1, 2, 2, 2, 2}, []int{4, 0, 0, 0, 0})
}

func assert(x bool) {
	if !x {
		panic("assertion failed")
	}
}

func test(a, r []int) {
	p := list(a)
	fmt.Println(p)
	assert(reflect.DeepEqual(p, r))
}

func list(a []int) []int {
	n := len(a)
	r := make([]int, n)
	for i := n - 2; i >= 0; i-- {
		if a[i] == a[i+1] {
			r[i] = r[i+1]
		} else if a[i] < a[i+1] {
			r[i] = n - i - 1
		}
	}
	return r
}
