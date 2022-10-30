/*

Create a function that determines how many number pairs are embedded in a space-separated string. The first numeric value in the space-separated string represents the count of the numbers, thus, excluded in the pairings.

Examples

number_pairs("7 1 2 1 2 1 3 2") ➞ 2
// (1, 1), (2, 2)

number_pairs("9 10 20 20 10 10 30 50 10 20") ➞ 3
// (10, 10), (20, 20), (10, 10)

number_pairs("4 2 3 4 1") ➞ 0
// Although two 4's are present, the first one is discounted.

Notes

Always take into consideration the first number in the string is not part of the pairing, thus, the count. It may not seem so useful as most people see it, but it's mathematically significant if you deal with set operations.

*/

package main

import (
	"fmt"
	"strings"
)

func main() {
	itab := []string{
		"7 1 2 1 2 1 3 2",
		"9 10 20 20 10 10 30 50 10 20",
		"4 2 3 4 1",
		"13 10 20 20 10 10 30 50 10 20 50 50 30 20",
		"10 1 2 5 6 5 2 1 7 8 1",
		"16 2 3 5 11 1 11 5 7 9 13 17 3 8 7 2 1",
		"6 1 2 2 4 3 4",
	}
	otab := []int{2, 3, 0, 6, 3, 6, 2}
	for i := range itab {
		assert(pairs(itab[i]) == otab[i])
	}
}

func assert(x bool) {
	if !x {
		panic("assertion failed")
	}
}

func pairs(s string) int {
	m := make(map[int]int)
	r := strings.NewReader(s)

	var x int
	fmt.Fscanf(r, "%d", &x)
	for {
		_, err := fmt.Fscanf(r, "%d", &x)
		if err != nil {
			break
		}
		m[x]++
	}

	t := 0
	for _, v := range m {
		t += v / 2
	}
	return t
}
