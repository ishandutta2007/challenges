/*

Assume the result of an exam has been published.

After 5 minutes, First person knows the result.

In next 5 minutes, new 8 persons know the result, and in total 9 know it.

Again after 5 minutes, new 27 people know, and total 36 know.

In similar fashion, total 100, 225..... people keep knowing it on 5 minute interval.

Challenge

Given a total number of people knowing (n), and a starting time in hour and minutes, output when total n people will know the result.

Example: If start is 1:02, and n is 225 the output time will be 1:27.

In output colons of time aren't needed, you may input or output as list or seperate variables.

n will be always in the sequence of totals, i.e. (1,9,36,100,225....)

*/

package main

import (
	"math"
)

func main() {
	test(1, 2, 225, 1, 27)
}

func assert(x bool) {
	if !x {
		panic("assertion failed")
	}
}

func test(h, m, n, hr, mr int) {
	hn, mn := populated(h, m, n)
	assert(hn == hr)
	assert(mn == mr)
}

func populated(h, m, n int) (int, int) {
	t := h*60 + m
	i := 0
	for ; i != math.MaxInt; i++ {
		if seq(i) >= n {
			break
		}
	}
	t += 5 * i
	return t / 60, t % 60
}

// https://oeis.org/A000537
func seq(n int) int {
	x := n * (n + 1) / 2
	return x * x
}
