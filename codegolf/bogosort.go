/*

Write the shortest function to implement bogosort. In specific, your function should:

    Take an array (or your language's equivalent) as input
    Check if its elements are in sorted order; if so, return the array
    If not, shuffle the elements, and start again

*/

package main

import (
	"fmt"
	"math/rand"
	"time"
)

func main() {
	rand.Seed(time.Now().UnixNano())

	fmt.Println(bogosort([]int{6, 4, 1, 5}))
	fmt.Println(bogosort([]int{90, 101, 3, 5, 8, 568, 59, 569}))
}

func sorted(a []int) bool {
	for i := 0; i < len(a)-1; i++ {
		if a[i] > a[i+1] {
			return false
		}
	}
	return true
}

// https://en.wikipedia.org/wiki/Bogosort
func bogosort(a []int) []int {
	for !sorted(a) {
		rand.Shuffle(len(a), func(i, j int) {
			a[i], a[j] = a[j], a[i]
		})
	}
	return a
}
