/*

Lets define a pointer sequence to be any sequence such that a(n) = a((n-1)-(a(n-1))) forall n greater than some finite number. For example if our sequence begun with

3 2 1

Our next term would be 2, because a(n-1) = 1, (n-1)-1 = 1, a(1) = 2 (this example is zero index however it does not matter what index you use the calculation will always be the same.). If we repeat the process we get the infinite sequence

3 2 1 2 2 1 2 2 1 2 2 1 2 2 1 2 2 1 2 2 1 2 2 1 2 2 1 2 2 1 2 2 1 2 2 1 2 2 1 2 2 1 2 2 1 2 2 1 2 2 1 2 2 1 2 2 1 2 2 1 2 2 1 2 2 1 2 2 1 2 2 1 2 2 1 2 2 1 2 2 1 2 2 1 2 2 1 2 2 1 2 2 1 2 2 1 2 2 1 2 2 1 2 2 1 2 2 1 2 2 1 2 2 1 2 2 1 2 2 1 2 2 1 2 2 1 2 2 1 2 2 1 2 2 1 2 2 1 2 2 1 2

Task

Given some initial array of positive integers output the pointer sequence starting with that array.
Output types

Output is intended to be flexible, if you choose to write a function as your program it can return, either an infinite list of integers or a function that indexes the sequence. If you choose to write a full program you may output terms of the sequence indefinitely.

You may also choose to take two inputs, the starting array and an index. If you choose to do this you need only output the term of the sequence at that index.

You will never be given a sequence that requires indexing before the beginning of the sequence. For example 3 is not a valid input because you would need terms before the 3 to resolve the next term.

This is code-golf so your score will be the number of bytes in your program with a lower score being better.
Test Cases

test cases are truncated for simplicity

2 1   -> 2 1 2 2 1 2 2 1 2 2 1 2 2 1 2 2 1 2 2 1 2 2 1 2 2 1 2 2 ...
2 3 1 -> 2 3 1 3 2 1 2 2 1 2 2 1 2 2 1 2 2 1 2 2 1 2 2 1 2 2 1 2 ...
3 3 1 -> 3 3 1 3 3 3 1 3 3 3 1 3 3 3 1 3 3 3 1 3 3 3 1 3 3 3 1 3 ...
4 3 1 -> 4 3 1 3 4 4 3 3 4 4 4 3 4 4 4 4 3 4 4 4 4 3 4 4 4 4 3 4 ...

*/

package main

import (
	"fmt"
	"reflect"
)

func main() {
	test([]int{2, 1}, []int{2, 1, 2, 2, 1, 2, 2, 1, 2, 2, 1, 2, 2, 1, 2, 2, 1, 2, 2, 1, 2, 2, 1, 2, 2, 1, 2, 2})
	test([]int{2, 3, 1}, []int{2, 3, 1, 3, 2, 1, 2, 2, 1, 2, 2, 1, 2, 2, 1, 2, 2, 1, 2, 2, 1, 2, 2, 1, 2, 2, 1, 2})
	test([]int{3, 3, 1}, []int{3, 3, 1, 3, 3, 3, 1, 3, 3, 3, 1, 3, 3, 3, 1, 3, 3, 3, 1, 3, 3, 3, 1, 3, 3, 3, 1, 3})
	test([]int{4, 3, 1}, []int{4, 3, 1, 3, 4, 4, 3, 3, 4, 4, 4, 3, 4, 4, 4, 4, 3, 4, 4, 4, 4, 3, 4, 4, 4, 4, 3, 4})
}

func test(a, r []int) {
	p := seq(a, len(r))
	fmt.Printf("%v\n%v\n\n", p, r)
	assert(reflect.DeepEqual(p, r))
}

func assert(x bool) {
	if !x {
		panic("assertion failed")
	}
}

func seq(a []int, n int) []int {
	r := make([]int, n)
	for i := 0; i < n; i++ {
		if i < len(a) {
			r[i] = a[i]
		} else {
			r[i] = r[(i-1)-r[i-1]]
		}
	}
	return r
}
