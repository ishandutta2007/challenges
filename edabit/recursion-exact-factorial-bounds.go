/*

Create a recursive function that tests if a number is the exact upper bound of the factorial of n.
If so, return an array of the exact factorial bound and n, or otherwise, the string "Not an exact bound!".

Examples

isExact(6) ➞ [6, 3]

isExact(24) ➞ [24, 4]

isExact(125) ➞ "Not an exact bound!"

isExact(720) ➞ [720, 6]

isExact(1024) ➞ "Not an exact bound!"

isExact(40320) ➞ [40320, 8]

Notes

    It is expected from the challenge-takers to come up with a solution using the concept of recursion or the so-called recursive approach.
    You can read on more topics about recursion (see Resources tab) if you aren't familiar with it yet or hasn't fully understood the concept behind it before taking up this challenge or unless otherwise.
    There will be no exceptions to handle, all inputs are positive integers.
    A recursive approach is prone to Uncaught RangeError or exceededing the maximum call size of the stack
    A non-recursive version of this challenge (of lesser difficulty and the total liberty of not using a recursive approach) can be found here.
    If you think recursion is fun, you can find a collection of those challenges here.

*/

package main

func main() {
	itab := []uint64{
		0, 1, 2, 6, 24, 120, 5040, 40320, 3628800, 20922789888000, 125, 721, 1024, 41845579776000,
	}
	otab := []interface{}{
		"Not an exact bound!", [2]uint64{1, 1}, [2]uint64{2, 2}, [2]uint64{6, 3}, [2]uint64{24, 4}, [2]uint64{120, 5},
		[2]uint64{5040, 7}, [2]uint64{40320, 8}, [2]uint64{3628800, 10}, [2]uint64{20922789888000, 16},
		"Not an exact bound!", "Not an exact bound!", "Not an exact bound!", "Not an exact bound!",
	}
	for i := range itab {
		assert(exact(itab[i]) == otab[i])
	}
}

func assert(x bool) {
	if !x {
		panic("assertion failed")
	}
}

func exact(n uint64) interface{} {
	v := factor(n, 1)
	if v == 0 {
		return "Not an exact bound!"
	}
	if v > 1 {
		v--
	}
	return [2]uint64{n, v}
}

func factor(n, m uint64) uint64 {
	if n == 1 {
		return 1
	}
	if n == 0 || n%m != 0 {
		return 0
	}

	v := factor(n/m, m+1)
	if v == 0 {
		return 0
	}
	return 1 + v
}
