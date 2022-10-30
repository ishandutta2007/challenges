/*

You are given a positive integer N. You have to print exactly N+1 positive integers satisfying the following conditions:

Exactly one value should appear twice, all the remaining values should appear only once.
Sum of all these values should be equal to 2^N.
You have to print the values in non-decreasing order. If there are multiple solutions, you can print any of them.

Input Format

The first line of the input contains a single integer T denoting the number of test cases. The description of T test cases follows.
The first and only line of each test case contains a single integer N.

Output Format

For each test case, print a single line containing N+1 positive integers in non-decreasing order that satisfy the given conditions. If there are multiple solutions, you may print any of them.

Constraints
1≤T≤60
1≤N≤60

*/

package main

import (
	"fmt"
)

func main() {
	test(1)
	test(3)
	test(4)
}

func assert(x bool) {
	if !x {
		panic("assertion failed")
	}
}

func test(n int) {
	p := values(n)
	fmt.Println(p)
	assert(len(p) == n+1)
	assert(sum(p) == 1<<n)
}

func sum(a []int) int {
	v := 0
	for i := range a {
		v += a[i]
	}
	return v
}

func values(n int) []int {
	r := []int{1}
	for i := 0; i < n; i++ {
		r = append(r, 1<<i)
	}
	return r
}
