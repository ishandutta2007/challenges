/*

Goldbach's Conjecture is amongst the oldest and well-known unsolved mathematical problems.
In correspondence with Leonhard Euler in 1742, German mathematician Christian Goldbach made a conjecture, which states:

"Every even whole number greater than 2 is the sum of two prime numbers."

Even though it's been thoroughly tested and analyzed and seems to be true, it hasn't been proved yet (thus, remaining a conjecture.)

Create a function that takes a number and returns an array as per the following rules:

    If the given number is odd and greater than two, return an empty array.
    If the given number is even and greater than two, return an array of two prime numbers whose sum is the given input.
    Both prime numbers must be the farthest (with the greatest difference).

Examples

goldbachConjecture(1) ➞ []
// The given number is not greater than 2.

goldbachConjecture(7) ➞ []
// The given number is not an even number.

goldbachConjecture(14) ➞ [3, 11]

Notes

Return array in sequence: [smaller, bigger]

*/

package main

import (
	"fmt"
	"math"
	"reflect"
	"sort"
)

func main() {
	test(1, nil)
	test(7, nil)
	test(14, []uint{3, 11})
	test(4, []uint{2, 2})
	test(8, []uint{3, 5})
	test(10, []uint{3, 7})
	test(24, []uint{5, 19})
	test(100, []uint{3, 97})
	test(1234, []uint{3, 1231})
	test(1400, []uint{19, 1381})
	test(1566, []uint{7, 1559})
	test(3444, []uint{11, 3433})
}

func test(n uint, r []uint) {
	p := goldbach(n)
	fmt.Println(n, p, r)
	if len(p) == 0 {
		assert(len(p) == len(r))
	} else {
		assert(reflect.DeepEqual(p, r))
	}
}

func assert(x bool) {
	if !x {
		panic("assertion failed")
	}
}

func goldbach(n uint) []uint {
	if n < 2 || n&1 != 0 {
		return nil
	}

	p := eratosthenes(n)
	for i := 0; i < len(p); i++ {
		j := sort.Search(len(p), func(k int) bool { return p[k] >= n-p[i] })
		if j < len(p) && p[i]+p[j] == n {
			return []uint{p[i], p[j]}
		}
	}
	return nil
}

func eratosthenes(n uint) []uint {
	l := uint(math.Sqrt(float64(n)))
	p := make([]bool, n)
	for i := uint(2); i <= l; i++ {
		for j := i + i; j < n; j += i {
			p[j] = true
		}
	}

	var r []uint
	for i := uint(2); i < n; i++ {
		if !p[i] {
			r = append(r, i)
		}
	}
	return r
}
