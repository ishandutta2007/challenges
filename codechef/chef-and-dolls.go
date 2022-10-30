/*

Chef is fan of pairs and he likes all things that come in pairs. He even has a doll collection in which the dolls come in pairs.
One day while going through his collection he found that there are odd number of dolls. Someone had stolen a doll!!!

Help chef find which type of doll is missing..

Input

The first line contains an integer T, the number of test cases.
The first line of each test case contains an integer N, the number of dolls.
The next N lines are the types of dolls that are left.

Output

For each test case, display the type of doll that doesn't have a pair, in a new line.

Constraints
1<=T<=10
1<=N<=100000 (10^5)
0<=type<=100000

*/

package main

import (
	"fmt"
	"reflect"
	"sort"
)

func main() {
	test([]int{1, 2, 1}, []int{2})
	test([]int{1, 1, 2, 2, 3}, []int{3})
}

func assert(x bool) {
	if !x {
		panic("assertion failed")
	}
}

func test(a, r []int) {
	p := doll(a)
	fmt.Println(p)
	assert(reflect.DeepEqual(p, r))
}

func doll(a []int) []int {
	m := make(map[int]int)
	for _, v := range a {
		m[v]++
	}

	var r []int
	for k, v := range m {
		if v&1 != 0 {
			r = append(r, k)
		}
	}
	sort.Ints(r)

	return r
}
