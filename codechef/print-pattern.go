/*

Consider the following 4×4 pattern:

 1  2  4  7
 3  5  8 11
 6  9 12 14
10 13 15 16

You are given an integer N. Print the N×N pattern of the same kind (containing integers 1 through N2).

Input

The first line of the input contains a single integer T denoting the number of test cases. The description of T test cases follows.
The first and only line of each test case contains a single integer N.

Output

For each test case, print N lines; each of them should contain N space-separated integers.

Constraints
1≤T≤10
1≤N≤100

*/

package main

import (
	"fmt"
	"reflect"
	"sort"
)

func main() {
	test(2, [][]int{
		{1, 2},
		{3, 4},
	})

	test(3, [][]int{
		{1, 2, 4},
		{3, 5, 7},
		{6, 8, 9},
	})

	test(4, [][]int{
		{1, 2, 4, 7},
		{3, 5, 8, 11},
		{6, 9, 12, 14},
		{10, 13, 15, 16},
	})
}

func assert(x bool) {
	if !x {
		panic("assertion failed")
	}
}

func test(n int, r [][]int) {
	p := pattern(n)
	fmt.Println(p)
	assert(reflect.DeepEqual(p, r))
}

func pattern(n int) [][]int {
	var p [][3]int
	for i := 0; i < n; i++ {
		for j := 0; j < n; j++ {
			p = append(p, [3]int{i + j, i, j})
		}
	}

	sort.SliceStable(p, func(i, j int) bool {
		return p[i][0] < p[j][0]
	})

	r := make([][]int, n)
	t := make([]int, n*n)
	for i := range r {
		r[i] = t[i*n : (i+1)*n]
	}

	for k, l := range p {
		i, j := l[1], l[2]
		r[i][j] = k + 1
	}
	return r
}
