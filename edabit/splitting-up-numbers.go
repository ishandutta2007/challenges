/*

Create a function that takes a number $num and returns each place value in the number.

Examples

numSplit(39) ➞ [30, 9]

numSplit(-434) ➞ [-400, -30, -4]

numSplit(100) ➞ [100, 0, 0]

Notes

N/A

*/

package main

import (
	"fmt"
	"reflect"
)

func main() {
	test(39, []int{30, 9})
	test(-434, []int{-400, -30, -4})
	test(100, []int{100, 0, 0})
	test(3929, []int{3000, 900, 20, 9})
	test(10293, []int{10000, 0, 200, 90, 3})
	test(900, []int{900, 0, 0})
	test(-100, []int{-100, 0, 0})
}

func test(n int, r []int) {
	p := split(n)
	fmt.Println(n, p)
	assert(reflect.DeepEqual(p, r))
}

func assert(x bool) {
	if !x {
		panic("assertion failed")
	}
}

func split(n int) []int {
	p := 1
	if n < 0 {
		n = -n
		p = -1
	}

	var r []int
	for {
		r = append(r, p*(n%10))
		if n /= 10; n == 0 {
			break
		}
		p *= 10
	}
	rev(r)
	return r
}

func rev(p []int) {
	for i := 0; i < len(p)/2; i++ {
		j := len(p) - i - 1
		p[i], p[j] = p[j], p[i]
	}
}
