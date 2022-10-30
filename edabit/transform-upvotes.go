/*

Create a function that transforms a string of upvote counts into an array of numbers. Each k represents a thousand.
Examples

transformUpvotes("6.8k 13.5k") ➞ [6800, 13500]

transformUpvotes("5.5k 8.9k 32") ➞ [5500, 8900, 32]

transformUpvotes("20.3k 3.8k 7.7k 992") ➞ [20300, 3800, 7700, 992]

Notes

Return the upvotes as an array.

*/

package main

import (
	"strconv"
	"strings"
)

func main() {
	eq(upvotes("6.8k 13.5k"), []int{6800, 13500})
	eq(upvotes("5.5k 8.9k 32"), []int{5500, 8900, 32})
	eq(upvotes("20.3k 3.8k 7.7k 992"), []int{20300, 3800, 7700, 992})
}

func upvotes(s string) []int {
	var p []int
	t := strings.SplitN(s, " ", -1)
	for _, t := range t {
		m := 1.0
		if strings.HasSuffix(t, "k") {
			m = 1000
			t = strings.TrimSuffix(t, "k")
		}
		n, err := strconv.ParseFloat(t, 64)
		if err != nil {
			continue
		}
		p = append(p, int(n*m))
	}
	return p
}

func eq(a, b []int) {
	assert(len(a) == len(b))
	for i := range a {
		assert(a[i] == b[i])
	}
}

func assert(x bool) {
	if !x {
		panic("assertion failed")
	}
}
