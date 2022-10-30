/*

An out-shuffle, also known as an out faro shuffle or a perfect shuffle, is a controlled method for shuffling playing cards.
It is performed by splitting the deck into two equal halves and interleaving them together perfectly, with the condition that the top card of the deck remains in place.

Using an array to represent a deck of cards, an out-shuffle looks like:

[1, 2, 3, 4, 5, 6, 7, 8] ➞ [1, 5, 2, 6, 3, 7, 4, 8]
// Card 1 remains in the first position.

If we repeat the process, the deck eventually returns to original order.

Shuffle 1:

[1, 2, 3, 4, 5, 6, 7, 8] ➞ [1, 5, 2, 6, 3, 7, 4, 8]

Shuffle 2:

[1, 5, 2, 6, 3, 7, 4, 8] ➞ [1, 3, 5, 7, 2, 4, 6, 8]

Shuffle 3:

[1, 3, 5, 7, 2, 4, 6, 8] ➞ [1, 2, 3, 4, 5, 6, 7, 8]
// Back where we started.

Write a function that takes a positive even integer representing the number of the cards in a deck, and returns the number of out-shuffles required to return the deck to its original order.
Examples

shuffle_count(8) ➞ 3

shuffle_count(14) ➞ 12

shuffle_count(52) ➞ 8

Notes

    The number of cards is always even and greater than one. Thus, the smallest possible deck size is two.
    A recursive version of this challenge can be found via this link.

*/

package main

func main() {
	itab := []int{
		2, 8, 14, 26, 52, 70, 104, 208,
	}
	otab := []int{
		1, 3, 12, 20, 8, 22, 51, 66,
	}
	for i := range itab {
		assert(outshuffle(itab[i]) == otab[i])
	}
}

func assert(x bool) {
	if !x {
		panic("assertion failed")
	}
}

// https://oeis.org/A002326
func outshuffle(n int) int {
	p := make([]int, n)
	q := make([]int, n)
	for i := range p {
		p[i] = i
	}

	c := 0
	for {
		interleave(p, q, n)
		p, q, c = q, p, c+1
		if isnatural(p) {
			break
		}
	}
	return c
}

func interleave(p, q []int, n int) {
	for i, j, k := 0, 0, n/2; i < n; i++ {
		l := 0
		if i&1 == 0 {
			l, j = j, j+1
		} else {
			l, k = k, k+1
		}
		q[i] = p[l]
	}
}

func isnatural(a []int) bool {
	for i := range a {
		if a[i] != i {
			return false
		}
	}
	return true
}
