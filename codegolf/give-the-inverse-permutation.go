/*

Task

Given a finite permutation output its inverse.

You may take input and output in any reasonable format equivalent to a list of natural numbers.
You may choose to use 0 indexing or 1 indexing. Your input and output format should be the same. You may assume a permutation has at least 1 element.

This is code-golf so the goal is to minimize the size of your source as measured in bytes.

Permutations

A finite permutation is a function which takes an n-tuple and produces an n-tuple such that every element of the input is present in the output, and the ordering does not rely on the values of the inputs.

We can unambiguously represent these permutations with an n-tuple where each element is the index of where it will end up. For example:

(3210)

This permutation reverses a 4 element tuple. The first element goes to the 3rd (last) position, the second goes to the 2nd (penultimate) position etc.

With this representation a valid permutation is just any list of size n which contains the numbers 0 through n−1.

For a permutation A the inverse permutation of A is a permutation such that when applied after A it restores the list to it's initial state.

For example (3210) is the permutation that reverse the order of 4 elements. It is its own inverse since reversing twice gets you back to where you started.
(12340) takes the first of 5 elements and moves it to the end, it has an inverse of (40123) since that takes the last of 5 elements and moves it to the front:

(A,B,C,D,E)−→−−−−−(12340)
(B,C,D,E,A)−→−−−−−(40123)
(A,B,C,D,E)

Every permutation has an inverse.

Test cases
[0] -> [0]
[0,1,2] -> [0,1,2]
[2,1,0] -> [2,1,0]
[1,2,0] -> [2,0,1]
[0,2,1] -> [0,2,1]
[1,2,0,5,4,3] -> [2,0,1,5,4,3]

*/

package main

import (
	"fmt"
	"reflect"
	"sort"
)

func main() {
	test([]int{3, 1, 2, 0}, []int{3, 1, 2, 0})
	test([]int{1, 2, 3, 4, 0}, []int{4, 0, 1, 2, 3})
	test([]int{0}, []int{0})
	test([]int{0, 1, 2}, []int{0, 1, 2})
	test([]int{2, 1, 0}, []int{2, 1, 0})
	test([]int{1, 2, 0}, []int{2, 0, 1})
	test([]int{0, 2, 1}, []int{0, 2, 1})
	test([]int{1, 2, 0, 5, 4, 3}, []int{2, 0, 1, 5, 4, 3})
}

func assert(x bool) {
	if !x {
		panic("assertion failed")
	}
}

func test(p, r []int) {
	pi := invperm(p)
	fmt.Println(pi)
	assert(reflect.DeepEqual(pi, r))
}

func invperm(p []int) []int {
	n := len(p)
	a := make([][2]int, n)
	for i := range p {
		a[i][0] = i
		a[i][1] = p[i]
	}
	sort.Slice(a, func(i, j int) bool {
		return a[i][1] < a[j][1]
	})

	r := make([]int, n)
	for i := range r {
		r[i] = a[i][0]
	}

	return r
}
