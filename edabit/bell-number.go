/*

The Bell number is the number of ways an array of n items can be partitioned into non-empty subarrays.
See the resources section for an in-depth explanation.

Create a function that takes a number n and returns the corresponding Bell number.

Examples

bell(1) ➞ 1
// sampleArr = [1]
// possiblePartitions = [[[1]]]

bell(2) ➞ 2
// sampleArr = [1, 2]
// possiblePartitions = [[[1, 2]], [[1], [2]]]

bell(3) ➞ 5
// sampleArr = [1, 2, 3]
// possiblePartitions = [[[1, 2, 3]], [[1, 2], [3]], [[1], [2, 3]], [[1, 3], [2]], [[1], [2], [3]]]

Notes

N/A

*/

package main

func main() {
	assert(bell(1) == 1)
	assert(bell(2) == 2)
	assert(bell(3) == 5)
	assert(bell(4) == 15)
	assert(bell(5) == 52)
	assert(bell(6) == 203)
}

func assert(x bool) {
	if !x {
		panic("assertion failed")
	}
}

var cache = map[int]int{0: 1}

// https://en.wikipedia.org/wiki/Bell_number
// https://oeis.org/A000110
func bell(n int) int {
	if b := cache[n]; b > 0 {
		return b
	}

	r := 0
	for k := 0; k < n; k++ {
		r += binomial(n-1, k) * bell(k)
	}
	cache[n] = r
	return r
}

func binomial(n, k int) int {
	if k < 0 || k > n {
		return 0
	}
	if k == 0 || k == n {
		return 1
	}

	k = min(k, n-k)
	c := 1
	for i := 0; i < k; i++ {
		c = c * (n - i) / (i + 1)
	}
	return c
}

func min(a, b int) int {
	if a < b {
		return a
	}
	return b
}
