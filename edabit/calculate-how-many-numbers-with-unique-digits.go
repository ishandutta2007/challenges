/*

The function is given an integer n. Count the numbers with unique digits in the range 0 <= num < pow(10, n).
Examples

numsWithUniqueDigits(2) ➞ 91
// There are 100 numbers in total (from 0 to 99 inclusive).
// The following 9 numbers should not be counted:
// 11, 22, 33, 44, 55, 66, 77, 88, 99
// Thus 100 – 9 ➞ 91

Notes

N/A

*/

package main

func main() {
	tab := []uint{
		1, 10, 91, 739, 5275, 32491, 168571, 712891, 2345851, 5611771,
	}
	for i := range tab {
		assert(count(uint(i)) == tab[i])
	}
}

func assert(x bool) {
	if !x {
		panic("assertion failed")
	}
}

var cache = map[uint]uint{0: 1}

func count(n uint) uint {
	if r := cache[n]; r > 0 {
		return r
	}

	cache[n] = uniq(n) + count(n-1)
	return cache[n]
}

// https://oeis.org/A073531
func uniq(n uint) uint {
	if n > 10 {
		return 0
	}
	return 9 * factorial(9) / factorial(10-n)
}

func factorial(n uint) uint {
	v := uint(1)
	for i := uint(2); i <= n; i++ {
		v *= i
	}
	return v
}
