/*

Print all integers ai such that ai is divisible by x and not divisible by y, where 1 < ai < n < 100000.

Input
First, you are given t (t<100) - the number of test cases. In each of the following t lines, 3 integers: n x y.

You might assume also that x < n and x is not divisible by y.

Output
In each of the following t lines, numbers requested in the problem description in the separated by a single space in ascending order.

Example

Input:
2
7 2 4
35 5 12

Output:
2 6
5 10 15 20 25 30

*/

package main

import (
	"fmt"
	"reflect"
)

func main() {
	test(7, 2, 4, []uint{2, 6})
	test(35, 5, 12, []uint{5, 10, 15, 20, 25, 30})
}

func assert(x bool) {
	if !x {
		panic("assertion failed")
	}
}

func test(n, x, y uint, r []uint) {
	p := divisibility(n, x, y)
	fmt.Println(p)
	assert(reflect.DeepEqual(p, r))
}

func divisibility(n, x, y uint) []uint {
	p := []uint{}
	if x == 0 || y == 0 {
		return p
	}
	for i := uint(1); i*x < n; i++ {
		if z := i * x; y != 0 && z%y != 0 {
			p = append(p, z)
		}
	}
	return p
}
