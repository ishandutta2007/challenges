/*

Create a function that takes a list of numbers and returns the sum of all prime numbers in the list.

Examples

SumPrimes(new int[] { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 }) ➞ 17

SumPrimes(new int[] { 2, 3, 4, 11, 20, 50, 71 }) ➞ 87

SumPrimes(new int[] { }) ➞ 0

Notes

    Given numbers won't exceed 101.
    A prime number is a number which has exactly two divisors (1 and itself).

*/

package main

import "math"

func main() {
	assert(sumprimes([]int{1, 2, 3, 4, 5, 6, 7, 8, 9, 10}) == 17)
	assert(sumprimes([]int{2, 3, 4, 11, 20, 50, 71}) == 87)
	assert(sumprimes([]int{19, 21, 24, 27, 30, 37}) == 56)
	assert(sumprimes([]int{69, 79, 87, 97, 101}) == 277)
	assert(sumprimes([]int{53, 59, 28, 50, 45, 33, 61}) == 173)
	assert(sumprimes([]int{}) == 0)
	assert(sumprimes([]int{11, 11, 11, 11, 11, 22, 22, 22}) == 55)
	assert(sumprimes([]int{67, 24, 58, 28, 71, 73, 99}) == 211)
}

func assert(x bool) {
	if !x {
		panic("assertion failed")
	}
}

func sumprimes(a []int) int {
	r := 0
	for i := range a {
		if isprime(a[i]) {
			r += a[i]
		}
	}
	return r
}

func isprime(n int) bool {
	if n < 2 {
		return false
	}

	l := math.Sqrt(float64(n))
	for i := 2; i <= int(l); i++ {
		if n%i == 0 {
			return false
		}
	}
	return true
}
