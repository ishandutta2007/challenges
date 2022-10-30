/*

Given a positive number n, rotate its base-10 digits m positions rightward. That is, output the result of m steps of moving the last digit to the start. The rotation count m will be a non-negative integer.

You should remove leading zeroes in the final result, but not in any of the intermediate steps. For example, for the test case 100,2 => 1, we first rotate to 010, then to 001, then finally drop the leading zeroes to get 1.

Tests
n,m => Output

123,1 => 312
123,2 => 231
123,3 => 123
123,4 => 312
1,637 => 1
10,1 => 1
100,2 => 1
10,2 => 10
110,2 => 101
123,0 => 123
9998,2 => 9899

*/

package main

import (
	"fmt"
	"strconv"
)

func main() {
	test(123, 1, 312)
	test(123, 2, 231)
	test(123, 3, 123)
	test(123, 4, 312)
	test(1, 637, 1)
	test(10, 1, 1)
	test(100, 2, 1)
	test(10, 2, 10)
	test(110, 2, 101)
	test(123, 0, 123)
	test(9998, 2, 9899)
}

func assert(x bool) {
	if !x {
		panic("assertion failed")
	}
}

func test(n, m, r uint) {
	p, err := rotate(n, m)
	fmt.Println(p)
	assert(err == nil)
	assert(p == r)
}

func rotate(n, m uint) (uint, error) {
	s := fmt.Sprint(n)
	l := uint(len(s))

	w := make([]byte, l)
	for i := uint(0); i < l; i++ {
		w[(i+m)%l] = s[i]
	}

	v, err := strconv.ParseUint(string(w), 10, 64)
	return uint(v), err
}
