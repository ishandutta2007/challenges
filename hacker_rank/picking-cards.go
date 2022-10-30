/*

There are N cards on the table and each has a number between 0 and N. Let us denote the number on the ith card by ci.
You want to pick up all the cards. The ith card can be picked up only if at least ci cards have been picked up before it.
(As an example, if a card has a value of 3 on it, you can't pick that card up unless you've already picked up 3 cards previously)
In how many ways can all the cards be picked up?

*/

package main

import "fmt"

func main() {
	fmt.Println(count([]int{0, 0, 0}))
	fmt.Println(count([]int{0, 0, 1}))
	fmt.Println(count([]int{0, 3, 3}))
	fmt.Println(count([]int{0, 0, 0, 0, 0}))
}

// Idea is to make a histogram of the card values and treat them as indices.
// If there is a value that is non-existent, it will return 0; we can't order them in that case
// Otherwise the multiplication will count the ways we can reorder them
func count(p []int) int {
	c := make(map[int]int)
	for i := range p {
		c[p[i]]++
	}

	s := 0
	w := 1
	for i := range p {
		s += c[i]
		w = (w * s) % 1000000007
		if w == 0 {
			break
		}
		s--
	}
	return w
}
