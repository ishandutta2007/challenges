/*

In the Recursive Staircase Problem, your task is to find the number of ways of climbing a staircase of n stairs, with a set s possible steps. The example below shows that if n was 2 and s was [ 1, 2 ], the answer would be 2:

       _
   _ |2  You could either go from step 0-2 (because the set s contains 2), or
_ | 1    you could go from 0-1-2 (because the set s contains 1, taking one step at a time).
0

More examples below.
Examples

numWays(4, [1, 2]) ➞ 5

numWays(3, [1, 2, 3]) ➞ 4

numWays(10, [1, 2, 3, 4]) ➞ 401

Notes

The more efficient your solution the better. Do not use unecessary recursion as this will mean the program needs far longer to complete the tests.

*/

package main

func main() {
	assert(ways(4, []uint64{1, 2}) == 5)
	assert(ways(3, []uint64{1, 2, 3, 4}) == 4)
	assert(ways(10, []uint64{1, 2, 3, 4}) == 401)
	assert(ways(50, []uint64{1, 2}) == 20365011074)
	assert(ways(100, []uint64{1}) == 1)
}

func assert(x bool) {
	if !x {
		panic("assertion failed")
	}
}

func ways(n uint64, p []uint64) uint64 {
	return recurse(n, p, make(map[uint64]uint64))
}

func recurse(n uint64, p []uint64, m map[uint64]uint64) uint64 {
	if n == 0 {
		return 1
	}
	if v, f := m[n]; f {
		return v
	}

	v := uint64(0)
	for i := range p {
		if p[i] <= n && p[i] != 0 {
			v += recurse(n-p[i], p, m)
		}
	}
	m[n] = v
	return v
}
