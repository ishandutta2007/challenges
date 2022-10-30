/*

Create a function that takes an integer argument and returns an array of prime numbers found in the decimal representation of that number (not factors).

For example, extractPrimes(1717) returns [7, 7, 17, 17, 71].

The array should be in acending order. If a prime number appears more than once, every occurance should be listed. If no prime numbers are found, return an empty array.

Examples

extractPrimes(1) ➞ []

extractPrimes(7) ➞ [7]

extractPrimes(73) ➞ [3, 7, 73]

extractPrimes(1313) ➞ [3, 3, 13, 13, 31, 131, 313]

Notes

    All test cases are positive real integers.
    Some numbers will have leading zeros. For example, the number 103 contains the prime number 3, but also contains 03. These should be treated as the same number, so the result would simply be [3].

*/

package main

import (
	"fmt"
	"math"
	"reflect"
	"sort"
)

func main() {
	test(1, []int{})
	test(2, []int{2})
	test(3, []int{3})
	test(13, []int{3, 13})
	test(101, []int{101})
	test(313, []int{3, 3, 13, 31, 313})
	test(10234, []int{2, 3, 23})
}

func test(n int, r []int) {
	p := extract(n)
	fmt.Println(p)
	assert(reflect.DeepEqual(p, r))
}

func assert(x bool) {
	if !x {
		panic("assertion failed")
	}
}

func extract(n int) []int {
	r := []int{}
	d := digits(n)
	for i := 0; i <= len(d); i++ {
		for j := 0; j < i; j++ {
			v := number(d[j:i])
			z := leadingzeroes(d[j:i])
			if !z && isprime(v) {
				r = append(r, v)
			}
		}
	}
	sort.Ints(r)
	return r
}

func leadingzeroes(d []int) bool {
	return d[len(d)-1] == 0
}

func number(d []int) int {
	r := 0
	for i := len(d) - 1; i >= 0; i-- {
		r = (r * 10) + d[i]
	}
	return r
}

func digits(n int) []int {
	var r []int
	for {
		r = append(r, abs(n%10))
		if n /= 10; n == 0 {
			break
		}
	}
	return r
}

func isprime(n int) bool {
	if n < 2 {
		return false
	}

	l := int(math.Sqrt(float64(n)))
	for i := 2; i <= int(l); i++ {
		if n%i == 0 {
			return false
		}
	}
	return true
}

func abs(x int) int {
	if x < 0 {
		x = -x
	}
	return x
}
