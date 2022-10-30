/*

Create a function that determines the number of partitions of a natural number.

A partition of a number n is an unordered sum of one or more numbers which totals n. For example, the partitions of the number 4 are:

1 + 1 + 1 + 1 = 4
1 + 1 + 2 = 4
1 + 3 = 4
2 + 2 = 4
4 = 4

Since partitions are unordered, the sums 1 + 1 + 2 = 1 + 2 + 1 = 2 + 1 + 1 = 4 are considered the same partition.
Examples

partitions(4) ➞ 5

partitions(10) ➞ 42

partitions(0) ➞ 1

partitions(1) ➞ 1

partitions(2) ➞ 2

Notes

Remember the trivial partition n = n. Also, we say there is one way to partition zero; namely, 0 = 0.

*/
package main

func main() {
	assert(partitions(0) == 1)
	assert(partitions(1) == 1)
	assert(partitions(2) == 2)
	assert(partitions(3) == 3)
	assert(partitions(4) == 5)
	assert(partitions(5) == 7)
	assert(partitions(6) == 11)
	assert(partitions(7) == 15)
	assert(partitions(8) == 22)
	assert(partitions(9) == 30)
	assert(partitions(10) == 42)
	assert(partitions(11) == 56)
	assert(partitions(12) == 77)
	assert(partitions(13) == 101)
	assert(partitions(14) == 135)
	assert(partitions(15) == 176)
	assert(partitions(16) == 231)
	assert(partitions(17) == 297)
	assert(partitions(19) == 490)
	assert(partitions(20) == 627)
}

func assert(x bool) {
	if !x {
		panic("assertion failed")
	}
}

var cache = make(map[int]int)

// https://en.wikipedia.org/wiki/Partition_function_(number_theory)
func partitions(n int) int {
	if n < 0 {
		return 0
	}
	if n == 0 {
		return 1
	}
	if v, ok := cache[n]; ok {
		return v
	}

	r := 0
	p := 1
	for k := 1; ; k++ {
		u := partitions(n - k*(3*k-1)/2)
		v := partitions(n - k*(3*k+1)/2)
		if u == 0 && v == 0 {
			break
		}
		r += u*p + v*p
		p = -p
	}
	cache[n] = r
	return r
}
