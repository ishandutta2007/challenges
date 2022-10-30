/*

N-bonacci numbers are generalisations of the fibonacci sequence, where the next term is always the sum of the previous N terms. By convention, the first (N-1) terms are all 0 and the Nth term is 1.

The initial 10 terms of the first 5 N-bonacci sequences are therefore:

    1-bonacci = 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, ...
    2-bonacci = 0, 1, 1, 2, 3, 5, 8, 13, 21, 34, ...
    3-bonacci = 0, 0, 1, 1, 2, 4, 7, 13, 24, 44, ...
    4-bonaaci = 0, 0, 0, 1, 1, 2, 4, 8, 15, 29, ...
    5-bonacci = 0, 0, 0, 0, 1, 1, 2, 4, 8, 16, ...

Write a function that returns the kth term of the N-bonacci sequence, for two integer arguments N and k.

Examples

bonacci(1, 10) ➞ 1

bonacci(2, 10) ➞ 34

bonacci(3, 10) ➞ 44

bonacci(4, 10) ➞ 29

bonacci(5, 10) ➞ 16

Notes

N/A

*/

package main

func main() {
	assert(bonacci(1, 10) == 1)
	assert(bonacci(2, 10) == 34)
	assert(bonacci(3, 10) == 44)
	assert(bonacci(4, 10) == 29)
	assert(bonacci(5, 10) == 16)
	assert(bonacci(2, 7) == 8)
	assert(bonacci(3, 13) == 274)
	assert(bonacci(5, 24) == 203513)
	assert(bonacci(8, 44) == 32440904961)
	assert(bonacci(1, 4) == 1)
	assert(bonacci(2, 2) == 1)
	assert(bonacci(3, 1) == 0)
}

func assert(x bool) {
	if !x {
		panic("assertion failed")
	}
}

func bonacci(n, k int64) int64 {
	if n <= 0 || k < 0 || k < n {
		return 0
	}
	if n == k {
		return 1
	}

	p := make([]int64, n)
	p[n-1] = 1

	r := int64(0)
	for i, l := int64(0), int64(0); i < k-n; i++ {
		v := int64(0)
		for j := int64(0); j < n; j++ {
			v += p[(j+l)%n]
		}
		p[l] = v
		r = p[l]
		l = (l + 1) % n
	}
	return r
}
