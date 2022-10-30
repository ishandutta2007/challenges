/*

Given two positive integers n and k, generate all binaries between the integers 0 and (2^n) - 1, inclusive.
These binaries will be sorted in descending order according to the number of existing 1s on it, if there is a tie, we choose the lowest numerical value.
Return the k-th element from the sorted array created.

For n = 3 and k = 5 for example, the numbers from 0 to 7 (7 = (2^3) - 1), make the binary array:

["0", "1", "10", "11", "100", "101", "110", "111"]

When sorted by the rules, we have:

["111", "11", "101", "110", "1", "10", "100", "0"]

And "1" is the fifth element on it.
Examples

kthBinaryArray(3, 5) ➞ "1"
// ["111", "11", "101", "110", "1", "10", "100", "0"]

kthBinaryArray(4, 10) ➞ "1010"
// ["1111", "111", "1011", "1101", "1110", "11", "101", "110", "1001", "1010", "1100", "1", "10", "100", "1000", "0"]

Notes

N/A

*/

package main

import (
	"fmt"
	"math/bits"
	"sort"
)

func main() {
	assert(kth(3, 5) == "1")
	assert(kth(4, 10) == "1010")
	assert(kth(5, 16) == "11100")
	assert(kth(10, 5) == "1110111111")
	assert(kth(7, 10) == "101111")
}

func assert(x bool) {
	if !x {
		panic("assertion failed")
	}
}

func kth(n, k uint) string {
	if k == 0 || k >= 1<<n {
		return ""
	}

	p := make([]uint, 1<<n)
	for i := range p {
		p[i] = uint(i)
	}
	sort.Slice(p, func(i, j int) bool {
		x := bits.OnesCount(p[i])
		y := bits.OnesCount(p[j])
		if x > y {
			return true
		}
		if x == y {
			return p[i] < p[j]
		}
		return false
	})
	return fmt.Sprintf("%b", p[k-1])
}
