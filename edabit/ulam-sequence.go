/*

The Ulam sequence starts with:

ulam = 1, 2

The next number in the sequence is the smallest positive number that is equal to the sum of 2 distinct numbers (that are already in the sequence) exactly one way and larger than all earlier terms.
Trivially, this is 3, as there are only 2 numbers in the starting sequence.

ulam = 1, 2, 3

The next number is 4, which is the sum of 3+1. 4 is also 2+2, but this equation does not count, as the 2 addends have to be distinct.

ulam = 1, 2, 3, 4

The next number cannot be 5, as 5 = 1 + 4, but also 5 = 2 + 3.
There should only be one way to make an Ulam number from 2 distinct addends found in the sequence.
The next number is 6 (2+4).
There are 2 ways to make 7 (1+6 or 3+4), so the next is 8 (2+6).
And so on.

ulam = 1, 2, 3, 4, 6, 8, 11, 13, 16, 18, 26, 28, 36, 38, 47, 48, 53, …

Create a function that takes a number n and returns the nth number in the Ulam sequence.
Examples

Ulam(4) ➞ 4

Ulam(9) ➞ 16

Ulam(206) ➞ 1856

Notes

N/A

*/

package main

func main() {
	assert(ulam(4) == 4)
	assert(ulam(9) == 16)
	assert(ulam(38) == 180)
	assert(ulam(99) == 688)
	assert(ulam(206) == 1856)
	assert(ulam(495) == 5597)
	assert(ulam(577) == 6782)
}

func assert(x bool) {
	if !x {
		panic("assertion failed")
	}
}

var (
	uxs xs
)

// https://oeis.org/A002858
func ulam(n int) int {
	if len(uxs.u) == 0 {
		uxs.init()
	}
	return uxs.gen(n)
}

type xs struct {
	u []int
	r []int
	i int
}

func (x *xs) init() {
	x.u = []int{1, 2}
	x.r = []int{2, 1}
	x.i = 2
}

func (x *xs) gen(n int) int {
	for len(x.u) <= n {
		x.i += 1
		if x.isulam(x.i, 0, x.u, x.r) {
			x.u = append(x.u, x.i)
			x.r = append([]int{x.i}, x.r...)
		}
	}
	return x.u[n-1]
}

func (x *xs) isulam(n, h int, u, r []int) bool {
	if h == 2 {
		return false
	}
	hu := u[0]
	hr := r[0]
	if hr <= hu {
		return h == 1
	}
	if hr+hu > n {
		r = r[1:]
	} else if hr+hu < n {
		u = u[1:]
	} else {
		h += 1
		r = r[1:]
		u = u[1:]
	}
	return x.isulam(n, h, u, r)
}
