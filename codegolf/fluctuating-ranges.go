/*

Given a list with number, output the ranges like this:

Input: [0, 5, 0] would become [0, 1, 2, 3, 4, 5, 4, 3, 2, 1, 0].

This is mapping a range through the array, so we first have to create the range [0, 5], which is [0, 1, 2, 3, 4, 5].
After that, we use the 5 to create the range [5, 0]. Appended at our previous range, this gives us:

[0, 1, 2, 3, 4, 5, 4, 3, 2, 1, 0]
Let's observe a test case with two same digits next to each other:

[3, 5, 5, 3], ranges:

[3, 5] = 3, 4, 5
[5, 5] = 5 (actually [5, 5] due to overlapping)
[5, 3] = 5, 4, 3
So this would give us [3, 4, 5, 5, 4, 3].

Some other test cases:

[1, 9] > [1, 2, 3, 4, 5, 6, 7, 8, 9]
[10, -10] > [10, 9, 8, 7, 6, 5, 4, 3, 2, 1, 0, -1, -2, -3, -4, -5, -6, -7, -8, -9, -10]
[3, 0, 0, -3] > [3, 2, 1, 0, 0, -1, -2, -3]
[1, 3, 5, 7, 5, 3, 1, -1, -3] > [1, 2, 3, 4, 5, 6, 7, 6, 5, 4, 3, 2, 1, 0, -1, -2, -3]

Input will always have at least 2 integers.

Shortest answer wins!

*/
package main

import (
	"fmt"
	"reflect"
)

func main() {
	test([]int{0, 5, 0}, []int{0, 1, 2, 3, 4, 5, 4, 3, 2, 1, 0})
	test([]int{3, 5, 5, 3}, []int{3, 4, 5, 5, 4, 3})
	test([]int{1, 9}, []int{1, 2, 3, 4, 5, 6, 7, 8, 9})
	test([]int{10, -10}, []int{10, 9, 8, 7, 6, 5, 4, 3, 2, 1, 0, -1, -2, -3, -4, -5, -6, -7, -8, -9, -10})
	test([]int{3, 0, 0, -3}, []int{3, 2, 1, 0, 0, -1, -2, -3})
	test([]int{1, 3, 5, 7, 5, 3, 1, -1, -3}, []int{1, 2, 3, 4, 5, 6, 7, 6, 5, 4, 3, 2, 1, 0, -1, -2, -3})
	test([]int{}, []int{})
	test([]int{1}, []int{})
}

func assert(x bool) {
	if !x {
		panic("assertion failed")
	}
}

func test(a, r []int) {
	p := fluctuate(a)
	fmt.Println(p)
	assert(reflect.DeepEqual(p, r))
}

func fluctuate(a []int) []int {
	r := []int{}
	for i := 1; i < len(a); i++ {
		x, y, z := a[i-1], a[i], cmp(a[i-1], a[i])
		if x == y {
			r = append(r, x)
		}

		if n := len(r); n > 0 && x == r[n-1] {
			x += z
		}

		for y += z; x != y; x += z {
			r = append(r, x)
		}
	}
	return r
}

func cmp(a, b int) int {
	if a < b {
		return 1
	}
	return -1
}
